/*
	Author: Revo

	Description:
	Replaces all selected objects with the types of objects defined in the GUI "Enh_BatchReplace".

	Parameter(s):
	-

	Returns:
	BOOLEAN:  true / false
*/

private ["_replaceWith","_class","_replaceWithArray","_objects"];
disableSerialization;//Because of BIS_fnc_3DENNotification

private _objects = (get3DENSelected "Object");
if(_objects isEqualTo [] || !is3DEN) exitWith {false};

private _replaceWith = ctrlText ((findDisplay 150000) displayCtrl 1400); //"sfd,2ffds,5,123"
profileNameSpace setVariable ['Enh_batchReplace_lastUsed',_replaceWith];

private _replaceWithArray = _replaceWith splitString ",";//Separates string by comma and values into an array //["sfd","2ffds","5","123"]

collect3DENHistory
{
	{
		private _class = selectRandom _replaceWithArray;
		if (isClass (ConfigFile >> "CfgVehicles" >> _class)) then
		{
			[_x] set3DENObjectType _class;
		}
		else
		{
			[format ["%1 (%2)",localize "STR_ENH_functions_batchReplace_error",_class]] call BIS_fnc_3DENNotification;
		};
	} forEach _objects;
};

true