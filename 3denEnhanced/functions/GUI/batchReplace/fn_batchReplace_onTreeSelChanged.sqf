/*
  Author: R3vo

  Date: 2021-04-05

  Description:
  Creates the ENH_BatchReplace GUI if objects are selected, if not it shows an error message.

  Parameter(s):
  0: CONTROL - Tree View
  1: ARRAY - Selected path

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;

params ["_ctrlTV", "_selectionPath"];

if (count _selectionPath < 2) exitWith {};

private _ctrlReplaceWith = ctrlParent _ctrlTV displayCtrl IDC_BATCHREPLACE_REPLACEWITH;
private _replaceWith = ctrlText _ctrlReplaceWith;
private _replaceWith = ctrlText _ctrlReplaceWith + " " + (_ctrlTV tvData _selectionPath);

//Format everything nicely
_ctrlReplaceWith ctrlSetText (_replaceWith splitString " ,;" joinString ", ");