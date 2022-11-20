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

// Get original size and limit it to what we have available in the UI
getTextureInfo _texture params ["_w", "_h"];

_w = _w * pixelW min (160 * GRID_W);
_h = _h * pixelH min (65 * GRID_W);

// Now lets position the UI in respect to width and height of the image
_ctrlTexturePreview ctrlSetPosition
[
  (CENTERED_X(160) + 80 * GRID_W - (ctrlPosition _ctrlTexturePreview select 2) / 2),
  (DIALOG_TOP + 82.5 * GRID_H - (ctrlPosition _ctrlTexturePreview select 3) / 2),
  _w,
  _h
];

_ctrlTexturePreview ctrlSetText _texture;
_ctrlTexturePreview ctrlCommit 0;