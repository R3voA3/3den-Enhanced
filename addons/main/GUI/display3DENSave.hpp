class Display3DENSave
{
  class ControlsBackground
  {
    class Background: ctrlStaticBackground
    {
      x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 0.5) * GRID_W);
      w = QUOTE(WINDOW_W_WIDE * GRID_W);
    };
    class BackgroundFilter: ctrlStatic
    {
      x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
      w = QUOTE((WINDOW_W_WIDE * 3/4 - 2) * GRID_W);
    };
    class BackgroundFiles: ctrlStaticOverlay
    {
      x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
      w = QUOTE((WINDOW_W_WIDE * 3/4 - 2) * GRID_W);
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
    class Search: ctrlEdit
    {
      x = QUOTE(CENTER_X + (WINDOW_W_WIDE * 1/4 - 5 - 1) * GRID_W);
      w = QUOTE((WINDOW_W_WIDE / 4) * GRID_W);
    };
    class SearchButton: ctrlButtonSearch
    {
      x = QUOTE(CENTER_X + (WINDOW_W_WIDE * 1/2 - 5 - 1) * GRID_W);
    };
    class Folders: ctrlTree
    {
      x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 0.5 - 1) * GRID_W);
      w = QUOTE((WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
    };
    class Files: ctrlListNBox
    {
      x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
      w = QUOTE((WINDOW_W_WIDE * 3/4 - 2) * GRID_W);
    };
    class Filter: ctrlListNBox
    {
      x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
      w = QUOTE((WINDOW_W_WIDE * 3/4 - 2) * GRID_W);
    };
    class NameText: ctrlStatic
    {
      x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 0.5 - 1) * GRID_W);
      w = QUOTE((WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
    };
    class Name: ctrlEdit
    {
      x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
      w = QUOTE((WINDOW_W_WIDE * 3/4 - 2) * GRID_W);
    };
    class BinarizeText: ctrlStatic
    {
      x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 0.5 - 1) * GRID_W);
      w = QUOTE((WINDOW_W_WIDE * 1/4 - 1) * GRID_W);
    };
    class Binarize: ctrlCheckbox
    {
      x = QUOTE(CENTER_X - (WINDOW_W_WIDE * 1/4) * GRID_W);
    };
    class ButtonOK: ctrlButtonOK
    {
      x = QUOTE(CENTER_X + (WINDOW_W_WIDE * 0.5 - 50 - 2) * GRID_W);
    };
    class ButtonPurchase: ctrlShortcutButtonSteam
    {
      x = QUOTE(CENTER_X + (WINDOW_W_WIDE * 0.5 - 60 - 2) * GRID_W);
    };
    class ButtonCancel: ctrlButtonCancel
    {
      x = QUOTE(CENTER_X + (WINDOW_W_WIDE * 0.5 - 25 - 1) * GRID_W);
    };
  };
};