#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-01

    Description:
    Toggles garrison mode.

    Parameter(s):
    -

    Return Value:
    BOOLEAN - True on success, false if failed

    Examples(s):
*/

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

if (findDisplay IDD_DISPLAY3DEN getVariable ["ENH_OnEntityDraggedID", -1] == -1) then
{
    if (get3DENActionState "toggleMap" > 0) exitWith
    {
        ["ENH_Garrison2_2D_Not_Supported"] call ENH_fnc_3DENNotificationQueue;
        false
    };

    if (get3DENSelected "Object" isEqualTo []) exitWith
    {
        ["ENH_NoEntitiesSelected"] call ENH_fnc_3DENNotificationQueue;
        false
    };

    ["ENH_Garrison2_Enabled"] call ENH_fnc_3DENNotificationQueue;

    _display3DEN setVariable ["ENH_MouseButtonUpID", _display3DEN displayAddEventHandler ["MouseButtonUp", ENH_fnc_garrison2_onMouseButtonUp]];
    _display3DEN setVariable ["ENH_OnEntityDraggedID", add3DENEventHandler ["OnEntityDragged", ENH_fnc_garrison2_onEntityDragged]];
    _display3DEN setVariable ["ENH_Draw3DID", addMissionEventHandler ["Draw3D", ENH_fnc_garrison2_draw3D]];
    _display3DEN setVariable ["ENH_OnBeforeMissionPreviewID", add3DENEventHandler ["OnBeforeMissionPreview", ENH_fnc_garrison2_exit]];
}
else
{
    call ENH_fnc_garrison2_exit;
    false
};

true
