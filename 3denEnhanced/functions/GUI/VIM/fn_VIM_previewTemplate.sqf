/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_VIM GUI. Applies the selected template.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
private _display = uiNamespace getVariable "ENH_Display_VIM";

//Get template data from listbox
private _ctrlItems = CTRL(IDC_VIM_AVAILABLEITEMSLIST);
private _row = lbCurSel _ctrlItems;

if (_row isEqualTo -1) exitWith {};

private _value = _ctrlItems lbData lbCurSel _ctrlItems;
[false, _value] call ENH_fnc_VIM_loadAttributeValue;