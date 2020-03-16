class ENH_Volume
{
	collapsed = 1;
	displayName = $STR_ENH_ATTRIBUTECATEGORY_VOLUME;
	class Attributes
	{
		class ENH_SoundVolume
		{
			displayName = $STR_ENH_SOUNDVOLUME_DISPLAYNAME;
			tooltip = "";
			property = "ENH_soundVolume";
			control = "Slider";
			expression = "if (!is3DEN && {hasInterface}) then {0 fadeSound _value}";
			defaultValue = "1";
		};
		class ENH_MusicVolume: ENH_SoundVolume
		{
			displayName = $STR_ENH_MUSICVOLUME_DISPLAYNAME;
			property = "ENH_musicVolume";
			expression = "if (!is3DEN && {hasInterface}) then {0 fadeMusic _value}";
		};
		class ENH_RadioVolume: ENH_SoundVolume
		{
			displayName = $STR_ENH_RADIOVOLUME_DISPLAYNAME;
			property = "ENH_radioVolume";
			expression = "if (!is3DEN && {hasInterface}) then {0 fadeRadio _value}";
		};
		class ENH_RandomMusic
		{
			displayName = $STR_ENH_RANDOMMUSIC_DISPLAYNAME;
			tooltip = $STR_ENH_RANDOMMUSIC_TOOLTIP;
			property = "ENH_randomMusic";
			control = "EditArray";
			expression = "if (!is3DEN && {!(_value isEqualTo []) && {hasInterface}}) then {playMusic (selectRandom _value)}";
			defaultValue = "[]";
		};
	};
};