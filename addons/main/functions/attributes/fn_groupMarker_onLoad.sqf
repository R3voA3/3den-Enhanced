#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-06-07

    Description:
    Is called when the group marker attribute is loaded. Properly inits all controls when multiple groups are edited.
    Needs to be spawned to make sure all controls are loaded.

    Parameter(s):
    0: CONTROL - Any attribute control

    Returns:
    -
*/

// Exit if only one group is selected
if (count (get3DENSelected "Group") == 1) exitWith {};

params ["_ctrl"];
private _ctrlGroup = ctrlParentControlsGroup _ctrl;
private _ctrlComboType =_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;
private _ctrlComboColor =_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01;

// Get all markers and sort them
private _markers = ("getNumber (_x >> 'scope') > 0" configClasses (configFile >> "CfgMarkers")) apply
{
    [getText (_x >> "name"), configName _x, getText (_x >> "icon"), getArray (_x >> "color")]
};

_markers = [_markers, [], {_x select 1}, "ASCEND"] call BIS_fnc_sortBy;
_markers insert [0, [[localize "STR_DISABLED", "", "", [1, 1, 1, 1]]]];

{
    _x params ["_name", "_class", "_icon", "_color"];

    // Adjust colors
    if (count _color == 4) then {_color = _color call BIS_fnc_parseNumberSafe} else {_color = [1, 1, 1, 1]};
    if (_color isEqualTo [0, 0, 0, 1]) then {_color = [1, 1, 1, 1]};

    private _i = _ctrlComboType lbAdd _name;
    _ctrlComboType lbSetData [_i, _class];
    _ctrlComboType lbSetPicture [_i, _icon];
    _ctrlComboType lbSetTooltip [_i, _class];
    _ctrlComboType lbSetPictureColor [_i, _color];
} forEach _markers;

// Fill marker color combo
{
    private _color = (_x >> "color") call bis_fnc_colorConfigToRGBA;
    private _class = configName _x;
    private _i = _ctrlComboColor lbAdd getText (_x >> "name");
    _ctrlComboColor lbSetData [_i, _class];
    _ctrlComboColor lbSetPicture [_i, "#(argb,8,8,3)color(1,1,1,1)"];
    _ctrlComboColor lbSetPictureColor [_i, _color];
    _ctrlComboColor lbSetPictureColorSelected [_i, _color];
    _ctrlComboColor lbSetTooltip [_i, _ctrlComboColor lbData _i];
} forEach ("getNumber (_x >> 'scope') > 0" configClasses (configFile >> "CfgMarkerColors"));

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_BUTTON_RESET) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) lbSetCurSel 0;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) lbSetCurSel 0;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) ctrlSetText "";
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03) cbSetChecked true;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04) cbSetChecked true;
}];
