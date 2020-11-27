/*
  Author: R3vo

  Date: 2020-01-16

  Description:
  Removes an entry from listBox. Saves list to profileNamespace.

  Parameter(s):
  0: STRING - Action to be taken

  Returns:
  -
*/

params ["_ctrlLnB","_key"];

if (_key isEqualTo 211) then
{
  _ctrlLnB lnbDeleteRow lnbCurSelRow _ctrlLnB;

  //Update list
  _ctrlLnB call ENH_fnc_3DENCam_saveList;
};