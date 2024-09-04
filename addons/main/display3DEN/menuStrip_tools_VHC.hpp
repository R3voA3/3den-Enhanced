class ENH_Folder_VHC
{
    text = "$STR_ENH_MAIN_FOLDER_VHC";
    picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
    items[] +=
    {
        "ENH_CopyVHC",
        "ENH_ApplyVHC",
        "ENH_RandomVHC",
        "Separator",
        "ENH_CopyPylonSettings",
        "ENH_ApplyPylonSettings",
        "ENH_ExportPylonsToSQF"
    };
};
class ENH_CopyVHC
{
    text = "$STR_ENH_MAIN_TOOLS_COPYVHC";
    action = "'copy' call (uiNamespace getVariable 'ENH_fnc_VHCTools')";
    wikiDescription = "Copies vehicle appearance.";
};
class ENH_ApplyVHC
{
    text = "$STR_ENH_MAIN_TOOLS_APPLYVHC";
    action = "'apply' call (uiNamespace getVariable 'ENH_fnc_VHCTools')";
    wikiDescription = "Applies previously copied vehicle appearance. If multiple appearances were copied a random one is selected for each entity.";
};
class ENH_RandomVHC
{
    text = "$STR_ENH_MAIN_TOOLS_RANDOMIZEVHC";
    action = "'random' call (uiNamespace getVariable 'ENH_fnc_VHCTools')";
    wikiDescription = "Randomizes vehicle appearance.";
};
class ENH_CopyPylonSettings
{
    text = "$STR_ENH_MAIN_TOOLS_COPYPYLONS";
    action = "'copy' call (uiNamespace getVariable 'ENH_fnc_pylonTools')";
    wikiDescription = "Copies pylon settings of selected entities.";
};
class ENH_ApplyPylonSettings
{
    text = "$STR_ENH_MAIN_TOOLS_APPLYPYLONS";
    action = "'apply' call (uiNamespace getVariable 'ENH_fnc_pylonTools')";
    wikiDescription = "Applies random pylon setting that from previously copied settings.";
};
class ENH_ExportPylonsToSQF
{
    text = "$STR_ENH_MAIN_TOOLS_EXPORTPYLONSTOSQF";
    action = "'exportToSQF' call (uiNamespace getVariable 'ENH_fnc_pylonTools')";
    wikiDescription = "Exports pylon settings as sqf script for later execution.";
};
