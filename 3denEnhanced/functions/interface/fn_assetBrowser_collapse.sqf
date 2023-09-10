/*
  Author: R3vo

  Date: 2020-02-20

  Description:
  Called onTerrainNew. Collapes all tree views of the asset browser

  Parameter(s):
  -

  Returns:
  -
*/

if !("Preferences" get3DENMissionAttribute "ENH_CollapseAssetBrowser") exitWith {};

disableSerialization;

private _fnc_collapse =
{
  private _path = _this;
  if (count _path > 0) then
  {
    _ctrlTree tvCollapse _path;
  };
  for "_i" from 0 to (_ctrlTree tvCount _path) do
  {
    (_path + [_i]) call _fnc_collapse;
  };
};

{
  private _ctrlTree = findDisplay 313 displayCtrl _x;
  [] call _fnc_collapse;
} foreach [61, 62, 63, 64, 56, 57, 58, 59];