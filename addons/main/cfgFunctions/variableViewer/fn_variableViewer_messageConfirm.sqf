#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-02-11

    Description:
    Used by the ENH_VariableViewer GUI. Shows a message which the user needs to confirm or deny.

    Parameter(s):
    0: DISPLAY - ENH_VariableViewer GUI

    Returns:
    BOOLEAN: true
*/

params ["_display"];

[
    localize "STR_ENH_MAIN_VARIABLEVIEWER_CONFIRM_MSG",
    localize "STR_ENH_MAIN_VARIABLEVIEWER_CONFIRM_MSG_HEADER",
    [
        localize "STR_ENH_MAIN_YES",
        {ENH_VariableViewer_Modify_Confirmed = true}
    ],
    [
        localize "STR_ENH_MAIN_NO",
        {ENH_VariableViewer_Modify_Confirmed = false}
    ],
    "\A3\ui_f\data\map\markers\handdrawn\warning_CA.paa",
    _display
] call BIS_fnc_3DENShowMessage;

true
