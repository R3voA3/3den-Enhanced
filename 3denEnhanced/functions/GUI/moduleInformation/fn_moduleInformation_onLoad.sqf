/*
  Author: R3vo

  Description:
  Used by the ENH_ModuleInformation GUI. Called onLoad.

  Parameter(s):
  0: DISPLAY - Module Information GUI

  Returns:
 -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"
#define LB "<br/>"

disableSerialization;

params ["_display"];

private _logicType = typeOf ((get3DENSelected "Logic") # 0);

private _fnc_getValue =
{
  private _cfgEntry = param [0, "", [""]];
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

_description = "<t font='RobotoCondensedBold'>" + localize "STR_ENH_MODULEINFORMATION_DESCRIPTION" + "</t> " + _description + format
[
  "%1%1<t font='RobotoCondensedBold'>%2</t> %3%1<t font='RobotoCondensedBold'>%4</t> %5%1<t font='RobotoCondensedBold'>%6</t> %7",
  LB, localize "STR_ENH_MODULEINFORMATION_POSITION", _position,
  localize "STR_ENH_MODULEINFORMATION_DUPLICATE", _duplicate,
  localize "STR_ENH_MODULEINFORMATION_DIRECTION", _direction
];

if (_sync isNotEqualto []) then
{
  _description = _description + format ["%1<t font='RobotoCondensedBold'>%2</t>%1", LB, localize "STR_ENH_MODULEINFORMATION_SYNC"];
  {
    _description = _description + "    - " + _x + LB;
  } forEach _sync;
};

CTRL(IDC_MODULEINFORMATION_DESCRIPTION) ctrlSetStructuredText parseText _description;