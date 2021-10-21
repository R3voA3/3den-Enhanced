class ENH_About
{
  text = "$STR_ENH_FOLDER_ABOUT";
  items[] +=
  {
    "ENH_About_Changelog",
    "ENH_About_Steam",
    "ENH_About_Translation",
    "ENH_About_Documentation",
    "ENH_About_Credits",
    "ENH_About_BugReport"
  };
};
class ENH_About_Changelog
{
  text = "$STR_ENH_ABOUT_CHANGELOG";
  picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
  weblink = "https://steamcommunity.com/sharedfiles/filedetails/changelog/623475643";
  opensNewWindow = 1;
};
class ENH_About_Steam: ENH_About_Changelog
{
  text = "$STR_ENH_ABOUT_STEAM";
  weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=623475643";
};
class ENH_About_Translation: ENH_About_Changelog
{
  text = "$STR_ENH_ABOUT_TRANSLATION";
  weblink = "https://github.com/R3voA3/3den-Enhanced/wiki/Translation";
};
class ENH_About_Documentation: ENH_About_Changelog
{
  text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
  weblink = "https://github.com/R3voA3/3den-Enhanced/wiki";
};
class ENH_About_Credits: ENH_About_Changelog
{
  text = "$STR_ENH_ABOUT_CREDITS";
  weblink = "https://github.com/R3voA3/3den-Enhanced/wiki/Credits";
};
class ENH_About_BugReport: ENH_About_Changelog
{
  text = "$STR_ENH_ABOUT_REPORT";
  weblink = "https://github.com/R3voA3/3den-Enhanced/issues/new/choose";
};