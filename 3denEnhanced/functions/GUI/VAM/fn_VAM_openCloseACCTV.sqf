/* #include "\a3\3DEN\UI\macros.inc"
#include "\3denEnhanced\defines\defineCommon.inc"

params ["_openBool"];

private _display = uiNamespace getVariable "ENH_VAM_display";

private _mainTV = _display displayCtrl IDC_VAM_TREEVIEW;
private _accTV = _display displayCtrl IDC_VAM_TREEVIEW_COMP_ITEMS;

private _selectedItemClass = toLower((uiNamespace getVariable "ENH_VAM_selectedItem") select 7);

if (_openBool) then {
  _mainTV ctrlSetPositionH (WINDOW_HAbs / 2);

  [_accTV, _selectedItemClass] call ENH_fnc_VAM_tvItemInit;

  _accTV ctrlShow true;
  _accTV ctrlEnable true;
  _mainTV ctrlCommit 0.1;
  _accTV ctrlCommit 0.1;
} else {
  _accTV ctrlShow false;
  _accTV ctrlEnable false;

  _mainTV ctrlSetPositionH (WINDOW_HAbs - 24 * GRID_H);
  _accTV ctrlCommit 0.1;
  _mainTV ctrlCommit 0.1;
}; */