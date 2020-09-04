params ["_ctrlCombo", "_selectedIndex"];

private _display = ctrlParent _ctrlCombo;
private _ctrlSearch = _display displayCtrl 5000;
private _ctrlButtonSearch = _display displayCtrl 5100;

//Update edit box and button
_ctrlSearch ctrlSetText "mod " + (_ctrlCombo lbData _selectedIndex);
_ctrlButtonSearch ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";

_ctrlSearch call ENH_fnc_IM_search;