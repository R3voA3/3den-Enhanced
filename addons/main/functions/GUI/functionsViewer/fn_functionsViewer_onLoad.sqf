/*
    Author: R3vo

    Description:
    Used by the ENH_FunctionViewer GUI. Called on load.

    Parameter(s):
    0: DISPLAY - Display

    Returns:
    -
*/
#include "\x\enh\addons\main\script_component.hpp"

disableSerialization;
params ["_display"];

uiNamespace setVariable ["ENH_Display_FunctionsViewer", _display];

ENH_FunctionsData = call ENH_fnc_functionsViewer_getFunctionsData;

_display displayCtrl IDC_FUNCTIONSVIEWER_LIST ctrlAddEventHandler ["TreeSelChanged", ENH_fnc_functionsViewer_onTreeSelChanged];

_display displayAddEventHandler ["KeyDown", //Focus Search
{
    params ["_display", "_key", "_shift", "_ctrl"];
    if (_key isEqualTo 33 && _ctrl && !_shift) then
    {
        ctrlSetFocus CTRL(IDC_FUNCTIONSVIEWER_SEARCH);
    }
}];

_display displayAddEventHandler ["KeyDown", //Focus Search Key
{
    params ["_display", "_key", "_shift", "_ctrl"];
    if (_key isEqualTo 33 && _ctrl && _shift) then
    {
        ctrlSetFocus CTRL(IDC_FUNCTIONSVIEWER_SEARCHCODE);
    }
}];

call ENH_fnc_functionsViewer_fillCtrlTV;

//Handle search button
CTRL(IDC_FUNCTIONSVIEWER_SEARCH) ctrlAddEventHandler ["EditChanged",
{
    params ["_ctrlEdit", "_newText"];

    private _image = [TEXTURE_SEARCH_END, TEXTURE_SEARCH_START] select (_newText == "");

    ctrlParent _ctrlEdit displayCtrl IDC_FUNCTIONSVIEWER_BUTTONSEARCH ctrlSetText _image;
}];

//Handle search button
CTRL(IDC_FUNCTIONSVIEWER_BUTTONSEARCH) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];

    //Change search button icon and clear edit control to reset tree view filter
    ctrlParent _ctrlButton displayCtrl IDC_FUNCTIONSVIEWER_SEARCH ctrlSetText "";
    _ctrlButton ctrlSetText TEXTURE_SEARCH_START;
}];
