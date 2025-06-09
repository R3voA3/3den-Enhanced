#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-06-23

    Description:
    Exports vehicle loadout.

    Parameter(s):
    0: STRING - Mode, can be: ace, sqf, arsenal

    Returns:
    -
*/

params [["_mode", "sqf"]];

private _data = parseSimpleArray ([true] call ENH_fnc_ESE_applyAttribute);

_data params ["_equipment"];
_equipment params ["_weapons", "_magazines", "_items", "_backpacks"];

private _export = "if !(local this) exitWith {};" + endl + endl;

switch _mode do
{
    case "sqf":
    {
        _export = _export + "clearWeaponCargoGlobal this;" + endl +
        "clearMagazineCargoGlobal this;" + endl +
        "clearItemCargoGlobal this;" + endl + "clearBackpackCargoGlobal this;" + endl + endl;

        {
            _x params ["_classesAndCounts", "_command"];
            _classesAndCounts params ["_classes", "_counts"];
            if (_classesAndCounts isEqualTo [[], []]) then {continue};
            private _classesAndCountsTemp = [];
            {
                _classesAndCountsTemp pushBack [_x, _counts # _forEachIndex];
            } forEach _classes;
            _export = _export + "{" + endl + "  " + "this " + _command + " _x;" + endl + "} " + "forEach " + str _classesAndCountsTemp + ";" + endl + endl;
        } forEach [[_weapons, "addWeaponCargoGlobal"], [_magazines, "addMagazineCargoGlobal"], [_items, "addItemCargoGlobal"], [_backpacks, "addBackpackCargoGlobal"]];
    };
    case "ace":
    {
        _export = str (_weapons # 0 + _magazines # 0 + _items # 0 + _backpacks # 0);
    };
    case "arsenal":
    {
        { // Add all classes. _forEachIndex defines what items are going to be added, see BIS_fnc_addVirtualItemCargo
            _x params ["_classes"];
            if (_classes isEqualTo []) then {continue};
            _export = _export + "[this, " + str _classes + ", true, true, 1, " + str _forEachIndex + "] call BIS_fnc_addVirtualItemCargo;" + endl + endl;
        } forEach [_items, _weapons, _magazines, _backpacks];
    };
};

_export = _export regexReplace ["(,)([^ ])", "$1 $2"];
_export = trim _export;

uiNamespace setVariable ["display3DENCopy_data", ["", _export]];
(uiNamespace getVariable ["ENH_Display_ESE", displayNull]) createDisplay "display3denCopy";

nil
