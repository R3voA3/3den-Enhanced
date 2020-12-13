/*
  Author: R3vo

  Date: 2019-05-24

  Description:
  Used by the ENH_ENH_ScenarioAttributesManager_TemplateData GUI.
  Applies attribute selected in tree view controls via button.

  Parameter(s):
  0: CONTROL - Button

  Returns:
  true
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _tvPath = tvCurSel CTRL(IDC_SCENARIOATTRIBUTESMANAGER_ATTRIBUTES);

if (count _tvPath < 2) exitWith {false};

//Data is string, we need an array, so compiling it is
_attributeData = call compile (CTRL(IDC_SCENARIOATTRIBUTESMANAGER_ATTRIBUTES) tvData _tvPath);//["Section","PropertyName",value];

set3DENMissionAttributes [_attributeData];

[
  format [localize "STR_ENH_TOOLS_ATTRIBUTEMANAGER_NOTIFICATION",_attributeData # 1, _attributeData # 2]
] call BIS_fnc_3DENNotification;

true