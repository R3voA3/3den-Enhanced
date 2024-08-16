class Help
{
    items[] +=
    {
        "ENH_GetExtensions",
        "ENH_AICompilationList",
        "ENH_3DENShortcuts",
        "ENH_Folder_Wiki"
    };
};
class ENH_Folder_Wiki
{
    text = "$STR_ENH_MAIN_FOLDER_WIKI";
    picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
    items[] +=
    {
        "ENH_CommandsList",
        "ENH_FunctionsList",
        "ENH_MissionPresentation",
        "ENH_DescriptionExt",
        "ENH_CodeOptimisation",
        "ENH_MissionOptimisation",
        "ENH_MultiplayerScripting"
    };
};
class ENH_GetExtensions
{
    text = "$STR_ENH_MAIN_GETEXTENSIONS";
    picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
    weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=1774491737";
    opensNewWindow = 1;
    wikiDescription = "Shows a collection of other editor extensions.";
};
//Community
class ENH_AICompilationList: ENH_GetExtensions
{
    text = "$STR_ENH_MAIN_AICOMPILATION";
    weblink = "https://forums.bistudio.com/topic/165560-ai-compilation-list-of-addonsmodsscripts-misc/";
    wikiDescription = "Shows a list of useful AI modifications.";
};
//Wiki
class ENH_CommandsList: ENH_GetExtensions
{
    text = "$STR_ENH_MAIN_COMMANDSOVERVIEW";
    weblink = "https://community.bistudio.com/wiki/Category:Scripting_Commands_by_Functionality";
    wikiDescription = "Open commmunity wiki page about commands.";
};
class ENH_FunctionsList: ENH_GetExtensions
{
    text = "$STR_ENH_MAIN_FUNCTIONSOVERVIEW";
    weblink = "https://community.bistudio.com/wiki/Category:Functions_by_Functionality";
    wikiDescription = "Open commmunity wiki page about functions.";
};
class ENH_MissionPresentation: ENH_GetExtensions
{
    text = "$STR_ENH_MAIN_MISSIONPRESENTATION";
    weblink = "https://community.bistudio.com/wiki/Mission_Presentation";
    wikiDescription = "Open commmunity wiki page about mission presentation.";
};
class ENH_DescriptionExt: ENH_GetExtensions
{
    text = "$STR_ENH_MAIN_DESCRIPTIONEXT";
    weblink = "https://community.bistudio.com/wiki/Description.ext";
    wikiDescription = "Open commmunity wiki page about code description.ext.";
};
class ENH_CodeOptimisation: ENH_GetExtensions
{
    text = "$STR_ENH_MAIN_CODEOPTIMISATION";
    weblink = "https://community.bistudio.com/wiki/Code_Optimisation";
    wikiDescription = "Open commmunity wiki page about code optimisation.";
};
class ENH_MissionOptimisation: ENH_GetExtensions
{
    text = "$STR_ENH_MAIN_MISSIONOPTIMISATION";
    weblink = "https://community.bistudio.com/wiki/Mission_Optimisation";
    wikiDescription = "Open commmunity wiki page about mission optimisation.";
};
class ENH_MultiplayerScripting: ENH_GetExtensions
{
    text = "$STR_ENH_MAIN_MULTIPLAYERSCRIPTING";
    weblink = "https://community.bistudio.com/wiki/Multiplayer_Scripting";
    wikiDescription = "Open commmunity wiki page about multiplayer scripting.";
};
class ENH_3DENShortcuts
{
    text = "$STR_ENH_MAIN_3DENSHORTCUTS_DISPLAYNAME";
    action = "findDisplay 313 createDisplay 'ENH_3DENShortcuts'";
    opensNewWindow = 1;
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_F1};
    wikiDescription = "Shows all eden editor shortcuts.";
};