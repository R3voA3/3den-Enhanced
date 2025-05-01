#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-01

    Description:
    This is an awesome description.

    Parameter(s):
    0: ARRAY - Some description, optional, default false

    Return Value:
    ARRAY - True on success, false if failed

    Examples(s):
    [] call ENH_fnc_missionDisplay;
*/
// TODO: add proper header 2025-05-01 R3vo

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

// [[], [], false] call BIS_fnc_drawBoundingBox;

["Quick garrison disabled!"] call BIS_fnc_3DENNotification;
