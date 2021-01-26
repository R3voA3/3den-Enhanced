/*
  Author: R3vo

  Date: 2019-05-24

  Description:
  Used by the ENH_ENH_ScenarioAttributesManager GUI.
  Saves all templates to profilenamespace when GUI is closed.

  Parameter(s):
  0: DISPLAY - Display

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_display"];

private _ctrlLB = CTRL(IDC_SCENARIOATTRIBUTESMANAGER_TEMPLATES);
private _lbSize = lbSize _ctrlLB;
private _templates = [];

for "_i" from 0 to _lbSize - 1 do
{
  private _data = call compile (_ctrlLB lbData _i);
  _templates pushBackUnique _data;
};

//Store templates in profilenamespace and save it.
profileNamespace setVariable ["ENH_ScenarioAttributesManager_Templates", _templates];
saveprofileNamespace;