class ENH_Volume
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_ATTRIBUTECATEGORY_VOLUME";
    class Attributes
    {
        class ENH_SoundVolume
        {
            displayName = "$STR_ENH_MAIN_SOUNDVOLUME_DISPLAYNAME";
            tooltip = "";
            property = "ENH_soundVolume";
            control = "Slider";
            expression = "if (!is3DEN && hasInterface) then {0 fadeSound _value}";
            defaultValue = 1;
        };
        class ENH_MusicVolume: ENH_SoundVolume
        {
            displayName = "$STR_ENH_MAIN_MUSICVOLUME_DISPLAYNAME";
            property = "ENH_musicVolume";
            expression = "if (!is3DEN && hasInterface) then {0 fadeMusic _value}";
        };
        class ENH_RadioVolume: ENH_SoundVolume
        {
            displayName = "$STR_ENH_MAIN_RADIOVOLUME_DISPLAYNAME";
            property = "ENH_radioVolume";
            expression = "if (!is3DEN && hasInterface) then {0 fadeRadio _value}";
        };
        class ENH_EnvironmentVolume: ENH_SoundVolume
        {
            displayName = "$STR_ENH_MAIN_ENVIRONMENTVOLUME_DISPLAYNAME";
            property = "ENH_environmentVolume";
            expression = "if (!is3DEN && hasInterface) then {0 fadeEnvironment _value}";
        };
        class ENH_RandomMusic
        {
            displayName = "$STR_ENH_MAIN_RANDOMMUSIC_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_RANDOMMUSIC_TOOLTIP";
            property = "ENH_randomMusic";
            control = "ENH_CfgMusic";
            expression = "if (!is3DEN && (_value isNotEqualTo []) && hasInterface) then {playMusic (selectRandom _value)}";
            defaultValue = "[]";
        };
    };
};
