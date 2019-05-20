/*
	Author: Revo, improved by dixon13

	Description:
	Sets the orientation of all selected objects.

	Parameter(s):
	NUMBER: Direction in degrees

	Returns:
	BOOLEAN: true / false
*/

private _input = param [0,0,[0]];

private _objects  = get3DENSelected "object";
private _markers  = get3DENSelected "Marker";
private _waypoints = get3DENSelected "Waypoint";
private _triggers = get3DENSelected "Trigger";
private _logics   = get3DENSelected "Logic";

private _entities = _objects + _markers + _triggers + _logics + _waypoints;

if (count _entities == 0) exitWith {false};

collect3DENHistory
{
	{
		_x set3DENAttribute ["rotation", [0,0,_input]];
		false;
	} count _entities;
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true
