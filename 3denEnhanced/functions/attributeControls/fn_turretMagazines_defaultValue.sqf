/*
   Author: R3vo

   Date: 2020-10-26

   Description:
   Sets the default value for the turret magazines attribute.

   Parameter(s):
   0: OBJECT

   Returns:
   STRING: "[[mag1,2],[mag2,3]]"
*/

params ["_vehicle"];

diag_log _vehicle;
private _mags = magazinesAllTurrets _vehicle;
private _value = [];

{
	_x params ['_magClass','_turretPath'];
	_value pushBackUnique [_magClass,_turretPath,count (_mags select {_x select 0 == _magClass})];
} forEach _mags;

str _value