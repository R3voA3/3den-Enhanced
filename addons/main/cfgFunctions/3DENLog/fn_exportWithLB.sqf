#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Modifies an array to be outputted with linebreaks for easier legibility.
    ["test", "test", "test"]

    ["test",
    "test",
    "test"]

    Parameter(s):
    0: ARRAY - Array which should be modified
    1: BOOLEAN: (Optional, default true) - Put output into brackets

    Returns:
    STRING - Modified array as string
*/

private _array = param [0, [], [[]]];
private _addBrackets = param [1, true, [true]];

private _export = "";
{
    if (_forEachIndex < count _array - 1) then
    {
        _export = _export + str _x + ", " + endl;
    }
    else
    {
        _export = _export + str _x;
    };
} forEach _array;

if _addBrackets then {_export = "[" + _export + "]"};

_export
