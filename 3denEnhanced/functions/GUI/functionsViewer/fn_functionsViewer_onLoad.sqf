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

//Handle search button
CTRL(IDC_FUNCTIONSVIEWER_SEARCH) ctrlAddEventHandler ["EditChanged",
{
  params ["_ctrlEdit", "_newText"];

  private _image = [IMG_SEARCH_END, IMG_SEARCH_START] select (_newText == "");

  ctrlParent _ctrlEdit displayCtrl IDC_FUNCTIONSVIEWER_BUTTONSEARCH ctrlSetText _image;
  call ENH_fnc_3DENRadio_searchList;
}];

//Handle search button
CTRL(IDC_FUNCTIONSVIEWER_BUTTONSEARCH) ctrlAddEventHandler ["ButtonClick",
{
  params ["_ctrlButton"];

  //Change search button icon and clear edit control to reset tree view filter
  ctrlParent _ctrlButton displayCtrl IDC_FUNCTIONSVIEWER_SEARCH ctrlSetText "";
  _ctrlButton ctrlSetText IMG_SEARCH_START;
}];