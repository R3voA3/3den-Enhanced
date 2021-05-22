#define DEFAULT_SIZE 50
#include "\3denEnhanced\ENH_defineCommon.hpp"
disableSerialization;

private _display = findDisplay IDD_3DEN;
ENH_Garrison_SelectedEntities = [["Object", "Logic", "Trigger"]] call ENH_fnc_all3DENSelected;

//Check if module was places previously and if not, create it
ENH_Garrison_AreaHelper = get3DENEntity (uiNamespace getVariable ["ENH_Garrison_AreaHelper_3DENID", -1]);

if (ENH_Garrison_AreaHelper isEqualTo -1) then
{
  ENH_Garrison_AreaHelper = create3DENEntity ["Logic", "ModuleCoverMap_F", screenToWorld [0.5, 0.5]];
  uiNamespace setVariable ["ENH_Garrison_AreaHelper_3DENID", get3DENEntityID ENH_Garrison_AreaHelper];
};

//Set up default module attributes
ENH_Garrison_AreaHelper set3DENAttribute ["Name", "ENH_Garrison_AreaHelper"];
ENH_Garrison_AreaHelper set3DENAttribute ["Size2", [DEFAULT_SIZE, DEFAULT_SIZE]];

//Workaround to make sure the cover map module is not present in scenario. Super hacky, but there is no reliable way to deleted it otherwise
ENH_Garrison_AreaHelper set3DENAttribute ["Init", "this spawn {sleep 0.1; deleteVehicle _this; [objNull, [], false] call BIS_fnc_moduleCoverMap;};"];

//Init default values and update UI
ENH_Garrison_AreaHelper call ENH_fnc_garrison_updateValues;

ENH_Garrison_AreaHelper addEventHandler ["AttributesChanged3DEN",
{
  params ["_object"];
  _object call ENH_fnc_garrison_updateValues;
}];

ENH_Garrison_AreaHelper addEventHandler ["UnregisteredFromWorld3DEN",
{
  ctrlDelete CTRL(IDC_GARRISON_GROUP);
  ENH_Garrison_AreaHelper = nil;
  //Remove icons
  false call ENH_fnc_garrison_drawBuildingInfo;
}];

CTRL(IDC_GARRISON_BLACKLIST_VALUE) ctrlAddEventHandler ["KeyUp",
{
  ENH_Garrison_AreaHelper call ENH_fnc_garrison_updateValues;
}];

CTRL(IDC_GARRISON_COVERAGE) ctrlAddEventHandler ["ToolBoxSelChanged",
{
  ENH_Garrison_AreaHelper call ENH_fnc_garrison_updateValues;
}];

CTRL(IDC_GARRISON_BLACKLIST_TOGGLE) ctrlAddEventHandler ["ToolBoxSelChanged",
{
  ENH_Garrison_AreaHelper call ENH_fnc_garrison_updateValues;
}];

CTRL(IDC_GARRISON_UPDATE_SELECTION) ctrlAddEventHandler ["ButtonClick",
{
  ENH_Garrison_SelectedEntities = [["Object", "Logic", "Trigger"]] call ENH_fnc_all3DENSelected;
  ENH_Garrison_SelectedEntities = ENH_Garrison_SelectedEntities - [ENH_Garrison_AreaHelper] - ENH_Garrison_ValidBuildings;
  ENH_Garrison_AreaHelper call ENH_fnc_garrison_updateValues;
}];

CTRL(IDC_GARRISON_CANCEL) ctrlAddEventHandler ["ButtonClick",
{
  call ENH_fnc_garrison_onUnload;
}];

CTRL(IDC_GARRISON_OK) ctrlAddEventHandler ["ButtonClick",
{
  call ENH_fnc_garrison_fillBuildings;
}];

do3DENAction "WidgetArea";

private _ctrlMode = CTRL(20004);
_ctrlMode lbAdd "Closest Building only";
_ctrlMode lbSetTooltip [0, "Only the closest building to the center (ENH_Garrison_AreaHelper) will be garrisoned."];
_ctrlMode lbAdd "From Center";
_ctrlMode lbSetTooltip [1, "Positions closer to the center will be filled first."];
_ctrlMode lbAdd "Random Positions";
_ctrlMode lbSetTooltip [2, "A random position inside the area (ENH_Garrison_AreaHelper) will be picked for each entity."];


//Set default selection
CTRL(IDC_GARRISON_PATH) lbSetCurSel 1;
CTRL(IDC_GARRISON_COVERAGE) lbSetCurSel 3;
_ctrlMode lbSetCurSel 0;

//Draw building positions and buildings
true call ENH_fnc_garrison_drawBuildingInfo;