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
waitUntil {isNil "Enh_EH_drawDist" && isNil "Enh_measureDist_markers"};

if (isNil "Enh_pos_1") then
{
   Enh_pos_1 = (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") # 0;
   [localize "STR_ENH_measureDistance_select2ndPoint"] call BIS_fnc_3DENNotification;
}
else
{
   //Measure distance and display 3D line
   Enh_pos_2 = (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") # 0;
   private _dist3D = Enh_pos_1 distance Enh_pos_2;
   private _dist2D = Enh_pos_1 distance2D Enh_pos_2;
   private _travelTime = _dist3D / (14.15 * 1000) * 60;//14.15 is the average speed of a soldier (km/h)

   //Display information
   [
      format
      [
         localize "STR_ENH_measureDistance_data",
         round _dist2D,
         round _dist3D,
         ceil _travelTime
      ],
      0,
      20
   ] call BIS_fnc_3DENNotification;

   if ((get3DENActionState "toggleMap" == 1)) then
   {
     Enh_measureDist_markers = [Enh_pos_1,Enh_pos_2,50] call BIS_fnc_markerPath;
     sleep 5;
     {deleteMarker _x} forEach Enh_measureDist_markers;
     Enh_measureDist_markers = nil;
   }
   else
   {
      Enh_EH_drawDist = addMissionEventHandler ["Draw3D",
      {
         drawLine3D [ASLToAGL Enh_pos_1,ASLToAGL Enh_pos_2,[1,0,0,1]];
      }];
      sleep 5;
      removeMissionEventHandler ["Draw3D",Enh_EH_drawDist];
      Enh_EH_drawDist = niL;
   };

   Enh_pos_1 = nil;
   Enh_pos_2 = nil;
};

true
