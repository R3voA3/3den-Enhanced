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
                    action = "private _entity = get3DENSelected ""Object"" param [0, objNull]; [_entity, _entity, true] call ace_arsenal_fnc_openBox";
                    shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_A};
                    wikiDescription = "Opens the ACE Arsenal.";
                };
            };
        };
    };
};
