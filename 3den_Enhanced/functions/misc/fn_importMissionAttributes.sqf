/*
   Author: Revo

   Description:
   Imports mission attributes from clipboard. The attributes need to be exported by Enh_fnc_exportMissionAttributes.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

set3DENMissionAttributes call compile copyFromClipboard;

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true