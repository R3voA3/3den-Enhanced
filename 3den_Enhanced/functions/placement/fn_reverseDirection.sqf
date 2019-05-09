/*
   Author: Revo

   Description:
   Reverse direction of all selected objects.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true / false
*/

private _objects  = get3DENSelected "Object";
private _markers  = get3DENSelected "Marker";
private _triggers = get3DENSelected "Trigger";
private _logics   = get3DENSelected "Logic";

private _entities = _objects + _markers + _triggers + _logics;

if (count _entities == 0) exitWith {false};

collect3DENHistory
{
   {
      private _dir = (_x get3DENAttribute "Rotation") # 0;
      _dir set [2,(_dir # 2) + 180];
      _x set3DENAttribute ["rotation",_dir];
   } forEach _entities;
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true

