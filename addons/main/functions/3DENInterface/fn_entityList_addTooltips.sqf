#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2023-02-02

    Description:
    Loops through the asset browser and adds the item text as tooltip
    to prevent long texts from being cut off. Function is recursive.

    Parameter(s):
    ARRAY: Path of current tree view item

    Returns:
    -
*/

params [["_path", []]];

if !(_path isEqualType []) then {_path = []};

private _ctrlTV = findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_EDIT;

for "_i" from 0 to (_ctrlTV tvCount _path) - 1 do
{
    private _currentPath = _path + [_i];
    _ctrlTV tvSetTooltip [_currentPath, _ctrlTV tvText _currentPath];
    [_currentPath] call ENH_fnc_entityList_addTooltips;
};
