#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Retrieves loadout of unit and formats it for CfgRespawnLoadouts. Content is copied to clipboard. Meant to be used with ENH_ExportInventory GUI.

    Parameter(s):
    0: BOOLEAN - Mode (True for loadout config, false for CfgRespawnLoadout)

    Returns:
    BOOLEAN: true / false
*/

if (!is3DEN) exitWith {false};

private _object = (get3DENSelected "Object") # 0;

if (isNil "_object") exitWith
{
    ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
    false
};

params [["_mode", true]];

// From BIS_fnc_exportLoadout START
private _fnc_addArray =
{
    params ["_name", "_array"];
    _export = _export + format [INDENT + "%1[] = {", _name];
    {
        if (_x == "") then {continue};
        if (_forEachIndex > 0) then {_export = _export + ", "};
        _export = _export + format ["""%1""", _x];
    } forEach _array;
    _export = _export + "};" + endl;
};

private _class = typeOf _object;
private _uniformClass = format ["uniformClass = ""%1"";", uniform _object];
private _backpack = format ["backpack = ""%1"";", backpack _object];

private _weapons = weapons _object;
private _primWeaponItems = primaryWeaponItems _object;
private _secWeaponItems = secondaryWeaponItems _object;
private _handgunItems = handgunItems _object;
private _magsInWeapons = flatten (weaponsItems _object apply {
    private _mag = (_x param [4, [], []]) param [0, ""];
    private _tube = (_x param [5, [], []]) param [0, ""];

    [_mag, _tube]
});
private _assignedItems = assignedItems _object;
private _gear = [vest _object, headgear _object, goggles _object];
private _export = "";

["weapons", _weapons + ["Throw", "Put"]] call _fnc_addArray;
["magazines", magazines _object + _magsInWeapons] call _fnc_addArray;
["items", items _object] call _fnc_addArray;
["linkedItems", _gear + _assignedItems - _weapons + _primWeaponItems + _secWeaponItems + _handgunItems] call _fnc_addArray;

if _mode then
{// Respawn Loadout for config
    _export = "class " + _class + endl + "{" + endl + INDENT + _uniformClass + endl + INDENT + _backpack + endl + _export + "};";
}
else
{// CfgRespawnLoadout
    private _displayName = format ["displayName = ""%1"";", getText (configOf _object >> "displayName")];
    private _icon = "icon = ""\A3\Ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"";";
    private _role = "role = ""Default"";";
    private _show = "show = ""true"";";
    _export = "class " + _class + endl + "{" + endl + INDENT + _displayName + endl + INDENT + _icon + endl + INDENT + _role + endl + INDENT + _show + endl + INDENT + _uniformClass + endl + INDENT + _backpack + endl + _export;
    _export = _export + "};" + endl + "// Biki: https:// community.bistudio.com/wiki/Arma_3_Respawn#Loadouts_and_Roles";
};

["ENH_DataCopied"] call BIS_fnc_3DENNotification;
copyToClipboard _export
