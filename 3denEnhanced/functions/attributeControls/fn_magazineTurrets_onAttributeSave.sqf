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