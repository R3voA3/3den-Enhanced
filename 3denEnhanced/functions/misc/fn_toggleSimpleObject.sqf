/*
	Author: Revo

	Description:
	Toggles simple object state of selected objects in Eden.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

if !(is3DEN) exitWith {false};

if (get3DENSelected "Object" isEqualTo []) exitWith
{
	["Enh_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
	false
};

#define ATTRIBUTE (_x get3DENAttribute "objectIsSimple")

collect3DENHistory
{
	{
		if (ATTRIBUTE isEqualTo [false]) then
		{
		 	_x set3DENAttribute ["objectIsSimple",true];
		}
		else
		{
			_x set3DENAttribute ["objectIsSimple",false];
		};
	} forEach get3DENSelected "Object";
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true