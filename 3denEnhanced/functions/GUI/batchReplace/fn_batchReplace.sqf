/*
	Author: Revo

	Description:
	Replaces all selected objects with the types of objects defined in the GUI "ENH_BatchReplace".

	Parameter(s):
	-

	Returns:
	BOOLEAN:  true / false
*/

disableSerialization;//Because of BIS_fnc_3DENNotification

private _objects = [["Object"]] call ENH_fnc_all3DENSelected;
private _replaceWith = ctrlText (findDisplay 150000 displayCtrl 1400); //"sfd,2ffds,5,123"

profileNameSpace setVariable ['ENH_batchReplace_lastUsed',_replaceWith];

private _replaceWithArray = _replaceWith splitString ",";//Separates string by comma and values into an array //["sfd","2ffds","5","123"]

collect3DENHistory
{
	{
		private _class = selectRandom _replaceWithArray;
		if (isClass (configFile >> "CfgVehicles" >> _class)) then
		{
			[_x] set3DENObjectType _class;
		}
		else
		{
			[format ["%1 (%2)",localize "STR_ENH_FUNCTIONS_BATCHREPLACE_ERROR",_class],1] call BIS_fnc_3DENNotification;
		};
	} forEach _objects;
};

true