#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2026-04-19

    Description:
    Moves entity into set default layer.

    Parameter(s):
    0: OBJECT - Eden entity

    Return Value:
    NOTHING
*/

params ["_entity"];

private _defaultLayer = call ENH_fnc_getDefaultLayer;

if (_defaultLayer != -1) then
{
    _entity set3DENLayer _defaultLayer;
};

nil
