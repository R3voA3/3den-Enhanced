#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Copies loadout from selected units and applies it to all selected ones (Tools can be selected in the menu strip).

    Parameter(s):
    STRING - _this - "copy", "apply"

    Returns:
    BOOLEAN: true / false
*/

#define CHECK_MAN _x isKindOf "Man"

private _input = param [0, "", [""]];
private _units = get3DENSelected "object";

if (_units isEqualTo []) exitWith
{
    ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
    false
};

switch _input do
{
    case "copy":
    {
        ENH_CopiedLoadout_Gear = _units apply
        {
            if (CHECK_MAN) then
            {
                getUnitLoadout _x;
            };
        };
    };
    case "apply":
    {
        {
            if (CHECK_MAN) then
            {
                _x setUnitLoadout selectRandom ENH_CopiedLoadout_Gear;
            };
        } forEach _units;

        save3DENInventory _units;
    };
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true
