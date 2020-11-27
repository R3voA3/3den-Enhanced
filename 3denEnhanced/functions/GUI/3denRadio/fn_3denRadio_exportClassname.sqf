/*
  Author: Revo

  Description:
  Exports classname of selected song and copies it to the clipboard.

  Parameter(s):
  -

  Returns:
  -
*/

disableSerialization;

params ["_ctrlLNB","_key","","_mod"];

if (_key isEqualTo 46 && _mod) then //CTRL + C
{
  private _class = _ctrlLNB lnbData [lnbCurSelRow _ctrlLNB,0];
  if (_class isEqualTo "") then
  {
    _class = _ctrlLNB lbData (lbCurSel _ctrlLNB);
  };
  copyToClipboard str _class;
  ["ENH_DataCopied"] call BIS_fnc_3DENNotification;
};