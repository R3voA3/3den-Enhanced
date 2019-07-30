/*
   Author: Revo

   Description:
   Puts all selected Eden entities into one array for easy access. DOES NOT RETURN GROUPS!

   Parameter(s):
   -

   Returns:
   ARRAY - List of selected entities
*/

get3DENSelected "Object" /* + get3DENSelected "Group" */ + get3DENSelected "Trigger" + get3DENSelected "Logic" + get3DENSelected "Waypoint" + get3DENSelected "Marker"


/*
   Author: Revo

   Description:
   Puts all selected Eden entities into one array for easy access. DOES NOT RETURN GROUPS!

   Parameter(s):
   0: ARRAY - Array filled with one or more strings. Strings can be:

   "object"
   "trigger"
   "logic"
   "waypoint"
   "marker"
   "layer"
   "comment"
   "" - all types except "layer", "comment" and "group"

   Returns:
   ARRAY - List of selected entities
*/
/*
params [["_types",[""],[]]]; 
 
private _return = [];
 
{ 
   _return = _return + get3DENSelected _x; 
} forEach _types; 

//Substract groups and return array 
_return - get3DENSelected "Group"