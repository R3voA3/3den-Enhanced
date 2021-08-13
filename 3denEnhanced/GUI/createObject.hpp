#define DIALOG_W 100
#define DIALOG_H 44

class ENH_CreateObject
{
  idd = IDD_CREATEOBJECT;
  movingEnable = true;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = (DIALOG_H + 1) * GRID_H;
    };
    class BackgroundButton: ctrlStaticFooter
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 43 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      text = "$STR_3DEN_HISTORY_CREATEOBJECT_DISPLAYNAME";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Mode: ctrlStatic
    {
      text = "$STR_3DEN_GARBAGECOLLECTION_ATTRIBUTE_MODE_DISPLAYNAME";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 6 * GRID_H;
      w = DIALOG_W * GRID_W - 4 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ModeValue: ctrlToolbox
    {
      idc = IDC_CREATEOBJECT_MODE;
      x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
      y = DIALOG_TOP + 12 * GRID_H;
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
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 17 * GRID_H;
      w = DIALOG_W * GRID_W - 2 * GRID_W;
      h = 5 * CTRL_DEFAULT_H;
      onLoad = "[_this select 0, 0] call ENH_fnc_createObject_changeFilter"; //Fill list
      rowHeight = 2 * CTRL_DEFAULT_H;
    };
    class OK: ctrlButtonOK
    {
      idc = IDC_CREATEOBJECT_CLOSE;
      text = "$STR_SINGLE_CREATE";
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 57 * GRID_W;
      y = DIALOG_TOP + 44 * GRID_H;
      w = 27 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_createObject_create";
    };
    class Cancel: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + DIALOG_W * GRID_W - 28 * GRID_W;
      y = DIALOG_TOP + 44 * GRID_H;
      w = 27 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};