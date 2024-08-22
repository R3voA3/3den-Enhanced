class Display3DENPublishMissionSelectImage
{
    class ControlsBackground
    {
        class BackgroundDisable: ctrlStaticBackgroundDisable {};
        class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles {};
        class Background: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_WIDE * GRID_W);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
        };
        class BackgroundPreview: ctrlStatic
        {
            x = QUOTE(CENTER_X + (WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
            w = QUOTE((WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
        };
        class BackgroundButtons: ctrlStaticFooter
        {
            x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 0.5) * GRID_W);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
        };
    };
    class Controls
    {
        class Title: ctrlStaticTitle
        {
            x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 0.5) * GRID_W);
            w = QUOTE(WINDOW_W_WIDE * GRID_W);
        };
        class Folders: ctrlTree
        {
            x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 0.5 - 1) * GRID_W);
            w = QUOTE((WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
        };
        class Files: ctrlListbox
        {
            x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
            w = QUOTE((WINDOW_W_WIDE * 2/4 - 2) * GRID_W);
        };
        class Preview: ctrlStaticPictureKeepAspect
        {
            x = QUOTE(CENTER_X + (WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
            w = QUOTE((WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
        };
        class Name: ctrlStaticMulti
        {
            x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 0.5 - 1) * GRID_W);
            w = QUOTE((WINDOW_W_WIDE - 2) * GRID_W);
        };
        class ButtonOK: ctrlButtonOK
        {
            x = QUOTE(CENTER_X + (WINDOW_W_WIDE * 0.5 - 50 - 2) * GRID_W);
        };
        class ButtonCancel: ctrlButtonCancel
        {
            x = QUOTE(CENTER_X + (WINDOW_W_WIDE * 0.5 - 25 - 1) * GRID_W);
        };
    };
};