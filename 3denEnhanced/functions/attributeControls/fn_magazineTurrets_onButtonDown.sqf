params ["_ctrlButton"];

private _ctrlList = (ctrlParentControlsGroup _ctrlButton) controlsGroupCtrl 100;
private _value = [];

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

lbClear _ctrlList;

{
	_x params ["_mag","_turretPath","_count"];
	_displayName = getText(configFile >> "CfgMagazines" >> _mag >> "displayName");
	if (_displayName == "") then {_displayName = _mag};
	_ctrlList lbAdd _displayName;
	_ctrlList lbSetTextRight [_forEachIndex,str _count];
	_ctrlList lbSetData  [_forEachIndex,str [_turretPath,_mag]];
	_ctrlList lbSetCurSel 0;
} forEach _value;

true