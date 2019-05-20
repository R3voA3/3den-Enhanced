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
if (count (get3DENSelected "Object") == 0) exitWith {false};

#define STATE (_x get3DENAttribute "objectIsSimple")

collect3DENHistory
{
	{
		if (STATE isEqualTo [false]) then
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