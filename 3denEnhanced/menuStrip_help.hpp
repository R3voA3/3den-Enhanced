class Help
{
	items[] +=
	{
		"ENH_Help_Folder_Community",
		"ENH_Help_Folder_Wiki"
	};
};
class ENH_Help_Folder_Community
{
	text = $STR_ENH_folder_community;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_Help_KK",
		"ENH_Help_Kylania",
		"ENH_Help_ScriptingBeginners",
		"ENH_Help_MissionCampaignGuide",
		"ENH_Help_FockersScriptingTutorial",
		"ENH_Help_FoxhoundInternational",
		"ENH_Help_AICompilationList"
	};
};
class ENH_Help_Folder_Wiki
{
	text = $STR_ENH_folder_wiki;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_Help_FunctionsList",
		"ENH_Help_MissionPresentation",
		"ENH_Help_DescriptionExt",
		"ENH_Help_CodeOptimisation",
		"ENH_Help_MissionOptimisation",
		"ENH_Help_MultiplayerScripting"
	};
};
//Community
class ENH_Help_KK
{
	text = $STR_ENH_help_KKBlog;
	picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
	weblink = "http://killzonekid.com/";
	opensNewWindow = 1;
};
class ENH_Help_Kylania: ENH_Help_KK
{
	text = $STR_ENH_help_kylania;
	weblink = "http://www.kylania.com/ex/";
};
class ENH_Help_ScriptingBeginners: ENH_Help_KK
{
	text = $STR_ENH_help_scriptingBeginners;
	weblink = "https://forums.bohemia.net/forums/topic/216796-arma-3-scripting-tutorials-from-gokitty1199im-sorry-buffaloboth-me/";
};
class ENH_Help_MissionCampaignGuide: ENH_Help_KK
{
	text = $STR_ENH_help_missionCampaignGuide;
	weblink = "https://forums.bistudio.com/topic/190820-thegens-guide-to-mission-campaign-making/";
};
class ENH_Help_FockersScriptingTutorial: ENH_Help_KK
{
	text = $STR_ENH_help_fockersScriptingTutorial;
	weblink = "http://www.armaholic.com/page.php?id=20465";
};
class ENH_Help_AICompilationList: ENH_Help_KK
{
	text = $STR_ENH_help_AICompilation;
	weblink = "https://forums.bistudio.com/topic/165560-ai-compilation-list-of-addonsmodsscripts-misc/";
};
class ENH_Help_FoxhoundInternational: ENH_Help_KK
{
	text = $STR_ENH_help_foxhoundInternational;
	weblink = "http://foxhound.international/development.html";
};
//Wiki
class ENH_Help_FunctionsList: ENH_Help_KK
{
	text = $STR_ENH_help_functionsOverview;
	weblink = "https://community.bistudio.com/wiki/Functions_by_Functionality";
};
class ENH_Help_MissionPresentation: ENH_Help_KK
{
	text = $STR_ENH_help_missionPresentation;
	weblink = "https://community.bistudio.com/wiki/Mission_Presentation";
};
class ENH_Help_DescriptionExt: ENH_Help_KK
{
	text = "Description.ext";
	weblink = "https://community.bistudio.com/wiki/Description.ext";
};
class ENH_Help_CodeOptimisation: ENH_Help_KK
{
	text = $STR_ENH_help_codeOptimisation;
	weblink = "https://community.bistudio.com/wiki/Code_Optimisation";
};
class ENH_Help_MissionOptimisation: ENH_Help_KK
{
	text = $STR_ENH_help_missionOptimisation;
	weblink = "https://community.bistudio.com/wiki/Mission_Optimisation";
};
class ENH_Help_MultiplayerScripting: ENH_Help_KK
{
	text = $STR_ENH_help_multiplayerScripting;
	weblink = "https://community.bistudio.com/wiki/Multiplayer_Scripting";
};