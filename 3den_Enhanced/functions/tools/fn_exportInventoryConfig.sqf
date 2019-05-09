/*
	Author: Revo

	Description:
	Retrieves loadout of unit and formats it for CfgRespawnLoadouts. Content is copied to clipboard. Meant to be used with Enh_ExportInventory GUI.

	Parameter(s):
	-

	Returns:
	BOOLEAN - True/False
*/

private _object = (get3DENSelected "Object") # 0;

if (!is3DEN || isNil "_object") exitWith {false};

#define CTRL_TEXT(IDC) ctrlText (_disp displayCtrl IDC)
#define LB endl
#define IND "    "

disableSerialization;
private _disp = findDisplay 170000;
private _class = CTRL_TEXT(1400);
private _displayName = format ["displayName = ""%1"";",CTRL_TEXT(1401)];
private _icon = format ["icon = ""%1"";",CTRL_TEXT(1402)];
private _role = format ["role = ""%1"";",CTRL_TEXT(1403)];
private _show = format ["show = ""%1"";",CTRL_TEXT(1404)];
private _uniformClass = format ["uniformClass = ""%1"";",uniform _object];
private _backpack = format ["backpack = ""%1"";",backpack _object];
private _weapons = weapons _object;
private _primWeaponItems = primaryWeaponItems _object;
private _secWeaponItems = secondaryWeaponItems _object;
private _assignedItems = assigneditems _object;

private _export = "class " + _class + LB + "{" + LB + IND + _displayName + LB + IND + _icon + LB + IND + _role + LB + IND + _show + LB + IND + _uniformClass + LB + IND + _backpack + LB;

//From BIS_fnc_exportLoadout START
private _fnc_addArray =
{
	params ["_name","_array"];
	_export = _export + format [IND + "%1[] = {",_name];
	{
		if (_foreachindex > 0) then {_export = _export + ",";};
		_export = _export + format ["""%1""",_x];
	} foreach _array;
	_export = _export + "};" + LB;
};

["weapons",_weapons + ["Throw","Put"]] call _fnc_addArray;
["magazines",magazines _object] call _fnc_addArray;
["items",items _object] call _fnc_addArray;
["linkedItems",[vest _object,headgear _object,goggles _object] + _assignedItems - _weapons + _primWeaponItems + _secWeaponItems] call _fnc_addArray;
//From BIS_fnc_exportLoadout END
_export = _export + "};" + LB + "//Visit https://community.bistudio.com/wiki/Arma_3_Respawn for detailed information" + LB + "//Add loadout: " + format ["[missionNamespace,""%1""] call BIS_fnc_addRespawnInventory;",_class];

["Enh_DataCopied"] call BIS_fnc_3DENNotification;
copyToClipboard _export;

_disp closeDisplay 1;

true