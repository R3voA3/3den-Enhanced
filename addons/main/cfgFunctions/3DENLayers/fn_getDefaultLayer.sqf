#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2026-04-19

    Description:
    Returns default layer ID. Always returns first index in the ARRAY
    if multiple layers are defined (should never happen)

    Parameter(s):
    -

    Return Value:
    NUMBER - Default layer ID, -1 if not found
*/

all3DENEntities param [6, []] select {_x get3DENAttribute "ENH_DefaultLayer" select 0} param [0, -1];
