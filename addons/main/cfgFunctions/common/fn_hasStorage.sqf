#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-09-07

    Description:
    Checks if given object has an inventory (ammobox, vehicle).

    Parameter(s):
    0: OBJECT - Object

    Returns:
    BOOLEAN: true if it has storage, false if not
*/

params ["_object"];

getNumber (configOf _object >> "maximumLoad") > 0
