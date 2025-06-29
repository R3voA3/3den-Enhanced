#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-20

    Description:
    Adjusts font size of attribute title controls so they fit into their control.

    Parameter(s):
    0: CONTROL - Title control

    Return Value:
    NOTHING
*/

params ["_ctrlTitle"];

if (profileNamespace getVariable ["ENH_EditorPreferences_Interface_AdjustTitleTextWidth", true]) then
{
    private _text = ctrlText _ctrlTitle;
    private _textOriginal = _text;
    private _tooltip = ctrlTooltip _ctrlTitle;
    private _charCount = 4; // First step substracts one char + 3 for "..."
    private _textAltered = false;

    while {ctrlTextWidth _ctrlTitle > (ATTRIBUTE_TITLE_W * GRID_W)} do
    {
        _text = (_text select [0, count _text - _charCount]) + "...";
        _ctrlTitle ctrlSetText _text;
        _charCount = _charCount + 1;
        _textAltered = true;
    };

    if (_textAltered && {_tooltip != _textOriginal}) then
    {
        if (_tooltip != "") then
        {
            _ctrlTitle ctrlSetTooltip (format ["%1%2%3%4", _textOriginal, endl, endl, ctrlTooltip _ctrlTitle]);
        }
        else // If the tooltip is empty we don't want to append empty lines
        {
            _ctrlTitle ctrlSetTooltip _textOriginal;
        };
    };
};

nil
