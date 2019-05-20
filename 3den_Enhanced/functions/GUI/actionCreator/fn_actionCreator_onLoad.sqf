/*
	Author: Revo

	Description:
	Used by Enh_actionCreator GUI.

	Parameter(s):
	-

	Returns:
	BOOLEAN - true
*/

disableSerialization;
private _display = findDisplay 190000;

private _title = _display displayCtrl 1408;
private _script = _display displayCtrl 1400;
private _args = _display displayCtrl 1401;
private _priority = _display displayCtrl 1402;
private _window = _display displayCtrl 1409;
private _hide = _display displayCtrl 1410;
private _shortcuts = _display displayCtrl 1405;
private _condition = _display displayCtrl 1403;
private _r = _display displayCtrl 1404;
private _unconscious = _display displayCtrl 1411;
private _selection = _display displayCtrl 1406;
private _memory = _display displayCtrl 1407;

private _save = profileNamespace getVariable ["Enh_actionCreator_lastUsed",[]];

if !(_save isEqualTo []) then
{
	_title ctrlSetText _save # 0;
	_script ctrlSetText _save # 1;
	_args ctrlSetText _save # 2;
	_priority ctrlSetText _save # 3;
	_window cbSetChecked _save # 4;
	_hide cbSetChecked _save # 5;
	_shortcuts ctrlSetText _save # 6;
	_condition ctrlSetText _save # 7;
	_r ctrlSetText _save # 8;
	_unconscious cbSetChecked _save # 9;
	_selection ctrlSetText _save # 10;
	_memory ctrlSetText _save # 11;
};

true