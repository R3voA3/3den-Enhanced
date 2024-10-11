class Tools
{
    items[] +=
    {
        "ENH_Folder_Utilities",
        "ENH_Folder_Placement",
        "ENH_Folder_Loadout",
        "ENH_Folder_VHC",
        "ENH_Folder_Debug",
        "ENH_Folder_Miscellaneous"
    };
};

#include "menuStrip_tools_utilities.hpp"
#include "menuStrip_tools_placement.hpp"
#include "menuStrip_tools_loadout.hpp"
#include "menuStrip_tools_VHC.hpp"
#include "menuStrip_tools_debug.hpp"
#include "menuStrip_tools_miscellaneous.hpp"

class FunctionsViewer
{
    action = QUOTE(findDisplay IDD_DISPLAY3DEN createDisplay 'ENH_FunctionsViewer');
    shortCuts[] = {INPUT_ALT_OFFSET + DIK_F};
};
class ConfigViewer
{
    shortCuts[] = {INPUT_ALT_OFFSET + DIK_C};
};
class DebugConsole
{
    shortCuts[] = {INPUT_CTRL_OFFSET + DIK_D};
};
class MissionFolder
{
    shortCuts[] = {INPUT_ALT_OFFSET + DIK_O};
};
