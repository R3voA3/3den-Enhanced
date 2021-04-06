/*
  Author: R3vo

  Date: 2021-04-05

  Description:
  Initializes ENH_BatchReplace GUI.

  Parameter(s):
  0: DISPLAY

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;

params ["_display"];

CTRL(IDC_BATCHREPLACE_REPLACEWITH) ctrlSetText (uiNamespace getVariable ["ENH_batchReplace_lastUsed", ""]);

CTRL(IDC_BATCHREPLACE_SEARCH) ctrlEnable false;

[CTRL(IDC_BATCHREPLACE_LIST)] call ENH_fnc_batchReplace_fillTreeView;

CTRL(IDC_BATCHREPLACE_LIST) ctrlAddEventHandler ["treeSelChanged", {_this call ENH_fnc_batchReplace_onTreeSelChanged}];

CTRL(IDC_BATCHREPLACE_SEARCH) ctrlEnable true;