/*
   Author: Revo

   Description:
   Logs position 3D of all selected entities and copies them to the clipboard. Array is shuffled.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

private _posArray = [];
private _export = "";
private _selection = call Enh_fnc_all3DENSelected;

{
   _posArray pushBack ((_x get3DENAttribute "Position") # 0);
} forEach _selection;

private _export = [_posArray,false] call Enh_fnc_exportWithLB;

copyToClipboard _export;

["Enh_DataCopied"] call BIS_fnc_3DENNotification;

true