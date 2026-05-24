class ENH_Folder_Utilities
{
    text = "$STR_ENH_MAIN_FOLDER_UTILITIES";
    picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
    items[] +=
    {
        "ENH_CfgDisabledCommands",
        "ENH_Jukebox",
        "ENH_MoonPhases",
        "ENH_PrintConfig",
        "ENH_ScriptCommands",
        "Separator",
        "ENH_3DENRadio",
        "ENH_SAM",
        "ENH_CfgSentencesBrowser",
        "ENH_TextureFinder",
        "Separator",
        "ENH_BriefingEditor",
        "ENH_AttributeSearch",
        "ENH_NameObjects",
        "ENH_ZeusAddons",
        "Separator",
        "ENH_CommandPalette",
        "ENH_CommandPalette_Reset_Priority"
    };
};
class ENH_MoonPhases
{
    text = "$STR_ENH_MAIN_TOOLS_MOONPHASES";
    action = "[] spawn compileScript ['A3\Functions_F\Debug\Utilities\utility_moonPhases.sqf']";
    opensNewWindow = 1;
    wikiDescription = "See [Arma 3: Utilities](https://community.bistudio.com/wiki/Arma_3:_Utilities).";
};
class ENH_Jukebox
{
    text = "$STR_ENH_MAIN_TOOLS_JUKEBOX";
    action = "spawn compileScript ['A3\Functions_F\Debug\Utilities\utility_jukebox.sqf']";
    opensNewWindow = 1;
    wikiDescription = "See [Arma 3: Utilities](https://community.bistudio.com/wiki/Arma_3:_Utilities).";
};
class ENH_PrintConfig
{
    text = "$STR_ENH_MAIN_TOOLS_PRINTCONFIG";
    action = "configNull spawn compileScript ['A3\Functions_F\Debug\Utilities\utility_printConfig.sqf']";
    opensNewWindow = 1;
    wikiDescription = "See [Arma 3: Utilities](https://community.bistudio.com/wiki/Arma_3:_Utilities).";
};
class ENH_CfgDisabledCommands
{
    text = "$STR_ENH_MAIN_TOOLS_CFGDISABLEDCOMMANDS";
    action = "0 spawn compileScript ['A3\Functions_F\Debug\Utilities\utility_cfgDisabledCommands.sqf']";
    opensNewWindow = 1;
    wikiDescription = "See [Arma 3: Utilities](https://community.bistudio.com/wiki/Arma_3:_Utilities).";
};
class ENH_ScriptCommands
{
    text = "$STR_ENH_MAIN_TOOLS_SCRIPTCOMMANDS";
    action = "spawn compileScript ['A3\Functions_F\Debug\Utilities\utility_scriptCommands.sqf']";
    opensNewWindow = 1;
    wikiDescription = "See [Arma 3: Utilities](https://community.bistudio.com/wiki/Arma_3:_Utilities).";
};
class ENH_BriefingEditor
{
    text = "$STR_ENH_MAIN_TOOLS_BRIEFINGEDITOR";
    picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\whiteboard_ca.paa";
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_briefingEditor');
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_B};
    opensNewWindow = 1;
    wikiDescription = "Opens the Briefing Editor. See GUI documentation for detailed information.";
};
class ENH_3DENRadio
{
    text = "$STR_ENH_MAIN_TOOLS_3DENRADIO";
    picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\radio_ca.paa";
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_3DENRadio');
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_M};
    opensNewWindow = 1;
    wikiDescription = "Opens 3DEN Radio. See GUI documentation for detailed information.";
};
class ENH_SAM
{
    text = "$STR_ENH_MAIN_TOOLS_SAM";
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_SAM');
    opensNewWindow = 1;
    wikiDescription = "Opens the Scenario Attributes Manager. See GUI documentation for detailed information.";
};
class ENH_NameObjects
{
    text = "$STR_ENH_MAIN_TOOLS_BATCHNAMING";
    action = "call ENH_fnc_nameObjects";
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_N};
    opensNewWindow = 1;
    wikiDescription = "Opens the Name Objects GUI. See GUI documentation for detailed information.";
};
class ENH_TextureFinder
{
    text = "$STR_ENH_MAIN_TOOLS_TEXTUREFINDER";
    picture = "\A3\ui_f\data\igui\cfg\simpleTasks\types\search_ca.paa";
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_TextureFinder');
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_T};
    opensNewWindow = 1;
    wikiDescription = "Opens the Texture Finder. See GUI documentation for detailed information.";
};
class ENH_CfgSentencesBrowser
{
    text = "$STR_ENH_MAIN_TOOLS_CFGSENTENCESBROWSER";
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_CfgSentencesBrowser');
    opensNewWindow = 1;
    wikiDescription = "Opens the CfgSentences Browser. See GUI documentation for detailed information.";
};
class ENH_ZeusAddons
{
    text = "$STR_ENH_MAIN_ZEUSADDONS_HEADER";
    action = "call ENH_fnc_zeusAddons";
    opensNewWindow = 1;
    wikiDescription = "Opens the Mange Zeus Addons GUI. See GUI documentation for detailed information.";
};
class ENH_AttributeSearch
{
    text = "$STR_ENH_MAIN_SEARCHATTRIBUTES_HEADER";
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_AttributeSearch');
    opensNewWindow = 1;
    wikiDescription = "Quickly search through the the text attributes such as 'ini' or 'condition' of all entities.";
};
class ENH_CommandPalette
{
    text = "$STR_ENH_MAIN_3DEN_COMMAND_PALETTE_OPEN";
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_SPACE};
    action = "call ENH_fnc_3DENCommandPalette_init";
    picture = TEXTURE_SEARCH_START;
};
class ENH_CommandPalette_Reset_Priority
{
    text = "$STR_ENH_MAIN_3DEN_COMMAND_PALETTE_RESET_PRIORITY";
    shortcuts[] = {};
    action = "profileNamespace setVariable ['ENH_3DENCommandPalette_PriorityMap', nil]";
};
