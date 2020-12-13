/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_InventoryManager GUI. Used to preview the selectd item.

  Parameter(s):
  0: CONTROL - Control Listbox
  1: NUMBER - Selected Row

  Returns:
  BOOLEAN: true
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_ctrlListbox","_selectedIndex"];
private _display = uiNamespace getVariable "Enh_Display_InventoryManager";
private _typeCtrl = ctrlType _ctrlListbox;

//Exit if templates are shown and user double clicks on template list
if (_typeCtrl == 5 && {ENH_IM_ShowTemplates}) exitWith {false};

_display = _display createDisplay "ENH_InventoryManager_ItemPreview";

private _ctrlPicture = CTRL(IDC_IM_ITEMPREVIEW_IMAGE);
private _ctrlHeader = CTRL(IDC_IM_ITEMPREVIEW_HEADER);
_ctrlPicture ctrlSetText (_ctrlListbox lbPicture _selectedIndex);
_ctrlHeader ctrlSetText (_ctrlListbox lbText _selectedIndex);


switch (true) do
{
  case (_typeCtrl == CT_LISTNBOX):
  {
    _ctrlPicture ctrlSetText (_ctrlListbox lnbPicture [_selectedIndex,0]);
    _ctrlHeader ctrlSetText (_ctrlListbox lnbText [_selectedIndex,1]);
  };
  case (_typeCtrl == CT_LISTBOX):
  {
    _ctrlPicture ctrlSetText (_ctrlListbox lbPicture _selectedIndex);
    _ctrlHeader ctrlSetText (_ctrlListbox lbText _selectedIndex);
  };
};

true