/*
   Author: Revo

   Description:
   Puts all selected Eden entities into one array for easy access. DOES NOT RETURN GROUPS!

   Parameter(s):
   -

   Returns:
   ARRAY - List of selected objects
*/

get3DENSelected "Object" /* + get3DENSelected "Group" */ + get3DENSelected "Trigger" + get3DENSelected "Logic" + get3DENSelected "Waypoint" + get3DENSelected "Marker"