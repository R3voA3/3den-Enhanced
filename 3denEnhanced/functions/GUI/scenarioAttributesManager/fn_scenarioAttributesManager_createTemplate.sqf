/*
  Author: R3vo

  Date: 2019-05-24

  Description:
  Used by the ENH_ENH_ScenarioAttributesManager_TemplateData GUI.
  Used to set the title and description of the template.

  Parameter(s):
  0: CONTROL - Control button

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;

ENH_ScenarioAttributesManager_TemplateTitle = ctrlText CTRL(IDC_SCENARIOATTRIBUTESMANAGER_TEMPLATEDATA_TITLE);
ENH_ScenarioAttributesManager_TemplateDescription = ctrlText CTRL(IDC_SCENARIOATTRIBUTESMANAGER_TEMPLATEDATA_DESCRIPTION);

//Close display ENH_ENH_ScenarioAttributesManager_TemplateData and wait for the parent display to be available again
_display closeDisplay 1;

[] spawn
{
  waitUntil {!(isNull findDisplay IDD_SCENARIOATTRIBUTESMANAGER)};

  private _display = findDisplay IDD_SCENARIOATTRIBUTESMANAGER;
  private _ctrlLB = CTRL(IDC_SCENARIOATTRIBUTESMANAGER_TEMPLATES);

  private _attributeValues = call ENH_fnc_scenarioAttributesManager_getScenarioAttributes;


  private _index = _ctrlLB lbAdd ENH_ScenarioAttributesManager_TemplateTitle;
  _ctrlLB lbSetTooltip [_index, ENH_ScenarioAttributesManager_TemplateDescription];

  //Save Title, Description and actual scenario attributes
  _ctrlLB lbSetData [_index, str [ENH_ScenarioAttributesManager_TemplateTitle, ENH_ScenarioAttributesManager_TemplateDescription, _attributeValues]];
  lbSort [_ctrlLB, "DESC"];
};