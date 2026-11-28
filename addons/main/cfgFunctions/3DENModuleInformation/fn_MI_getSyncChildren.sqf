#include "\x\enh\addons\main\script_component.hpp"

/*
    Description:
    Gets a module's synchronization children from its module description
    config when available, falling back to the module config itself.

    Parameter(s):
    0: CONFIG - Module config

    Returns:
    ARRAY - Synchronization child class names
*/

params ["_parentConfig"];

private _cfgModuleDescription = _parentConfig >> "ModuleDescription";

if (isClass _cfgModuleDescription) exitWith
{
    getArray (_cfgModuleDescription >> "sync")
};

getArray (_parentConfig >> "sync")
