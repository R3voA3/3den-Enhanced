/*
  Author: Revo

  Description:
  Used by ENH_actionCreator GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

private _display = findDisplay IDD_ACTIONCREATOR;
private _title = ctrlText CTRL(IDC_ACTIONCREATOR_TITLE);
private _script = ctrlText CTRL(IDC_ACTIONCREATOR_SCRIPT);
private _args = ctrlText CTRL(IDC_ACTIONCREATOR_ARGUMENTS);
private _priority = ctrlText CTRL(IDC_ACTIONCREATOR_PRIORITY);
private _window = CTRL(IDC_ACTIONCREATOR_TOOLBOX) ctrlChecked 1;
private _hide = CTRL(IDC_ACTIONCREATOR_TOOLBOX) ctrlChecked 2;
private _shortcuts = ctrlText CTRL(IDC_ACTIONCREATOR_SHORTCUT);
private _condition = ctrlText CTRL(IDC_ACTIONCREATOR_CONDITION);
private _r = ctrlText CTRL(IDC_ACTIONCREATOR_CONDITION);
private _unconscious = CTRL(IDC_ACTIONCREATOR_TOOLBOX) ctrlChecked 0;
private _selection = ctrlText CTRL(IDC_ACTIONCREATOR_SELECTION);
private _memory = ctrlText CTRL(IDC_ACTIONCREATOR_MEMORYPOINT);

if (_args isEqualTo "") then {_args = "nil"};
if (_priority isEqualTo "") then {_priority = "1.5"};
if (_r isEqualTo "") then {_r = "50"};
if (_condition isEqualTo "") then {_condition = "true"};


profileNamespace setVariable ["ENH_ActionCreator_LastUsed",[_title,_script,_args,_priority,_window,_hide,_shortcuts,_condition,_r,_unconscious,_selection,_memory]];

copyToClipboard format
[
  "this addAction [""%1"",""%2"",%3,%4,%5,%6,""%7"",""%8"",%9,%10,""%11"",""%12""];",
  _title,
  _script,
  _args,
  _priority,
  _window,
  _hide,
  _shortcuts,
  _condition,
  _r,
  _unconscious,
  _selection,
  _memory
];

["ENH_DataCopied"] call BIS_fnc_3DENNotification;

_display closeDisplay 1;