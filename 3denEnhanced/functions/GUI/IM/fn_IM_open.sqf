/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_InventoryManager GUI. Initialises the GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
ENH_IM_templatesVisible = false;
ENH_IM_target = get3DENSelected "Object" select 0;

if (isNil "ENH_IM_target" || {ENH_IM_target isKindOf "CAManBase" || !(ENH_IM_target call ENH_fnc_hasStorage)}) exitWith
{
  ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
};

private _display = findDisplay IDD_3DEN createDisplay "ENH_InventoryManager";
uiNamespace setVariable ["Enh_Display_InventoryManager",_display];

call ENH_fnc_getAllItems;
call ENH_fnc_IM_loadAttributeValue;

//Get all addons and add them to filter control
{
  _x params ["_addonClass","_addonName","_addonIcon"];
  [CTRL(IDC_IM_FILTERSEARCH),_addonName,_addonClass,"",_addonIcon] call ENH_fnc_IM_lbAdd;
} forEach (uiNamespace getVariable "ENH_IM_allAddons");

[CTRL(IDC_IM_FILTER),0] call ENH_fnc_IM_filterList;

//Add background icon
private _icon = getText (configFile >> "CfgVehicles" >> typeOf ENH_IM_target >> "icon");

//Stupid workaround because some vehicles / crates don't have the icon texture in their config...
if !(".paa" in _icon) then
{
  _icon = getText (configfile >> "CfgVehicleIcons" >> _icon);
};
CTRL(IDC_IM_BACKGROUNDICON) ctrlSetText _icon;

{
  CTRL(_x) ctrlEnable false;
} forEach [IDC_IM_CREATETEMPLATE,IDC_IM_DELETETEMPLATE,IDC_IM_APPLYTEMPLATE];