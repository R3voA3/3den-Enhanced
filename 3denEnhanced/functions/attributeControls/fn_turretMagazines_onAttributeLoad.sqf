/*
   Author: R3vo

   Date: 2020-10-26

   Description:
   Used by the ENH_TurretMagazines attribute control. Called when attribute is loaded.

   Parameter(s):
   0: CONTORL - Button

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];

private _magData = parseSimpleArray _value;
private _ctrlList = _ctrlGroup controlsGroupCtrl 100;
private _ctrlSlider = _ctrlGroup controlsGroupCtrl 101;

_ctrlSlider ctrlAddEventHandler ["sliderPosChanged",
{
	params ["_ctrlSlider","_value"];
	_ctrlList = (ctrlParentControlsGroup _ctrlSlider) controlsGroupCtrl 100;
	_ctrlList lbSetTextRight [lbCursel _ctrlList, str _value];
}];

_ctrlList ctrlAddEventHandler ["lbSelChanged",
{
	params ["_ctrlList","_selectedIndex"];
	_ctrlSlider = (ctrlParentControlsGroup _ctrlList) controlsGroupCtrl 101;
	_ctrlSlider sliderSetPosition parseNumber (_ctrlList lbTextRight _selectedIndex);
}];

{
	_x params ["_mag","_turretPath","_count"];
	_displayName = getText (configFile >> "CfgMagazines" >> _mag >> "displayName");
	if (_displayName == "") then {_displayName = _mag};
	_ctrlList lbAdd _displayName;
	_ctrlList lbSetTextRight [_forEachIndex,str _count];
	_ctrlList lbSetData  [_forEachIndex,str [_turretPath,_mag]];
	_ctrlList lbSetCurSel 0;
} forEach _magData;

true