#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-06-14

    Description:
    Used by the ENH_ESE GUI. Adds an item to a listNbox.

    Parameter(s):
    0: CONTROL - Control ListNbox
    1: STRING - Item Data
    2: STRING - Item Text
    3: STRING - Image of the first column
    4: STRING - Image of the forth column
    5: NUMBER - Value set in the second column (Text of second column will be that value)
    6: STRING - Tooltip

    Returns:
    -
*/

disableSerialization;

params ["_ctrlLnb", "_data", "_text", "_image", "_addonIcon", "_value", "_tooltip", "_specificType"];

if (_text != "") then
{
    private _row = _ctrlLnb lnbAddRow ["", _text, str _value, ""];

    // Column #0
    _ctrlLnb lnbSetData [[_row, 0], _data];
    _ctrlLnb lnbSetPicture [[_row, 0], _image];
    _ctrlLnb lnbSetTooltip [[_row, 0], _tooltip];

    // Column #1
    _ctrlLnb lnbSetValue [[_row, 1], _value];
    _ctrlLnb lnbSetData [[_row, 1], _specificType];

    // Column #2 - Count
    _ctrlLnb lnbSetText [[_row, 2], str _value];

    // Column #3 - Addon Icon
    _ctrlLnb lnbSetPicture [[_row, 3], _addonIcon];
    _ctrlLnb lnbSetData [[_row, 3], _addonIcon]
};
