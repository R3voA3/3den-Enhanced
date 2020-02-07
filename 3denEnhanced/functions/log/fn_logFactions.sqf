/*
   Author: R3vo

   Date: 2019-08-20

   Description:
   Logs faction class names of selected objects to clipboard.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

private _selection = get3DENSelected "object";
private _factions = [];

{
   _factions pushBackUnique faction _x;
} forEach _selection;

private _export = [_factions,false] call ENH_fnc_exportWithLB;

copyToClipboard _export;

["ENH_DataCopied"] call BIS_fnc_3DENNotification;

true
