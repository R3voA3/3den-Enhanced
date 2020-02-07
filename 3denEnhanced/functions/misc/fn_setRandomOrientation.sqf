/*
	Author: Revo, improved by dixon13

	Description:
	Sets random direction for selected 3den entities.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

if (!is3DEN) exitWith {false};

private _entities = [["Object","Logic","Trigger","Marker"]] call ENH_fnc_all3denSelected;

if (_entities isEqualTo []) exitWith
{
	["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
	false
};
collect3DENHistory
{
	{
		_x set3DENAttribute ["rotation", [0,0,random 360]];
		false
	} count _entities;
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true
