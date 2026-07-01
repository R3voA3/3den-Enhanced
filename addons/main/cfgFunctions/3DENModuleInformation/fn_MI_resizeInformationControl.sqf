#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-10-06

    Description:
    This is an awesome description.

    Parameter(s):
    0: CONTROL - Structured Text Control of ENH_ModuleInformation GUI.

    Return Value:
    NOTHING
*/

params ["_ctrlStructuredText"];

// Resize control but only as small as controls group
_ctrlStructuredText ctrlSetPositionH ((ctrlTextHeight _ctrlStructuredText) max (ctrlPosition (ctrlParentControlsGroup _ctrlStructuredText) # 3));
_ctrlStructuredText ctrlCommit 0;

nil
