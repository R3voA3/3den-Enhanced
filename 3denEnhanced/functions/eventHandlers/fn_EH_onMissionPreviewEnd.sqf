/*
  Author: R3vo

  Date: 2019-06-05

  Description:
  Is called by Eden event handler onMissionPreviewEnd. Content of this function may be altered by ENH_Config.hpp.

  Parameter(s):
  -

  Returns:€
  -
*/

#if __has_include("\userconfig\ENH_Config.hpp")
#include "\userconfig\ENH_Config.hpp"
#endif

//Enable 3DEN Radio
call ENH_fnc_3DENRadio_toggleRadio;

#ifndef ENH_HIDE_INTERFACE
//Enable session timer
[] spawn ENH_fnc_statusbar_sessionTimer;

//Add tooltips to entity browser so long names are not cut off
(findDisplay 313 displayCtrl 55) ctrlAddEventHandler ["MouseEnter", {[[]] call ENH_fnc_entityList_addTooltips}];

//Init direction display
addMissionEventHandler ["EachFrame",
{
  findDisplay 313 displayCtrl 681 ctrlSetText format ["%1 °", round getDir get3DENCamera];
}];
#endif