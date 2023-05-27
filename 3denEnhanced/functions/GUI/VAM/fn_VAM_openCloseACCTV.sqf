#include "\a3\3DEN\UI\macros.inc"
#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

params ["_openBool"];

private _display = uiNamespace getVariable "ENH_VAM_display";

private _mainTV = _display displayCtrl IDC_VAM_TREEVIEW;
private _accTV = _display displayCtrl IDC_VAM_ACCTREEVIEW;

private _selectedItemClass = toLower((uiNamespace getVariable "ENH_VAM_selectedItem") select 7);

if (_openBool) then {
  _mainTV ctrlSetPosition [
    CENTER_X - 0.5 * WINDOW_W * GRID_W + GRID_W,
    CENTER_Y - 0.5 * WINDOW_HAbs + 17 * GRID_H,
    WINDOW_W * GRID_W - 2 * GRID_W,
    (WINDOW_HAbs / 2)
  ];

  [_accTV, _selectedItemClass] call ENH_fnc_VAM_tvItemInit;

  _accTV ctrlShow true;
  _accTV ctrlEnable true;
  _mainTV ctrlCommit 0.1;
  _accTV ctrlCommit 0.1;
} else {
  _accTV ctrlShow false;
  _accTV ctrlEnable false;

  _mainTV ctrlSetPosition [
    CENTER_X - 0.5 * WINDOW_W * GRID_W + GRID_W,
    CENTER_Y - 0.5 * WINDOW_HAbs + 17 * GRID_H,
    WINDOW_W * GRID_W - 2 * GRID_W,
    WINDOW_HAbs - 24 * GRID_H
  ];
  _accTV ctrlCommit 0.1;
  _mainTV ctrlCommit 0.1;
};