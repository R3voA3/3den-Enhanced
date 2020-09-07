params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _ctrlSearch = _display displayCtrl 3400;

_ctrlSearch ctrlSetText "";
_ctrlButton ctrlSetText "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";

_ctrlSearch call ENH_fnc_IM_search;