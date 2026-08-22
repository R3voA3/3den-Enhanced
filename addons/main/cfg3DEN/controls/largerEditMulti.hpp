class Edit: Title
{
    class Controls: Controls
    {
        class Title;
        class Value;
    };
};
class EditMulti3: Edit // We leave this one unchanged as it's not used anyway
{
    class Controls: Controls
    {
        class Background;
        class Title;
        class Value;
    };
};
class EditMulti5: EditMulti3
{
    h = QUOTE(75 * GRID_H);
    class Controls: Controls
    {
        class Background: Background
        {
            h = QUOTE(73 * GRID_H);
        };
        class Title: Title
        {
            h = QUOTE(75 * GRID_H);
        };
        class Value: Value
        {
            h = QUOTE(69 * GRID_H);
        };
    };
};
class EditCodeMulti3: EditMulti3
{
    h = QUOTE(57.5 * GRID_H);
    class Controls: Controls
    {
        class Background: Background
        {
            h = QUOTE(55.5 * GRID_H);
        };
        class Title: Title
        {
            h = QUOTE(57.5 * GRID_H);
        };
        class Value: Value
        {
            h = QUOTE(52.5 * GRID_H - GRID_H);
        };
    };
};
class EditCodeMulti5: EditMulti5
{
    h = QUOTE(75 * GRID_H);
    class Controls: Controls
    {
        class Background: Background
        {
            h = QUOTE(73 * GRID_H);
        };
        class Title: Title
        {
            h = QUOTE(75 * GRID_H);
        };
        class Value: Value
        {
            h = QUOTE(69 * GRID_H);
        };
    };
};
