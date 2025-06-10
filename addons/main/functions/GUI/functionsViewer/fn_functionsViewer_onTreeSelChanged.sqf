#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Used by the ENH_FunctionViewer GUI. Called when selection of tv tree control has changed.

    Parameter(s):
    0: CONTROL - Tree Control
    1: ARRAY - Path

    Returns:
    -
*/

disableSerialization;
forceUnicode 0;

private _display = uiNamespace getVariable ["ENH_Display_FunctionsViewer", displayNull];

params
[
    ["_ctrlTV", CTRL(IDC_FUNCTIONSVIEWER_LIST)],
    ["_path", tvCurSel CTRL(IDC_FUNCTIONSVIEWER_LIST)]
];

private _ctrlCode = CTRL(IDC_FUNCTIONSVIEWER_CODE);
private _ctrlLines = CTRL(IDC_FUNCTIONSVIEWER_LINES);
private _data = _ctrlTV tvData _path;
private _linesText = "";

// If a category is selected, exit and disable biki entry
if (_data isEqualTo "") exitWith {CTRL(IDC_FUNCTIONSVIEWER_MENU) menuEnable [[2, 1], false]};

CTRL(IDC_FUNCTIONSVIEWER_GROUP) ctrlSetScrollValues [0, 0];

_data = call compile _data;
_data params ["_fileName", "_filePath"];// Filename is also Function name

CTRL(IDC_FUNCTIONSVIEWER_NAME) ctrlSetText _fileName;
CTRL(IDC_FUNCTIONSVIEWER_PATH) ctrlSetText _filePath;

private _loadFileIndex = profileNamespace getVariable ["ENH_FunctionsViewer_LoadFileIndex", 0];

private _text = call
{
    if (_loadFileIndex == 0) exitWith {loadFile _filePath};
    if (_loadFileIndex == 1) exitWith {preprocessFile _filePath};
    if (_loadFileIndex == 2) exitWith {preprocessFileLineNumbers _filePath};
};

_ctrlCode ctrlSetText _text;

CTRL(IDC_FUNCTIONSVIEWER_MENU) menuSetURL [[2, 1], format ["https:// community.bistudio.com/wiki/%1", _fileName]];
CTRL(IDC_FUNCTIONSVIEWER_MENU) menuEnable [[2, 1], _fileName select [0, 3] in ["BIS", "BIN"]];

private _textHeight = (safeZoneH - 26 * GRID_H) max (ctrlTextHeight _ctrlCode);
private _numLines = count (_text regexFind ["\r\n", 0]) + 5;

// Get the number of lines that should be displayed
for "_i" from 1 to _numLines do
{
    _linesText = _linesText + format ["%1<br/>", _i];
};

// When a new function is selected, change scroll width and height dynamically
_ctrlCode ctrlSetPositionH _textHeight;
_ctrlCode ctrlCommit 0;

_ctrlLines ctrlSetPositionH _textHeight;
_ctrlLines ctrlCommit 0;
_ctrlLines ctrlSetStructuredText parseText _linesText;

profileNamespace setVariable ["ENH_FunctionsViewer_LastViewed", _filePath];
saveProfileNamespace;
