class Date
{
	class Attributes
	{
		class ENH_TimeMultiplier
		{
			displayName = $STR_ENH_TIMEMULTIPLIER_DISPLAYNAME;
			tooltip = $STR_ENH_TIMEMULTIPLIER_TOOLTIP;
			property = "ENH_timeMultiplier";
			control = "ENH_TimeMultiplier";
			expression = "if (!is3DEN && {isServer && {_value != 1}}) then {setTimeMultiplier _value}";
			defaultValue = "1";
		};
	};
};