/*
  Author: R3vo

  Date: 2019-05-25

  Description:
  Used by the ENH_ENH_SAM GUI.
  Fills listbox with templates stored in profilenamespace when UI is loaded.

  Parameter(s):
  0: DISPLAY - Display

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

disableSerialization;
params ["_display"];

_ctrlLB = CTRL(IDC_SAM_TEMPLATES);
_templates = profileNamespace getVariable ["ENH_SAM_Templates", []];

if (_templates isEqualTo []) exitWith {false};

{
  private _index = _ctrlLB lbAdd (_x # 0); //Use title as lb entry
  _ctrlLB lbSetTooltip [_index, _x # 1]; //Use description of templates as tooltip
  _ctrlLB lbSetData [_index, str _x]; //Store the whole template data as lb data for easy access
} forEach _templates;

lbSort [_ctrlLB, "DESC"];

_disp displayAddEventHandler ["keyDown", //Focus Search
{
  params ["_display", "_key", "", "_ctrl"];
  if (_key isEqualTo 33 && _ctrl) then
  {
    ctrlSetFocus CTRL(IDC_SAM_SEARCH);
  }
}];