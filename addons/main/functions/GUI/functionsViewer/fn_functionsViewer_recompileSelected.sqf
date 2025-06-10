#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Used by the ENH_FunctionViewer GUI.

    Parameter(s):
    -

    Returns:
    -
*/

private _fncName = ctrlText ((uiNamespace getVariable ["ENH_Display_FunctionsViewer", displayNull]) displayCtrl IDC_FUNCTIONSVIEWER_NAME);

// Function was not found anywhere. It's a script file then
if (isNil {uiNamespace getVariable _fncName} && isNil {missionNamespace getVariable _fncName}) exitWith {};

_fncName call BIS_fnc_recompile;

playSound "3DEN_notificationDefault";
