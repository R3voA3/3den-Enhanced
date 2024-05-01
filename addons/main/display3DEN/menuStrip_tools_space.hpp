class ENH_Folder_Space
{
  text = "$STR_ENH_MAIN_FOLDER_SPACE";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_SpaceEquallyX",
    "ENH_SpaceEquallyY",
    "ENH_SpaceEquallyZ"
  };
};
class ENH_SpaceEquallyX
{
  text = "$STR_ENH_MAIN_TOOLS_SPACEEQUALLY_X";
  action = "0 call (uiNamespace getVariable 'ENH_fnc_spaceEqually')";
};
class ENH_SpaceEquallyY
{
  text = "$STR_ENH_MAIN_TOOLS_SPACEEQUALLY_Y";
  action = "1 call (uiNamespace getVariable 'ENH_fnc_spaceEqually')";
};
class ENH_SpaceEquallyZ
{
  text = "$STR_ENH_MAIN_TOOLS_SPACEEQUALLY_Z";
  action = "2 call (uiNamespace getVariable 'ENH_fnc_spaceEqually')";
};