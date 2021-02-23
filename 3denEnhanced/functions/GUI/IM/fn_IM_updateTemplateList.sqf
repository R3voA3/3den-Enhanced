/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_InventoryManager GUI. Used to update the template list, once a new template is created.

  Parameter(s):
  -

  Returns:
  BOOLEAN: true
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
private _display = uiNamespace getVariable "Enh_Display_InventoryManager";
private _ctrlItems = CTRL(IDC_IM_AVAILABLEITEMSLIST);
_templates = profileNamespace getVariable ["ENH_IM_Templates", []];
lbClear _ctrlItems;
{
  _x params ["_name", "_description", "_data"];
  _test = _ctrlItems lbAdd _name;
  _ctrlItems lbSetData [_forEachIndex, _data];
  _ctrlItems lbSetTooltip [_forEachIndex, _description];
} forEach _templates;

true