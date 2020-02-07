/*
   Author: R3vo

   Date: 2019-08-20

   Description:
   Logs grid positions to clipboard.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

private _posArray = [];
private _export = "";
private _selection = [["Object","Logic","Trigger","Marker","Waypoint"]] call ENH_fnc_all3DENSelected;

if (_selection isEqualTo []) then 
{
   (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") params ["_pos3D"];
   
   _posArray pushBack mapGridPosition _pos3D;
}
else
{
   {
      _posArray pushBackUnique mapGridPosition ((_x get3DENAttribute "Position") # 0);
   } forEach _selection;
};

private _export = [_posArray,false] call ENH_fnc_exportWithLB;

copyToClipboard _export;

["ENH_DataCopied"] call BIS_fnc_3DENNotification;

true