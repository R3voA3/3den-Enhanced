/*
   Author: Revo

   Description:
   Copies loadout from selected units and applies it to all selected ones (Tools can be selected in the menu strip).

   Parameter(s):
   STRING - _this - "copy", "apply"

   Returns:
   BOOLEAN: true / false
*/

#define CHECK_MAN _x isKindOf "Man"

private _input = param [0,"",[""]];
private _units = get3DENSelected "object";

if (_units isEqualTo []) exitWith 
{
	["Enh_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
	false
};

switch (_input) do
{
	case "copy":
	{
		Enh_CopiedLoadout_Gear = _units apply
		{
			if (CHECK_MAN) then
			{
				getUnitLoadout _x;
			};
		};
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
	};
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true