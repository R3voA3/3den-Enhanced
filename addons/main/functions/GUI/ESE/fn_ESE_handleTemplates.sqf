#include "\x\enh\addons\main\script_component.hpp"

params ["_mode"];
disableSerialization;

private _display = uiNamespace getVariable "ENH_Display_ESE";

switch _mode do
{
    case "create":
    {
        0 spawn
        {
            private _displayTemplateData = (uiNamespace getVariable "ENH_Display_ESE") createDisplay "ENH_TemplateData";

            waitUntil {isNull _displayTemplateData};

            private _title = uiNamespace getVariable ["ENH_TitleValue", ""];
            private _description = uiNamespace getVariable ["ENH_DescriptionValue", ""];

            if (_title == "") exitWith {};

            private _templates = profileNamespace getVariable ["ENH_VIM_Templates", []];

            // Return inventory data
            private _value = [true] call ENH_fnc_ESE_applyAttribute;

            _templates pushBack [_title, _description, _value];
            profileNamespace setVariable ["ENH_VIM_Templates", _templates];
            "update" call ENH_fnc_ESE_handleTemplates;
        };
    };
    case "delete":
    {
        private _ctrlItems = CTRL(IDC_ESE_TEMPLATESLIST);
        private _row = lbCurSel _ctrlItems;

        _ctrlItems lbDelete _row;

        // Update templates variable
        private _templates = profileNamespace getVariable ["ENH_VIM_Templates", []];
        _templates deleteAt _row;
        profileNamespace setVariable ["ENH_VIM_Templates", _templates];
    };
    case "preview":
    {
        // Get template data from listbox
        private _ctrlItems = CTRL(IDC_ESE_TEMPLATESLIST);
        private _row = lbCurSel _ctrlItems;

        if (_row isEqualTo -1) exitWith {};

        private _value = _ctrlItems lbData lbCurSel _ctrlItems;
        [false, _value] call ENH_fnc_ESE_loadAttributeValue;
    };
    case "update":
    {
        private _lbTemplates = CTRL(IDC_ESE_TEMPLATESLIST);
        lbClear _lbTemplates;
        {
            _x params ["_name", "_description", "_data", ["_date", systemTime]];
            [_lbTemplates, _name, _data, "", "", _description, [_date] call ENH_fnc_systemTimeFormatted] call ENH_fnc_ESE_lbAdd;
        } forEach (profileNamespace getVariable ["ENH_VIM_Templates", []]);
    };
};
