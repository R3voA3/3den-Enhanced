#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-06-05

    Description:
    Is called by Eden event handler onTerrainNew.

    Parameter(s):
    -

    Returns:
    -
*/

// Show or hide panels
["ShowPanelRight", profileNamespace getVariable ["ENH_EditorPreferences_Interface_ShowPanelRight", true]] call BIS_fnc_3DENInterface;
["ShowPanelLeft", profileNamespace getVariable ["ENH_EditorPreferences_Interface_ShowPanelLeft", true]] call BIS_fnc_3DENInterface;

// Collapse asset browser
call ENH_fnc_assetBrowser_collapse;

// Init favorites list
["onLoad", []] call ENH_fnc_favoritesList;

// Update location list
["init"] call ENH_fnc_locationList_enhanced;

// Enable 3DEN Radio
call ENH_fnc_3DENRadio_toggleRadio;

// Initialize ambient animations
call ENH_fnc_ambientAnimations_initInEditor;
