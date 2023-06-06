/*
  Author: R3vo

  Date: 2021-06-17

  Description:
  Used to create object or marker with given classname. Used in the ENH_SpawnObject GUI.

  Parameter(s):
  0: CONTROL - Button

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

disableSerialization;

params ["_ctrlButton"];

//Get mode
private _modeID = lbCurSel (ctrlParent _ctrlButton displayCtrl IDC_CREATEOBJECT_MODE);
private _modeStr = ["object", "marker"] select _modeID;

//Get selected index
private _ctrlListbox = ctrlParent _ctrlButton displayCtrl IDC_CREATEOBJECT_LIST;
private _selectedRow = lbCurSel _ctrlListbox;

//Warning if nothing is selected
if (_selectedRow == -1) then
{
  (ctrlParent _ctrlButton displayCtrl IDC_CREATEOBJECT_LIST) spawn
  {
    disableSerialization;
    private _ctrlHighlight = [_this, 5] call BIS_fnc_highlightControl;
    sleep 2;
    ctrlDelete _ctrlHighlight;
  };
}
else
//Create object
{
  create3DENEntity [_modeStr, _ctrlListbox lbText _selectedRow, screenToWorld [0.5, 0.5], true];
  if (_modeStr == "marker" && (get3DENActionState "ToggleMap" == 0)) then {do3DENAction "ToggleMap"};
  if (_modeStr == "object" && (get3DENActionState "ToggleMap" == 1)) then {do3DENAction "ToggleMap"};

  move3DENCamera [screenToWorld [0.5, 0.5], true];
};