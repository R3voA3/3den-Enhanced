/*
  Author: R3vo

  Date: 2020-12-25

  Description:
  Used by the Menu Strip Blacklist Eden Editor attribute. Can be used to blacklist entries which are then removed when the
  editor is opened.

  Parameter(s):
  0: CONTROL - Controls group

  Returns:
  -
*/

#include "\x\enh\addons\main\script_component.hpp"

disableSerialization;

params ["_ctrlGroup"];

private _ctrlLB = _ctrlGroup controlsGroupCtrl 100;
private _row = 0;
private _data = profileNamespace getVariable ["ENH_MenuStrip_Blacklist", []];
private _added = [];
{
  private _key = getTextRaw (_x >> "text") trim ["$", 1];
  private _children = getArray (_x >> "items");
  if !(_key in _added) then
  {
    _key = getTextRaw (_x >> "text") trim ["$", 1];
    _row = _ctrlLB lbAdd (localize _key);
    _ctrlLB lbSetPictureRight [_row, [TEX_CHECKED, TEX_UNCHECKED] select (_key in _data)];
    _ctrlLB lbSetData [_row, _key];
    _added append [_key];
    if (_children isNotEqualTo []) then
    {
      {
        if (_x == "Separator") then {continue};
        _key = getTextRaw (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items" >> _x >> "text") trim ["$", 1];
        _row = _ctrlLB lbAdd ("         " + localize _key);
        _ctrlLB lbSetPictureRight [_row, [TEX_CHECKED, TEX_UNCHECKED] select (_key in _data)];
        _ctrlLB lbSetData [_row, _key];
        _added append [_key];
      } forEach _children;
    };
  };
} forEach (configProperties [(configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items"), "'ENH' in configName _x"]);

//Update blacklist when selection is changed
_ctrlLB ctrlAddEventHandler ["LBSelChanged",
{
  params ["_ctrlLB", "_row"];
  private _blacklist = profileNamespace getVariable ["ENH_MenuStrip_Blacklist", []];
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
  profileNamespace setVariable ["ENH_MenuStrip_Blacklist", _blacklist];
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
  profileNamespace setVariable ["ENH_MenuStrip_Blacklist", []];
}];