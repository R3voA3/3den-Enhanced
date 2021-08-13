/*
  Author: R3vo

  Date: 2021-06-11

  Description:
  Removes all factions from asset browser that were blacklisted.

  Parameter(s):
  -

  Returns:
  -
*/

disableSerialization;
private _blacklist = profileNamespace getVariable ["ENH_AssetBrowser_Blacklist", []];
if (_blacklist isEqualTo []) exitWith {};

{
  private _ctrlTree = findDisplay 313 displayCtrl _x;

  for "_j" from ((_ctrlTree tvCount []) - 1) to 0 step -1 do
  {
    private _faction = _ctrlTree tvData [_j];
    if !(_faction in _blacklist) then {continue};
    _ctrlTree tvDelete [_j];
  };
} forEach [61, 62, 63, 64, 56, 57, 58, 59];