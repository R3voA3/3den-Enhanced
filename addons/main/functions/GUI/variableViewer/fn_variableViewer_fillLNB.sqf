#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-02-11

    Description:
    Used by the ENH_VariableViewer GUI. Called when listNbox selection changed.

    Parameter(s):
    -

    Returns:
    -
*/

#define HIDE_FNC (profileNamespace getVariable ["ENH_VariableViewer_HideFunctions", false])

disableSerialization;

private _display = findDisplay IDD_VARIABLEVIEWER;

params [["_ctrlLNB", CTRL(IDC_VARIABLEVIEWER_LIST), [controlNull]]];

private _searchText = toLower ctrlText CTRL(IDC_VARIABLEVIEWER_SEARCH);
private _namespace = call ENH_fnc_variableViewer_getNamespace;
private _counter = 0;

lbClear _ctrlLNB;

{
    private _variableValue = _namespace getVariable _x;

    if (HIDE_FNC && {"_fnc" in _x && {_variableValue isEqualType {}}}) then {continue};
    if (_searchText != "" && {!(_searchText in _x)}) then {continue};

    _ctrlLNB lnbAddRow
    [
        _x,
        format ["%1", _variableValue],
        typeName _variableValue
    ];
    _counter = _counter + 1;
} forEach allVariables _namespace;

CTRL(IDC_VARIABLEVIEWER_VARIABLECOUNT) ctrlSetText format ["#%1", _counter];
