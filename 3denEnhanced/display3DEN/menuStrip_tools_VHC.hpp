class ENH_Folder_VHC
{
  text = "$STR_ENH_FOLDER_VHC";
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
  text = "$STR_ENH_TOOLS_COPYVHC";
  action = "'copy' call (uiNamespace getVariable 'ENH_fnc_VHCTools')";
};
class ENH_ApplyVHC
{
  text = "$STR_ENH_TOOLS_APPLYVHC";
  action = "'apply' call (uiNamespace getVariable 'ENH_fnc_VHCTools')";
};
class ENH_RandomVHC
{
  text = "$STR_ENH_TOOLS_RANDOMIZEVHC";
  action = "'random' call (uiNamespace getVariable 'ENH_fnc_VHCTools')";
};
class ENH_CopyPylonSettings
{
  text = "$STR_ENH_TOOLS_COPYPYLONS";
  action = "'copy' call (uiNamespace getVariable 'ENH_fnc_pylonTools')";
};
class ENH_ApplyPylonSettings
{
  text = "$STR_ENH_TOOLS_APPLYPYLONS";
  action = "'apply' call (uiNamespace getVariable 'ENH_fnc_pylonTools')";
};
class ENH_ExportPylonsToSQF
{
  text = "$STR_ENH_TOOLS_EXPORTPYLONSTOSQF";
  action = "'exportToSQF' call (uiNamespace getVariable 'ENH_fnc_pylonTools')";
};