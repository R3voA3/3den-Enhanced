#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-02-11

    Description:
    Used by the ENH_VariableViewer GUI. Used to set or create variables in the selected namespace.

    Parameter(s):
    0: CONTROL - Button control

    Returns:
    -
*/

disableSerialization;
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _ctrlLNB = CTRL(IDC_VARIABLEVIEWER_LIST);
private _varName = ctrlText CTRL(IDC_VARIABLEVIEWER_VARIABLENAME);// Does not support groups, objects and locations, only real data types like string, number, array
private _varValue = ctrlText CTRL(IDC_VARIABLEVIEWER_VARIABLEVALUE);

private _varType = _ctrlLNB lnbText [lnbCurSelRow _ctrlLNB, 2];

// Exit if type is not supported (Objects, groups, locations...)
if !(_varType in ["STRING", "SCALAR", "BOOL", "ARRAY", "CODE"]) exitWith {false};

// Exit if no actual value was set
if (_varValue isEqualTo "") exitWith {false};

_display call ENH_fnc_variableViewer_messageConfirm;

waitUntil {!isNil "ENH_VariableViewer_Modify_Confirmed"};

private _namespace = call ENH_fnc_variableViewer_getNamespace;
private _valueTypeNew = call compile _varValue;

// If variable isn't new, only update selected row. Else create new row and re-sort
if (_varName in allVariables _namespace) then
{
    _ctrlLNB lnbSetText [[lnbCurSelRow _ctrlLNB, 1], _varValue];
    _ctrlLNB lnbSetText [[lnbCurSelRow _ctrlLNB, 2], _valueTypeNew];
}
else
{
    _ctrlLNB lnbAddRow [_varName, _varValue, _valueTypeNew];
    _ctrlLNB lnbSort [0, false];
};

// Set variable or create new
_namespace setVariable [_varName, call compile _varValue];
