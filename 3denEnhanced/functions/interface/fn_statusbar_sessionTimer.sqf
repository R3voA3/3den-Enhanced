/*
  Author: R3vo

  Date: 2019-08-20

  Description:
  Initialises the 3den Enhanced session timer. Needs to be spawned!

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

//TODO: This can be excuted multiple times. It resets itself on preview or exiting Eden Editor though

disableSerialization;
private _ctrlTimer = findDisplay IDD_DISPLAY3DEN displayCtrl IDC_STATUSBAR_SESSIONTIMER;

while {is3DEN} do
{
  _ctrlTimer ctrlSetText ([diag_tickTime / 3600] call BIS_fnc_timeToString);
  uiSleep 1;
};