#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo, improved by dixon13

    Description:
    Sets the orientation of all selected objects. Checks if rotation attribute has 1 dimension or 3.

    Parameter(s):
    NUMBER: -1: random
            -2: reverse
           >-1: Direction in degrees

    Returns:
    -
*/

if (!is3DEN) exitWith {};

params [["_mode", 0, [0]]];

private _entities = flatten (get3DENSelected "Marker" + get3DENSelected "Trigger" + get3DENSelected "Object" + get3DENSelected "Logic");

[localize "STR_ENH_MAIN_FOLDER_ORIENT", nil, "a3\ui_f\data\gui\rsc\rscdisplayarsenal\compass_ca.paa"] collect3DENHistory
{
    switch _mode do
    {
        case -2:
        {
            {
                private _rotation = (_x get3DENAttribute "rotation") # 0;
                if (_rotation isEqualType []) then
                {
                    _rotation set [2, (_rotation # 2) + 180];
                    _x set3DENAttribute ["rotation", _rotation];
                }
                else
                {
                    _x set3DENAttribute ["rotation", _rotation + 180];
                };
            } forEach _entities;
        };
        case -1:
        {
            {
                private _rotation = (_x get3DENAttribute "rotation") # 0;
                if (_rotation isEqualType []) then
                {
                    _rotation set [2, random 360];
                    _x set3DENAttribute ["rotation", _rotation];
                }
                else
                {
                    _x set3DENAttribute ["rotation", random 360];
                };
            } forEach _entities;
        };
        default
        {
            {
                private _rotation = (_x get3DENAttribute "rotation") # 0;
                if (_rotation isEqualType []) then
                {
                    _rotation set [2, _mode];
                    _x set3DENAttribute ["rotation", _rotation];
                }
                else
                {
                    _x set3DENAttribute ["rotation", _mode];
                };
            } forEach _entities;
        };
    };
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
