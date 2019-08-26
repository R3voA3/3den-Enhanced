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
private _selection = call Enh_fnc_all3DENSelected;

{
   _posArray pushBackUnique mapGridPosition ((_x get3DENAttribute "Position") # 0);
} forEach _selection;

private _export = [_posArray,false] call Enh_fnc_exportWithLB;

copyToClipboard _export;

["Enh_DataCopied"] call BIS_fnc_3DENNotification;

true