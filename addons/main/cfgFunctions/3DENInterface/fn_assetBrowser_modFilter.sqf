#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-07-13

    Description:
    Fills the mod filter list in the Asset Browser. Compared to vanilla it omits addons without units or weapons.

    Parameter(s):
    0: CONTROL - The filter control

    Return Value:
    NOTHING
*/

params [["_ctrlMods", controlNull]];

private _mods = [];

lbClear _ctrlMods;

private _condition = "isClass _x && {getArray (_x >> 'units') isNotEqualTo []}";

{
    _mods pushBackUnique (configSourceMod _x)
} forEach configProperties [configFile >> "CfgPatches", _condition];

{
    private _params = if (_x == "") then {[]} else
    {
        modParams [_x, ["name", "logoSmall"]]
    };

    if (_params isNotEqualTo []) then
    {
        _params params ["_name", "_logoSmall"];

        private _row = _ctrlMods lbAdd _name;

        _ctrlMods lbSetData [_row, _x];
        _ctrlMods lbSetPictureRight [_row, _logoSmall];
        _ctrlMods lbSetTooltip [_row, _name + "\n" + _x];
    };
} forEach _mods;

lbSort _ctrlMods;

nil
