/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_InventoryManager GUI. Shows all templates and handles the visual appearance of the GUI.

  Parameter(s):
  0: CONTROL - Control Button

  Returns:
  BOOLEAN: true
*/

params ["_ctrlButton"];
private _display = uiNamespace getVariable "Enh_Display_InventoryManager";
private _ctrlItems = _display displayCtrl 2200;
lbClear _ctrlItems;

private _showTemplate = isNil "ENH_IM_ShowTemplates";

//Disable controls
{
  _display displayCtrl _x ctrlEnable !_showTemplate;
} forEach [2100,2400,2500,2600,2700,2800,3300,3400,3500];

//Enable controls
{
  _display displayCtrl _x ctrlEnable _showTemplate;
} forEach [2900,3000,3100];

if (isNil "ENH_IM_ShowTemplates") then
{
  _ctrlButton ctrlSetText localize "STR_ENH_IM_HIDETEMPLATES";
  _display displayCtrl 1000 ctrlSetText localize "STR_ENH_IM_TEMPLATES";

  _display call ENH_fnc_IM_updateTemplateList;
  ENH_IM_ShowTemplates = true;
}
else
{
  _ctrlButton ctrlSetText localize "STR_ENH_IM_SHOWTEMPLATES";
  _display displayCtrl 1000 ctrlSetText localize "STR_ENH_IM_AVAILABLEITEMS";
  private _ctrlFilter = _display displayCtrl 2100;
  [_ctrlFilter,lbCurSel _ctrlFilter] call ENH_fnc_IM_filterList;

  ENH_IM_ShowTemplates = nil;
};

true