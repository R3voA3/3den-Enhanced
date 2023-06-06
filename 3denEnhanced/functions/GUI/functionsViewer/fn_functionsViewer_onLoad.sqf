/*
  Author: R3vo

  Description:
  Used by the ENH_FunctionViewer GUI. Called on load.

  Parameter(s):
  0: DISPLAY - Display

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

disableSerialization;
params ["_display"];

uiNamespace setVariable ["ENH_Display_FunctionsViewer", _display];

ENH_FunctionsData = call ENH_fnc_functionsViewer_getFunctionsData;

_display displayAddEventHandler ["keyDown", //Focus Search
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 33 && _ctrl && !_shift) then
  {
    ctrlSetFocus CTRL(IDC_FUNCTIONSVIEWER_SEARCH);
  }
}];

_display displayAddEventHandler ["keyDown", //Focus Search Key
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 33 && _ctrl && _shift) then
  {
    ctrlSetFocus CTRL(IDC_FUNCTIONSVIEWER_SEARCHCODE);
  }
}];

call ENH_fnc_functionsViewer_fillCtrlTV;