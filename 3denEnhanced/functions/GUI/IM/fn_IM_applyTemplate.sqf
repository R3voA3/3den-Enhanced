/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_InventoryManager GUI. Applies the selected template.

  Parameter(s):
  -

  Returns:
  BOOLEAN: true
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
private _display = uiNamespace getVariable "Enh_Display_InventoryManager";

//Get template data from listbox
private _ctrlItems = CTRL(IDC_IM_AVAILABLEITEMSLIST);
private _row = lbCurSel _ctrlItems;
if (_row isEqualTo -1) exitWith {false};
private _value = _ctrlItems lbData lbCurSel _ctrlItems;
ENH_IM_target set3DENAttribute ["ammoBox", _value];
call ENH_fnc_IM_loadAttributeValue;

true