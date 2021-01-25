/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_InventoryManager GUI. Shows all templates and handles the visual appearance of the GUI.

  Parameter(s):
  0: CONTROL - Control Button

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];
private _display = uiNamespace getVariable "Enh_Display_InventoryManager";

lbClear CTRL(IDC_IM_AVAILABLEITEMSLIST);

private _showTemplate = isNil "ENH_IM_ShowTemplates";

//Disable controls
{
  _display displayCtrl _x ctrlEnable ENH_IM_templatesVisible;
} forEach [IDC_IM_FILTER,IDC_IM_ADDONE,IDC_IM_ADDTEN,IDC_IM_REMOVEONE,IDC_IM_REMOVETEN,IDC_IM_REMOVEALL,IDC_IM_FILTERSEARCH,IDC_IM_SEARCH,IDC_IM_BUTTONSEARCH];

//Enable controls
{
  _display displayCtrl _x ctrlEnable !ENH_IM_templatesVisible;
} forEach [IDC_IM_CREATETEMPLATE,IDC_IM_DELETETEMPLATE,IDC_IM_APPLYTEMPLATE];

if (!ENH_IM_templatesVisible) then
{
  CTRL(IDC_IM_FILTER) ctrlSetFade 0.5; //No colorDisabled for CT_TOOLBOX so we use ctrlSetFade
  CTRL(IDC_IM_FILTER) ctrlCommit 0;
  _ctrlButton ctrlSetText localize "STR_ENH_IM_HIDETEMPLATES";
  CTRL(IDC_IM_AVAILABLEITEMSTEXT) ctrlSetText localize "STR_ENH_IM_TEMPLATES";
  _display call ENH_fnc_IM_updateTemplateList;
  ENH_IM_templatesVisible = true;
}
else
{
  CTRL(IDC_IM_FILTER) ctrlSetFade 0;
  CTRL(IDC_IM_FILTER) ctrlCommit 0;
  _ctrlButton ctrlSetText localize "STR_ENH_IM_SHOWTEMPLATES";
  CTRL(IDC_IM_AVAILABLEITEMSTEXT) ctrlSetText localize "STR_ENH_IM_AVAILABLEITEMS";
  [CTRL(IDC_IM_FILTER),lbCurSel CTRL(IDC_IM_FILTER)] call ENH_fnc_IM_filterList;
  ENH_IM_templatesVisible = false;
};