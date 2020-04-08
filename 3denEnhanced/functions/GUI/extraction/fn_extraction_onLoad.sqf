/*
   Author: R3vo

   Date: 2019-09-06

   Description:
   Used by the ENH_Extraction GUI. Is called when display is created.

   Parameter(s):
   0: DISPLAY - ENH_Extraction GUI

   Returns:
   BOOLEAN: true
*/

#define GET_CTRL(IDC) (_display displayCtrl IDC)
#define CFG_MAGAZINES ["SmokeShell","smokeShellGreen","smokeShellOrange","smokeShellBlue","smokeShellRed","smokeShellPurple","smokeShellYellow","Chemlight_blue","Chemlight_red","Chemlight_green","Chemlight_yellow","B_IR_Grenade"]

params ["_display"];
(uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") params ["_center","_veh"];

private _ctrlShowRadio = _display displayCtrl 100;
_ctrlShowRadio cbSetChecked false;

private _ctrlRequester = GET_CTRL(200);
_ctrlRequester ctrlSetText groupId group player;
_ctrlRequester ctrlEnable false;

private _ctrlTransport = GET_CTRL(300);
_ctrlTransport ctrlSetText groupId group _veh;
_ctrlTransport ctrlEnable false;

private _ctrlConditionStart = GET_CTRL(400);
_ctrlConditionStart ctrlSetText "ENH_Extraction_Start";

private _ctrlGrenadeType = GET_CTRL(500);
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
	   _ctrlGrenadeType lbSetData [_forEachIndex,_cfgMagazineClass];
   };
} forEach ["-"] + CFG_MAGAZINES;

_ctrlGrenadeType lbSetCurSel 0;

private _ctrlCondition = GET_CTRL(600);
_ctrlCondition ctrlSetText "units player findIf {!(_x in vehicle this) && alive _x} < 0;";

private _ctrlGridPos = GET_CTRL(700);
_ctrlGridPos ctrlSetText mapGridPosition _center;
_ctrlGridPos ctrlEnable false;

private _ctrlVehClass = GET_CTRL(800);
_ctrlVehClass ctrlSetText typeOf _veh;
_ctrlVehClass ctrlEnable false;

private _ctrlPosition = GET_CTRL(900);
_ctrlPosition ctrlSetText str _center;
_ctrlPosition ctrlEnable false;

private _ctrlImage = GET_CTRL(1000);
_ctrlImage ctrlSetText getText (configfile >> "CfgVehicles" >> typeOf _veh >> "picture");

true