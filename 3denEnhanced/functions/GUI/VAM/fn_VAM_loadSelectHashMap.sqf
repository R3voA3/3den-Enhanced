/*
	Author: linkion and R3vo

	Description:
	select items for main treeview from selectHashMap

	Parameter(s):
	-

	Returns:
	-

	Usage:
	[_ctrl, _selectHashMap] call ENH_fnc_VAM_loadSelectHashMap;
*/

params ["_ctrl", ["_selectHashMap", createHashMap]];

{
  // Current key is saved in variable _x
  // Current value is saved in variable _y
  _y params ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort", "_class"];

  private _indexAddon = _allAddonClasses find _addonClass;
  private _indexCategory = (uiNamespace getVariable ["ENH_VIM_types", []]) find _category;
  private _indexEquipment = -1;

  if (_indexCategory < 0) then
  {
   _indexCategory = (uiNamespace getVariable ["ENH_VIM_types", []]) find _specificType;
  };

  for [0, _ctrl tvCount [_indexAddon, _indexCategory], 1] do {
    if ((_ctrl tvData [_indexAddon, _indexCategory, _i]) isEqualTo (toLower _class)) then {
      _indexEquipment = _i;
    };
  };

  [_ctrl, 1, [_indexAddon, _indexCategory, _indexEquipment]] call ENH_fnc_switchNodeState;
} forEach _selectHashMap;