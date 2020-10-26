/*
   Author: R3vo

   Date: 2020-10-26

   Description:
   Used by the ENH_TurretMagazines attribute control. Called when attribute is saved.

   Parameter(s):
   0: CONTORL - Button

   Returns:
   STRING: "[[mag1,2],[mag2,3]]"
*/

params ["_ctrlGroup"];

private _ctrlList = _ctrlGroup controlsGroupCtrl 100;
private _value = [];

for "_i" from 0 to (lbSize _ctrlList - 1) do
{
	(call compile (_ctrlList lbData _i)) params ["_turretPath","_magClass"];
	private _count = parseNumber (_ctrlList lbTextRight _i);
	_value pushBack [_magClass,_turretPath,_count];
};

str _value