/*
  Author: R3vo

  Date: 2023-06-01

  Description:
  Opens all ENH displays to check for missing ;, translations or UI sizes.

  Parameter(s):
  0: ARRAY - Blacklisted display classnames, optional, default ["ENH_TextureFinder"] as it takes long to load
  1: NUMBER - Time each display is shown, optional, default 0.5

  Returns:
  -
*/

if (!is3DEN) exitWith {};

_this spawn
{
  params [["_blacklist", ["ENH_TextureFinder"], [""]], [["_delay", 0.5, [0]]]];

  private _ENHClasses = "'ENH_' in configName _x && getNumber (_x >> 'IDD') != 0" configClasses configFile apply {configName _x};

  {
    if (_x in _blacklist) then {continue};
    private _display = findDisplay 313 createDisplay _x;
    waitUntil {!isNull _display};

    sleep 0.5;

    _display closeDisplay 0;

  } forEach _ENHClasses;
};