/*
  Author: R3vo

  Date: 2020-10-15

  Description:
  Exports all ENH menustrip actions in markdown format for the Github 3den Enhanced wiki to the clipboard. Supports two levels.

  Parameter(s):
  -

  Returns:
  -
*/

private _menuStipEntries = "configName _x select [0, 3] == 'ENH'" configClasses (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items");
private _export = format ["_**Number of added entries: %1**_", count _menuStipEntries] + endl + "___" + endl + endl + endl;

_allEntries = [];
{
  if !(getArray (_x >> "items") isEqualTo []) then
  {//Main
    private _folderName = getText (_x >> "text");
    private _folder = [_folderName];
    private _folderItems = [];
    { //_folder
      if !("ENH_" in _x) then {continue};
      private _cfg = configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items" >> _x;
      private _text = getText (_cfg >> "text");
      private _action = getText (_cfg >> "action");
      private _link = getText (_cfg >> "weblink");
      _folderItems pushBack [_text, _action, _link];
    } forEach (getArray (_x >> "items"));
    _folder pushBack _folderItems;
    _folderItems sort true;
    _allEntries pushBack _folder;
  };
} forEach _menuStipEntries;

_allEntries sort true;

{
  _x params ["_folderName", "_items"];
  _export = _export + "# " + _folderName + endl + endl;
  {
    _x params ["_name", "_action", "_weblink"];
    if (_action == "") then
    {
      _export = _export + "## " + _name + endl + "Description: " + "*TBD*" + endl + endl + "Weblink: " + _weblink + endl + endl;
    }
    else
    {
      _export = _export + "## " + _name + endl + "Description: " + "*TBD*" + endl + endl + "Action: " + "```" + _action + "```" + endl + endl;
    };
  } forEach _items;
} forEach _allEntries;

uinamespace setVariable ["display3DENCopy_data", ["Menu Strip Documentation", _export]];
findDisplay 313 createDisplay "display3denCopy";