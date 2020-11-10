/*
    Author: R3vo

    Date: 2020-11-04

    Description:
    Updates Functions Viewer key controls according to found keys.

    Parameter(s):
    0: CONTROL - Button
    1: NUMBER - Increment

    Returns:
    BOOLEAN: true
*/

params ["_ctrlButton","_increment"];

private _display = ctrlParent _ctrlButton;
private _currentIndex = uiNamespace getVariable ["ENH_FunctionsViewer_CurIndex",0];
private _indices = uiNamespace getVariable ["ENH_FunctionsViewer_SearchIndices",[]];
private _indicesCount = count _indices;

if (_indices isEqualTo []) exitWith
{
    (_display displayCtrl 2100) ctrlSetText "";
    false
};

private _newIndex = if (_increment < 0) then
{
    (_currentIndex + _increment) max 0;
}
else
{
    (_currentIndex + _increment) min (_indicesCount -1);
};

(_display displayCtrl 2100) ctrlSetText format ["%1 / %2",_newIndex + 1,_indicesCount];

(_display displayCtrl 1401) ctrlSetTextSelection
[
    _indices select _newIndex,
    count (uiNamespace getVariable ["ENH_FunctionsViewer_Key",""])
];

uiNamespace setVariable ["ENH_FunctionsViewer_CurIndex",_newIndex];

true