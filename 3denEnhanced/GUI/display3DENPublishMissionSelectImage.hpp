class display3DENPublishMissionSelectImage
{//Only changed classes and attributes are listed here
    class ControlsBackground
    {
        class Background: ctrlStaticBackground
        {
            x = CENTER_X - 110 * GRID_W;
            y = 0.5 - (100 * 0.5 - 10) * GRID_H;
            w = 220 * GRID_W;
            h = (100 - (10 + 5)) * GRID_H;
        };
        class BackgroundPreview: ctrlStatic
        {
            x = CENTER_X + 30 * GRID_W;
            y = 0.5 - (100 * 0.5 - 11) * GRID_H;
            w = (80 - 1) * GRID_W;
            h = (100 - (23 + 5 + 2)) * GRID_H;
        };
        class BackgroundButtons: ctrlStaticFooter
        {
            x = CENTER_X - (110) * GRID_W;
            y = 0.5 + (100 * 0.5 - 2 * (5 + 1)) * GRID_H;
            w = 220 * GRID_W;
            h = (5 + 2) * GRID_H;
        };
    };
    class Controls
    {
        class Title: ctrlStaticTitle
        {
            x = CENTER_X - 110 * GRID_W;
            y = 0.5 - (100 * 0.5 - 5) * GRID_H;
            w = 220 * GRID_W;
            h = CTRL_DEFAULT_H;
        };
        class Folders: ctrlTree
        {
            x = CENTER_X - (110 - 1) * GRID_W;
            y = 0.5 - (100 * 0.5 - 11) * GRID_H;
            w = (100 - 1) * GRID_W;
            h = (100 - (23 + 5 + 2)) * GRID_H;
        };
        class Files: ctrlListbox
        {
            x = CENTER_X - (10 - 1) * GRID_W;
            y = 0.5 - (100 * 0.5 - 11) * GRID_H;
            w = (80 * 2/4 - 2) * GRID_W;
            h = (100 - (23 + 5 + 2)) * GRID_H;
        };
        class Preview: ctrlStaticPictureKeepAspect
        {
            x = CENTER_X + 30 * GRID_W;
            y = 0.5 - (100 * 0.5 - 11) * GRID_H;
            w = (80 - 1) * GRID_W;
            h = (100 - (23 + 5 + 2)) * GRID_H;
        };
        class Name: ctrlStaticMulti
        {
            x = CENTER_X - (110 - 1) * GRID_W;
            y = 0.5 + (100 * 0.5 - (3 * 5 + 3)) * GRID_H;
            w = (280 - 2) * GRID_W;
            h = CTRL_DEFAULT_H;
        };
    };
};