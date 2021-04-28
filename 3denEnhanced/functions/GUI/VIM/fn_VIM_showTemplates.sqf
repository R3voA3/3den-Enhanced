/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_VIM GUI. Shows all templates and handles the visual appearance of the GUI.

  Parameter(s):
  0: CONTROL - Control Button

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];
private _display = uiNamespace getVariable "ENH_Display_VIM";

lbClear CTRL(IDC_VIM_AVAILABLEITEMSLIST);

//Hide controls
{
  CTRL(_x) ctrlShow ENH_VIM_templatesVisible;
} forEach [IDC_VIM_FILTER, IDC_VIM_ADDONE, IDC_VIM_ADDTEN, IDC_VIM_REMOVEONE, IDC_VIM_REMOVETEN, IDC_VIM_REMOVEALL, IDC_VIM_FILTERSEARCH, IDC_VIM_SEARCH, IDC_VIM_BUTTONSEARCH, IDC_VIM_FULLARSENAL, IDC_VIM_VIRTUAL, IDC_VIM_VIRTUAL_TEXT, IDC_VIM_RESET];

//Enable controls
{
  CTRL(_x) ctrlShow !ENH_VIM_templatesVisible;
} forEach [IDC_VIM_CREATETEMPLATE, IDC_VIM_DELETETEMPLATE, IDC_VIM_APPLYTEMPLATE];

if (!ENH_VIM_templatesVisible) then
{
  _ctrlButton ctrlSetText localize "STR_ENH_VIM_HIDETEMPLATES";
  CTRL(IDC_VIM_AVAILABLEITEMSTEXT) ctrlSetText localize "STR_ENH_VIM_TEMPLATES";
  _display call ENH_fnc_VIM_updateTemplateList;
  ENH_VIM_templatesVisible = true;
}
else
{
  _ctrlButton ctrlSetText localize "STR_ENH_VIM_SHOWTEMPLATES";
  CTRL(IDC_VIM_AVAILABLEITEMSTEXT) ctrlSetText localize "STR_ENH_VIM_AVAILABLEITEMS";
  [CTRL(IDC_VIM_FILTER), lbCurSel CTRL(IDC_VIM_FILTER)] call ENH_fnc_VIM_filterList;
  ENH_VIM_templatesVisible = false;
};