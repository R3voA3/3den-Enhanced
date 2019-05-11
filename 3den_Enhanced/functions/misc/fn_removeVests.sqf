/*
	Author: Revo

	Description:
	Removes vests from selected units and saves their inventory.

	Parameter(s):
	-
	Returns:
	BOOLEAN - true / false
*/

private _units = get3DENSelected "Object";

if (_units isEqualTo [] || !is3DEN) exitWith {false};

collect3DENHistory
{
	{
		removeVest _x;
	} forEach _units;
	save3DENInventory _units;
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true