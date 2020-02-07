/*
	Author: Revo

	Description:
	Replaces all selected Eden entities with empty ones.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

private _toReplace = get3DENSelected "Object";

{
	delete3DENEntities crew _x;
} forEach _toReplace;


["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true