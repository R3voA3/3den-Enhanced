class ENH_Folder_Placement
{
    text = "$STR_ENH_MAIN_FOLDER_PLACEMENTTOOLS";
    picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
    items[] +=
    {
        "ENH_PlacementTools",
        "Separator",
        "ENH_Folder_Orient",
        "ENH_Folder_Align",
        "ENH_Folder_Space",
        "Separator",
        "ENH_SnapToSurface"
    };
};
class ENH_PlacementTools
{
    text = "$STR_ENH_MAIN_TOOLS_PLACEMENTTOOL";
    action = "[nil, 'createUI'] call ENH_fnc_placementTools";
    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_L};
    opensNewWindow = 1;
    wikiDescription = "Opens Placement Tool GUI. See GUI documentation for detailed information.";
};
class ENH_SnapToSurface
{
    text = "$STR_3DEN_DISPLAY3DEN_ENTITYMENU_MOVESURFACE_TEXT";
    action = "do3DENAction 'SnapToSurface'";
    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_SPACE};
    picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveSurface_ca.paa";
    wikiDescription = "Snaps all selected entities to the surface.";
};

#include "menuStrip_tools_orient.hpp"
#include "menuStrip_tools_align.hpp"
#include "menuStrip_tools_space.hpp"
