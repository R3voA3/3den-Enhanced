/*
	Author: Revo

	Description:
	Logs position 2D of all selected entities and copies them to the clipboard. Array is shuffled.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

private _objects  = get3DENSelected "Object";
private _markers  = get3DENSelected "Marker";
private _triggers = get3DENSelected "Trigger";
private _logics   = get3DENSelected "Logic";
private _posArray = [];
private _export = "";

private _entities = _objects + _triggers + _logics + _markers;

if (_entities isEqualTo []) exitWith {false};

{
	private _pos = (_x get3DENAttribute "Position") # 0;
	_pos = [_pos # 0,_pos # 0];
	_posArray pushBack _pos;
} forEach _entities;

private _export = [_posArray,false] call Enh_fnc_exportWithLB;

copyToClipboard _export;

["Enh_DataCopied"] call BIS_fnc_3DENNotification;

true