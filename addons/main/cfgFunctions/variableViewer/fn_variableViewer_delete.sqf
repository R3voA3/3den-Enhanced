#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-02-11

    Description:
    Used by the ENH_VariableViewer GUI. Deletes an entry from listNBox.

    Parameter(s):
    0: CONTROL - Button control

    Returns:
    BOOLEAN: true / false
*/

disableSerialization;
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _ctrlLNB = CTRL(IDC_VARIABLEVIEWER_LIST);
private _selectedRows = lbSelection _ctrlLNB;
// If nothing selected, exit
if (_selectedRows isEqualTo []) exitWith {false};

_display call ENH_fnc_variableViewer_messageConfirm;

waitUntil {!isNil "ENH_VariableViewer_Modify_Confirmed"};

// Deletion request needs to be confirmed twice
if (ENH_VariableViewer_Modify_Confirmed) then
{
    private _namespace = call ENH_fnc_variableViewer_getNamespace;

    // Reverse array, otherwise indexes will change if entry gets deleted
    reverse _selectedRows;
    // Delete variables
    {
        private _LNBData = _ctrlLNB lnbText [_x, 0];
        _namespace setVariable [_LNBData, nil];
        _ctrlLNB lbSetSelected [_x, false];
        _ctrlLNB lnbDeleteRow _x;
    } forEach _selectedRows;

    // Reduce variable count by one
    CTRL(IDC_VARIABLEVIEWER_VARIABLECOUNT) ctrlSetText format ["#%1", lnbSize _ctrlLNB select 0];
};

ENH_VariableViewer_Modify_Confirmed = nil;

true
