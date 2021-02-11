/*
  Author: R3vo

  Date: 2019-06-05

  Description:
  Is called by Eden event handler onMissionNew. Content of this function may be altered by ENH_Config.hpp.

  Parameter(s):
  -

  Returns:
  -
*/

#if __has_include("\userconfig\ENH_Config.hpp")
#include "\userconfig\ENH_Config.hpp"
#endif

//Enable 3DEN Radio
call ENH_fnc_3DENRadio_toggleRadio;

#ifndef ENH_HIDE_INTERFACE
//Enable session timer
[] spawn ENH_fnc_sessionTimer;
#endif

#ifndef ENH_HIDE_DYNAMICVIEWDISTANCE
//Enable dynamic view distance
call ENH_fnc_dynamicViewDistance;
#endif