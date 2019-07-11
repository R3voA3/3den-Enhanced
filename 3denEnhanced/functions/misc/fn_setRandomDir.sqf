/*
	Author: Revo, improved by dixon13

	Description:
	Sets random direction for selected 3den entities (objects,markers,triggers,Logics).

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

private _objects  = get3DENSelected "object";
private _markers  = get3DENSelected "Marker";
private _triggers = get3DENSelected "Trigger";
private _logics   = get3DENSelected "Logic";

private _entities = _objects + _markers + _triggers + _logics;

if (_entities isEqualTo []) exitWith {false};

collect3DENHistory
{
	{
		_x set3DENAttribute ["rotation", [0,0,random 360]];
		false
	} count _entities;
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true
