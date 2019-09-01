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

private _entities = [["Object","Logic","Trigger","Marker"]] call Enh_fnc_all3denSelected;

if (_entities isEqualTo []) exitWith
{
	["Enh_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
	false
};
systemChat format ["Entities: %1",_entities];
collect3DENHistory
{
	{
		_x set3DENAttribute ["rotation", [0,0,random 360]];
		false
	} count _entities;
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true
