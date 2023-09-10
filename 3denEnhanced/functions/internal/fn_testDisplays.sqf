/*
  Author: R3vo

  Date: 2023-06-01

  Description:
  Opens all ENH displays to check for missing ;, translations or UI sizes.

  Parameter(s):
  -

  Returns:
  -
*/

if (!is3DEN) exitWith {};

[] spawn
{
  private _ENHClasses = "'ENH_' in configName _x && getNumber (_x >> 'IDD') != 0" configClasses configFile apply {configName _x};

  {
    private _display = findDisplay 313 createDisplay _x;
    waitUntil {!isNull _display};

    sleep 0.5;

    _display closeDisplay 0;

  } forEach _ENHClasses;
};