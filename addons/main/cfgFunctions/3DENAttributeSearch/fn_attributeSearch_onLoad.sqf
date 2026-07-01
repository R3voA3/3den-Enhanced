#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2023-09-16
    File: 3denEnhanced\functions\GUI\attributeSearch\fn_attributeSearch_onLoad.sqf

    Description:
    Initializes the Search Attributes GUI.

    Parameter(s):
    0: DISPLAY - The Search Attributes GUI

    Return Value:
    -

    Examples(s):
    -
*/

#define COLOR_ATTRIBUTE [0.86, 0.73, 0.38, 1]
#define COLOR_ENTITY [0.81, 0.51, 0.29, 1]
#define COLOR_VALUE [0.42, 0.6, 0.24, 1]
#define ATT(ENTITY, ATTNAME) (ENTITY get3DENAttribute ATTNAME select 0)

if (!is3DEN) exitWith {};

disableSerialization;

params ["_display"];

private _ctrlTV = CTRL(IDC_ATTRIBUTESEARCH_TREE);
uiNamespace setVariable ["ENH_AttributeSearch_Display", _display];

all3DENEntities params ["_objects", "_groups", "_triggers", "_systems", "_waypoints", "_markers"];

// Allow users to add own attributes
private _attributes = profileNamespace getVariable
[
    "ENH_AttributeSearch",
    [
        ["init", [""]],
        ["presenceCondition", ["true"]],
        ["condition", ["this", "true"]],
        ["onActivation", [""]],
        ["onDeactivation", [""]],
        ["name", [""]],
        ["effectCondition", ["true"]],
        ["markerName", [""]],
        ["groupID", [""]],
        ["description", [""]],
        ["effectCondition", ["true"]],
        ["script", [""]]
    ]
];

{
    _ctrlTV tvAdd [[], toUpper (_x#0)];
    _ctrlTV tvSetColor [[_forEachIndex], COLOR_ATTRIBUTE];
} forEach _attributes;

ENH_AttributeSearch_AttributesCounter_Total = 0;
ENH_AttributeSearch_AttributesCounter_Valid = 0;

// Fill tree view
{
    ENH_AttributeSearch_TempIndex = 0;
    private _entity = _x;
    {
        _x params ["_attributeName", "_ignoredValues"];

        _ignoredValues = _ignoredValues + [""];
        private _attributeValue = ATT(_entity,_attributeName);

        private _displayName = switch (true) do
        {
            case (_entity in _groups):
            {
                format ["%1 - %2", ATT(_entity,"groupID"),ATT(_entity,"name")];
            };
            case (_entity in _objects or _entity in _systems):
            {
                format ["%1 - %2", [configOf _entity] call BIS_fnc_displayName, ATT(_entity,"name")];
            };
            case (_entity in _triggers):
            {
                format ["%1 - %2", localize "STR_3DEN_TRIGGER_TEXTPLURAL", ATT(_entity,"name")];
            };
            case (_entity in _waypoints):
            {
                format ["%1 - %2", ATT(_entity,"itemClass"), str _entity];
            };
            case (_entity in _markers):
            {
                format ["%1 - %2", getText (configFile >> "CfgMarkers" >> ATT(_entity,"itemClass") >> "name"), ATT(_entity,"markerName")];
            };
        };

        _displayName = _displayName trim [" -", 2];

        if (!isNil "_attributeValue" && {!(_attributeValue in _ignoredValues)}) then
        {
            private _entityIndex = _ctrlTV tvAdd [[ENH_AttributeSearch_TempIndex], _displayName + "     " + str get3DENEntityID _entity];

            _ctrlTV tvSetColor [[ENH_AttributeSearch_TempIndex, _entityIndex], COLOR_ENTITY];
            _ctrlTV tvSetValue [[ENH_AttributeSearch_TempIndex, _entityIndex], get3DENEntityID _entity];

            private _valueTextIndex = _ctrlTV tvAdd [[ENH_AttributeSearch_TempIndex, _entityIndex], _attributeValue];
            _ctrlTV tvSetColor [[ENH_AttributeSearch_TempIndex, _entityIndex, _valueTextIndex], COLOR_VALUE];
            _ctrlTV tvSetTooltip [[ENH_AttributeSearch_TempIndex, _entityIndex, _valueTextIndex], _attributeValue];
            ENH_AttributeSearch_AttributesCounter_Valid = ENH_AttributeSearch_AttributesCounter_Valid + 1;
        };

        ENH_AttributeSearch_TempIndex = ENH_AttributeSearch_TempIndex + 1;
        ENH_AttributeSearch_AttributesCounter_Total = ENH_AttributeSearch_AttributesCounter_Total + 1;
    } forEach _attributes;
} forEach (_objects + _groups + _systems + _triggers + _waypoints + _markers);

ENH_AttributeSearch_TempIndex = nil;

// Remove empty nodes
for "_index" from ((count _attributes) - 1) to 0 step -1 do
{
    if (_ctrlTV tvCount [_index] == 0) then {_ctrlTV tvDelete [_index]};
};

// Update counter
CTRL(IDC_ATTRIBUTESEARCH_COUNTER) ctrlSetText format ["%1/%2", ENH_AttributeSearch_AttributesCounter_Valid, ENH_AttributeSearch_AttributesCounter_Total];

// Wait until button was initialised and set its text and state
_display spawn
{
    waitUntil {!isNull (_this displayCtrl IDC_ATTRIBUTESEARCH_EDITATTRIBUTES)};
    _this displayCtrl IDC_ATTRIBUTESEARCH_EDITATTRIBUTES ctrlEnable false;
    _this displayCtrl IDC_ATTRIBUTESEARCH_EDITATTRIBUTES ctrlSetText format ["%1...", localize "STR_3DEN_Display3DEN_MenuBar_Attributes_text"];
};

_ctrlTV ctrlAddEventHandler ["TreeSelChanged",
{
    params ["_ctrlTV", "_selectionPath"];

    // Disable Edit Attributes button
    if (count _selectionPath < 3) exitWith
    {
        ctrlParent _ctrlTV displayCtrl IDC_ATTRIBUTESEARCH_EDITATTRIBUTES ctrlEnable false;

        // Move camera
        if (count _selectionPath == 2) exitWith
        {
            private _id = (_ctrlTV tvValue _selectionPath);
            private _entity = get3DENEntity _id;

            all3DENEntities params ["", "_groups", "", "", "", "_markers"];

            private _pos = [0, 0, 0];

            switch (true) do
            {
                case (_entity in _groups):
                {
                    _pos = ATT(leader _entity,"position");
                    if (get3DENActionState "toggleMap" > 0) then {do3DENAction "toggleMap"};
                };
                case (_entity in _markers):
                {
                    if (get3DENActionState "toggleMap" != 1) then {do3DENAction "toggleMap"};
                    private _ctrlmap = findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_MAP;

                    _pos = ATT(_entity,"position");
                    _ctrlmap ctrlMapAnimAdd [0, ctrlMapScale _ctrlmap, _pos];
                    ctrlMapAnimCommit _ctrlmap;
                    _pos
                };
                default
                {
                    if (get3DENActionState "toggleMap" > 0) then {do3DENAction "toggleMap"};
                    _pos = ATT(_entity,"position");
                };
            };

            move3DENCamera
            [
                ATLToASL _pos,
                true
            ];
        };
    };

    // Enable Edit Attributes button
    if (count _selectionPath == 3) exitWith
    {
        ctrlParent _ctrlTV displayCtrl IDC_ATTRIBUTESEARCH_EDITATTRIBUTES ctrlEnable true;
    };
}];

ENH_fnc_attributeSearch_editAttributes =
{
    params ["_ctrlTV", "_selectionPath"];

    if (count _selectionPath != 3) exitWith {};

    // Get ID of parent item
    _selectionPath resize 2;
    private _id = (_ctrlTV tvValue _selectionPath);
    set3DENSelected [_id];

    spawn
    {
        (uiNamespace getVariable ["ENH_AttributeSearch_Display", displayNull]) closeDisplay 1;
        waitUntil {isNull (uiNamespace getVariable ["ENH_AttributeSearch_Display", displayNull])};
        do3DENAction "OpenAttributes";

        // Wait until Edit Attributes display is present
        waitUntil {!isNull findDisplay 315};

        // Wait until Edit Attributes display is destroyed
        waitUntil {isNull findDisplay 315};

        // Create attribute search display again
        findDisplay IDD_DISPLAY3DEN createDisplay "ENH_AttributeSearch";
    };
};

_ctrlTV ctrlAddEventHandler ["TreeDblClick",
{
    call ENH_fnc_attributeSearch_editAttributes;
}];

(ctrlParent _ctrlTV displayCtrl IDC_ATTRIBUTESEARCH_EDITATTRIBUTES) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlTV = ctrlParent (_this#0) displayCtrl IDC_ATTRIBUTESEARCH_TREE;
    [_ctrlTV, tvCurSel _ctrlTV] call ENH_fnc_attributeSearch_editAttributes;
}];

[CTRL(IDC_ATTRIBUTESEARCH_SEARCH), CTRL(IDC_ATTRIBUTESEARCH_BUTTONSEARCH)] call ENH_fnc_initSearchControls;
