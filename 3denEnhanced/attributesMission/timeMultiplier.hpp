class Date
{
	class Attributes
	{
		class Enh_TimeMultiplier
		{
			displayName = $STR_ENH_timeMultiplier_displayName;
			tooltip = $STR_ENH_timeMultiplier_tooltip;
			property = "Enh_timeMultiplier";
			control = "Enh_TimeMultiplier";
			expression = "if (!is3DEN && isServer) then {setTimeMultiplier _value}";
			defaultValue = "1";
		};
	};
};
