/*
  Author: R3vo

  Date: 2020-02-11

  Description:
  Used by the ENH_VariableViewer GUI. Called when listNbox selection changed.

  Parameter(s):
  0: CONTROL - ListNBox control
  1: NUMBER - Selected index

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_ctrlLNB","_selectedRow"];

private _display = ctrlParent _ctrlLNB;

CTRL(IDC_VARIABLEVIEWER_VARIABLENAME) ctrlSetText (_ctrlLNB lnbText [_selectedRow,0]);
CTRL(IDC_VARIABLEVIEWER_VARIABLEVALUE) ctrlSetText (_ctrlLNB lnbText [_selectedRow,1]);