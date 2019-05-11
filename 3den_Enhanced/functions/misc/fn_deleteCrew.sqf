/*
	Author: Revo

	Description:
	Replaces all selected Eden entities with empty ones.

	Parameter(s):
	-

	Returns:
	BOOLEAN - true
*/

private _toReplace = get3DENSelected "Object";

collect3DENHistory//Doesn't collect history
{
	{

		delete3DENEntities (crew _x);
		false;
	} count _toReplace;
};


["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true