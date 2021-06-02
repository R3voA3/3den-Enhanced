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

#include "\3denEnhanced\ENH_defineCommon.hpp"

params ["_ctrlTV", "_path"];

//Exit if category or nothing is selected
if (count _path < 2) exitWith {};

(ctrlparent _ctrlTV displayCtrl IDC_TEXTUREFINDER_PREVIEW) ctrlSetText (_ctrlTV tvText _path);