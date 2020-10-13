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

/* if (_value isEqualTo "[]") then // Only get default magazines if value is empty, else just use value
{
	_mags = magazinesAllTurrets (get3DENSelected "Object" select 0);
	{
		_x params ["_magClass","_turretPath"];
		_value pushBackUnique
		[
			_magClass,
			_turretPath,
			count (_mags select {_x # 0 == _magClass})
		];
	} forEach _mags;
}; */

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