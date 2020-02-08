/*
   Author: R3vo

   Date: 2019-06-21

   Description:
   Creates a template and adds it to the listbox.

   Parameter(s):
   0: CONTROL - Controlb button

   Returns:
   BOOLEAN: true / false
*/

#define CTRL(IDC) (_display displayCtrl IDC)
params ["_ctrlButton"];
private _display = ctrlParent _ctrlButton;

private _briefingTitle = ctrlText CTRL(30);

if (_briefingTitle isEqualTo "") exitWith {false};

private _subject = ctrlText CTRL(20);
private _briefingText = ctrlText CTRL(10);
private _index = CTRL(80) lbAdd _briefingTitle;

CTRL(80) lbSetData [_index,_briefingText];
CTRL(80) lbSetTooltip [_index,localize "STR_ENH_BRIEFINGEDITOR_LOADTEMPLATE_TOOLTIP"];

true