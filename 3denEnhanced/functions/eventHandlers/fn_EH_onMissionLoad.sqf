/*
  Author: R3vo

  Date: 2019-06-05

  Description:
  Is called by Eden event handler onMissionLoad. Content of this function may be altered by ENH_Config.hpp.

  Parameter(s):
  -

  Returns:
  -
*/

#if __has_include("\userconfig\ENH_Config.hpp")
#include "\userconfig\ENH_Config.hpp"
#endif

#ifndef ENH_HIDE_AMBIENTANIMATIONS
//Initialize ambient animations
call ENH_fnc_ambientAnimations_initInEditor;
#endif

//Enable 3DEN Radio
call ENH_fnc_3DENRadio_toggleRadio;

#ifndef ENH_HIDE_DYNAMICVIEWDISTANCE
//Enable dynamic view distance
call ENH_fnc_dynamicViewDistance;
#endif

#ifndef ENH_HIDE_INTERFACE
//Enable session timer
[] spawn ENH_fnc_sessionTimer;

//Collapse left tree view (entity list). A small delay is needed to let the list fully load first
if ("Preferences" get3DENMissionAttribute "ENH_CollapseEntityList") then
{
  [] spawn
  {
    sleep 0.1;
    ["collapseEntityList"] call BIS_fnc_3DENInterface;
  };
};
#endif