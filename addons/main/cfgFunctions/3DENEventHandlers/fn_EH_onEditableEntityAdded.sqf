#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-06-05

    Description:
    Is called by Eden event handler onEditableEntityAdded.

    Parameter(s):
    OBJECT: Entity that was added

    Returns:
    -
*/

params ["_entity"];

[_entity] call ENH_fnc_moveIntoDefaultLayer;
