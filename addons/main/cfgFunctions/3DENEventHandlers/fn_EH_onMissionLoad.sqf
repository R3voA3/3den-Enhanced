#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-06-05

    Description:
    Is called by Eden event handler onMissionLoad.

    Parameter(s):
    -

    Returns:
    -
*/

// Initialize ambient animations
call ENH_fnc_ambientAnimations_initInEditor;

// Enable 3DEN Radio
call ENH_fnc_3DENRadio_toggleRadio;

// Collapse left tree view (entity list). A small delay is needed to let the list fully load first
if (profileNamespace getVariable ["ENH_EditorPreferences_Interface_CollapseEntityList", false]) then
{
    spawn
    {
        sleep 0.1;
        ["collapseEntityList"] call BIS_fnc_3DENInterface;
    };
};
