/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the group marker attribute. Call when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute value	

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];
_value params ["_typeValue","_colorValue","_textValue","_showGroupSize"];

private _ctrlComboType =_ctrlGroup controlsGroupCtrl 100;
private _ctrlComboColor =_ctrlGroup controlsGroupCtrl 101;
private _ctrlEdit =_ctrlGroup controlsGroupCtrl 102;
private _ctrlCheckbox = _ctrlGroup controlsGroupCtrl 103;

//Set up checkbox and edit control
_ctrlEdit ctrlSetText _textValue;
_ctrlCheckbox cbSetChecked _showGroupSize;

//Fill marker type combo
{
	if (_forEachIndex == 0) then
	{
		_ctrlComboType lbAdd localize "str_disabled";
		_ctrlComboType lbSetData [_forEachIndex,""];
		if (_typeValue isEqualTo "") then {_ctrlComboType lbSetCurSel 0};
	}
	else
	{
		private _name = getText (_x >> "name");
		private _class = configName _x;
		private _icon = getText (_x >> "icon");
		private _i = _ctrlComboType lbAdd _name;
		_ctrlComboType lbSetData [_i,_class];
		_ctrlComboType lbSetPicture [_i,_icon];
		if (_typeValue isEqualTo _class) then 
		{
			_ctrlComboType lbSetCurSel _i;
		};
	};
} forEach configProperties [configFile >> "CfgMarkers","isClass _x && getNumber (_x >> 'scope') > 0"];

//Fill marker color combo
{
    private _color = (_x >> "color") call bis_fnc_colorConfigToRGBA;
	private _class = configname _x;
    private _i = _ctrlComboColor lbAdd getText (_x >> "name");
    _ctrlComboColor lbSetData [_i,_class];
    _ctrlComboColor lbSetPicture [_i,"#(argb,8,8,3)color(1,1,1,1)"];
    _ctrlComboColor lbSetPictureColor [_i,_color];
  	_ctrlComboColor lbSetPictureColorSelected [_i,_color];
    _ctrlComboColor lbSetTooltip [_i,(_ctrlComboColor lbText _i) + "\n" + (_ctrlComboColor lbData _i)];
	if (_colorValue isEqualTo _class) then 
	{
		_ctrlComboColor lbSetCurSel _i;
	};
} foreach configproperties [configfile >> "CfgMarkerColors","isClass _x && getNumber (_x >> 'scope') > 0"];

true