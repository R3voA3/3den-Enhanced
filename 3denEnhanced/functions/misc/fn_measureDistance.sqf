/*
   Author: Revo

   Description:
   Measures the distance between two positions.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

disableSerialization;//For BIS_fnc_3DENNotification

//Make sure the old EH was deleted
waitUntil {isNil "ENH_EH_drawDist" && isNil "ENH_measureDist_markers"};

if (isNil "ENH_pos_1") then
{
   ENH_pos_1 = (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") # 0;
   [localize "STR_ENH_MEASUREDISTANCE_SELECT2NDPOINT"] call BIS_fnc_3DENNotification;
}
else
{
   //Measure distance and display 3D line
   ENH_pos_2 = (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") # 0;
   private _dist3D = ENH_pos_1 distance ENH_pos_2;
   private _dist2D = ENH_pos_1 distance2D ENH_pos_2;
   private _travelTime = _dist3D / (14.15 * 1000) * 60;//14.15 is the average speed of a soldier (km/h)

   //Display information
   [
      format
      [
         localize "STR_ENH_MEASUREDISTANCE_DATA",
         round _dist2D,
         round _dist3D,
         ceil _travelTime
      ],
      0,
      20
   ] call BIS_fnc_3DENNotification;

   if ((get3DENActionState "toggleMap" == 1)) then
   {
     ENH_measureDist_markers = [ENH_pos_1,ENH_pos_2,50] call BIS_fnc_markerPath;
     sleep 5;
     {deleteMarker _x} forEach ENH_measureDist_markers;
     ENH_measureDist_markers = nil;
   }
   else
   {
      ENH_EH_drawDist = addMissionEventHandler ["Draw3D",
      {
         drawLine3D [ASLToAGL ENH_pos_1,ASLToAGL ENH_pos_2,[1,0,0,1]];
      }];
      sleep 5;
      removeMissionEventHandler ["Draw3D",ENH_EH_drawDist];
      ENH_EH_drawDist = niL;
   };

   ENH_pos_1 = nil;
   ENH_pos_2 = nil;
};

true