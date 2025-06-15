#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2023-12-14
    File: 3denEnhanced\functions\interface\fn_3DENMinimap.sqf

    Description:
    Shows a minimap in Eden editor.

    Parameter(s):
    -

    Return Value:
    -

    Examples(s):
    -
*/

disableSerialization;

params [["_display3DEN", findDisplay IDD_DISPLAY3DEN]];

_display3DEN ctrlCreate ["ctrlStaticBackground", IDC_3DEN_MINIMAP_BACKGROUND];

private _ctrlMap = _display3DEN ctrlCreate ["ENH_3DENMinimap", IDC_3DEN_MINIMAP_MAP];
_ctrlMap ctrlEnable false;

// After previewing, the player position indicator is gone (engine bug?). So we create our own
private _ctrlImage = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", IDC_3DEN_MINIMAP_CENTER];
_ctrlImage ctrlSetText "a3\ui_f\data\gui\rsc\rscdisplaymissioneditor\iconcamera_ca.paa";
_ctrlImage ctrlSetTextColor [0.7, 0.09, 0, 1];

private _code =
{
    private _display3DEN = findDisplay IDD_DISPLAY3DEN;

    private _ctrlMap = _display3DEN displayCtrl IDC_3DEN_MINIMAP_MAP;
    private _ctrlBackground = _display3DEN displayCtrl IDC_3DEN_MINIMAP_BACKGROUND;
    private _ctrlImage = _display3DEN displayCtrl IDC_3DEN_MINIMAP_CENTER;

    private _attributeValue = profileNamespace getVariable ["ENH_EditorPreferences_Interface_MinimapSize", 0];

    private _hide = (get3DENActionState "ToggleMap" == 1) ||
    (round ctrlFade (_display3DEN displayCtrl IDC_DISPLAY3DEN_PLAY) > 0) ||
    (_attributeValue == 0) ||
    !isNil "ACE_arsenal_center" || // ACE Arsenal
    !isNil "BIS_fnc_arsenal_center"; // BI Arsenal

    _ctrlMap ctrlShow !_hide;
    _ctrlBackground ctrlShow !_hide;
    _ctrlImage ctrlShow !_hide;

    if !_hide then
    {
        // This hides the circle that indicates player position.
        if !(is3DENPreview || {is3DENMultiplayer }) then {disableMapIndicators [true, false, false, false]};

        private _scale = linearConversion
        [
            0,
            1000 * (profileNamespace getVariable ["ENH_EditorPreferences_Interface_MinimapScaleMultiplier", 0]),
            getPosASL get3DENCamera # 2,
            0.001,
            3,
            true
        ];

        private _position = switch _attributeValue do
        {
            case 1: // Small
            {
                [
                    safeZoneX + 62 * GRID_W,
                    safeZoneY + 14 * GRID_H,
                    32 * GRID_W,
                    32 * GRID_H
                ];
            };
            case 2: // Medium
            {
                [
                    safeZoneX + 62 * GRID_W,
                    safeZoneY + 14 * GRID_H,
                    62 * GRID_W,
                    62 * GRID_H
                ];
            };
            case 3: // Large
            {
                [
                    safeZoneX + 62 * GRID_W,
                    safeZoneY + 14 * GRID_H,
                    92 * GRID_W,
                    92 * GRID_H
                ];
            };
            default // Disabled, 0
            {
                [0, 0, 0, 0];
            };
        };

        if !(profileNamespace getVariable ["display3DEN_panelLeft", true]) then
        {
            _position set [0, _position # 0 - 54 * GRID_W];
        };

        _ctrlMap ctrlMapSetPosition _position;
        _ctrlMap ctrlMapAnimAdd [0, _scale, getPosWorld get3DENCamera];
        ctrlMapAnimCommit _ctrlMap;

        _ctrlBackground ctrlSetPosition
        [
            _position # 0 - 1 * GRID_W,
            _position # 1 - 1 * GRID_H,
            _position # 2 + 2 * GRID_W,
            _position # 3 + 2 * GRID_H
        ];

        _ctrlBackground ctrlCommit 0;

        _ctrlImage ctrlSetPosition
        [
            ctrlPosition _ctrlBackground # 0 + ctrlPosition _ctrlBackground # 2 / 2 - 2.5 * GRID_W,
            ctrlPosition _ctrlBackground # 1 + ctrlPosition _ctrlBackground # 3 / 2 - 2.5 * GRID_H,
            5 * GRID_W,
            5 * GRID_H
        ];

        _ctrlImage ctrlSetAngle [getDir get3DENCamera, 0.5, 0.5, true];
        _ctrlImage ctrlCommit 0;
    };
};

_display3DEN displayAddEventHandler ["MouseHolding", _code];
_display3DEN displayAddEventHandler ["MouseMoving", _code];
