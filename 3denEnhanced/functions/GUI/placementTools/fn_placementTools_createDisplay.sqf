/*
  Author: R3vo

  Date: 2019-06-11

  Description:
  Checks if ENH_PlacementTools GUI should be opened and if yes, creates the display.

  Parameter(s):
  -

  Returns:
  BOOLEAN: true / false
*/

#include "\3denEnhanced\defineCommon.hpp"

ENH_PlacementTools_Selected = [["Object", "Logic", "Trigger", "Marker"]] call ENH_fnc_all3DENSelected;

if (ENH_PlacementTools_Selected isEqualTo []) exitWith {["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification; false};

findDisplay IDD_3DEN createDisplay "ENH_PlacementTools";

true