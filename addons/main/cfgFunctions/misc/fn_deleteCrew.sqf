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
    private _entity = _x;
    private _attributes = _entity get3DENAttributes "";
    private _classIdx = _attributes apply {_x#0} find "ItemClass";
    if (_classIdx == -1) exitWith {};

    private _class = _attributes # _classIdx # 1;
    
    delete3DENEntities [_entity];

    private _newEntity = create3DENEntity ["Object", _class, [0,0,0], true];
    {
        _newEntity set3DENAttribute _x;
    } forEach _attributes;
} forEach _toReplace;

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
