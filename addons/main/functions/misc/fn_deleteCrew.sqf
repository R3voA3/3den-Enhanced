#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Replaces all selected Eden entities with empty ones.

    Parameter(s):
    -

    Returns:
    -
*/

private _toReplace = get3DENSelected "Object";

{
    delete3DENEntities crew _x;
} forEach _toReplace;

["ENH_actionPerformed"] call ENH_fnc_3DENNotificationQueue;
