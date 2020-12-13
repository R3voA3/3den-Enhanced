/*
  Author: R3vo

  Date: 2020-09-09

  Description:
  Used by the ENH_Inventory Manager GUI. Gets default storage from vehicle's config and adds it to the GUI.

  Parameter(s):
  -

  Returns:
  BOOLEAN: true
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

ENH_fnc_IM_resetStorage_main =
{
  _display = uiNamespace getVariable "Enh_Display_InventoryManager";
  private _ctrlInventory = CTRL(IDC_IM_INVENTORYLIST);

  //Clear inventory listbox
  call ENH_fnc_IM_clearInventory;

  //Get all items defined in vehicle's config and add them to the listbox
  {
    private _classes = "true" configClasses (configOf ENH_IM_target >> _x);
    {
        _count = getNumber (_x >> "count");
        _configName = configName _x select [4,count (configName _x) -1];

        [_ctrlInventory,_configName,"","","",_count,_configName +  "\n" + localize "STR_ENH_IM_PREVIEW_TOOLTIP"] call ENH_fnc_IM_lnbAdd;
    } forEach _classes;
  } forEach ["TransportWeapons","TransportMagazines","TransportItems","TransportBackpacks"];

  //Apply attribute will read the listbox content and set the attribute
  false call ENH_fnc_IM_applyAttribute;

  //Let's just read the attribute value to properly fill the inventory listbox with DLC icons etc.
  call ENH_fnc_IM_loadAttributeValue;
};


[
  localize "STR_ENH_IM_RESET_TOOLTIP",
  "",
  [
    "Yes",
    {call ENH_fnc_IM_resetStorage_main; nil}//Return nil so the dialog is closed
  ],
  [
    "No",
    {}
  ],
  "\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa",
  uiNamespace getVariable "Enh_Display_InventoryManager"
] call BIS_fnc_3DENShowMessage;