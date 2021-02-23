/*
  Author: R3vo

  Date: 2019-07-30

  Description:
  Creates the ENH_BatchReplace GUI if objects are selected, if not it shows an error message.

  Parameter(s):
  0: DISPLAY - Display

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

if !(is3DEN) exitWith {};

if ((get3DENSelected "Object") isEqualTo []) exitWith
{
  ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
};

findDisplay IDD_3DEN createDisplay "ENH_BatchReplace";