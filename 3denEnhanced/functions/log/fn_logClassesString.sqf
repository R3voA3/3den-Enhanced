/*
   Author: R3vo

   Date: 2019-08-26

   Description:
   Logs unique classes of selected eden entities to clipboard. Class names are strings "className".

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

private _classes = [];
private _export = "";
private _selection = [["Object","Logic","Trigger","Marker"]] call ENH_fnc_all3DENSelected;

{
	_classes pushBackUnique typeOf _x;
} forEach _selection;

private _export = [_classes,false] call ENH_fnc_exportWithLB;

copyToClipboard _export;

["ENH_DataCopied"] call BIS_fnc_3DENNotification;

true