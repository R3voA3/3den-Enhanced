class Enh_Volume
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_volume;
	class Attributes
	{
		class Enh_SoundVolume
		{
			displayName = $STR_ENH_soundVolume_displayName;
			tooltip = "";
			property = "Enh_soundVolume";
			control = "Slider";
			expression = "if (!is3DEN && hasInterface) then {0 fadeSound _value}";
			defaultValue = "1";
		};
		class Enh_MusicVolume: Enh_SoundVolume
		{
			displayName = $STR_ENH_musicVolume_displayName;
			property = "Enh_musicVolume";
			expression = "if (!is3DEN && hasInterface) then {0 fadeMusic _value}";
		};
		class Enh_RadioVolume: Enh_SoundVolume
		{
			displayName = $STR_ENH_radioVolume_displayName;
			property = "Enh_radioVolume";
			expression = "if (!is3DEN && hasInterface) then {0 fadeRadio _value}";
		};
		class Enh_RandomMusic
		{
			displayName = $STR_ENH_randomMusic_displayName;
			tooltip = $STR_ENH_randomMusic_tooltip;
			property = "Enh_randomMusic";
			control = "EditArray";
			expression = "if (!is3DEN && !(_value isEqualTo []) && hasInterface) then {playMusic (selectRandom _value)}";
			defaultValue = "[]";
		};
	};
};
