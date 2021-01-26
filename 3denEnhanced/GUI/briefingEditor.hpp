class ENH_BriefingEditor
{
  idd = IDD_BRIEFINGEDITOR;
  movingEnable = true;
  onLoad = "_this spawn ENH_fnc_briefingEditor_onLoad";
  onUnload = "_this call ENH_fnc_briefingEditor_onUnload";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(160);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = 160 * GRID_W;
      h = 110 * GRID_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_BRIEFINGEDITOR";
      x = CENTERED_X(160);
      y = DIALOG_TOP;
      w = 160 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Templates: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_TEMPLATES";
      x = CENTERED_X(160);
      y = DIALOG_TOP + CTRL_DEFAULT_H + 1 * GRID_H;
      w = 33 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TemplateList: ctrlListbox
    {
      idc = IDC_BRIEFINGEDITOR_TEMPLATES;
      x = CENTERED_X(160) + 1 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 7 * GRID_H;
      w = 33 * GRID_W;
      h = 90 * GRID_H;
      onKeyDown = "if ((_this # 1) == 211 ) then {(_this #  0) lbDelete (lbCurSel (_this # 0))}";
      onLBDblClick = "_this call ENH_fnc_briefingEditor_getTemplate";
    };
    class Marker: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_MARKER";
      x = CENTER_X + 45 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 1 * GRID_H;
      w = 35 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class MarkerList: ctrlListbox
    {
      idc = IDC_BRIEFINGEDITOR_MARKERS;
      x = CENTER_X + 46 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 7 * GRID_H;
      w = 33 * GRID_W;
      h = 25 * GRID_H;
    };
    class Colours: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_COLOUR";
      x = CENTER_X + 45 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 33 * GRID_H;
      w = 35 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
     class ColourList: ctrlListbox
    {
      idc = IDC_BRIEFINGEDITOR_COLOURS;
      x = CENTER_X + 46 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 39 * GRID_H;
      w = 33 * GRID_W;
      h = 30 * GRID_H;
    };
    class Fonts: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_FONT";
      x = CENTER_X + 45 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 70 * GRID_H;
      w = 35 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class FontsList: ctrlListbox
    {
      idc = IDC_BRIEFINGEDITOR_FONTS;
      x = CENTER_X + 46 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 76 * GRID_H;
      w = 33 * GRID_W;
      h = 21 * GRID_H;
    };
    class Subject: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_SUBJECT";
      x = CENTER_X - 46 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 1 * GRID_H;
      w = 45 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SubjectValue: ctrlEdit
    {
      idc = IDC_BRIEFINGEDITOR_SUBJECT;
      x = CENTER_X - 45 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 7 * GRID_H;
      w = 45 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Title: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_BRIEFINGTITLE";
      x = CENTER_X;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 1 * GRID_H;
      w = 44 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TitleValue: ctrlEdit
    {
      idc = IDC_BRIEFINGEDITOR_TITLE;
      x = CENTER_X + 1 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 7 * GRID_H;
      w = 44 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class BriefingText: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_TEXT";
      tooltip = "$STR_ENH_BRIEFINGEDITOR_TEXT_TOOLTIP";
      x = CENTERED_X(90);
      y = DIALOG_TOP + CTRL_DEFAULT_H + 13 * GRID_H;
      w = 90 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class BriefingTextValue: ctrlEditMulti
    {
      idc = IDC_BRIEFINGEDITOR_BRIEFINGTEXT;
      x = CENTERED_X(90);
      y = DIALOG_TOP + CTRL_DEFAULT_H + 19 * GRID_H;
      w = 90 * GRID_W;
      h = 60 * GRID_H;
    };
    class ShowTitle: ctrlToolbox
    {
      idc = IDC_BRIEFINGEDITOR_SHOWTITLE;
      x = CENTERED_X(90);
      y = DIALOG_TOP + CTRL_DEFAULT_H + 80 * GRID_H;
      w = 90 * GRID_W;
      h = CTRL_DEFAULT_H;
      rows = 1;
      columns = 2;
      strings[] =
      {
        "$STR_ENH_BRIEFINGEDITOR_SHOWTITLE",
        "$STR_ENH_BRIEFINGEDITOR_HIDETITLE"
      };
      values[] = {0, 1};
    };
    class TAGs: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_TAGS";
      x = CENTERED_X(90);
      y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
      w = 85 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Help: ctrlButton
    {
      text = "?";
      url = "https://community.bistudio.com/wiki/createDiaryRecord";
      x = CENTER_X + 40 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
     class TAGsValue: ctrlCombo
    {
      idc = IDC_BRIEFINGEDITOR_TAGS;
      x = CENTERED_X(90);
      y = DIALOG_TOP + CTRL_DEFAULT_H + 92 * GRID_H;
      w = 90 * GRID_W;
      h = CTRL_DEFAULT_H;
      onLBSelChanged = "_this call ENH_fnc_briefingEditor_onLBSelChanged";
    };
    class FirstParam: ctrlStatic
    {
      idc = IDC_BRIEFINGEDITOR_FIRSTPARAM;
      x = CENTER_X - 46 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 98 * GRID_H;
      w = 29 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class FirstParamValue: ctrlEdit
    {
      idc = IDC_BRIEFINGEDITOR_FIRSTPARAMVALUE;
      x = CENTER_X - 45 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
      w = 29 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SecondParam: ctrlStatic
    {
      idc = IDC_BRIEFINGEDITOR_SECONDPARAM;
      x = CENTER_X - 16 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 98 * GRID_H;
      w = 29 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SecondParamValue: ctrlEdit
    {
      idc = IDC_BRIEFINGEDITOR_SECONDPARAMVALUE;
      x = CENTER_X - 15 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
      w = 29 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ThirdParam: ctrlStatic
    {
      idc = IDC_BRIEFINGEDITOR_THIRDPARAM;
      x = CENTER_X + 14 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 98 * GRID_H;
      w = 31 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ThirdParamValue: ctrlEdit
    {
      idc = IDC_BRIEFINGEDITOR_THIRDPARAMVALUE;
      x = CENTER_X + 15 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class CreateTemplate: ctrlButton
    {
      text = "$STR_ENH_BRIEFINGEDITOR_CREATETEMPLATE";
      x = CENTERED_X(160) + 1 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 98 * GRID_H;
      w = 33 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_briefingEditor_createTemplate";
    };
    class AddTAG: ctrlButton
    {
      text = "$STR_ENH_BRIEFINGEDITOR_ADDTAG";
      x = CENTER_X + 46 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 98 * GRID_H;
      w = 33 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_briefingEditor_addTAG";
    };
    class Export: ctrlButton
    {
      text = "$STR_ENH_BRIEFINGEDITOR_EXPORT";
      x = CENTERED_X(160) + 1 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
      w = 33 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_briefingEditor_export";
    };
    class Close: ctrlButtonClose
    {
      x = CENTER_X + 46 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
      w = 33 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};