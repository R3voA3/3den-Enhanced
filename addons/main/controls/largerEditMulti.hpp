class Edit: Title
{
    class Controls: Controls
    {
        class Title;
        class Value;
    };
};
class EditMulti3: Edit
{
    class Controls: Controls
    {
        class Value: Value
        {
            h = QUOTE(69 * GRID_H);
        };
        class Background: ctrlStaticOverlay
        {
            h = QUOTE(73 * GRID_H);
        };
        class Title: ctrlStaticFrame
        {
            h = QUOTE(75 * GRID_H);
        };
    };
};
class EditMulti5: EditMulti3
{
    class Controls: Controls
    {
        class Value;
        class Background;
        class Title;
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
        class Value: Value
        {
            h = QUOTE(52.5 * GRID_H - GRID_H);
        };
        class Title: Title
        {
            h = QUOTE(57.5 * GRID_H);
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
        class Value: Value
        {
            h = QUOTE(69 * GRID_H);
        };
        class Title: Title
        {
            h = QUOTE(75 * GRID_H);
        };
    };
};
