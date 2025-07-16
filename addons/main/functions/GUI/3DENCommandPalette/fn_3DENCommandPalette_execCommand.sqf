#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-07-13

    Description:
    Executes a command from 3DEN command palette.

    Parameter(s):
    0: CONTROL - Action button

    Return Value:
    NOTHING
*/

params [["_ctrlFakeButton", controlNull]];

if (isNull _ctrlFakeButton) exitWith {nil};

// Get action saved in button and call it
private _action = _ctrlFakeButton getVariable ["Action", ""];
private _copyToClipboard = _ctrlFakeButton getVariable ["CopyToClipboard", false];

if (_action == "") exitWith {nil};

ctrlParent _ctrlFakeButton closeDisplay 1;

// Exec command after one frame. Some actions need the Command Palette to be closed first
addMissionEventHandler ["EachFrame",
{
    _thisArgs params ["_frameNo", "_action", "_copyToClipboard"];

    if (diag_frameNo >= (_frameNo + 1)) then
    {
        // Update priority map for sorting popular commands
        private _actionHash = hashValue _action;
        private _priorityMap = profileNamespace getVariable ["ENH_3DENCommandPalette_PriorityMap", createHashMap];
        private _priority = _priorityMap getOrDefault [_actionHash, 0];

        // Priority is higher the lower the value. This is because we sort it alongside alphabetical order which is ascending
        _priorityMap set [_actionHash, _priority - 1];

        profileNamespace setVariable ["ENH_3DENCommandPalette_PriorityMap", _priorityMap];

        removeMissionEventHandler [_thisEvent, _thisEventHandler];

        if (_copyToClipboard) then
        {
            ["ENH_DataCopied"] call BIS_fnc_3DENNotification;
            copyToClipboard _action;
        }
        else
        {
            [findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_MENUSTRIP] call compile _action;
        };

    };
}, [diag_frameNo, _action, _copyToClipboard]];

nil
