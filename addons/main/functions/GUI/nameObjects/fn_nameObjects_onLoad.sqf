/*
  Author: R3vo

  Date: 2020-11-10

  Description:
  Is called when ENH_NameObjects GUI is loaded.

  Parameter(s):
  0: DISPLAY

  Returns:
  -
*/

#include "\x\enh\addons\main\script_component.hpp"

disableSerialization;
params ['_display'];

if !(is3DEN) exitWith {};

if (([["Object", "Logic", "Trigger", "Marker"]] call ENH_fnc_all3DENSelected) isEqualTo []) exitWith
{
  ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
  _display closeDisplay 1;
  false
};

CTRL(IDC_NAMEOBJECTS_VARIABLENAME) ctrlSetText (profileNamespace getVariable ['ENH_NameObjects_LastVarName', profileName]);