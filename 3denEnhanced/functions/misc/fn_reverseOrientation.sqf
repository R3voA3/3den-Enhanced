/*
   Author: Revo

   Description:
   Reverse direction of all selected objects.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

if (!is3DEN) exitWith {false};

private _entities = [["Object","Logic","Trigger","Marker"]] call ENH_fnc_all3denSelected;

if (_entities isEqualTo []) exitWith
{
	["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
	false
};
systemChat format ["Entities: %1",_entities];
collect3DENHistory
{
   {
      private _dir = (_x get3DENAttribute "Rotation") # 0;
      _dir set [2,(_dir # 2) + 180];
      _x set3DENAttribute ["rotation",_dir];
   } forEach _entities;
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true