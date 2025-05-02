#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-01

    Description:
    Exits garrison mode.

    Parameter(s):
    -

    Return Value:
    BOOLEAN - True
*/

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

["ENH_Garrison2_Disabled"] call ENH_fnc_3DENNotificationQueue;

true
