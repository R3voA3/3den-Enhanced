/*
	Author: Revo

	Description:
	Used by ENH_actionCreator GUI.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

disableSerialization;

private _display = findDisplay 190000;
private _title = ctrlText (_display displayCtrl 1408);
private _script = ctrlText (_display displayCtrl 1400);
private _args = ctrlText (_display displayCtrl 1401);
private _priority = ctrlText (_display displayCtrl 1402);
private _window = (_display displayCtrl 1000) ctrlChecked 1;
private _hide = (_display displayCtrl 1000) ctrlChecked 2;
private _shortcuts = ctrlText (_display displayCtrl 1405);
private _condition = ctrlText (_display displayCtrl 1403);
private _r = ctrlText (_display displayCtrl 1404);
private _unconscious = (_display displayCtrl 1000) ctrlChecked 0;
private _selection = ctrlText (_display displayCtrl 1406);
private _memory = ctrlText (_display displayCtrl 1407);

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

true