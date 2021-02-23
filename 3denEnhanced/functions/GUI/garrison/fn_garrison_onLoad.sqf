/*
  Author: R3vo

  Date: 2019-08-03

  Description:
  Called when ENH_Garrison GUI is created. Used to set default values.

  Parameter(s):
  0: DISPLAY - Display

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

params ["_display"];

CTRL(IDC_GARRISON_RADIUS) ctrlSetText (profileNamespace getVariable ['ENH_garrison_lastRadius', "500"]);
CTRL(IDC_GARRISON_COVERAGE) lbSetCurSel (profileNamespace getVariable ['ENH_garrison_lastCoverage', 1]);
CTRL(IDC_GARRISON_STANCE) lbSetCurSel (profileNamespace getVariable ['ENH_garrison_lastStance', 0]);