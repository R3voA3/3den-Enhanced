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

#include "\3denEnhanced\defines\defineCommon.inc"
#define PREF(B) ("Preferences" get3DENMissionAttribute B)

private _index = diag_allMissionEventHandlers find "EachFrame";
diag_log format ["No. of EachFrame EHs: %1", diag_allMissionEventHandlers select (_index + 1)];
systemChat format ["No. of EachFrame EHs: %1", diag_allMissionEventHandlers select (_index + 1)];

if (!is3DEN || !PREF("ENH_MinimapEnabled")) exitWith {call ENH_fnc_3DENMinimap_cleanUp};

ENH_fnc_3DENMinimap_cleanUp =
{
  ctrlDelete (findDisplay IDD_DISPLAY3DEN displayCtrl IDC_3DEN_MINIMAP_MAP);
  ctrlDelete (findDisplay IDD_DISPLAY3DEN displayCtrl IDC_3DEN_MINIMAP_BACKGROUND);

  private _ehID = uiNamespace getVariable ["ENH_3DENMiniMap_EH", -1];

  if (_ehID > -1) then
  {
    removeMissionEventHandler ["EachFrame", _ehID];
    uiNamespace setVariable ["ENH_3DENMiniMap_EH", -1];
  };
};

//Make sure to clean up first
call ENH_fnc_3DENMinimap_cleanUp;

findDisplay IDD_DISPLAY3DEN ctrlCreate ["ctrlStaticBackground", IDC_3DEN_MINIMAP_BACKGROUND];

private _ctrlMap = findDisplay IDD_DISPLAY3DEN ctrlCreate ["ctrlMap", IDC_3DEN_MINIMAP_MAP];
_ctrlMap ctrlEnable false;

private _ehID = addMissionEventHandler ["EachFrame",
{
  if (!is3DEN || !PREF("ENH_MinimapEnabled")) exitWith {call ENH_fnc_3DENMinimap_cleanUp};

  private _display3DEN = findDisplay IDD_DISPLAY3DEN;

  _ctrlMap = _display3DEN displayCtrl IDC_3DEN_MINIMAP_MAP;
  _ctrlBackground = _display3DEN displayCtrl IDC_3DEN_MINIMAP_BACKGROUND;

  private _show = get3DENActionState "ToggleMap" != 1;

  _ctrlMap ctrlShow _show;
  _ctrlBackground ctrlShow _show;

  private _scale = linearConversion [0, 1000, getPosATL get3DENCamera # 2, 0.05, 1, true] * PREF("ENH_MinimapScaleMultiplier");

  private _position = switch PREF("ENH_MinimapSize") do
  {
    case 1: //Small
    {
      [
        safezoneX + safeZoneW - 94 * GRID_W,
        safezoneY + 14 * GRID_H,
        32 * GRID_W,
        32 * GRID_H
      ];
    };
    case 3: //Large
    {
      [
        safezoneX + safeZoneW - 154 * GRID_W,
        safezoneY + 14 * GRID_H,
        92 * GRID_W,
        92 * GRID_H
      ];
    };
    default //Medium
    {
      [
        safezoneX + safeZoneW - 124 * GRID_W,
        safezoneY + 14 * GRID_H,
        62 * GRID_W,
        62 * GRID_H
      ];
    };
  };

  if !(profileNamespace getVariable ["display3DEN_panelRight", true]) then
  {
    _position set [0, _position # 0 + 54 * GRID_W];
  };

  _ctrlMap ctrlMapSetPosition _position;
  _ctrlMap ctrlMapAnimAdd [0, _scale, getPosASL get3DENCamera];
  ctrlMapAnimCommit _ctrlMap;

  _ctrlBackground ctrlSetPosition
  [
    _position # 0 - 1 * GRID_W,
    _position # 1 - 1 * GRID_H,
    _position # 2 + 2 * GRID_W,
    _position # 3 + 2 * GRID_H
  ];

  _ctrlBackground ctrlCommit 0;
}];

uiNamespace setVariable ["ENH_3DENMiniMap_EH", _ehID];