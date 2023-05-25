#include "\a3\3DEN\UI\macros.inc"

#define WINDOW_W 140
#define IDC_TREEVIEW 10
#define IDC_ACE_CHECKBOX 20
#define IDC_BI_CHECKBOX 25
#define IDC_PREVIEW_PICTURE 30
#define IDC_ACCTREEVIEW 40
#define IDC_SEARCH 645
#define IDC_PROGRESS_1 40
#define IDC_PROGRESS_2 50
#define IDC_PROGRESS_3 60
#define IDC_PROGRESS_4 70
#define IDC_PROGRESS_5 80
#define IDC_PROGRESS_TEXT_1 90
#define IDC_PROGRESS_TEXT_2 100
#define IDC_PROGRESS_TEXT_3 110
#define IDC_PROGRESS_TEXT_4 120
#define IDC_PROGRESS_TEXT_5 130

params ["_openBool"];

private _display = uiNamespace getVariable "ENH_VAM_display";

private _mainTV = _display displayCtrl IDC_TREEVIEW;
private _accTV = _display displayCtrl IDC_ACCTREEVIEW;

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
    WINDOW_HAbs - 17 * GRID_H
  ];
  _accTV ctrlCommit 0.1;
  _mainTV ctrlCommit 0.1;
};