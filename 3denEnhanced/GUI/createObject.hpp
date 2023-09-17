class ENH_CreateObject
{
  idd = IDD_CREATEOBJECT;
  movingEnable = true;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
       text = "$STR_3DEN_HISTORY_CREATEOBJECT_DISPLAYNAME";
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W;
      y = 0.5 - WINDOW_HAbs * 0.5 + 5 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W;
      y = 0.5 - WINDOW_HAbs * 0.5 + 10 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = WINDOW_HAbs - 15 * GRID_H;
    };
    class BackgroundButton: ctrlStaticFooter
    {
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W;
      y = 0.5 + WINDOW_HAbs * 0.5 - 12 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class ModeValue: ctrlToolbox
    {
      idc = IDC_CREATEOBJECT_MODE;
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = 0.5 - WINDOW_HAbs * 0.5 + 11 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = CTRL_DEFAULT_H;
      colorSelectedBg[] = {COLOR_TAB_RGBA};
      colorBackground[] = {COLOR_BACKGROUND_RGBA};
      columns = 2;
      rows = 1;
      strings[] =
      {
        "$STR_3DEN_HISTORY_CREATEOBJECT_DISPLAYNAME",
        "$STR_3DEN_HISTORY_CREATEMARKER_DISPLAYNAME"
      };
      onToolBoxSelChanged = "_this call ENH_fnc_createObject_changeFilter";
    };
    class ObjectList: ctrlListBox
    {
      idc = IDC_CREATEOBJECT_LIST;
      x = CENTER_X - DIALOG_W * 0.5 * GRID_W + GRID_W;
      y = 0.5 - WINDOW_HAbs * 0.5 + 16 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = WINDOW_HAbs - 29 * GRID_H;
      onLoad = "[_this select 0, 0] call ENH_fnc_createObject_changeFilter"; //Fill list
      rowHeight = 2 * CTRL_DEFAULT_H;
    };
    class OK: ctrlButtonOK
    {
      idc = IDC_CREATEOBJECT_CLOSE;
      text = "$STR_SINGLE_CREATE";
      x = CENTER_X + DIALOG_W * 0.5 * GRID_W - 52 * GRID_W;
      y = 0.5 + WINDOW_HAbs * 0.5 - 11 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_createObject_create";
    };
    class Cancel: ctrlButtonClose
    {
      x = CENTER_X + DIALOG_W * 0.5 * GRID_W - 26 * GRID_W;
      y = 0.5 + WINDOW_HAbs * 0.5 - 11 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};