#include "\x\enh\addons\main\script_component.hpp"

disableSerialization;

private _display = findDisplay IDD_DISPLAY3DEN;
ENH_Garrison_SelectedEntities = [["Object", "Logic", "Trigger"]] call ENH_fnc_all3DENSelected;

// Create area helper
ENH_Garrison_AreaHelper = create3DENEntity ["Trigger", "EmptyDetector", screenToWorld [CENTER_X, CENTER_Y]];

// Set up default size
ENH_Garrison_AreaHelper set3DENAttribute ["text", "ENH_Garrison_AreaHelper"];
ENH_Garrison_AreaHelper set3DENAttribute ["size3", [50, 50, -1]];

ENH_Garrison_OnSelectionChange_EH = add3DENEventHandler ["OnSelectionChange",
{
    private _newSelection = [["Object", "Logic", "Trigger"]] call ENH_fnc_all3DENSelected;

    // Only update selection if it makes sense
    if (_newSelection isEqualTo [] || _newSelection isEqualTo [ENH_Garrison_AreaHelper]) exitWith {};

    ENH_Garrison_SelectedEntities = _newSelection - [ENH_Garrison_AreaHelper] - ENH_Garrison_ValidBuildings;
}];

ENH_Garrison_OnDeleteUnits_EH = add3DENEventHandler ["OnDeleteUnits",
{
    // Check if area helper trigger is still present
    if (all3DENEntities # 2 findIf {_x == ENH_Garrison_AreaHelper} == -1) then
    {
        ENH_Garrison_AreaHelper = objNull;
        call ENH_fnc_garrison_onUnload;
    };
}];

ENH_Garrison_OnBeforeMissionPreview_EH = add3DENEventHandler ["OnBeforeMissionPreview",
{
    call ENH_fnc_garrison_onUnload;
}];

ENH_Garrison_OnMissionNew_EH = add3DENEventHandler ["OnMissionNew",
{
    call ENH_fnc_garrison_onUnload;
}];

ENH_Garrison_OnMissionLoad_EH = add3DENEventHandler ["OnMissionLoad",
{
    call ENH_fnc_garrison_onUnload;
}];

ENH_Garrison_OnTerrainNew_EH = add3DENEventHandler ["OnTerrainNew",
{
    call ENH_fnc_garrison_onUnload;
}];

CTRL(IDC_GARRISON_CANCEL) ctrlAddEventHandler ["ButtonClick",
{
    call ENH_fnc_garrison_onUnload;
}];

CTRL(IDC_GARRISON_OK) ctrlAddEventHandler ["ButtonClick",
{
    call ENH_fnc_garrison_fillBuildings;
}];

CTRL(IDC_GARRISON_BLACKLIST_VALUE) ctrlSetText (profileNamespace getVariable ["ENH_Garrison_Classes", ""]);

do3DENAction "WidgetScale";

private _ctrlMode = CTRL(IDC_GARRISON_MODE);
_ctrlMode lbAdd localize "$STR_ENH_MAIN_GARRISON_CLOSEST_BUILDING_TEXT";
_ctrlMode lbSetTooltip [0, localize "$STR_ENH_MAIN_GARRISON_CLOSEST_BUILDING_TOOLTIP"];

_ctrlMode lbAdd localize "$STR_ENH_MAIN_GARRISON_FROM_CENTER_TEXT";
_ctrlMode lbSetTooltip [1, localize "$STR_ENH_MAIN_GARRISON_FROM_CENTER_TOOLTIP"];

_ctrlMode lbAdd localize "$STR_ENH_MAIN_GARRISON_RANDOM_POSITIONS_TEXT";
_ctrlMode lbSetTooltip [2, localize "$STR_ENH_MAIN_GARRISON_RANDOM_POSITIONS_TOOLTIP"];

// Set default selection
CTRL(IDC_GARRISON_PATH) lbSetCurSel 1;
CTRL(IDC_GARRISON_COVERAGE) lbSetCurSel 3;
_ctrlMode lbSetCurSel 0;

// Draw building positions and buildings
true call ENH_fnc_garrison_draw;
