/*
	Author: Revo, improved by dixon13

	Description:
	Sets the orientation of all selected objects.

	Parameter(s):
	NUMBER: -1: random
			-2: reverse
			>-1: Direction in degrees

	Returns:
	BOOLEAN: true / false
*/

if (!is3DEN) exitWith {false};

private _input = param [0,0,[0]];
private _entities = [["Object","Logic","Trigger","Marker"]] call ENH_fnc_all3denSelected;

if (_entities isEqualTo []) exitWith
{
	["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
	false
};
collect3DENHistory
{
	switch _input do
	{
		case -2://reverse
		{
			{
				private _dir = (_x get3DENAttribute "Rotation") # 0;
				_dir set [2,(_dir # 2) + 180];
				_x set3DENAttribute ["rotation",_dir];
			} forEach _entities;
		};
		case -1://randomise
		{
			{
				private _dir = random 360;
				_x set3DENAttribute ["rotation", [0,0,_dir]];
			} forEach _entities;
		};
		default
		{
			{
				_x set3DENAttribute ["rotation", [0,0,_input]];
			} forEach _entities;
		};
	};
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true