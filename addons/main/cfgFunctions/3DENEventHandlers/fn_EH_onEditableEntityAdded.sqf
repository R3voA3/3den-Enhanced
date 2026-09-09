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

// When a new mission is loaded all entities
// are placed by the engine, triggering this event
// We only want it to trigger on manual placement
if (time == 0) exitWith {};

params ["_entity"];

[_entity] call ENH_fnc_moveIntoDefaultLayer;
