/*
  Author: R3vo

  Date: 2019-06-05

  Description:
  Is called by Eden event handler onMissionLoad. Content of this function may be altered by ENH_Config.hpp.

  Parameter(s):
  -

  Returns:
  -
*/

//Initialize ambient animations
call ENH_fnc_ambientAnimations_initInEditor;

//Enable 3DEN Radio
call ENH_fnc_3DENRadio_toggleRadio;

//Enable dynamic view distance
call ENH_fnc_dynamicViewDistance;

//Enable session timer
0 spawn ENH_fnc_statusbar_sessionTimer;

//Collapse left tree view (entity list). A small delay is needed to let the list fully load first
if (profileNamespace getVariable ['ENH_EditorPreferences_Interface_CollapseEntityList', false]) then
{
  0 spawn
  {
    sleep 0.1;
    ["collapseEntityList"] call BIS_fnc_3DENInterface;
  };
};

//Add tooltips to entity browser so that long names are not cut off
(findDisplay 313 displayCtrl 55) ctrlAddEventHandler ["MouseEnter", ENH_fnc_entityList_addTooltips];

//Init direction display
addMissionEventHandler ["EachFrame",
{
  private _dir = round getDir get3DENCamera;
  private _dir = switch (count str _dir) do
  {
    case 1: {format ["00%1 °", _dir]};
    case 2: {format ["0%1 °", _dir]};
    default {format ["%1 °", _dir]};
  };
  findDisplay 313 displayCtrl 681 ctrlSetText _dir;
}];

//Enable Minimap
"init" call ENH_fnc_3DENMinimap;