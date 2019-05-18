/*
   Author: Revo

   Description:
   Copies loadout from selected units and applies it to all selected ones (Tools can be selected in the menu strip).

   Parameter(s):
   _this: STRING - action ("copy" or "apply")

   Returns:
   BOOLEAN - true when successfull, otherwise false
*/

private _input = param [0,"",[""]];
private _units = get3DENSelected "object";
if (_units isEqualTo []) exitWith {false};

switch (_input) do
{
	case "copy":
	{
		Enh_CopiedLoadout_Gear = [];
		{
			if (_x isKindOf "Man") then	{Enh_CopiedLoadout_Gear pushBack (getUnitLoadout _x)};
		} forEach _units;

		["Enh_DataCopied"] call BIS_fnc_3DENNotification;
		true;
	};
	case "apply":
	{
		{
			if (_x isKindOf "Man") then
			{
				_x setUnitLoadout selectRandom Enh_CopiedLoadout_Gear;
			};
		} forEach _units;

		save3DENInventory _units;
		["Enh_actionPerformed"] call BIS_fnc_3DENNotification;
		true;
	};
};



