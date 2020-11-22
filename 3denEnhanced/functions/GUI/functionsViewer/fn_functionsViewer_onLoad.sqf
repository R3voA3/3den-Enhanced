/*
  Author: Revo

  Description:
  Used by the ENH_FunctionViewer GUI. Called on load.

  Parameter(s):
  0: DISPLAY - Display

  Returns:
  BOOLEAN: true
*/

disableSerialization;

params ["_display"];

ENH_FunctionsData = call ENH_fnc_functionsViewer_getFunctionsData;

_display displayAddEventHandler ["keyDown",//Focus Search
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 33 && _ctrl && !_shift) then
  {
    ctrlSetFocus (_display displayCtrl 1400);
  }
}];

_display displayAddEventHandler ["keyDown",//Copy
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 45 && _ctrl) then
  {
    (_display displayCtrl 1602) call ENH_fnc_functionsViewer_copy;
  }
}];

_display displayAddEventHandler ["keyDown",//Focus Search Key
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 33 && _ctrl && _shift) then
  {
    ctrlSetFocus (_display displayCtrl 2000);
  }
}];

//Set filters to last used or default value
(_display displayCtrl 1700) lbSetCurSel (profileNamespace getVariable ["ENH_FunctionsViewer_ConfigIndex",0]);
(_display displayCtrl 1800) lbSetCurSel (profileNamespace getVariable ["ENH_FunctionsViewer_ModeIndex",0]);
(_display displayCtrl 2200) lbSetCurSel (profileNamespace getVariable ["ENH_FunctionsViewer_LoadFileIndex",0]);

//Set up tree view
(_display displayCtrl 1500) call ENH_fnc_FunctionsViewer_fillCtrlTV;

true