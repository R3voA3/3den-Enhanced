/*
  Author: R3vo

  Date: 2023-06-01

  Description:
  Opens all ENH displays to check for missing ; or translations.

  Parameter(s):
  -

  Returns:
  -
*/

if (!is3DEN) exitWith {};

[] spawn
{
  _ENHClasses = "'ENH_' in configName _x" configClasses configFile apply {configName _x};
  _ENHClasses = _ENHClasses select {getNumber (configFile >> _x >> "idd") != 0};

  {
    private _display = findDisplay 313 createDisplay _x;
    waitUntil {!isNull _display};

    sleep 0.1;

    _display closeDisplay 0;

  } forEach _ENHClasses;
};