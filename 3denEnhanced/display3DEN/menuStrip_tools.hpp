class Tools
{
  items[] +=
  {
    "ENH_Folder_Utilities",
    "ENH_Folder_Placement",
    "ENH_Folder_Loadout",
    "ENH_Folder_Arsenal",
    //"ENH_Folder_Pylons",
    "ENH_Folder_VHC",
    "ENH_Folder_Debug",
    /* "ENH_Folder_GUI", */
    "ENH_Folder_Miscellaneous"
  };
};

#include "menuStrip_tools_utilities.hpp"
#include "menuStrip_tools_placement.hpp"
#include "menuStrip_tools_loadout.hpp"
//#include "menuStrip_tools_pylons.hpp"
#include "menuStrip_tools_VHC.hpp"
#include "menuStrip_tools_debug.hpp"
//#include "menuStrip_tools_GUI.hpp"
#include "menuStrip_tools_miscellaneous.hpp"
#include "menuStrip_tools_arsenal.hpp"

class FunctionsViewer//Overwrites the default function viewer
{
  action = "findDisplay 313 createDisplay 'ENH_FunctionsViewer'";
  data = "";
  opensNewWindow = 1;
  shortCuts[] = {INPUT_ALT_OFFSET + DIK_F};
};
class ConfigViewer//Overwrites the default config viewer to change shortcut
{
  shortCuts[] = {INPUT_ALT_OFFSET + DIK_C};
};
class DebugConsole//Overwrites the default debug console to change shortcut
{
  shortCuts[] = {INPUT_CTRL_OFFSET + DIK_D};
};