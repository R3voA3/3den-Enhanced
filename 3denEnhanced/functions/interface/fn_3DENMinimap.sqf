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

params [["_mode", "init"]];

#include "\3denEnhanced\defines\defineCommon.inc"

switch _mode do
{
  case "exit":
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
  case "init":
  {
    if (!is3DEN || !G_PREF("ENH_MinimapEnabled")) exitWith {"exit" call ENH_fnc_3DENMinimap};

    //Make sure to clean up first
    "exit" call ENH_fnc_3DENMinimap;

    findDisplay IDD_DISPLAY3DEN ctrlCreate ["ctrlStaticBackground", IDC_3DEN_MINIMAP_BACKGROUND];

    private _ctrlMap = findDisplay IDD_DISPLAY3DEN ctrlCreate ["ctrlMap", IDC_3DEN_MINIMAP_MAP];
    _ctrlMap ctrlEnable false;

    private _ehID = addMissionEventHandler ["EachFrame",
    {
      if (!is3DEN || !G_PREF("ENH_MinimapEnabled")) exitWith {"exit" call ENH_fnc_3DENMinimap};

      private _display3DEN = findDisplay IDD_DISPLAY3DEN;

      _ctrlMap = _display3DEN displayCtrl IDC_3DEN_MINIMAP_MAP;
      _ctrlBackground = _display3DEN displayCtrl IDC_3DEN_MINIMAP_BACKGROUND;

      private _hide = get3DENActionState "ToggleMap" == 1 || round ctrlFade (_display3DEN displayCtrl IDC_DISPLAY3DEN_PLAY) > 0;

      _ctrlMap ctrlShow !_hide;
      _ctrlBackground ctrlShow !_hide;

      private _scale = linearConversion [0, 1000, getPosATL get3DENCamera # 2, 0.05, 1, true] * G_PREF("ENH_MinimapScaleMultiplier");

      private _position = switch G_PREF("ENH_MinimapSize") do
      {
        case 1: //Small
        {
          [
            safezoneX + 62 * GRID_W,
            safezoneY + 14 * GRID_H,
            32 * GRID_W,
            32 * GRID_H
          ];
        };
        case 3: //Large
        {
          [
            safezoneX + 62 * GRID_W,
            safezoneY + 14 * GRID_H,
            92 * GRID_W,
            92 * GRID_H
          ];
        };
        default //Medium
        {
          [
            safezoneX + 62 * GRID_W,
            safezoneY + 14 * GRID_H,
            62 * GRID_W,
            62 * GRID_H
          ];
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
    }];

    uiNamespace setVariable ["ENH_3DENMiniMap_EH", _ehID];
  };
  case "toggleFromMenu":
  {
    //Switching the state of the attribute also executes the code set in the G_PREFerences
    S_PREF("ENH_MinimapEnabled", !G_PREF("ENH_MinimapEnabled"));
  };
  case "AdjustSizeFromMenu":
  {
    private _currSize = G_PREF("ENH_MinimapSize");

    if (_currSize == 3) then
    {
      _currSize = 1;
    }
    else
    {
      _currSize = _currSize + 1;
    };

    //Switching the state of the attribute also executes the code set in the G_PREFerences
    S_PREF("ENH_MinimapSize", _currSize);
  };
};