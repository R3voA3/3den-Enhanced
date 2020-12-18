/*
  Author: R3vo

  Description:
  Used by the ENH_TexturFinder GUI. Exports path of selected lb entry by pressing CTRL + C.

  Parameter(s):
  -

  Returns:
  -
*/

disableSerialization;
params ["_ctrlTV","_key","","_ctrl"];

if (_key isEqualTo 46 && _ctrl) then
{
  private _path = _ctrlTV tvText (tvCurSel _ctrlTV);
  if (_path isEqualTo "") exitWith {false};
  copyToClipboard str _path;
  ["ENH_DataCopied"] call BIS_fnc_3DENNotification;
};