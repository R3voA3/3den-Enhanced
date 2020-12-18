/*
  Author: R3vo

  Description:
  Used by ENH_actionCreator GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

params ["_display"];

private _save = profileNamespace getVariable ["ENH_ActionCreator_LastUsed",[]];

if !(_save isEqualTo []) then
{
  CTRL(IDC_ACTIONCREATOR_TITLE) ctrlSetText _save # 0;
  CTRL(IDC_ACTIONCREATOR_SCRIPT) ctrlSetText _save # 1;
  CTRL(IDC_ACTIONCREATOR_ARGUMENTS) ctrlSetText _save # 2;
  CTRL(IDC_ACTIONCREATOR_PRIORITY) ctrlSetText _save # 3;
  CTRL(IDC_ACTIONCREATOR_TOOLBOX) ctrlSetChecked [1,_save # 4];
  CTRL(IDC_ACTIONCREATOR_TOOLBOX) ctrlSetChecked [2,_save # 5];
  CTRL(IDC_ACTIONCREATOR_SHORTCUT) ctrlSetText _save # 6;
  CTRL(IDC_ACTIONCREATOR_CONDITION) ctrlSetText _save # 7;
  CTRL(IDC_ACTIONCREATOR_RADIUS) ctrlSetText _save # 8;
  CTRL(IDC_ACTIONCREATOR_TOOLBOX) ctrlSetChecked [0,_save # 9];
  CTRL(IDC_ACTIONCREATOR_SELECTION) ctrlSetText _save # 10;
  CTRL(IDC_ACTIONCREATOR_MEMORYPOINT) ctrlSetText _save # 11;
};