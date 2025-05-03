#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-02

    Description:
    This is a queue system for ENH_fnc_3DENNotificationQueue.

    Parameter(s):
    0: ARRAY - Some description, optional, default false

    Return Value:
    ARRAY - True on success, false if failed

    Examples(s):
    [] call ENH_fnc_missionDisplay;
*/

private _class = param [0,"",[0,""]];
private _type = param [1,0,[0,false]];
private _duration = param [2,-1,[0]];
private _animate = param [3,true,[true]];
private _volume = param [4,1,[0]];

// Start new queue of none exists
if (isNil "ENH_3DENNotification_Queue") then
{
    ENH_3DENNotification_Queue = [];

    addMissionEventHandler ["EachFrame",
    {
        if (ENH_3DENNotification_Queue isEqualTo []) exitWith {};
        if (isNil "BIS_fnc_3DENNotification_spawn" || {isNull BIS_fnc_3DENNotification_spawn}) then
        {
            ENH_3DENNotification_Queue#0 call BIS_fnc_3DENNotification;
            ENH_3DENNotification_Queue deleteAt 0;
        };
    }];
};

ENH_3DENNotification_Queue pushBack [_class, _type, _duration, _animate, _volume];

true
