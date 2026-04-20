#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-02-11

    Description:
    Used by the ENH_VariableViewer GUI. Called when listNbox selection changed.

    Parameter(s):
    0: CONTROL - ListNBox control
    1: NUMBER - Selected index

    Returns:
    -
*/

disableSerialization;
params ["_ctrlLNB", "_selectedRow"];

private _display = ctrlParent _ctrlLNB;
private _conditionDisable = !(_ctrlLNB lnbText [_selectedRow, 2] in ["STRING", "SCALAR", "CODE", "BOOL"]);

if _conditionDisable then
{
    CTRL(IDC_VARIABLEVIEWER_VARIABLENAME) ctrlSetText "";
    CTRL(IDC_VARIABLEVIEWER_VARIABLEVALUE) ctrlSetText "";
}
else
{
    CTRL(IDC_VARIABLEVIEWER_VARIABLENAME) ctrlSetText (_ctrlLNB lnbText [_selectedRow, 0]);
    CTRL(IDC_VARIABLEVIEWER_VARIABLEVALUE) ctrlSetText (_ctrlLNB lnbText [_selectedRow, 1]);
};

CTRL(IDC_VARIABLEVIEWER_VARIABLENAME) ctrlEnable !_conditionDisable;
CTRL(IDC_VARIABLEVIEWER_VARIABLEVALUE) ctrlEnable !_conditionDisable;
CTRL(IDC_VARIABLEVIEWER_SET) ctrlEnable !_conditionDisable;
CTRL(IDC_VARIABLEVIEWER_DELETE) ctrlEnable !_conditionDisable;
