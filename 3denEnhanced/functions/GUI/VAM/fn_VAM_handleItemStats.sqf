#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

params ["_ctrl"];

private _path = uiNamespace getVariable["ENH_VAM_selectedItemTVPath", []];
private _display = ctrlParent _ctrl;

private _ctrlProgress_1 = _display displayCtrl IDC_VAM_PROGRESS_1;
private _ctrlProgress_2 = _display displayCtrl IDC_VAM_PROGRESS_2;
private _ctrlProgress_3 = _display displayCtrl IDC_VAM_PROGRESS_3;
private _ctrlProgress_4 = _display displayCtrl IDC_VAM_PROGRESS_4;
private _ctrlProgress_5 = _display displayCtrl IDC_VAM_PROGRESS_5;

private _ctrlProgressText_1 = _display displayCtrl IDC_VAM_PROGRESS_TEXT_1;
private _ctrlProgressText_2 = _display displayCtrl IDC_VAM_PROGRESS_TEXT_2;
private _ctrlProgressText_3 = _display displayCtrl IDC_VAM_PROGRESS_TEXT_3;
private _ctrlProgressText_4 = _display displayCtrl IDC_VAM_PROGRESS_TEXT_4;
private _ctrlProgressText_5 = _display displayCtrl IDC_VAM_PROGRESS_TEXT_5;

// No item selected
if ((_ctrl tvCount _path) == 0) then
{
  private _currentItemSelected = uiNamespace getVariable ["ENH_VAM_selectedItem", ["", "", "", "", "", "", "", ""]];
  private _itemConfigPath = configFile >> "CfgWeapons" >> (_currentItemSelected select 7);
  ((_currentItemSelected select 7) call BIS_fnc_itemType) params["_itemCategory", "_itemType"];


  switch (_itemCategory) do {
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

      _ctrlProgress_1 progressSetPosition 1;
      _ctrlProgress_2 progressSetPosition (["passthrough", _itemConfigPath, [[0, 0.63], [0.01, 1], false]] call ENH_fnc_statBarStatement_default);
      _ctrlProgress_3 progressSetPosition (["armor", _itemConfigPath, [[0, 0.8], [0.01, 1], false]] call ENH_fnc_statBarStatement_default);
      _ctrlProgress_4 progressSetPosition (["maximumLoad", _itemConfigPath, [[0, 500], [0.01, 1], false]] call ENH_fnc_statBarStatement_default);
    };
    case "Item": {
      switch (_itemType) do {
        case "AccessorySights": {
          _ctrlProgress_1 ctrlShow true;
          _ctrlProgress_2 ctrlShow true;
          _ctrlProgress_3 ctrlShow true;
          _ctrlProgress_4 ctrlShow false;
          _ctrlProgress_5 ctrlShow false;

          _ctrlProgressText_1 ctrlShow true;
          _ctrlProgressText_2 ctrlShow true;
          _ctrlProgressText_3 ctrlShow true;
          _ctrlProgressText_4 ctrlShow false;
          _ctrlProgressText_5 ctrlShow false;

          _ctrlProgressText_1 ctrlSetText format["%1: %2", localize "$STR_a3_rscdisplayarsenal_stat_weight", [_itemConfigPath] call ENH_fnc_statTextStatement_mass];
          _ctrlProgressText_2 ctrlSetText format["Magnification: %1", ["", _itemConfigPath] call ENH_fnc_statTextStatement_scopeMag];
          _ctrlProgressText_3 ctrlSetText format["Vision Mode: %1", ["", _itemConfigPath] call ENH_fnc_statTextStatement_scopeVisionMode];

          _ctrlProgress_1 progressSetPosition 1;
          _ctrlProgress_2 progressSetPosition 1;
          _ctrlProgress_3 progressSetPosition 1;

        };
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