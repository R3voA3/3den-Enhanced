/*
  Author: R3vo

  Date: 2019-06-21

  Description:
  Closes the briefing editor and creates a history.

  Parameter(s):
  0: DISPLAY - ENH_BriefingEditor

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

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