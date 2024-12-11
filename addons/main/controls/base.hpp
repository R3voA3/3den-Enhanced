// Base class templates
class Default; // Empty template with pre-defined width and single line height
class Title: Default
{
    class Controls
    {
        class Title;
    };
};

class Slider: Title {
    class Controls;
};
class SliderMultiplier: Slider {
    class Controls: Controls {
        class Title;
        class Edit;
        class Value;
    };
};