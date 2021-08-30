class ENH_Folder_Pylons
{
  text = "$STR_ENH_FOLDER_PYLONS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_CopyPylonSettings",
    "ENH_ApplyPylonSettings"
  };
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