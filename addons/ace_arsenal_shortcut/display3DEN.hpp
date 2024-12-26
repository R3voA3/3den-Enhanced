class Display3DEN
{
    class Controls
    {
        class MenuStrip: ctrlMenuStrip
        {
            class Items
            {
                class ENH_Folder_Loadout
                {
                    items[] +=
                    {
                        "ENH_ACEArsenalShortcut"
                    };
                };
                class ENH_ACEArsenalShortcut
                {
                    text = "$STR_ACE_ARSENAL_SETTINGCATEGORY";
                    action = "call ENH_fnc_openACEArsenal";
                    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_SHIFT_OFFSET + DIK_L};
                    wikiDescription = "Opens the ACE Arsenal.";
                };
            };
        };
    };
};
