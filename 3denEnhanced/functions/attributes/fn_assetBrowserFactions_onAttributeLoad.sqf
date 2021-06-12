/*
  Author: R3vo

  Date: 2020-12-25

  Description:
  Used by the Asset Browser Factions Eden Editor attribute. Unchecked factions will be removed from the Asset Browser.

  Parameter(s):
  0: CONTROL - Controls group

  Returns:
  -
*/

#include "\a3\ui_f\hpp\definedikcodes.inc"
#define TEX_CHECKED "\a3\3DEN\Data\Controls\ctrlCheckbox\textureChecked_ca.paa"
#define TEX_UNCHECKED "\a3\3DEN\Data\Controls\ctrlCheckbox\textureUnchecked_ca.paa"

disableSerialization;

params ["_ctrlGroup"];

//Gather all factions and their data
_factions = [];

{
  _factions pushBackUnique [configName _x, getText (_x >> "displayName"), getNumber (_x >> "side")];
} forEach ("getNumber (_x >> 'side') in [0, 1, 2, 3]" configClasses (configFile >> "CfgFactionClasses"));

{
  if !(getNumber (_x >> "side") in [0, 1, 2, 3]) then {continue};
  private _sideID = getNumber (_x >> "side");
  {
    _factions pushBackUnique [configName _x, getText (_x >> "name"), _sideID];
  } forEach ("true" configClasses (configFile >> "CfgGroups" >> configname _x))
} forEach ("true" configClasses (configFile >> "CfgGroups"));

private _ctrlLB = _ctrlGroup controlsGroupCtrl 100;
private _data = profileNamespace getVariable ["ENH_AssetBrowser_Blacklist", []];
{
  _x params ["_configName", "_displayName", "_sideID"];
  private _row = _ctrlLB lbAdd _displayName;
  _ctrlLB lbSetData [_row, _configName];
  _ctrlLB lbSetValue [_row, _sideID];//remove later
  _ctrlLB lbSetPictureRight [_row, [TEX_CHECKED, TEX_UNCHECKED] select (_configName in _data)];
  _ctrlLB lbSetTextRight [_row, _sideID call BIS_fnc_sideName];
  _ctrlLB lbSetTooltip [_row, _configName];
} forEach _factions;

lbSortByValue _ctrlLB;

//_ctrlLB lbSortBy ["TEXT", false, false, true];
systemChat "Implement lbSortBy when availabe";

//Update blacklist when selection is changed
_ctrlLB ctrlAddEventHandler ["LBSelChanged",
{
  params ["_ctrlLB", "_row"];
  private _blacklist = profileNamespace getVariable ["ENH_AssetBrowser_Blacklist", []];
  private _data = _ctrlLB lbData _row;

  if (_data in _blacklist) then
  {
    _blacklist = _blacklist - [_data];
  }
  else
  {
    _blacklist append [_data];
  };
  _ctrlLB lbSetPictureRight [_row, [TEX_CHECKED, TEX_UNCHECKED] select (_data in _blacklist)];
  profileNamespace setVariable ["ENH_AssetBrowser_Blacklist", _blacklist];
}];

//Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["buttonClick",
{
  private _ctrlGroup = ctrlParentControlsGroup (_this select 0);
  private _ctrlLB = _ctrlGroup controlsGroupCtrl 100;

  for "_row" from 0 to (lbSize _ctrlLB - 1) do
  {
    _ctrlLB lbSetPictureRight [_row, TEX_CHECKED];
  };
  profileNamespace setVariable ["ENH_AssetBrowser_Blacklist", []];
}];