#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-11-02

    Description:
    Refills the history combo box for the marker color attribute.

    Parameter(s):
    0: CONTROL - Listbox

    Returns:
    true
*/

params ["_ctrlComboHistory"];

lbClear _ctrlComboHistory;
_ctrlComboHistory lbAdd localize "$STR_ENH_MAIN_CUSTOM_MARKER_COLOR_SELECT_PRESET";
_ctrlComboHistory lbSetCurSel 0;

{
    // Default value for _alpha for backwards compatibility
    _y params ["_red", "_green", "_blue", ["_alpha", 1]];

    private _index = _ctrlComboHistory lbAdd format
    [
        "#(%1,%2,%3,%4)",
        _red,
        _green,
        _blue,
        _alpha
    ];

    _ctrlComboHistory lbSetData [_index, _x];
    _ctrlComboHistory lbSetPicture [_index, format
    [
        "#(argb,1,1,1)color(%1,%2,%3,%4)",
        _red,
        _green,
        _blue,
        _alpha
    ]];
} forEach (profileNamespace getVariable ["ENH_Attributes_MarkerColor_History", createHashMap]);

true
