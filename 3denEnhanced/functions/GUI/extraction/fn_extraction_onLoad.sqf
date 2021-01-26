/*
  Author: R3vo

  Date: 2019-09-06

  Description:
  Used by the ENH_Extraction GUI. Is called when display is created.

  Parameter(s):
  0: DISPLAY - ENH_Extraction GUI

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

#define CFG_MAGAZINES ["SmokeShell", "smokeShellGreen", "smokeShellOrange", "smokeShellBlue", "smokeShellRed", "smokeShellPurple", "smokeShellYellow", "Chemlight_blue", "Chemlight_red", "Chemlight_green", "Chemlight_yellow", "B_IR_Grenade"]

params ["_display"];
(uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") params ["_center", "_veh"];

CTRL(IDC_EXTRACTION_SHOWRADIOCHAT) cbSetChecked false;

CTRL(IDC_EXTRACTION_NAMEREQUESTER) ctrlSetText groupId group player;
CTRL(IDC_EXTRACTION_NAMEREQUESTER) ctrlEnable false;

CTRL(IDC_EXTRACTION_NAMETRANSPORT) ctrlSetText groupId group _veh;
CTRL(IDC_EXTRACTION_NAMETRANSPORT) ctrlEnable false;

CTRL(IDC_EXTRACTION_CONDITIONSTART) ctrlSetText "ENH_Extraction_Start";

private _ctrlGrenadeType = CTRL(IDC_EXTRACTION_GRENADE);
{
  if (_x isEqualTo "-") then
  {
    _ctrlGrenadeType lbAdd _x;
  }
  else
  {
    private _cfgMagazineClass = getText (configfile >> "CfgMagazines" >> _x >> "ammo");
    private _displayName = getText (configfile >> "CfgMagazines" >> _x >> "displayName");
    _ctrlGrenadeType lbAdd _displayName;
    _ctrlGrenadeType lbSetData [_forEachIndex, _cfgMagazineClass];
  };
} forEach ["-"] + CFG_MAGAZINES;

_ctrlGrenadeType lbSetCurSel 0;

CTRL(IDC_EXTRACTION_CONDITION) ctrlSetText "units player findIf {!(_x in vehicle this) && alive _x} < 0;";

CTRL(IDC_EXTRACTION_GRID) ctrlSetText mapGridPosition _center;
CTRL(IDC_EXTRACTION_GRID) ctrlEnable false;

CTRL(IDC_EXTRACTION_VEHICLE) ctrlSetText typeOf _veh;
CTRL(IDC_EXTRACTION_VEHICLE) ctrlEnable false;

CTRL(IDC_EXTRACTION_POSITION) ctrlSetText str _center;
CTRL(IDC_EXTRACTION_POSITION) ctrlEnable false;

CTRL(IDC_EXTRACTION_IMAGE) ctrlSetText getText (configfile >> "CfgVehicles" >> typeOf _veh >> "picture");