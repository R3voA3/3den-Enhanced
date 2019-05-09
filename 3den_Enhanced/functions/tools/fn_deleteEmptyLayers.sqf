/*
   Author: Revo

   Description:
   Deletes all empty layers and creates a history entry.

   Parameter(s):
   -

   Returns:
   BOOLEAN - true
*/

collect3DENHistory
{
	{
 		if (count (get3DENLayerEntities _x) == 0) then
	    {
	     remove3DENLayer _x;
	    };
	} forEach (all3DENEntities # 6);
};

disableSerialization;
["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true