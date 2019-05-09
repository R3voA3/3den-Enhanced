/*
   Author: Revo

   Description:
   Creates a template and adds it to the listbox.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true / false
*/

#define GET_CONTROL(IDD,IDC) ((findDisplay IDD) displayCtrl IDC)

private _briefingTitle = ctrlText GET_CONTROL(50000,30);
private _subject = ctrlText GET_CONTROL(50000,20);
private _briefingText = ctrlText GET_CONTROL(50000,10);
private _index = GET_CONTROL(50000,80) lbAdd _briefingTitle;

if (_briefingTitle isEqualTo "") exitWith {false};

GET_CONTROL(50000,80) lbSetData [_index,_briefingText];
GET_CONTROL(50000,80) lbSetTooltip [_index,localize "STR_ENH_briefingEditor_loadTemplate_tooltip"];

true