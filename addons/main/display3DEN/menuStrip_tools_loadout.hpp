class ENH_Folder_Loadout
{
    text = "$STR_ENH_MAIN_FOLDER_LOADOUTTOOLS";
    picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
    items[] +=
    {
        "ENH_ESE",
        "ENH_CopyLoadout",
        "ENH_ApplyLoadout",
        "ENH_ExportLoadoutConfig",
        "ENH_ExportLoadoutCfgRespawnInventory",
        "Separator",
        "ENH_RemoveNVGs",
        "ENH_RemoveVests",
        "ENH_RemoveGoggles",
        "ENH_RemoveHeadgear",
        "ENH_RemoveWeapons",
        "ENH_RemoveGear"
    };
};
class ENH_CopyLoadout
{
    text = "$STR_ENH_MAIN_TOOLS_COPYLOADOUTS";
    action = "'copy' call ENH_fnc_loadoutTool";
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_C};
    wikiDescription = "Copies loadout of all selected entities.";
};
class ENH_ApplyLoadout
{
    text = "$STR_ENH_MAIN_TOOLS_APPLYLOADOUTS";
    action = "'apply' call ENH_fnc_loadoutTool";
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_A};
    wikiDescription = "Applies copied loadouts to all selected entities. If multiple loadouts were copied a random one for each selected entity is choosen.";
};
class ENH_ExportLoadoutCfgRespawnInventory
{
    text = "$STR_ENH_MAIN_TOOLS_EXPORTLOADOUT_CFGRESPAWNINVENTORY";
    action = "false call ENH_fnc_exportLoadout";
    wikiDescription = "Exports loadout in CfgRespawnInventory format.";
};
class ENH_ExportLoadoutConfig
{
    text = "$STR_ENH_MAIN_TOOLS_EXPORTLOADOUT_CONFIG";
    action = "true call ENH_fnc_exportLoadout";
    wikiDescription = "Exports loadout in config format.";
};
class ENH_RemoveNVGs
{
    text = "$STR_ENH_MAIN_TOOLS_REMOVENVGS";
    action = "2 call ENH_fnc_removeGear";
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_N};
    wikiDescription = "Removes NVG of all selected entities.";
};
class ENH_RemoveVests
{
    text = "$STR_ENH_MAIN_TOOLS_REMOVEVESTS";
    action = "3 call ENH_fnc_removeGear";
    wikiDescription = "Removes vest of all selected entities.";
};
class ENH_RemoveGoggles
{
    text = "$STR_ENH_MAIN_TOOLS_REMOVEGOGGLES";
    action = "0 call ENH_fnc_removeGear";
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_G};
    wikiDescription = "Removes goggles of all selected entities.";
};
class ENH_RemoveHeadgear
{
    text = "$STR_ENH_MAIN_TOOLS_REMOVEHEADGEAR";
    action = "1 call ENH_fnc_removeGear";
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_H};
    wikiDescription = "Removes headgear of all selected entities.";
};
class ENH_RemoveWeapons
{
    text = "$STR_ENH_MAIN_TOOLS_REMOVEWEAPONS";
    action = "4 call ENH_fnc_removeGear";
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_W};
    wikiDescription = "Removes weapons of all selected entities.";
};
class ENH_RemoveGear
{
    text = "$STR_ENH_MAIN_TOOLS_REMOVEGEAR";
    action = "7 call ENH_fnc_removeGear";
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_D};
    wikiDescription = "Clear inventory of all selected entities.";
};
class ENH_ESE
{
    text = "$STR_ENH_MAIN_TOOLS_ESE";
    action = "call ENH_fnc_ESE_open";
    opensNewWindow = 1;
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_I};
    wikiDescription = "Opes the Vehicle Inventory Manager. See GUI documentation for detailed information.";
};
