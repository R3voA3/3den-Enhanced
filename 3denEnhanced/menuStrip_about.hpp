class Enh_About
{
	text = $STR_ENH_folder_about;
	items[] +=
	{
		"Enh_About_Forum",
		"Enh_About_Changelog",
		"Enh_About_Steam",
		"Enh_About_Translation",
		"Enh_About_FAQ",
		"Enh_About_Credits"
	};
};
class Enh_About_Forum
{
	text = $STR_ENH_about_forums;
	picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
	weblink = "https://forums.bistudio.com/topic/188312-3den-enhanced/";
	opensNewWindow = 1;
};
class Enh_About_Changelog: Enh_About_Forum
{
	text = $STR_ENH_about_changelog;
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/changelog/623475643";
};
class Enh_About_Steam: Enh_About_Forum
{
	text = $STR_ENH_about_steam;
	weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=623475643";
};
class Enh_About_Translation: Enh_About_Forum
{
	text = $STR_ENH_about_translation;
	weblink = "https://github.com/RevoArma3/3den-Enhanced";
};
class Enh_About_FAQ: Enh_About_Forum
{
	text = $STR_ENH_about_FAQ;
	weblink = "https://forums.bohemia.net/forums/topic/188312-3den-enhanced/?do=findComment&comment=2984094";
};
class Enh_About_Credits: Enh_About_Forum
{
	text = $STR_ENH_about_credits;
	action = "findDisplay 313 createDisplay 'Enh_Credits'";
	weblink = "";
};