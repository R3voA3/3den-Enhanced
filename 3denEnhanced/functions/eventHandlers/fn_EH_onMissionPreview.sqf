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

#if __has_include("\userconfig\ENH_Config.hpp")
#include "\userconfig\ENH_Config.hpp"
#endif

#ifndef ENH_HIDE_DEBUGOPTIONS
0 spawn ENH_fnc_debugOptions_init;
#endif

if (fileExists "ENH_init3DENMissionPreview.sqf") then {execVM "ENH_init3DENMissionPreview.sqf"};