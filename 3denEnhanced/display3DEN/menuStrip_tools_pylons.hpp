class ENH_Folder_Pylons
{
  text = "Pylon Tools";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_CopyPylonSettings",
    "ENH_ApplyPylonSettings"
  };
};
class ENH_CopyPylonSettings
{
  text = "Copy Pylon Settings (localize)";
  action = "'copy' call ENH_fnc_pylonTools";
};
class ENH_ApplyPylonSettings
{
  text = "Apply Pylon Settings (localize)";
  action = "'apply' call ENH_fnc_pylonTools";
};