/*
  Author: R3vo

  Date: 2022-04-11

  Description:
  Moves selected entities into selected layer.

  Parameter(s):
  0: CONTROL - Button control

  Returns:
  BOOLEAN
*/

params ["_ctrlButton"];

private _ctrlListBox = ctrlParent _ctrlButton displayCtrl 100;

if (lbCurSel _ctrlListBox == -1) exitWith {false};

private _layerID = _ctrlListBox lbValue (lbCurSel _ctrlListbox);

collect3DENHistory
{
  {
    _x set3DENLayer _layerID;
  } forEach ([] call ENH_fnc_all3DENSelected);
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true