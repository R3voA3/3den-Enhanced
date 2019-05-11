/*
   Author: Revo

   Description:
   Copies loadout from selected units and applies it to all selected onces (Tools can be selected in the menu strip).

   Parameter(s):
   _this: STRING - action ("copy" or "apply")

   Returns:
   BOOLEAN - true when successfull, otherwise false
*/

private _input = param [0,"",[""]];
private _units = get3DENSelected "object";
if (_units isEqualTo []) exitWith {false};

switch (toUpper _input) do
{
	case "COPY":
	{
		Enh_copiedLoadout_gear = [];
		{
			if (_x isKindOf "Man") then	{Enh_copiedLoadout_gear pushBack (getUnitLoadout _x)};
			false;
		} count _units;
		["Enh_DataCopied"] call BIS_fnc_3DENNotification;
		true;
	};
	case "APPLY":
	{
		{
			if (_x isKindOf "Man") then
			{
				_x setUnitLoadout (selectRandom Enh_copiedLoadout_gear);
				save3DENInventory [_x];
			};
			false;
		} count _units;
		["Enh_actionPerformed"] call BIS_fnc_3DENNotification;
		true;
	};
	default
	{
		false;
	};
};



