#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-05-03

    Description:
    Handles the RPTViewer GUI.

    Parameter(s):
    0: STRING - Mode, can be "open" or "update"

    Returns:
    -
*/

#define LINES (uiNamespace getVariable ["ENH_RPTViewer_Lines", 100])

if !(isClass (configFile >> "CfgPatches" >> "PY3_Pythia")) exitWith
{
    ["ENH_GetPythiaMod_Warning", 1, 10] call BIS_fnc_3DENNotification;
};

disableSerialization;

params [["_mode", "open"]];
private _display = displayNull;

switch _mode do
{
    case "open":
    {
        _display = findDisplay IDD_DISPLAY3DEN createDisplay "ENH_RPTViewer";
        uiNamespace setVariable ["ENH_RPTViewer_Display", _display];
    };
    case "update":
    {
        _display = uiNamespace getVariable ["ENH_RPTViewer_Display", displayNull];
        uiNamespace setVariable ["ENH_RPTViewer_Lines", parseNumber (ctrlText CTRL(IDC_RPTVIEWER_LINES))];
    };
};

private _text = ["ENH_Pythia.RPT_read", [LINES]] call (uiNamespace getVariable "py3_fnc_callExtension");
private _fileName = ["ENH_Pythia.RPT_name"] call (uiNamespace getVariable "py3_fnc_callExtension");
private _fileSize = ["ENH_Pythia.RPT_size"] call (uiNamespace getVariable "py3_fnc_callExtension");

(systemTime apply {if (_x < 10) then {"0" + str _x} else {str _x}}) params ["", "", "", "_h", "_min", "_s"];

private _ctrlEdit = CTRL(IDC_RPTVIEWER_EDIT);
_ctrlEdit ctrlSetText _text;
CTRL(IDC_RPTVIEWER_TITLE) ctrlSetText format ["%1 / %2 kB / %3:%4:%5", _fileName, _fileSize, _h, _min, _s];
CTRL(IDC_RPTVIEWER_LINES) ctrlSetText str LINES;

// Adjust the height of the edit control properly
_ctrlEdit ctrlSetPositionH (ctrlTextHeight _ctrlEdit max (ctrlPosition CTRL(IDC_RPTVIEWER_GROUP) # 3));
_ctrlEdit ctrlCommit 0;
