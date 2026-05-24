#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-11-04

    Description:
    Searches code in Functions Viewer for specific key word.

    Parameter(s):
    0: CONTROL - Search

    Returns:
    BOOLEAN: true
*/

disableSerialization;
params ["_ctrlSearchCode"];

private _display = ctrlParent _ctrlSearchCode;

private _key = toLower ctrlText CTRL(IDC_FUNCTIONSVIEWER_SEARCHCODE);
private _text = toLower ctrlText CTRL(IDC_FUNCTIONSVIEWER_CODE);

private _fnc_findStringsInString =
{
    params ["_text", "_key"];
    if (_text == "" || {_key == ""}) exitWith {[]};
    private _searchLength = count _key;
    private _return = [];
    private _i = 0;
    private _index = 0;
    while {_index = _text find _key; _index != -1} do
    {
        _text = _text select [_index + _searchLength];
        _i = _i + _index + _searchLength;
        _return pushBackUnique _i - _searchLength;
    };
    _return
};

private _indices = [_text, _key] call _fnc_findStringsInString;

uiNamespace setVariable ["ENH_FunctionsViewer_SearchIndices", _indices];
uiNamespace setVariable ["ENH_FunctionsViewer_Key", _key];
uiNamespace setVariable ["ENH_FunctionsViewer_CurIndex", 0];

[_ctrlSearchCode, 0] call ENH_fnc_functionsViewer_incrementKey;

true
