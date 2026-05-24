class Date
{
    class Attributes
    {
        class ENH_SliderMulti120
        {
            displayName = "$STR_ENH_MAIN_TIMEMULTIPLIER_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_TIMEMULTIPLIER_TOOLTIP";
            property = "ENH_timeMultiplier";
            control = "ENH_SliderMulti120";
            expression = "if (!is3DEN && isServer && _value != 1) then {setTimeMultiplier _value}";
            defaultValue = 1;
        };
    };
};
