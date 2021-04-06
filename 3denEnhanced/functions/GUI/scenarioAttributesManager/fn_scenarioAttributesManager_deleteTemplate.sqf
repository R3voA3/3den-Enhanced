/*
  Author: R3vo

  Date: 2019-05-24

  Description:
  Used by the ENH_ENH_ScenarioAttributesManager_TemplateData GUI.
  Removes currently selected item from template listbox.

  Parameter(s):
  0: CONTROL - Control button

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;

CTRL(IDC_SCENARIOATTRIBUTESMANAGER_TEMPLATES) lbDelete (lbCurSel CTRL(IDC_SCENARIOATTRIBUTESMANAGER_TEMPLATES));