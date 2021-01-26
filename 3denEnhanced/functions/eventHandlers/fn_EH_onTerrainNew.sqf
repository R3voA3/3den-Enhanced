/*
  Author: R3vo

  Date: 2019-06-05

  Description:
  Is called by Eden event handler onTerrainNew.

  Parameter(s):
  -

  Returns:
  -
*/

//Reinitialize Eden interface to prevent issues when game directly starts inside the editor via startup parameter
['init'] call BIS_fnc_3DENStatusBar;
['init'] call BIS_fnc_3DENInterface;

//Show or hide panels
["ShowPanelRight", "Preferences" get3DENMissionAttribute "ENH_ShowPanelRight"] call BIS_fnc_3DENINterface;
["ShowPanelLeft", "Preferences" get3DENMissionAttribute "ENH_ShowPanelLeft"] call BIS_fnc_3DENINterface;

//Collapse asset browser
call ENH_fnc_3DENCollapseAssetBrowser;

//Set up entity counter in status bar according to preferences
"init" call ENH_fnc_statusbar_entityCounter;
"run" call ENH_fnc_statusbar_entityCounter;

//Enable 3DEN Radio
call ENH_fnc_3DENRadio_toggleRadio;

//Enable session timer
[] spawn ENH_fnc_sessionTimer;

//Update location list
call ENH_fnc_locationList;

//Initialize ambient animations
call ENH_fnc_initAmbientAnimationsInEditor;

//Add custom menu strip entries
call ENH_fnc_addCustomMenuStripEntries;

//Remove unwanted menu strip entries
call ENH_fnc_removeItemsFromMenu;