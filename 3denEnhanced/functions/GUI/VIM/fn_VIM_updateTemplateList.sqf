/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_VIM GUI. Used to update the template list, once a new template is created.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
private _display = uiNamespace getVariable "ENH_Display_VIM";
private _ctrlItems = CTRL(IDC_VIM_AVAILABLEITEMSLIST);
lbClear _ctrlItems;
{
  _x params ["_name", "_description", "_data"];
  _test = _ctrlItems lbAdd _name;
  _ctrlItems lbSetData [_forEachIndex, _data];
  _ctrlItems lbSetTooltip [_forEachIndex, _description];
} forEach (profileNamespace getVariable ["ENH_VIM_Templates", []]);