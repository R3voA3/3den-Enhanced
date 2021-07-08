/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_VIM GUI. Initialises the GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;

ENH_VIM_target = get3DENSelected "Object" select 0;

if (isNil "ENH_VIM_target" || {ENH_VIM_target isKindOf "CAManBase" || !(ENH_VIM_target call ENH_fnc_hasStorage)}) exitWith
{
  ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
};

private _display = findDisplay IDD_3DEN createDisplay "ENH_VIM";
uiNamespace setVariable ["ENH_Display_VIM", _display];

[] call ENH_fnc_getAllItems;
[] call ENH_fnc_VIM_loadAttributeValue;

//Get all addons and add them to filter control
{
  _x params ["_addonClass", "_addonName", "_addonIcon"];
  [CTRL(IDC_VIM_FILTERSEARCH), _addonName, _addonClass, "", _addonIcon] call ENH_fnc_VIM_lbAdd;
} forEach (uiNamespace getVariable "ENH_VIM_allAddons");

//By default select no mod
CTRL(IDC_VIM_FILTERSEARCH) lbSetCurSel 0;

[CTRL(IDC_VIM_FILTER), 0] call ENH_fnc_VIM_filterList;
[CTRL(IDC_VIM_MENU), [2, 0]] call ENH_fnc_VIM_changeFilter; //Load ARs as default

//Disable template options
CTRL(IDC_VIM_MENU) menuEnable [[3, 1], false];
CTRL(IDC_VIM_MENU) menuEnable [[3, 2], false];
CTRL(IDC_VIM_MENU) menuEnable [[3, 3], false];
CTRL(IDC_VIM_MENU) menuEnable [[3, 5], false];

//Overwrite default ESC behaviour
_display displayAddEventHandler ["KeyDown",
{
  params ["", "_key"];
  if (_key == DIK_ESCAPE) then {call ENH_fnc_VIM_close; true};
}];