class ENH_About
{
    text = "$STR_ENH_MAIN_FOLDER_ABOUT";
    items[] +=
    {
        "ENH_Changelog",
        "ENH_Steam",
        "ENH_Contributing",
        "ENH_Documentation",
        "ENH_Credits",
        "ENH_BugReport"
    };
};
class ENH_Changelog
{
    text = "$STR_ENH_MAIN_CHANGELOG";
    picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
    weblink = "https://github.com/R3voA3/3den-Enhanced/blob/master/CHANGELOG.md";
    opensNewWindow = 1;
    wikiDescription = "Opens the changelog.";
};
class ENH_Steam: ENH_Changelog
{
    text = "$STR_ENH_MAIN_STEAM";
    weblink = "https://steamcommunity.com/sharedfiles/filedetails/?id=623475643";
    wikiDescription = "Open 3den Enhanced Steam page.";
};
class ENH_Contributing: ENH_Changelog
{
    text = "$STR_ENH_MAIN_CONTRIBUTE";
    weblink = "https://github.com/R3voA3/3den-Enhanced/blob/master/CONTRIBUTING.md";
    wikiDescription = "Explains how to contribute.";
};
class ENH_Documentation: ENH_Changelog
{
    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
    weblink = "https://github.com/R3voA3/3den-Enhanced/wiki";
    wikiDescription = "Opens the 3den Enhanced documentation.";
};
class ENH_Credits: ENH_Changelog
{
    text = "$STR_ENH_MAIN_CREDITS";
    weblink = "https://github.com/R3voA3/3den-Enhanced/blob/master/CONTRIBUTORS.md";
    wikiDescription = "Shows all contributors.";
};
class ENH_BugReport: ENH_Changelog
{
    text = "$STR_ENH_MAIN_REPORT";
    weblink = "https://github.com/R3voA3/3den-Enhanced/issues/new/choose";
    wikiDescription = "Open a bug report on GitHub.";
};
