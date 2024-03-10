#define DEFAULT_SIZE 50
#include "\3denEnhanced\defines\defineCommon.inc"
disableSerialization;

private _display = findDisplay IDD_DISPLAY3DEN;
ENH_Garrison_SelectedEntities = [["Object", "Logic", "Trigger"]] call ENH_fnc_all3DENSelected;

//Create area helper
ENH_Garrison_AreaHelper = create3DENEntity ["Trigger", "EmptyDetector", screenToWorld [0.5, 0.5]];

//Set up default size
ENH_Garrison_AreaHelper set3DENAttribute ["text", "ENH_Garrison_AreaHelper"];
ENH_Garrison_AreaHelper set3DENAttribute ["size3", [DEFAULT_SIZE, DEFAULT_SIZE, -1]];

ENH_Garrison_OnSelectionChange_EH = add3DENEventHandler ["OnSelectionChange",
{
  private _newSelection = [["Object", "Logic", "Trigger"]] call ENH_fnc_all3DENSelected;

  //Only update selection if it makes sense
  if (_newSelection isEqualTo [] || _newSelection isEqualTo [ENH_Garrison_AreaHelper]) exitWith {};

  ENH_Garrison_SelectedEntities = _newSelection - [ENH_Garrison_AreaHelper] - ENH_Garrison_ValidBuildings;
}];


//Add event handlers that should remove the UI
ENH_Garrison_AreaHelper addEventHandler ["UnregisteredFromWorld3DEN",
{
  call ENH_fnc_garrison_onUnload;
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
_ctrlMode lbAdd "Closest Building only";
_ctrlMode lbSetTooltip [0, "Only the closest building to the center will be garrisoned."];
_ctrlMode lbAdd "From Center";
_ctrlMode lbSetTooltip [1, "Positions closer to the center will be filled first."];
_ctrlMode lbAdd "Random Positions";
_ctrlMode lbSetTooltip [2, "A random position inside the area will be picked for each entity."];

//Set default selection
CTRL(IDC_GARRISON_PATH) lbSetCurSel 1;
CTRL(IDC_GARRISON_COVERAGE) lbSetCurSel 3;
_ctrlMode lbSetCurSel 0;

//Draw building positions and buildings
true call ENH_fnc_garrison_drawBuildingInfo;