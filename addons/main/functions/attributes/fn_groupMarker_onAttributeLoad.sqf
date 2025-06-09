#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the group marker attribute. Call when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
_value params ["_typeValue", "_colorValue", "_textValue", "_showGroupSize", "_showGroupVehicle"];

private _ctrlComboType =_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;
private _ctrlComboColor =_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01;
private _ctrlEdit =_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02;
private _ctrlCheckbox = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_03;
private _ctrlCheckbox2 = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_04;

// Set up checkbox and edit control
_ctrlEdit ctrlSetText _textValue;
_ctrlCheckbox cbSetChecked _showGroupSize;
_ctrlCheckbox2 cbSetChecked _showGroupVehicle;

// Fill marker type combo
{
    if (_forEachIndex == 0) then
    {
        _ctrlComboType lbAdd localize "str_disabled";
        _ctrlComboType lbSetData [_forEachIndex, ""];
        if (_typeValue isEqualTo "") then {_ctrlComboType lbSetCurSel 0};
    }
    else
    {
        private _name = getText (_x >> "name");
        private _class = configName _x;
        private _icon = getText (_x >> "icon");
        private _i = _ctrlComboType lbAdd _name;
        _ctrlComboType lbSetData [_i, _class];
        _ctrlComboType lbSetPicture [_i, _icon];
        if (_typeValue isEqualTo _class) then
        {
            _ctrlComboType lbSetCurSel _i;
        };
    };
} forEach configProperties [configFile >> "CfgMarkers", "isClass _x && getNumber (_x >> 'scope') > 0"];

// Fill marker color combo
{
     private _color = (_x >> "color") call BIS_fnc_colorConfigToRGBA;
     private _class = configName _x;
     private _i = _ctrlComboColor lbAdd getText (_x >> "name");
     _ctrlComboColor lbSetData [_i, _class];
     _ctrlComboColor lbSetPicture [_i, "#(argb,8,8,3)color(1,1,1,1)"];
     _ctrlComboColor lbSetPictureColor [_i, _color];
     _ctrlComboColor lbSetPictureColorSelected [_i, _color];
     _ctrlComboColor lbSetTooltip [_i, (_ctrlComboColor lbText _i) + "\n" + (_ctrlComboColor lbData _i)];
    if (_colorValue isEqualTo _class) then
    {
        _ctrlComboColor lbSetCurSel _i;
    };
} forEach configProperties [configFile >> "CfgMarkerColors", "isClass _x && getNumber (_x >> 'scope') > 0"];

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
