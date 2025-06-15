#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Used by the ENH_FunctionViewer GUI. Called on load.

    Parameter(s):
    0: DISPLAY - Display

    Returns:
    -
*/

disableSerialization;
params ["_display"];

uiNamespace setVariable ["ENH_Display_FunctionsViewer", _display];

ENH_FunctionsData = call ENH_fnc_functionsViewer_getFunctionsData;

CTRL(IDC_FUNCTIONSVIEWER_LIST) ctrlAddEventHandler ["TreeSelChanged", ENH_fnc_functionsViewer_onTreeSelChanged];

_display displayAddEventHandler ["KeyDown", // Focus Search
{
    params ["_display", "_key", "_shift", "_ctrl"];
    if (_key isEqualTo 33 && _ctrl && !_shift) then
    {
        ctrlSetFocus CTRL(IDC_FUNCTIONSVIEWER_SEARCH);
    }
}];

_display displayAddEventHandler ["KeyDown", // Focus Search Key
{
    params ["_display", "_key", "_shift", "_ctrl"];
    if (_key isEqualTo 33 && _ctrl && _shift) then
    {
        ctrlSetFocus CTRL(IDC_FUNCTIONSVIEWER_SEARCHCODE);
    }
}];

call ENH_fnc_functionsViewer_fillCtrlTV;

[CTRL(IDC_FUNCTIONSVIEWER_SEARCH), CTRL(IDC_FUNCTIONSVIEWER_BUTTONSEARCH)] call ENH_fnc_initSearchControls;
