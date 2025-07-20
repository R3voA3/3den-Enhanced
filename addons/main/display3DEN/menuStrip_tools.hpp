class Tools
{
    items[] +=
    {
        "ENH_Folder_Utilities",
        "ENH_Folder_Placement",
        "ENH_Folder_Loadout",
        "ENH_Folder_VHC",
        "ENH_Folder_Debug",
        "ENH_Folder_Miscellaneous",
        "ENH_Folder_Layer"
    };
};

#include "\x\enh\addons\main\display3DEN\menuStrip_tools_utilities.hpp"
#include "\x\enh\addons\main\display3DEN\menuStrip_tools_placement.hpp"
#include "\x\enh\addons\main\display3DEN\menuStrip_tools_loadout.hpp"
#include "\x\enh\addons\main\display3DEN\menuStrip_tools_VHC.hpp"
#include "\x\enh\addons\main\display3DEN\menuStrip_tools_debug.hpp"
#include "\x\enh\addons\main\display3DEN\menuStrip_tools_miscellaneous.hpp"
#include "\x\enh\addons\main\display3DEN\menuStrip_tools_layer.hpp"

class FunctionsViewer
{
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_FunctionsViewer');
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_F};
};
class ConfigViewer
{
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_C};
};
class DebugConsole
{
    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_D};
};
class MissionFolder
{
    shortcuts[] = {INPUT_ALT_OFFSET + DIK_O};
};
