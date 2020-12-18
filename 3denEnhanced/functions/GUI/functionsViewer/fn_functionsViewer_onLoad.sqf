/*
  Author: R3vo

  Description:
  Used by the ENH_FunctionViewer GUI. Called on load.

  Parameter(s):
  0: DISPLAY - Display

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_display"];

ENH_FunctionsData = call ENH_fnc_functionsViewer_getFunctionsData;

_display displayAddEventHandler ["keyDown",//Focus Search
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 33 && _ctrl && !_shift) then
  {
    ctrlSetFocus CTRL(IDC_FUNCTIONSVIEWER_SEARCH);
  }
}];

_display displayAddEventHandler ["keyDown",//Copy
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 45 && _ctrl) then
  {
    CTRL(IDC_FUNCTIONSVIEWER_COPY) call ENH_fnc_functionsViewer_copy;
  }
}];

_display displayAddEventHandler ["keyDown",//Focus Search Key
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 33 && _ctrl && _shift) then
  {
    ctrlSetFocus CTRL(IDC_FUNCTIONSVIEWER_SEARCHCODE);
  }
}];

//Set filters to last used or default value
CTRL(IDC_FUNCTIONSVIEWER_FILTERCONFIG) lbSetCurSel (profileNamespace getVariable ["ENH_FunctionsViewer_ConfigIndex",0]);
CTRL(IDC_FUNCTIONSVIEWER_FILTERMODE) lbSetCurSel (profileNamespace getVariable ["ENH_FunctionsViewer_ModeIndex",0]);
CTRL(IDC_FUNCTIONSVIEWER_LOADMODE) lbSetCurSel (profileNamespace getVariable ["ENH_FunctionsViewer_LoadFileIndex",0]);

//Set up tree view
CTRL(IDC_FUNCTIONSVIEWER_LIST) call ENH_fnc_FunctionsViewer_fillCtrlTV;