class Tools
{
    items[] +=
    {
        "ENH_CommandPalette",
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
class ENH_CommandPalette
{
    text = "Open Command Palette";
    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_P};
    action = "call ENH_fnc_3DENCommandPalette";
    picture = TEXTURE_SEARCH_START;
};
