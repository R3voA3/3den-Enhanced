/*
	Author: Revo

	Description:
	Initialises the 3den Enhanced session timer. Needs to be spawned!

	Parameter(s):
	-
	Returns:
	BOOLEAN - true
*/

private _display3DEN = (findDisplay 313) displayCtrl 668;

while {is3DEN} do
{
	_display3DEN ctrlSetText ([diag_tickTime / 3600] call BIS_fnc_timeToString);
	uiSleep 1;
};

true