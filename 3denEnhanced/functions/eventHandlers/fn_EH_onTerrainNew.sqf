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

//Set up entity counter in status bar according to preferences
"init" call Enh_fnc_statusbar_entityCounter;
"run" call Enh_fnc_statusbar_entityCounter;

//Enable 3den Radio
'ONLOAD' call Enh_fnc_3denRadio_toggleRadio;

//Enable session timer
[] spawn Enh_fnc_sessionTimer;

//Update location list
call Enh_fnc_locationList;

//Show github message
call Enh_fnc_gitHubNotification;

true