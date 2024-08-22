class ENH_Folder_Miscellaneous
{
    text = "$STR_ENH_MAIN_FOLDER_MISCELLANEOUS";
    picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
    items[] +=
    {
        "ENH_CreateTrigger",
        "Separator",
        "ENH_SwitchTime",
        "ENH_ToggleGrass",
        "Separator",
        "ENH_ToggleSimpleObject",
        "ENH_ToggleSimulation",
        "ENH_ToggleDynamicSimulation",
        "ENH_TogglePlayable",
        "ENH_ToggleIsLocalOnly",
        "ENH_ToggleAIFeatures"
    };
};
class ENH_CreateTrigger
{
    text = "$STR_ENH_MAIN_TOOLS_CREATETRIGGER";
    picture = "\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
    action = "private _trigger = create3DENEntity ['Trigger', 'EmptyDetectorArea10x10', [worldSize / 2, worldSize / 2, 0]]; _trigger set3DENAttribute ['size3', [worldSize / 2, worldSize / 2, 0]]; ['ENH_ActionPerformed'] call BIS_fnc_3DENNotification";
    wikiDescription = "Creates a trigger which covers exactly the whole map.";
};
class ENH_SwitchTime
{
    text = "$STR_ENH_MAIN_TOOLS_SWITCHTIME";
    picture = "\A3\ui_f\data\igui\cfg\actions\settimer_ca.paa";
    action = "call ENH_fnc_switchTime";
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_UP};
    wikiDescription = "Switches the time and weather in Eden Editor so editing can be done with best visibility. Changes are not applied to the scenario. Press again to revert.";
};
class ENH_ToggleGrass
{
    text = "$STR_ENH_MAIN_TOOLS_TOGGLEGRASS";
    action = "0 spawn ENH_fnc_toggleGrass";
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_DOWN};
    wikiDescription = "Hides grass in Eden Editor.";
};
class ENH_ToggleSimpleObject
{
    text = "$STR_ENH_MAIN_TOOLS_TOGGLESIMPLEOBJECT";
    picture = "";
    action = "[['Object'], ['objectIsSimple']] call ENH_fnc_toggleAttributes";
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_S};
    wikiDescription = "Toggles simple object state of all selected entities.";
};
class ENH_ToggleSimulation
{
    text = "$STR_ENH_MAIN_TOOLS_TOGGLESIMULATION";
    picture = "";
    action = "[['Object'], ['enableSimulation']] call ENH_fnc_toggleAttributes";
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_E};
    wikiDescription = "Toggles simulation of all selected entities.";
};
class ENH_ToggleDynamicSimulation
{
    text = "$STR_ENH_MAIN_TOOLS_TOGGLEDYNAMICSIMULATION";
    picture = "";
    action = "[['Object', 'Group'], ['dynamicSimulation']] call ENH_fnc_toggleAttributes";
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_D};
    wikiDescription = "Toggles dynamic simulation of all selected entities.";
};
class ENH_ToggleIsLocalOnly
{
    text = "$STR_ENH_MAIN_TOOLS_TOGGLEISLOCALONLY";
    picture = "";
    action = "[['Object'], ['isLocalOnly']] call ENH_fnc_toggleAttributes";
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_L};
     wikiDescription = "Toggles the local only attribute of all selected entities.";
};
class ENH_ToggleAIFeatures
{
    text = "$STR_ENH_MAIN_TOOLS_TOGGLEAIFEATURES";
    action = "[['object'], ['ENH_disableAI_all']] call ENH_fnc_toggleAttributes";
    wikiDescription = "Will toggle all AI features (Inverse their state).";
};
class ENH_TogglePlayable
{
    text = "$STR_ENH_MAIN_TOOLS_PLAYABLE";
    action = "[['Object'], ['ControlMP']] call ENH_fnc_toggleAttributes";
    picture = "\a3\3den\data\cfg3den\object\iconplayer_ca.paa";
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_P};
    wikiDescription = "Toggles playable state of all selected entities.";
};