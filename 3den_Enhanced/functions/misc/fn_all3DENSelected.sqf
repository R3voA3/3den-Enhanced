/*
   Author: Revo

   Description:
   Puts all selected Eden entities into one array for easy access.

   Parameter(s):
   -
   Returns:
   ARRAY - List of selected objects
*/

private _o = get3DENSelected "Object";
private _g = get3DENSelected "Group";
private _t = get3DENSelected "Trigger";
private _l = get3DENSelected "Logic";
private _w = get3DENSelected "Waypoint";
private _m = get3DENSelected "Marker";

 _o + _g + _t + _l + _w + _m