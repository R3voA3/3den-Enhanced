/*
  Author: R3vo

  Date: 2019-06-21

  Description:
  Creates a template and adds it to the listbox.

  Parameter(s):
  0: CONTROL - Controlb button

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

params ["_ctrlButton"];
private _display = ctrlParent _ctrlButton;

private _briefingTitle = ctrlText CTRL(IDC_BRIEFINGEDITOR_TITLE);

if (_briefingTitle isEqualTo "") exitWith {false};

private _subject = ctrlText CTRL(IDC_BRIEFINGEDITOR_SUBJECT);
private _briefingText = ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT);
private _index = CTRL(IDC_BRIEFINGEDITOR_TEMPLATES) lbAdd _briefingTitle;

CTRL(IDC_BRIEFINGEDITOR_TEMPLATES) lbSetData [_index, _briefingText];
CTRL(IDC_BRIEFINGEDITOR_TEMPLATES) lbSetTooltip [_index, localize "STR_ENH_BRIEFINGEDITOR_LOADTEMPLATE_TOOLTIP"];