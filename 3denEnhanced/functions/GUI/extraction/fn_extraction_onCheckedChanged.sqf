/*
  Author: R3vo

  Date: 2019-09-13

  Description:
  Used by the ENH_Extraction GUI. Called when checkbox state is changed. Enables or disables edit boxes for callsigns.

  Parameter(s):
  0: CONTROL - Checkbox control
  1: NUMBER - Checkbox state

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

params ["_ctrlCheckbox", "_checked"];

private _display = ctrlParent _ctrlCheckbox;
private _enable = [false, true] select _checked;

CTRL(IDC_EXTRACTION_NAMEREQUESTER) ctrlEnable _enable;
CTRL(IDC_EXTRACTION_NAMETRANSPORT) ctrlEnable _enable;