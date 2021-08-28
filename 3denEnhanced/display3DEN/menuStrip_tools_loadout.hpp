class ENH_Folder_Loadout
{
  text = "$STR_ENH_FOLDER_LOADOUTTOOLS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_VIM",
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
  text = "$STR_ENH_TOOLS_COPYLOADOUTS";
  action = "'copy' call ENH_fnc_loadoutTool";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_C};
};
class ENH_ApplyLoadout
{
  text = "$STR_ENH_TOOLS_APPLYLOADOUTS";
  action = "'apply' call ENH_fnc_loadoutTool";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_A};
};
class ENH_ExportLoadoutCfgRespawnInventory
{
  text = "$STR_ENH_TOOLS_EXPORTLOADOUT_CFGRESPAWNINVENTORY";
  action = "false call ENH_fnc_exportLoadout";
};
class ENH_ExportLoadoutConfig
{
  text = "$STR_ENH_TOOLS_EXPORTLOADOUT_CONFIG";
  action = "true call ENH_fnc_exportLoadout";
};
class ENH_RemoveNVGs
{
  text = "$STR_ENH_TOOLS_REMOVENVGS";
  action = "2 call ENH_fnc_removeGear";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_N};
};
class ENH_RemoveVests
{
  text = "$STR_ENH_TOOLS_REMOVEVESTS";
  action = "3 call ENH_fnc_removeGear";
};
class ENH_RemoveGoggles
{
  text = "$STR_ENH_TOOLS_REMOVEGOGGLES";
  action = "0 call ENH_fnc_removeGear";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_G};
};
class ENH_RemoveHeadgear
{
  text = "$STR_ENH_TOOLS_REMOVEHEADGEAR";
  action = "1 call ENH_fnc_removeGear";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_H};
};
class ENH_RemoveWeapons
{
  text = "$STR_ENH_TOOLS_REMOVEWEAPONS";
  action = "4 call ENH_fnc_removeGear";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_W};
};
class ENH_RemoveGear
{
  text = "$STR_ENH_TOOLS_REMOVEGEAR";
  action = "7 call ENH_fnc_removeGear";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_F};
};
class ENH_VIM
{
  text = "$STR_ENH_TOOLS_VIM";
  action = "call ENH_fnc_VIM_open";
  opensNewWindow = 1;
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_I};
};