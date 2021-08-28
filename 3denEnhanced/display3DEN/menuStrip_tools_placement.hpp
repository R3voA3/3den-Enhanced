class ENH_Folder_Placement
{
  text = "$STR_ENH_FOLDER_PLACEMENTTOOLS";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_PlacementTools",
    "Separator",
    "ENH_Folder_Orient",
    "ENH_Folder_Align",
    "ENH_Folder_Space"
  };
};

class ENH_PlacementTools
{
  text = "$STR_ENH_TOOLS_PLACEMENTTOOL";
  action = "call ENH_fnc_placementTools_createDisplay";
  shortcuts[] = {INPUT_CTRL_OFFSET + DIK_L};
  opensNewWindow = 1;
};

#include "menuStrip_tools_orient.hpp"
#include "menuStrip_tools_align.hpp"
#include "menuStrip_tools_space.hpp"