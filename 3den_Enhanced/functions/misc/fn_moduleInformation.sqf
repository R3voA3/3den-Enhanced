/*
   Author: Revo

   Description:
   Retrieves module's description and displays it formatted via systemChat.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true
*/

disableSerialization;
private _disp = findDisplay 130000;

private _logicType = typeOf ((get3DENSelected "Logic") # 0);

private _fnc_getValue =
{
	private _cfgEntry = param [0,"",[""]];
	(configFile >> "CfgVehicles" >> _logicType >> "ModuleDescription" >> _cfgEntry) call BIS_fnc_getCfgData;
};

private _description = "description" call _fnc_getValue;
private _direction = "direction" call _fnc_getValue;
private _duplicate = "duplicate" call _fnc_getValue;
private _position = "position" call _fnc_getValue;
private _sync = "sync" call _fnc_getValue;

if (isNil "_direction") exitWith {false};

private _direction = if (_direction > 0) then
{
	"directionEnabled" call _fnc_getValue;
}
else
{
	"directionDisabled" call _fnc_getValue;
};

private _duplicate = if (_duplicate > 0) then
{
	"duplicateEnabled" call _fnc_getValue;
}
else
{
	"duplicateDisabled" call _fnc_getValue;
};

private _position = if (_position > 0) then
{
	"positionEnabled" call _fnc_getValue;
}
else
{
	"positionDisabled" call _fnc_getValue;
};

private _descFinal = "";

if (_description isEqualType []) then
{
	{
		if (_descFinal isEqualTo "") then {_descFinal = _descFinal + _x} else {_descFinal = _descFinal + " " + _x};
	} forEach _description;
	_description = _descFinal;
};

private _ctrlDesc = _disp displayCtrl 1400;
private _ctrlPos = _disp displayCtrl 1401;
private _ctrlDup = _disp displayCtrl 1402;
private _ctrlDir = _disp displayCtrl 1403;
private _ctrlSync = _disp displayCtrl 1404;

_ctrlDesc ctrlSetStructuredText text _description;
_ctrlPos ctrlSetStructuredText text _position;
_ctrlDup ctrlSetStructuredText text _duplicate;
_ctrlDir ctrlSetStructuredText text _direction;
_ctrlSync ctrlSetStructuredText text str _sync;

true