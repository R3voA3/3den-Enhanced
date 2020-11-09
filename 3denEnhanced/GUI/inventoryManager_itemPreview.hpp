class ENH_InventoryManager_ItemPreview
{
    idd = -1;
    class ControlsBackground
    {
        DISABLE_BACKGROUND
        class Background: ctrlStaticBackground
        {
            x = CENTERED_X(60);
            y = DIALOG_TOP + 50 * GRID_H + CTRL_DEFAULT_H;
            w = 60 * GRID_W;
            h = 60 * GRID_H;
        };
    };
    class Controls
    {
        class Header: ctrlStaticTitle
        {
            idc = 1000;
            x = CENTERED_X(60);
            y = DIALOG_TOP + 50 * GRID_H;
            w = 60 * GRID_W;
            h = CTRL_DEFAULT_H;
        };
        class Image: ctrlStaticPictureKeepAspect
        {
            idc = 1100;
            x = CENTERED_X(60);
            y = DIALOG_TOP + 50 * GRID_H + CTRL_DEFAULT_H;
            w = 60 * GRID_W;
            h = 60 * GRID_H;
        };
        class Close: ctrlButtonClose
        {
            x = CENTERED_X(60) + 35 * GRID_W;
            y = DIALOG_TOP + 110 * GRID_H + CTRL_DEFAULT_H;
            w = 25 * GRID_W;
            h = CTRL_DEFAULT_H;
        };
    };
};