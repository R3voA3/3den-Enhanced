/*
  Author: R3vo

  Date: 2019-06-05

  Description:
  Is called by Eden event handler onMissionPreview. Content of this function may be altered by ENH_Config.hpp.

  Parameter(s):
  -

  Returns:
  -
*/

0 spawn ENH_fnc_debugOptions_init;

if (fileExists "ENH_init3DENMissionPreview.sqf") then {execVM "ENH_init3DENMissionPreview.sqf"};