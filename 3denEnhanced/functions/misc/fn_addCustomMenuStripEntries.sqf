/*
  Author: R3vo

  Date: 2020-11-21

  Description:
  Adds custom menu strip entries created with the GUI. Is executed onTerrainNew.

  Parameter(s):
  -

  Returns:
  -
*/

disableSerialization;

private _ctrlMenuStrip = findDisplay 313 displayCtrl 120;

//Prevent it from running twice by comparing existing entries with the once that should be added
private _defaultEntries = [];
for "_i" from 0 to ((_ctrlMenuStrip menuSize []) - 1) do
{
  _defaultEntries pushBack (_ctrlMenuStrip menuText [_i]);
};

{
  parseSimpleArray _x params ["_text","_weblink","_picture","_action","_path","_ctrl","_alt","_shift","_key"];

  //Compare _text of entries with with path [] with default entries. If they already exist then exit
  if (_text in _defaultEntries && (count _path == 0)) exitWith {};

  //Check how many entries are already there and set first index of custom ones to that number - 1
  private _numExistingEntries = _ctrlMenuStrip menuSize [];
  if (count _path > 0) then {_path set [0,_numExistingEntries - 1]};

  private _index = _ctrlMenuStrip menuAdd [_path,_text];
  _ctrlMenuStrip menuSetURL [_path + [_index],_weblink];
  _ctrlMenuStrip menuSetPicture [_path + [_index],_picture];
  _ctrlMenuStrip menuSetAction [_path + [_index],_action];

  private _shortcut = 0;
  if (_ctrl) then {_shortcut = 512};
  if (_alt) then {_shortcut = _shortcut + 2048};
  if (_shift) then {_shortcut = _shortcut + 1024};

  _ctrlMenuStrip menuSetShortcut [_path + [_index],_shortcut + call compile _key];

} forEach (profileNamespace getVariable ["ENH_CustomMenuStrip_Data",[]]);