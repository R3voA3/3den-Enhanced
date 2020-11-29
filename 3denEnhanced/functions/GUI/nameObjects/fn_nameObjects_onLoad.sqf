/*
  Author: R3vo

  Date: 2020-11-10

  Description:
  Is called when ENH_NameObjects GUI is loaded.

  Parameter(s):
  0: DISPLAY

  Returns:
  BOOLEAN: true, false if executed outside of Eden Editor
*/

params ['_display'];

if !(is3DEN) exitWith {false};

if (([["Object","Logic","Trigger","Marker"]] call ENH_fnc_all3DENSelected) isEqualTo []) exitWith
{
  ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
  _display closeDisplay 1;
  false
};

CTRL(IDC_NAMEOBJECTS_VARIABLENAME) ctrlSetText (profileNamespace getVariable ['ENH_NameObjects_LastVarName',profileName]);

true