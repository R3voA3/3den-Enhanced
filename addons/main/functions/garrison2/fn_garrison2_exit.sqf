#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-01

    Description:
    Exits garrison mode.

    Parameter(s):
    0: NUMBER - Exit code
        0: Normal exit mode
        1: Exit due to switching to 2D view
        2: Exit due to no entities being selected

    Return Value:
    BOOLEAN - True
*/

params [["_exitCode", 0]];

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

_display3DEN displayRemoveEventHandler
[
    "MouseButtonUp",
    _display3DEN getVariable ["ENH_MouseButtonUpID", -1]
];

remove3DENEventHandler
[
    "OnEntityDragged",
    _display3DEN getVariable ["ENH_OnEntityDraggedID", -1]
];

remove3DENEventHandler
[
    "OnBeforeMissionPreview",
    _display3DEN getVariable ["ENH_OnBeforeMissionPreviewID", -1]
];

_display3DEN setVariable ["ENH_MouseButtonUpID", nil];
_display3DEN setVariable ["ENH_OnEntityDraggedID", nil];
_display3DEN setVariable ["ENH_EachFrameID", nil];
_display3DEN setVariable ["ENH_Draw3DID", nil];
_display3DEN setVariable ["ENH_OnBeforeMissionPreviewID", nil];

_display3DEN setVariable ["ENH_CurrentBuilding", nil];
_display3DEN setVariable ["ENH_CursorInBuilding", nil];

switch (_exitCode) do
{
    case 0:
    {
        ["ENH_Garrison2_Disabled"] call BIS_fnc_3DENNotification;
    };
    case 1:
    {
        ["ENH_Garrison2_2D_Not_Supported"] call BIS_fnc_3DENNotification;
    };
    case 2:
    {
        ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
    };
};

true
