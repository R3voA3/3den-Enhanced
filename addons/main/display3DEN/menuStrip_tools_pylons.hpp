class ENH_Folder_Pylons
{
    text = "$STR_ENH_MAIN_FOLDER_PYLONS";
    picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
    items[] +=
    {
        "ENH_CopyPylonSettings",
        "ENH_ApplyPylonSettings",
        "ENH_ExportPylonsToSQF"
    };
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
