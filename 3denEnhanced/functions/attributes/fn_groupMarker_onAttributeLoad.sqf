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
_value params ["_typeValue", "_colorValue", "_textValue", "_showGroupSize"];

private _ctrlComboType =_ctrlGroup controlsGroupCtrl 100;
private _ctrlComboColor =_ctrlGroup controlsGroupCtrl 101;
private _ctrlEdit =_ctrlGroup controlsGroupCtrl 102;
private _ctrlCheckbox = _ctrlGroup controlsGroupCtrl 103;

//Set up checkbox and edit control
_ctrlEdit ctrlSetText _textValue;
_ctrlCheckbox cbSetChecked _showGroupSize;

//Get all markers and sort them
private _markers = ("getNumber (_x >> 'scope') > 0" configClasses (configFile >> "CfgMarkers")) apply
{
  [getText (_x >> "name"), configName _x, getText (_x >> "icon"), getArray (_x >> "color")]
};

_markers = [_markers, [], {_x select 1}, "ASCEND"] call BIS_fnc_sortBy;
_markers insert [0, [[localize "STR_DISABLED", "", "", [1, 1, 1, 1]]]];

{
  _x params ["_name", "_class", "_icon", "_color"];

  //Adjust colors
  if (count _color == 4) then {_color = _color call BIS_fnc_parseNumberSafe} else {_color = [1, 1, 1, 1]};
  if (_color isEqualTo [0, 0, 0, 1]) then {_color = [1, 1, 1, 1]};

  private _i = _ctrlComboType lbAdd _name;
  _ctrlComboType lbSetData [_i, _class];
  _ctrlComboType lbSetPicture [_i, _icon];
  _ctrlComboType lbSetTooltip [_i, _class];
  _ctrlComboType lbSetPictureColor [_i, _color];
  if (_class == _typeValue) then {_ctrlComboType lbSetCurSel _i};
} forEach _markers;

//Fill marker color combo
{
  private _color = (_x >> "color") call bis_fnc_colorConfigToRGBA;
  private _class = configname _x;
  private _i = _ctrlComboColor lbAdd getText (_x >> "name");
  _ctrlComboColor lbSetData [_i, _class];
  _ctrlComboColor lbSetPicture [_i, "#(argb,8,8,3)color(1,1,1,1)"];
  _ctrlComboColor lbSetPictureColor [_i, _color];
  _ctrlComboColor lbSetPictureColorSelected [_i, _color];
  _ctrlComboColor lbSetTooltip [_i, _ctrlComboColor lbData _i];
  if (_colorValue isEqualTo _class) then
  {
    _ctrlComboColor lbSetCurSel _i;
  };
} foreach configproperties [configfile >> "CfgMarkerColors", "isClass _x && getNumber (_x >> 'scope') > 0"];

//Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["buttonClick",
{
  private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

  //Setting default values, colour and group ID cannot be retrieved from here so they are ignored
  (_ctrlGroup controlsGroupCtrl 100) lbSetCurSel 0;
  (_ctrlGroup controlsGroupCtrl 101) lbSetCurSel 0;
  (_ctrlGroup controlsGroupCtrl 103) cbSetChecked true;
}];