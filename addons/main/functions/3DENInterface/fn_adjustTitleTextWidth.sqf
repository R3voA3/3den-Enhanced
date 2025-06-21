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
    while {ctrlTextWidth _ctrlTitle > (ATTRIBUTE_TITLE_W * GRID_W)} do
    {
        _ctrlTitle ctrlSetFontHeight (ctrlFontHeight _ctrlTitle * 0.95);
    };
};

nil
