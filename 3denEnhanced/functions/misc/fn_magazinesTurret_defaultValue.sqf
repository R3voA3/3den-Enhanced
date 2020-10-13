params ["_vehicle"];

diag_log _vehicle;
private _mags = magazinesAllTurrets _vehicle;
private _value = [];

{
	_x params ['_magClass','_turretPath'];
	_value pushBackUnique [_magClass,_turretPath,count (_mags select {_x select 0 == _magClass})];
} forEach _mags;

str _value