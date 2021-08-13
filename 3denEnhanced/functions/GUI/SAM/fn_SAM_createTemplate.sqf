/*
  Author: R3vo

  Date: 2019-05-24

  Description:
  Used by the ENH_ENH_SAM_TemplateData GUI.
  Used to set the title and description of the template.

  Parameter(s):
  0: CONTROL - Control button

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;

ENH_SAM_TemplateTitle = ctrlText CTRL(IDC_SAM_TEMPLATEDATA_TITLE);
ENH_SAM_TemplateDescription = ctrlText CTRL(IDC_SAM_TEMPLATEDATA_DESCRIPTION);

//Close display ENH_ENH_SAM_TemplateData and wait for the parent display to be available again
_display closeDisplay 1;

[] spawn
{
  waitUntil {!(isNull findDisplay IDD_SAM)};

  private _display = findDisplay IDD_SAM;
  private _ctrlLB = CTRL(IDC_SAM_TEMPLATES);

  private _attributeValues = call ENH_fnc_SAM_getScenarioAttributes;


  private _index = _ctrlLB lbAdd ENH_SAM_TemplateTitle;
  _ctrlLB lbSetTooltip [_index, ENH_SAM_TemplateDescription];

  //Save Title, Description and actual scenario attributes
  _ctrlLB lbSetData [_index, str [ENH_SAM_TemplateTitle, ENH_SAM_TemplateDescription, _attributeValues]];
  lbSort [_ctrlLB, "DESC"];
};