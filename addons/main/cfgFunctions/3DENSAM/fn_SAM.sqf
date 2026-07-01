#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-06-21

    Description:
    Handles the Scenario Manager UI.

    Parameter(s):
    0: DISPLAY - Scenario Manager UI
    0: STRING - Mode

    Returns:
    -
*/

disableSerialization;

params
[
    ["_display", uiNamespace getVariable ['ENH_SAM_Display', displayNull]],
    ["_mode", "onLoad"]
];

switch _mode do
{
    case "onLoad":
    {
        uiNamespace setVariable ["ENH_SAM_Display", _display];

        private _ctrlLB = CTRL(IDC_SAM_TEMPLATES);

        // Load templates
        {
            private _index = _ctrlLB lbAdd (_x # 0); // Use title as lb entry
            _ctrlLB lbSetTooltip [_index, _x # 1]; // Use description of templates as tooltip
            _ctrlLB lbSetData [_index, str _x]; // Store the whole template data as lb data for easy access
        } forEach (profileNamespace getVariable ["ENH_SAM_Templates", []]);

        lbSort [_ctrlLB, "DESC"];

        // Focus Search
        _display displayAddEventHandler ["KeyDown",
        {
            params ["_display", "_key", "", "_ctrl"];
            if (_key isEqualTo 33 && _ctrl) then
            {
                ctrlSetFocus CTRL(IDC_SAM_SEARCH);
            }
        }];

        [CTRL(IDC_SAM_SEARCH), CTRL(IDC_SAM_BUTTONSEARCH)] call ENH_fnc_initSearchControls;
    };
    case "loadTemplate":
    {
        private _ctrlTV = CTRL(IDC_SAM_ATTRIBUTES);
        private _ctrlLB = CTRL(IDC_SAM_TEMPLATES);
        private _selectedItem = lbCurSel _ctrlLB;

        // Clear search
        CTRL(IDC_SAM_SEARCH) ctrlSetText "";

        tvClear _ctrlTV;

        // Get only the data stored in the selected item
        private _templateData = _ctrlLB lbData _selectedItem;

        // Attributes are stored as string. Call and compile them to convert them to an array
        _templateData = call compile _templateData;
        _attributes = _templateData # 2;

        if (_templateData isEqualTo []) exitWith {false};

        // Add base categories and a custom one used for modded attributes
        _ctrlTV tvAdd [[], "Intel"];
        _ctrlTV tvAdd [[], "Scenario"];
        _ctrlTV tvAdd [[], "Multiplayer"];
        _ctrlTV tvAdd [[], "GarbageCollection"];
        _ctrlTV tvAdd [[], "Preferences"];
        _ctrlTV tvAdd [[], "Mods"];

        // Put all attributes into their corresponding categories
        {
            private _baseIndex = switch (_x # 0) do
            {
                case "Intel": {0};
                case "Scenario": {1};
                case "Multiplayer": {2};
                case "GarbageCollection": {3};
                case "Preferences": {4};
                default {5};
            };
            // _x # 0 => Attribute Section
            // _x # 1 => PropertyName
            // _x # 2 => Attribute Value
            // _x # 3 => Attribute Display Name
            private _attributeIndex = _ctrlTV tvAdd [[_baseIndex], format ["%1 (%2)", _x # 3, _x # 1]];
            _ctrlTV tvSetData [[_baseIndex, _attributeIndex], str _x];

            private _valueIndex = _ctrlTV tvAdd [[_baseIndex, _attributeIndex], str (_x # 2)];

            // We set data here as well, so players can select both value and attribute to apply attribute
            _ctrlTV tvSetData [[_baseIndex, _attributeIndex, _valueIndex], str _x];

            _ctrlTV tvSetTooltip [[_baseIndex, _attributeIndex, _valueIndex], str (_x # 2)];
        } forEach _attributes;

        _ctrlTV tvSortAll [[], false];
    };
    case "createTemplate":
    {
        _display spawn
        {
            params ["_display"];
            private _displayTemplateData = _display createDisplay "ENH_TemplateData";

            waitUntil {isNull _displayTemplateData};

            private _title = uiNamespace getVariable ["ENH_TitleValue", ""];
            private _description = uiNamespace getVariable ["ENH_DescriptionValue", ""];

            if (_title == "") exitWith {};

            private _attributeValues = [nil, "getScenarioAttributes"] call ENH_fnc_SAM;

            private _ctrlLB = CTRL(IDC_SAM_TEMPLATES);

            private _index = _ctrlLB lbAdd _title;
            _ctrlLB lbSetTooltip [_index, _description];

            // Save Title, Description and actual scenario attributes
            _ctrlLB lbSetData [_index, str [_title, _description, _attributeValues]];
            lbSort [_ctrlLB, "DESC"];

            [nil, "saveTemplates"] call ENH_fnc_SAM;
        };
    };
    case "deleteTemplate":
    {
        CTRL(IDC_SAM_TEMPLATES) lbDelete (lbCurSel CTRL(IDC_SAM_TEMPLATES));

        // Clear tree view
        tvClear CTRL(IDC_SAM_ATTRIBUTES);

        // Clear search
        CTRL(IDC_SAM_SEARCH) ctrlSetText "";

        [nil, "saveTemplates"] call ENH_fnc_SAM;
    };
    case "applyTemplate":
    {
        private _ctrlLB = CTRL(IDC_SAM_TEMPLATES);
        private _index = lbCurSel _ctrlLB;

        if (_index isEqualTo -1) exitWith {};

        // Data is string but needs to be array
        _data = call compile (_ctrlLB lbData _index);

        // We don't need the title and description of the template, only the attributes
        _data = _data # 2;

        collect3DENHistory
        {
            set3DENMissionAttributes _data;
        };

        playSound SOUND_FEEDBACK;
    };
    case "saveTemplates":
    {
        private _ctrlLB = CTRL(IDC_SAM_TEMPLATES);
        private _lbSize = lbSize _ctrlLB;
        private _templates = [];

        for "_i" from 0 to _lbSize - 1 do
        {
            private _data = call compile (_ctrlLB lbData _i);
            _templates pushBackUnique _data;
        };

        // Store templates in profilenamespace and save it.
        profileNamespace setVariable ["ENH_SAM_Templates", _templates];
        saveProfileNamespace;
    };
    case "getScenarioAttributes":
    {
        private _attributeValues = [];
        private _sections = [configFile >> "Cfg3DEN" >> "Mission", 0, false] call BIS_fnc_returnChildren;

        {
            private _section = configName _x;
            private _children = [configFile >> "Cfg3DEN" >> "Mission" >> _section >> "AttributeCategories", 2, false] call BIS_fnc_returnChildren;
            {
                private _attributeDisplayName = getText (_x >> "displayName");
                private _attributeName = getText (_x >> "property");// By default get _attributeValue by propertyName
                private _attributeValue = _section get3DENMissionAttribute _attributeName;

                if (isNil "_attributeValue") then
                {
                    _attributeName = getText (_x >> "data");
                    _attributeValue = _section get3DENMissionAttribute _attributeName;// If it's still nil get_attributeValue by data config entry
                };
                if (!isNil "_attributeValue") then// If value is still nil, then it's an attribute description or a not correctly configured attribute
                {
                    _attributeValues pushBack [_section, _attributeName, _attributeValue, _attributeDisplayName];
                };
            } forEach _children;
        } forEach _sections;

        _attributeValues
    };
    case "applyAttribute":
    {
        private _tvPath = tvCurSel CTRL(IDC_SAM_ATTRIBUTES);

        if (count _tvPath < 2) exitWith {};

        // Data is string, we need an array, so compiling it is
        _attributeData = call compile (CTRL(IDC_SAM_ATTRIBUTES) tvData _tvPath);// ["Section", "PropertyName", value];

        set3DENMissionAttributes [_attributeData];

        playSound SOUND_FEEDBACK;
    };
};
