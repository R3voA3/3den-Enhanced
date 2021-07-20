/*
  Author: R3vo

  Date: 2021-04-26

  Description:
  Updates the preview image.

  Parameter(s):
  0: CONTROL - Tree View
  1: ARRAY - Path to item

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

params ["_ctrlTV", "_path"];

//Exit if category or nothing is selected
if (count _path < 3) exitWith {};

private _ctrlTexturePreview = ctrlparent _ctrlTV displayCtrl IDC_TEXTUREFINDER_PREVIEW;
private _texture = _ctrlTV tvText _path;

_ctrlTexturePreview ctrlSetText _texture;

getTextureInfo _texture params ["_w", "_h"];
_w = _w * pixelW min 800 * pixelW;
_h = _h * pixelH min 400 * pixelH;

_ctrlTexturePreview ctrlSetPosition
[
  CENTERED_X(160) + 80 * GRID_W - _w / 2,
  DIALOG_TOP + 58 * GRID_H + 200 * pixelH - (_h min 200 * pixelH),
  _w,
  _h
];

_ctrlTexturePreview ctrlCommit 0;

/* #include "\3denEnhanced\defines\ENH_defineCommon.hpp"

params ["_ctrlTV", "_path"];

//Exit if category or nothing is selected
if (count _path < 3) exitWith {};

(ctrlparent _ctrlTV displayCtrl IDC_TEXTUREFINDER_PREVIEW) ctrlSetText (_ctrlTV tvText _path); */