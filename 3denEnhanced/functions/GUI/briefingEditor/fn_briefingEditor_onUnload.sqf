/*
  Author: R3vo

  Date: 2019-06-21

  Description:
  Closes the briefing editor and creates a history.

  Parameter(s):
  0: DISPLAy - ENH_BriefingEditor

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;

params ["_display"];

//Create history of last input when closing the display
profileNamespace setVariable
[
  "ENH_briefingEditor_history",
  [
    ctrlText CTRL(IDC_BRIEFINGEDITOR_TITLE),
    ctrlText CTRL(IDC_BRIEFINGEDITOR_SUBJECT),
    ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT)
  ]
];

//Save templates to profileNamespace
private _ctrlLBTemplates = CTRL(IDC_BRIEFINGEDITOR_TEMPLATES);
private _savedTemplates = [];

for "_index" from 0 to (lbSize _ctrlLBTemplates - 1) do
{
  private _briefingTitle =_ctrlLBTemplates lbText _index;
  private _briefingText = _ctrlLBTemplates lbData _index;
  _savedTemplates pushBack [_briefingTitle, _briefingText];
};

profileNamespace setVariable ["ENH_briefingEditor_templates", _savedTemplates];