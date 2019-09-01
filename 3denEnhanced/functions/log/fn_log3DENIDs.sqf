/*
   Author: Revo

   Description:
   Logs 3DEN IDs of selected objects to clipboard

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

private _selection = [["Object","Logic","Trigger","Marker"]] call Enh_fnc_all3DENSelected;

private _IDs = _selection apply {get3DENEntityID _x};
private _export = [_IDs,false] call Enh_fnc_exportWithLB;

copyToClipboard _export;

['Enh_DataCopied'] call BIS_fnc_3DENNotification;

true