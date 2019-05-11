/*
   Author: Revo

   Description:
   Adds a linebreak to the briefing.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true
*/
#define GET_CONTROL(IDD,IDC) ((findDisplay IDD) displayCtrl IDC)

private _briefingText = ctrlText GET_CONTROL(50000,10);

GET_CONTROL(50000,10) ctrlSetText (_briefingText + "<br/>");

ctrlSetFocus GET_CONTROL(50000,10);

true