/*
   Author: R3vo

   Date: 2020-06-14

   Description:
   Used by the ENH_InventoryManager GUI. Used to search the item listbox.

   Parameter(s):
   0: CONTROL - Control Edit

   Returns:
   BOOLEAN: true
*/

params ["_ctrlSearch"];
private _display = ctrlParent _ctrlSearch;
private _ctrlItems = _display displayCtrl 2200;
private _filter = toUpper ctrlText _ctrlSearch;
private _classesToSearch = uiNamespace getVariable ["ENH_IM_FilteredItems",[]];

if (_filter == "") then
{
   (_display displayCtrl 3500) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
}
else
{
   (_display displayCtrl 3500) ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
};

lbClear _ctrlItems;
{
   _x params ["_configName","_displayName","_picture","_addonIcon","_addon"];

   if ((_filter select [0,3] == "MOD") && ((_filter select [4,50]) in toUpper _addon)) then
   {
      [_ctrlItems,_displayName,_configName,_picture,_addonIcon] call ENH_fnc_IM_lbAdd;
   }
   else
   {
	   if ((_filter in toUpper _displayName) || (_filter == "")) then
	   {
	   	[_ctrlItems,_displayName,_configName,_picture,_addonIcon] call ENH_fnc_IM_lbAdd;
      };
   };
} forEach _classesToSearch;

lbSort [_ctrlItems,"ASC"];

true