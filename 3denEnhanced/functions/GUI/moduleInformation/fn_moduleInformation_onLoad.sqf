/*
  Author: R3vo

  Description:
  Used by the ENH_ModuleInformation GUI. Called onLoad.

  Parameter(s):
  0: DISPLAY - Module Information GUI

  Returns:
  BOOLEAN: True on success, false when failed
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

params ["_display"];

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

CTRL(IDC_MODULEINFORMATION_DESCRIPTION) ctrlSetText _description;
CTRL(IDC_MODULEINFORMATION_POSITION) ctrlSetText _position;
CTRL(IDC_MODULEINFORMATION_DUPLICATE) ctrlSetText _duplicate;
CTRL(IDC_MODULEINFORMATION_DIRECTION) ctrlSetText _direction;
CTRL(IDC_MODULEINFORMATION_SYNC) ctrlSetText str _sync;

true