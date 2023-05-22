params ["_ctrl"];

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

private _path = uiNamespace getVariable["ENH_VAM_selectedItemTVPath", []];

private _ctrlProgress_1 = _display displayCtrl IDC_PROGRESS_1;
private _ctrlProgress_2 = _display displayCtrl IDC_PROGRESS_2;
private _ctrlProgress_3 = _display displayCtrl IDC_PROGRESS_3;
private _ctrlProgress_4 = _display displayCtrl IDC_PROGRESS_4;
private _ctrlProgress_5 = _display displayCtrl IDC_PROGRESS_5;

private _ctrlProgressText_1 = _display displayCtrl IDC_PROGRESS_TEXT_1;
private _ctrlProgressText_2 = _display displayCtrl IDC_PROGRESS_TEXT_2;
private _ctrlProgressText_3 = _display displayCtrl IDC_PROGRESS_TEXT_3;
private _ctrlProgressText_4 = _display displayCtrl IDC_PROGRESS_TEXT_4;
private _ctrlProgressText_5 = _display displayCtrl IDC_PROGRESS_TEXT_5;

// No item selected
if ((_ctrl tvCount _path) == 0) then
{
  private _display = ctrlParent _ctrl;
  private _currentItemSelected = uiNamespace getVariable ["ENH_VAM_selectedItem", ["", "", "", "", "", "", "", ""]];
  private _itemConfigPath = configFile >> "CfgWeapons" >> (_currentItemSelected select 7);

  switch ((((uiNamespace getVariable "ENH_VAM_selectedItem") select 7) call BIS_fnc_itemType) select 0) do {
    case "Weapon": {
      _ctrlProgress_1 ctrlShow true;
      _ctrlProgress_2 ctrlShow true;
      _ctrlProgress_3 ctrlShow true;
      _ctrlProgress_4 ctrlShow true;
      _ctrlProgress_5 ctrlShow true;

      _ctrlProgressText_1 ctrlShow true;
      _ctrlProgressText_2 ctrlShow true;
      _ctrlProgressText_3 ctrlShow true;
      _ctrlProgressText_4 ctrlShow true;
      _ctrlProgressText_5 ctrlShow true;

      _ctrlProgressText_1 ctrlSetText format["%1: %2", localize "$STR_a3_rscdisplayarsenal_stat_weight", [_itemConfigPath] call ENH_fnc_statTextStatement_mass];
      _ctrlProgressText_2 ctrlSetText format["%1: %2", localize "$STR_a3_rscdisplayarsenal_stat_rof", [_itemConfigPath] call ENH_fnc_statTextStatement_rateOfFire];
      _ctrlProgressText_3 ctrlSetText format["%1: %2", localize "$STR_a3_rscdisplayarsenal_stat_dispersion", [_itemConfigPath] call ENH_fnc_statTextStatement_accuracy];
      _ctrlProgressText_4 ctrlSetText format["%1: %2", localize "$STR_a3_rscdisplayarsenal_stat_range", ["maxZeroing", _itemConfigPath, [[0, 2500], [0.01, 1]]] call ENH_fnc_statBarStatement_default];
      _ctrlProgressText_5 ctrlSetText localize "$STR_a3_rscdisplayarsenal_stat_impact";

      _ctrlProgress_1 progressSetPosition 1;
      _ctrlProgress_2 progressSetPosition ([_itemConfigPath, [[-1.4, 0.31], [1, 0.01]]] call ENH_fnc_statBarStatement_rateOfFire);
      _ctrlProgress_3 progressSetPosition ([_itemConfigPath, [[-4, -1.7], [1, 0.01]]] call ENH_fnc_statBarStatement_accuracy);
      _ctrlProgress_4 progressSetPosition 1;
      _ctrlProgress_5 progressSetPosition ([_itemConfigPath, [[0, 3.2], [-1, 1100]]] call ENH_fnc_statBarStatement_impact);
    };
    case "Equipment": {
      _ctrlProgress_1 ctrlShow true;
      _ctrlProgress_2 ctrlShow true;
      _ctrlProgress_3 ctrlShow true;
      _ctrlProgress_4 ctrlShow true;
      _ctrlProgress_5 ctrlShow false;

      _ctrlProgressText_1 ctrlShow true;
      _ctrlProgressText_2 ctrlShow true;
      _ctrlProgressText_3 ctrlShow true;
      _ctrlProgressText_4 ctrlShow true;
      _ctrlProgressText_5 ctrlShow false;

      _ctrlProgressText_1 ctrlSetText format["%1: %2", localize "$STR_a3_rscdisplayarsenal_stat_weight", [_itemConfigPath] call ENH_fnc_statTextStatement_mass];
      _ctrlProgressText_2 ctrlSetText localize "$STR_a3_rscdisplayarsenal_stat_passthrough";
      _ctrlProgressText_3 ctrlSetText localize "$STR_a3_rscdisplayarsenal_stat_armor";
      _ctrlProgressText_4 ctrlSetText localize "$STR_a3_rscdisplayarsenal_stat_load";

      // TODO: Equipment stat bars
      _ctrlProgress_1 progressSetPosition 1;
      _ctrlProgress_2 progressSetPosition 1;
      _ctrlProgress_3 progressSetPosition 1;
      _ctrlProgress_4 progressSetPosition 1;
    };
    // TODO: Items >> Scopes & (Grenades??, probably not)
    default {
      _ctrlProgress_1 ctrlShow false;
      _ctrlProgress_2 ctrlShow false;
      _ctrlProgress_3 ctrlShow false;
      _ctrlProgress_4 ctrlShow false;
      _ctrlProgress_5 ctrlShow false;

      _ctrlProgressText_1 ctrlShow false;
      _ctrlProgressText_2 ctrlShow false;
      _ctrlProgressText_3 ctrlShow false;
      _ctrlProgressText_4 ctrlShow false;
      _ctrlProgressText_5 ctrlShow false;
    };
  };

};