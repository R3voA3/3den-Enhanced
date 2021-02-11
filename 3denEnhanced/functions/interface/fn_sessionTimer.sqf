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

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
private _display3DEN = findDisplay IDD_3DEN displayCtrl IDC_STATUSBAR_SESSIONTIMER;

while {is3DEN} do
{
  _display3DEN ctrlSetText ([diag_tickTime / 3600] call BIS_fnc_timeToString);
  uiSleep 1;
};