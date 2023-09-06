/*
  Author: R3vo

  Date: 2019-07-29

  Description:
  Sets the increment size. Used in the ENH_PatternTools GUI. Called when toolbox selection was changed.

  Parameter(s):
  0: CONTROL - Control tool box

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

disableSerialization;
params ["_ctrlToolbox", "_selectedIndex"];

private _display = ctrlParent _ctrlToolbox;
private _stepSize = _ctrlToolbox lbValue _selectedIndex;

missionNamespace setVariable ["ENH_PlacementTools_stepSizeIndex", _selectedIndex];

//Set slider speed
{
  (_display displayCtrl _x) sliderSetSpeed [_stepSize, _stepSize];
} forEach
[
  IDC_PLACEMENTTOOLS_RADIUS,
  IDC_PLACEMENTTOOLS_INITIALANGLE,
  IDC_PLACEMENTTOOLS_CENTRALANGLE,
  IDC_PLACEMENTTOOLS_SPACING,
  IDC_PLACEMENTTOOLS_NUMCOLUMNS,
  IDC_PLACEMENTTOOLS_SPACEX,
  IDC_PLACEMENTTOOLS_SPACEY,
  IDC_PLACEMENTTOOLS_A, IDC_PLACEMENTTOOLS_B
];