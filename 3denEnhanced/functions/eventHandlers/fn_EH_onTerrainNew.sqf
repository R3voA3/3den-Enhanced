/*
  Author: R3vo

  Date: 2019-06-05

  Description:
  Is called by Eden event handler onTerrainNew. Content of this function may be altered by ENH_Config.hpp.

  Parameter(s):
  -

  Returns:
  -
*/

#if __has_include("\userconfig\ENH_Config.hpp")
#include "\userconfig\ENH_Config.hpp"
#endif

#ifndef ENH_HIDE_INTERFACE
//Reinitialize Eden interface to prevent issues when game directly starts inside the editor via startup parameter
['init'] call BIS_fnc_3DENStatusBar;
['init'] call BIS_fnc_3DENInterface;

//Show or hide panels
["ShowPanelRight", "Preferences" get3DENMissionAttribute "ENH_ShowPanelRight"] call BIS_fnc_3DENInterface;
["ShowPanelLeft", "Preferences" get3DENMissionAttribute "ENH_ShowPanelLeft"] call BIS_fnc_3DENInterface;

//Collapse asset browser
call ENH_fnc_assetBrowser_collapse;

//Set up entity counter in status bar according to preferences
"init" call ENH_fnc_statusbar_entityCounter;
"run" call ENH_fnc_statusbar_entityCounter;

//Enable session timer
[] spawn ENH_fnc_statusbar_sessionTimer;

//Remove unwanted menu strip entries
call ENH_fnc_menuStrip_removeItems;

//Update location list
call ENH_fnc_locationList;
#endif

//Enable 3DEN Radio
call ENH_fnc_3DENRadio_toggleRadio;

#ifndef ENH_HIDE_AMBIENTANIMATIONS
//Initialize ambient animations
call ENH_fnc_ambientAnimations_initInEditor;
#endif

//Preload the ammo attribute to get rid of initial freeze and loading screen
[] call ENH_fnc_preloadAmmoAttribute;

//Init favorites list
["onLoad", []] call ENH_fnc_favoritesList;

//Add tooltips to entity browser so long names are not cut off
(findDisplay 313 displayCtrl 55) ctrlAddEventHandler ["MouseEnter", {[[]] call ENH_fnc_assetBrowser_addTooltips}];