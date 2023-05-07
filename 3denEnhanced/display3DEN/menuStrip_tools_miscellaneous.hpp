class ENH_Folder_Miscellaneous
{
  text = "$STR_ENH_FOLDER_MISCELLANEOUS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_CreateTrigger",
    "ENH_ExportMissionParameters",
    "ENH_GenerateSteamMissionDescription",
    "Separator",
    "ENH_SwitchTime",
    "ENH_ToggleGrass",
    "Separator",
    "ENH_ToggleSimpleObject",
    "ENH_ToggleSimulation",
    "ENH_ToggleDynamicSimulation",
    "ENH_TogglePlayable",
    "ENH_ToggleIsLocalOnly",
    "ENH_ToggleAIFeatures",
    "ENH_ToggleMarkerAlpha"
  };
};
class ENH_SwitchTime
{
  text = "$STR_ENH_TOOLS_SWITCHTIME";
  picture = "\A3\ui_f\data\igui\cfg\actions\settimer_ca.paa";
  action = "call ENH_fnc_switchTime";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_UP};
};
class ENH_ToggleGrass
{
  text = "$STR_ENH_TOOLS_TOGGLEGRASS";
  action = "[] spawn ENH_fnc_toggleGrass";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_DOWN};
};
class ENH_ToggleSimpleObject
{
  text = "$STR_ENH_TOOLS_TOGGLESIMPLEOBJECT";
  picture = "";
  action = "[['Object'], ['objectIsSimple']] call ENH_fnc_toggleAttributes";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_S};
};
class ENH_ToggleSimulation
{
  text = "$STR_ENH_TOOLS_TOGGLESIMULATION";
  picture = "";
  action = "[['Object'], ['enableSimulation']] call ENH_fnc_toggleAttributes";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_E};
};
class ENH_ToggleDynamicSimulation
{
  text = "$STR_ENH_TOOLS_TOGGLEDYNAMICSIMULATION";
  picture = "";
  action = "[['Object', 'Group'], ['dynamicSimulation']] call ENH_fnc_toggleAttributes";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_D};
};
class ENH_ToggleIsLocalOnly
{
  text = "$STR_ENH_TOOLS_TOGGLEISLOCALONLY";
  picture = "";
  action = "[['Object'], ['isLocalOnly']] call ENH_fnc_toggleAttributes";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_L};
};
class ENH_ToggleAIFeatures
{
  text = "$STR_ENH_TOOLS_TOGGLEAIFEATURES";
  action = "[['object'], ['ENH_disableAI_all']] call ENH_fnc_toggleAttributes";
};
class ENH_TogglePlayable
{
  text = "$STR_ENH_TOOLS_PLAYABLE";
  action = "[['Object'], ['ControlMP']] call ENH_fnc_toggleAttributes";
  picture = "\a3\3den\data\cfg3den\object\iconplayer_ca.paa";
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_P};
};
class ENH_ToggleMarkerAlpha
{
  text = "$STR_ENH_TOOLS_TOGGLEMARKERALPHA";
  action = "call ENH_fnc_toggleMarkerAlpha";
  picture = "\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
  shortcuts[] = {DIK_V};
};
class ENH_GenerateSteamMissionDescription
{
  text = "$STR_ENH_TOOLS_GENERATESTEAMMISSIONDESCRIPTION";
  action = "[] spawn ENH_fnc_generateSteamMissionDescription";
  opensNewWindow = 1;
};
class ENH_ExportMissionParameters
{
  text = "$STR_ENH_TOOLS_EXPORTMISSIONPARAMETERS";
  action = "call ENH_fnc_exportMissionParams";
};
class ENH_CreateTrigger
{
  text = "$STR_ENH_TOOLS_CREATETRIGGER";
  picture = "\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
  action = "private _trigger = create3DENEntity ['Trigger', 'EmptyDetectorArea10x10', [worldSize / 2, worldSize / 2, 0]]; _trigger set3DENAttribute ['size3', [worldSize / 2, worldSize / 2, 0]]; ['ENH_ActionPerformed'] call BIS_fnc_3DENNotification";
};