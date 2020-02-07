class Date
{
	class Attributes
	{
		class ENH_TimeMultiplier
		{
			displayName = $STR_ENH_timeMultiplier_displayName;
			tooltip = $STR_ENH_timeMultiplier_tooltip;
			property = "ENH_timeMultiplier";
			control = "ENH_TimeMultiplier";
			expression = "if (!is3DEN && isServer && _value != 1) then {setTimeMultiplier _value}";
			defaultValue = "1";
		};
	};
};