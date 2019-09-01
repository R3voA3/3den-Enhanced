/*
   Author: Revo

   Description:
   Puts all selected Eden entities into one array for easy access.

   Parameter(s):
   0: ARRAY - Array of strings. Entities types to return. For possible values see https://community.bistudio.com/wiki/get3DENSelected
   Default [""]

   Returns:
   ARRAY - List of selected entities
*/

params [["_whiteList",["Object","Logic","Trigger","Marker"],[[]]]];
private _return = [];

{
   _return = _return + get3DENSelected _x;
} forEach _whiteList;

_return