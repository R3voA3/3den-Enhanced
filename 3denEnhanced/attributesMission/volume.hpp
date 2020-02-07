class ENH_Volume
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_volume;
	class Attributes
	{
		class ENH_SoundVolume
		{
			displayName = $STR_ENH_soundVolume_displayName;
			tooltip = "";
			property = "ENH_soundVolume";
			control = "Slider";
			expression = "if (!is3DEN && hasInterface) then {0 fadeSound _value}";
			defaultValue = "1";
		};
		class ENH_MusicVolume: ENH_SoundVolume
		{
			displayName = $STR_ENH_musicVolume_displayName;
			property = "ENH_musicVolume";
			expression = "if (!is3DEN && hasInterface) then {0 fadeMusic _value}";
		};
		class ENH_RadioVolume: ENH_SoundVolume
		{
			displayName = $STR_ENH_radioVolume_displayName;
			property = "ENH_radioVolume";
			expression = "if (!is3DEN && hasInterface) then {0 fadeRadio _value}";
		};
		class ENH_RandomMusic
		{
			displayName = $STR_ENH_randomMusic_displayName;
			tooltip = $STR_ENH_randomMusic_tooltip;
			property = "ENH_randomMusic";
			control = "EditArray";
			expression = "if (!is3DEN && !(_value isEqualTo []) && hasInterface) then {playMusic (selectRandom _value)}";
			defaultValue = "[]";
		};
	};
};
