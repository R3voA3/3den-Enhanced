/*
	Author: linkion and R3vo

	Description:
	select items for main treeview from selectHashMap

	Parameter(s):
	-

	Returns:
	-

	Usage:
	[_selectHashMap] call ENH_fnc_VAM_loadSelectHashMap;
*/

params [["_selectHashMap", uiNamespace getVariable ["ENH_VAM_selectHashMap", createHashMap]]];
#define IDC_TREEVIEW 10

_selectHashMap = +_selectHashMap;

private _ctrlTV = uiNamespace getVariable "ENH_VAM_display" displayCtrl IDC_TREEVIEW;

for "_i" from 0 to (_ctrlTV tvCount []) do {
  // clear current selection
  [_ctrlTV, 0, [_i]] call ENH_fnc_VAM_switchNodeState;
};

{
  // Current key is saved in variable _x
  // Current value is saved in variable _y
  _y params ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort", "_class"];

  private _indexAddon = -1;
  private _indexCategory = -1;
  private _indexEquipment = -1;

  //format["tvCount: %1 inAdd: %2 inCat: %3 values: %4", (_ctrlTV tvCount [_indexAddon, _indexCategory]), _indexAddon, _indexCategory, _y] call BIS_fnc_3DENNotification;
  for "_i" from 0 to (_ctrlTV tvCount []) do {
    if ((toLower(_ctrlTV tvData [_i])) isEqualTo (toLower(_addonClass))) then {
      _indexAddon = _i;
      break;
    };
  };
  //format["ctrlTV: %4 tvCount[]: %1 tvCount[0]: %2", _ctrlTV tvCount [], _ctrlTV tvCount [0], _ctrlTV] call BIS_fnc_3DENNotification;

  for "_i" from 0 to (_ctrlTV tvCount [_indexAddon]) do {
    if (
      (toLower(_ctrlTV tvData [_indexAddon, _i])) isEqualTo (toLower(_category)) ||
      (toLower(_ctrlTV tvData [_indexAddon, _i])) isEqualTo (toLower(_specificType))
      ) then {
      _indexCategory = _i;
      break;
    };
  };

  for "_i" from 0 to (_ctrlTV tvCount [_indexAddon, _indexCategory]) do {
    if ((toLower(_ctrlTV tvData [_indexAddon, _indexCategory, _i])) isEqualTo (toLower(_class))) then {
      _indexEquipment = _i;
      break;
    };
  };

  [_ctrlTV, 1, [_indexAddon, _indexCategory, _indexEquipment]] call ENH_fnc_VAM_switchNodeState;
} forEach _selectHashMap;