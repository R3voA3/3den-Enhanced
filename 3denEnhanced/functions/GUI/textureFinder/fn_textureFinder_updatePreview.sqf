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

#include "\3denEnhanced\defines\defineCommon.inc"

params ["_ctrlTV", "_path"];

//Exit if category or nothing is selected
if (count _path < 3) exitWith {};

private _ctrlTexturePreview = ctrlparent _ctrlTV displayCtrl IDC_TEXTUREFINDER_PREVIEW;
private _ctrlTexturePreviewBG = ctrlparent _ctrlTV displayCtrl IDC_TEXTUREFINDER_PREVIEWBACKGROUND;

_ctrlTexturePreview ctrlShow false;
_ctrlTexturePreviewBG ctrlShow false;

private _texture = _ctrlTV tvData _path;

//Get original size and limit it to what we have available in the UI
getTextureInfo _texture params ["_w", "_h"];

_w = _w * pixelW min (158 * GRID_W);
_h = _h * pixelH min (61 * GRID_H);

//Now lets position the UI in respect to width and height of the image
_ctrlTexturePreview ctrlSetPosition
[
  (CENTERED_X(160) + 80 * GRID_W - (ctrlPosition _ctrlTexturePreview select 2) / 2),
  safezoneY + safezoneH - (77 * GRID_H + CTRL_DEFAULT_H),
  _w,
  _h
];

//Set final position for image
_ctrlTexturePreview ctrlSetText _texture;
_ctrlTexturePreview ctrlCommit 0;
_ctrlTexturePreview ctrlShow true;

//Adjust background according to image
_ctrlTexturePreviewBG ctrlSetPosition (ctrlPosition _ctrlTexturePreview);
_ctrlTexturePreviewBG ctrlCommit 0;
_ctrlTexturePreviewBG ctrlShow true;