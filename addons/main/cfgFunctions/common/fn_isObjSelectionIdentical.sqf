#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2026-05-07

    Description:
    Checks if currently selected objects are all of the same class.

    Parameter(s):
    NOTHING

    Return Value:
    BOOLEAN - True if identical, false if not
*/

private _objs = get3DENSelected "Object" apply {typeOf _x};

_objs - [_objs#0] isEqualTo [];
