/*
   Author: R3vo

   Date: 2019-06-05

   Description:
   Is called by Eden event handler onTerrainNew.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

//Reinitialize Eden interface to prevent issues when game directly starts inside the editor via startup parameter
['init'] call BIS_fnc_3DENStatusBar;
['init'] call BIS_fnc_3DENInterface;

//Show or hide panels
["ShowPanelRight",profileNamespace getVariable ['ENH_ShowPanelRight',true]] call bis_fnc_3DENINterface;
["ShowPanelLeft",profileNamespace getVariable ['ENH_ShowPanelLeft',true]] call bis_fnc_3DENINterface;

//Collapse asset browser
call ENH_fnc_3DENCollapseAssetBrowser;

//Set up entity counter in status bar according to preferences
"init" call ENH_fnc_statusbar_entityCounter;
"run" call ENH_fnc_statusbar_entityCounter;

//Enable 3den Radio
'ONLOAD' call ENH_fnc_3denRadio_toggleRadio;

//Enable session timer
[] spawn ENH_fnc_sessionTimer;

//Update location list
call ENH_fnc_locationList;

//Show github message
[] spawn ENH_fnc_gitHubNotification;

//Show version 4.3 message
[] spawn ENH_fnc_newVersionNotification

//Initialize ambient animations
call ENH_fnc_initAmbientAnimationsInEditor;

true