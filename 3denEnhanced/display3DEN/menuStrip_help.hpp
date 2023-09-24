class Help
{
  items[] +=
  {
    "ENH_Help_GetExtensions",
    "ENH_Help_MissionCampaignGuide",
    "ENH_Help_AICompilationList",
    "ENH_Help_3DENShortcuts",
    "ENH_Help_Folder_Wiki"
  };
};
class ENH_Help_Folder_Wiki
{
  text = "$STR_ENH_FOLDER_WIKI";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_Help_CommandsList",
    "ENH_Help_FunctionsList",
    "ENH_Help_MissionPresentation",
    "ENH_Help_DescriptionExt",
    "ENH_Help_CodeOptimisation",
    "ENH_Help_MissionOptimisation",
    "ENH_Help_MultiplayerScripting"
  };
};
class ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_GETEXTENSIONS";
  picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
  weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1774491737";
  opensNewWindow = 1;
};
//Community
class ENH_Help_ScriptingBeginners: ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_SCRIPTINGBEGINNERS";
  weblink = "https://forums.bohemia.net/forums/topic/216796-arma-3-scripting-tutorials-from-gokitty1199im-sorry-buffaloboth-me/";
};
class ENH_Help_MissionCampaignGuide: ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_MISSIONCAMPAIGNGUIDE";
  weblink = "https://forums.bistudio.com/topic/190820-thegens-guide-to-mission-campaign-making/";
};
class ENH_Help_AICompilationList: ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_AICOMPILATION";
  weblink = "https://forums.bistudio.com/topic/165560-ai-compilation-list-of-addonsmodsscripts-misc/";
};
//Wiki
class ENH_Help_CommandsList: ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_COMMANDSOVERVIEW";
  weblink = "https://community.bistudio.com/wiki/Category:Scripting_Commands_by_Functionality";
};
class ENH_Help_FunctionsList: ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_FUNCTIONSOVERVIEW";
  weblink = "https://community.bistudio.com/wiki/Category:Functions_by_Functionality";
};
class ENH_Help_MissionPresentation: ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_MISSIONPRESENTATION";
  weblink = "https://community.bistudio.com/wiki/Mission_Presentation";
};
class ENH_Help_DescriptionExt: ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_DESCRIPTIONEXT";
  weblink = "https://community.bistudio.com/wiki/Description.ext";
};
class ENH_Help_CodeOptimisation: ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_CODEOPTIMISATION";
  weblink = "https://community.bistudio.com/wiki/Code_Optimisation";
};
class ENH_Help_MissionOptimisation: ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_MISSIONOPTIMISATION";
  weblink = "https://community.bistudio.com/wiki/Mission_Optimisation";
};
class ENH_Help_MultiplayerScripting: ENH_Help_GetExtensions
{
  text = "$STR_ENH_HELP_MULTIPLAYERSCRIPTING";
  weblink = "https://community.bistudio.com/wiki/Multiplayer_Scripting";
};
class ENH_Help_3DENShortcuts
{
  text = "$STR_ENH_3DENSHORTCUTS_DISPLAYNAME";
  action = "findDisplay 313 createDisplay 'ENH_3DENShortcuts'";
  opensNewWindow = 1;
  shortcuts[] = {INPUT_ALT_OFFSET + DIK_F1};
};