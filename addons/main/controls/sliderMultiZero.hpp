class ENH_SliderMultiZero: SliderMultiplier
{
    class Controls: Controls
    {
        class Title: Title {};
        class Edit: Edit {};
        class Value: Value
        {
            sliderRange[] = {0, 3};
            sliderPosition = 1;
            lineSize = 0.1;
            sliderStep = 0.1;
        };
    };
};
