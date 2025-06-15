#include "\x\enh\addons\main\script_component.hpp"

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

params ["_ctrlTV", "_path"];

// Exit if category or nothing is selected
if (count _path < 3) exitWith {};

private _ctrlTexturePreview = ctrlParent _ctrlTV displayCtrl IDC_TEXTUREFINDER_PREVIEW;
private _ctrlTexturePreviewBG = ctrlParent _ctrlTV displayCtrl IDC_TEXTUREFINDER_PREVIEWBACKGROUND;

private _texture = _ctrlTV tvData _path;

// Prevent function from constantly running, even if image hasn't changed
if (_ctrlTV getVariable ["LastImagePath", ""] == _texture) exitWith {};
_ctrlTV setVariable ["LastImagePath", _texture];

_ctrlTexturePreview ctrlShow false;
_ctrlTexturePreviewBG ctrlShow false;

// Get original size and limit it to what we have available in the UI
getTextureInfo _texture params ["_w", "_h"];

// Calculate available vertical space dynamically
private _verticalSpace = ctrlPosition (ctrlParent _ctrlTV displayCtrl IDC_TEXTUREFINDER_SEARCH) # 1 - (ctrlPosition _ctrlTV # 1 + ctrlPosition _ctrlTV # 3) - 3 * GRID_H;

_w = _w * pixelW min ((WINDOW_W_ATTRIBUTES - 2) * GRID_W);
_h = _h * pixelH min _verticalSpace;

// Now lets position the UI in respect to width and height of the image
_ctrlTexturePreview ctrlSetPosition
[
    CENTER_X - _w / 2,
    WINDOW_TOPAbs + WINDOW_HAbs - 78 * GRID_H + 2 * CTRL_DEFAULT_H,
    _w,
    _h
];

// Set final position for image
_ctrlTexturePreview ctrlSetText _texture;
_ctrlTexturePreview ctrlCommit 0;
_ctrlTexturePreview ctrlShow true;

// Adjust background according to image
_ctrlTexturePreviewBG ctrlSetPosition (ctrlPosition _ctrlTexturePreview);
_ctrlTexturePreviewBG ctrlCommit 0;
_ctrlTexturePreviewBG ctrlShow true;
