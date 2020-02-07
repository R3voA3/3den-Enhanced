/*
   Author: R3vo

   Date: 2019-09-13

   Description:
   Used by the ENH_Extraction GUI. Called when checkbox state is changed. Enables or disables edit boxes for callsigns.

   Parameter(s):
   0: CONTROL - Checkbox control
   1: NUMBER - Checkbox state

   Returns:
   BOOLEAN: true
*/

#define GET_CTRL(IDC) (_display displayCtrl IDC)

params ["_ctrlCheckbox", "_checked"];

private _display = ctrlParent _ctrlCheckbox;
private _enable = [false,true] select _checked;

GET_CTRL(200) ctrlEnable _enable;
GET_CTRL(300) ctrlEnable _enable;