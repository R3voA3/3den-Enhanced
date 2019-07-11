class Help
{
	items[] +=
	{
		"Enh_Help_Folder_Community",
		"Enh_Help_Folder_Wiki"
	};
};
class Enh_Help_Folder_Community
{
	text = $STR_ENH_folder_community;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"Enh_Help_KK",
		"Enh_Help_Kylania",
		"Enh_Help_ScriptingBeginners",
		"Enh_Help_MissionCampaignGuide",
		"Enh_Help_FockersScriptingTutorial",
		"Enh_Help_FoxhoundInternational",
		"Enh_Help_AICompilationList"
	};
};
class Enh_Help_Folder_Wiki
{
	text = $STR_ENH_folder_wiki;
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"Enh_Help_FunctionsList",
		"Enh_Help_MissionPresentation",
		"Enh_Help_DescriptionExt",
		"Enh_Help_CodeOptimisation",
		"Enh_Help_MissionOptimisation"
	};
};
//Community
class Enh_Help_KK
{
	text = $STR_ENH_help_KKBlog;
	picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
	weblink = "http://killzonekid.com/";
	opensNewWindow = 1;
};
class Enh_Help_Kylania: Enh_Help_KK
{
	text = $STR_ENH_help_kylania;
	weblink = "http://www.kylania.com/ex/";
};
class Enh_Help_ScriptingBeginners: Enh_Help_KK
{
	text = $STR_ENH_help_scriptingBeginners;
	weblink = "https://forums.bohemia.net/forums/topic/216796-arma-3-scripting-tutorials-from-gokitty1199im-sorry-buffaloboth-me/";
};
class Enh_Help_MissionCampaignGuide: Enh_Help_KK
{
	text = $STR_ENH_help_missionCampaignGuide;
	weblink = "https://forums.bistudio.com/topic/190820-thegens-guide-to-mission-campaign-making/";
};
class Enh_Help_FockersScriptingTutorial: Enh_Help_KK
{
	text = $STR_ENH_help_fockersScriptingTutorial;
	weblink = "http://www.armaholic.com/page.php?id=20465";
};
class Enh_Help_AICompilationList: Enh_Help_KK
{
	text = $STR_ENH_help_AICompilation;
	weblink = "https://forums.bistudio.com/topic/165560-ai-compilation-list-of-addonsmodsscripts-misc/";
};
class Enh_Help_FoxhoundInternational: Enh_Help_KK
{
	text = $STR_ENH_help_foxhoundInternational;
	weblink = "http://foxhound.international/development.html";
};
//Wiki
class Enh_Help_FunctionsList: Enh_Help_KK
{
	text = $STR_ENH_help_functionsOverview;
	weblink = "https://community.bistudio.com/wiki/Functions_by_Functionality";
};
class Enh_Help_MissionPresentation: Enh_Help_KK
{
	text = $STR_ENH_help_missionPresentation;
	weblink = "https://community.bistudio.com/wiki/Mission_Presentation";
};
class Enh_Help_DescriptionExt: Enh_Help_KK
{
	text = "Description.ext";
	weblink = "https://community.bistudio.com/wiki/Description.ext";
};
class Enh_Help_CodeOptimisation: Enh_Help_KK
{
	text = $STR_ENH_help_codeOptimisation;
	weblink = "https://community.bistudio.com/wiki/Code_Optimisation";
};
class Enh_Help_MissionOptimisation: Enh_Help_KK
{
	text = $STR_ENH_help_missionOptimisation;
	weblink = "https://community.bistudio.com/wiki/Mission_Optimisation";
};


