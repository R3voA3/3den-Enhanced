/*
   Author: Revo

   Description:
   Counts all selected 3DEN entities and updates statusbar accordingly.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

disableSerialization;
_display = findDisplay 313;

(_display displayCtrl 674) ctrlSetText (str count get3DENSelected "Object");
(_display displayCtrl 673) ctrlSetText (str count get3DENSelected "Group");
(_display displayCtrl 672) ctrlSetText (str count get3DENSelected "Trigger");
(_display displayCtrl 671) ctrlSetText (str count get3DENSelected "Waypoint");
(_display displayCtrl 670) ctrlSetText (str count get3DENSelected "Logic");
(_display displayCtrl 669) ctrlSetText (str count get3DENSelected "Marker");

true