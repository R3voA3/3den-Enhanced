/*
   Author: Revo

   Description:
   Deletes all empty layers and creates a history entry.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

collect3DENHistory
{
   {
      if ((get3DENLayerEntities _x) isEqualTo []) then
      {
         remove3DENLayer _x;
      };
   } forEach (all3DENEntities # 6);
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true