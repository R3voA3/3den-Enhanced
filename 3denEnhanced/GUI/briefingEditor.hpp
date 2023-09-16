class ENH_BriefingEditor
{
  idd = IDD_BRIEFINGEDITOR;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_briefingEditor_onLoad";
  onUnload = "_this call ENH_fnc_briefingEditor_onUnload";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_BRIEFINGEDITOR";
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W;
      y = DIALOG_TOP;
      w = 160 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = 160 * GRID_W;
      h = 110 * GRID_H;
    };
    class Separator: ctrlStaticFrame
    {
      x = CENTER_X * 0.5 * 158 * GRID_W * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 95 * GRID_H;
      w = 158 * GRID_W;
      h = 0;
    };
    class BackgroundButtons: ctrlStaticFooter
    {
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 103 * GRID_H;
      w = 160 * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
    class Subject: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_SUBJECT";
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 1 * GRID_H;
      w = 45 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SubjectValue: ctrlEdit
    {
      idc = IDC_BRIEFINGEDITOR_SUBJECT;
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W + GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 6 * GRID_H;
      w = 45 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Title: Subject
    {
      text = "$STR_ENH_BRIEFINGEDITOR_BRIEFINGTITLE";
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W + 47 * GRID_W;
    };
    class TitleValue: SubjectValue
    {
      idc = IDC_BRIEFINGEDITOR_TITLE;
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W + 48 * GRID_W;
    };
    class ShowTitle: Subject
    {
      text = "$STR_ENH_BRIEFINGEDITOR_SHOWTITLE";
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W + 94 * GRID_W;
    };
    class ShowTitleValue: ctrlToolbox
    {
      idc = IDC_BRIEFINGEDITOR_SHOWTITLE;
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W + 95 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 6 * GRID_H;
      w = 32 * GRID_W;
      h = CTRL_DEFAULT_H;
      rows = 1;
      columns = 2;
      strings[] =
      {
        "$STR_ENH_YES",
        "$STR_ENH_NO"
      };
      values[] = {0, 1};
    };
    class BriefingText: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_TEXT";
      tooltip = "$STR_ENH_BRIEFINGEDITOR_TEXT_TOOLTIP";
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 13 * GRID_H;
      w = 90 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Group: ctrlControlsGroup
    {
      x = CENTER_X * 0.5 * 158 * GRID_W * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 19 * GRID_H;
      w = 158 * GRID_W;
      h = 60 * GRID_H;
      class Controls
      {
        class BriefingTextValue: ctrlEditMulti
        {
          idc = IDC_BRIEFINGEDITOR_BRIEFINGTEXT;
          x = 0;
          y = 0;
          w = 158 * GRID_W;
          h = 60 * GRID_H;
          font = "ENH_BlankFont";
          colorBackground[] = {0,0,0,0};
          colorText[] = {0,0,0,1};
          forceDrawCaret = 1;
          colorSelection[] =
          {
            "profilenamespace getvariable ['GUI_BCG_RGB_R', 0.13]",
            "profilenamespace getvariable ['GUI_BCG_RGB_G', 0.54]",
            "profilenamespace getvariable ['GUI_BCG_RGB_B', 0.21]",
            0.3
          };
        };
        class BriefingTextSyntaxHighligthingValue: ctrlStructuredText
        {
          idc = IDC_BRIEFINGEDITOR_HIGHLIGHT;
          x = 0;
          y = 0;
          w = 158 * GRID_W;
          h = 60 * GRID_H;
          class Attributes
          {
            font = "EtelkaMonospacePro";
            align = "left";
          };
        };
      };
    };
    class TAGs: ctrlStatic
    {
      text = "$STR_ENH_BRIEFINGEDITOR_TAGS";
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 80 * GRID_H;
      w = 8 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TAGsValue: ctrlCombo
    {
      idc = IDC_BRIEFINGEDITOR_TAGS;
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W + GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
      w = 27 * GRID_W;
      h = CTRL_DEFAULT_H;
      onLBSelChanged = "_this call ENH_fnc_briefingEditor_onLBSelChanged";
    };
    class Help: ctrlButton
    {
      text = "?";
      url = "https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#briefing-editor";
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W + 29 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class FirstParamText: TAGs
    {
      idc = IDC_BRIEFINGEDITOR_FIRSTPARAM;
      x = CENTER_X - 46 * GRID_W;
      w = 20 * GRID_W;
    };
    class FirstParamValue: ctrlEdit
    {
      idc = IDC_BRIEFINGEDITOR_FIRSTPARAMVALUE;
      x = CENTER_X - 45 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
      w = 29 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SecondParamText: TAGs
    {
      idc = IDC_BRIEFINGEDITOR_SECONDPARAM;
      x = CENTER_X - 16 * GRID_W;
    };
    class SecondParamValue: ctrlEdit
    {
      idc = IDC_BRIEFINGEDITOR_SECONDPARAMVALUE;
      x = CENTER_X - 15 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
      w = 29 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ThirdParamText: TAGs
    {
      idc = IDC_BRIEFINGEDITOR_THIRDPARAM;
      x = CENTER_X + 14 * GRID_W;
      w = 20 * GRID_W;
    };
    class MarkerList: ctrlCombo
    {
      idc = IDC_BRIEFINGEDITOR_MARKERS;
      x = CENTER_X - 45 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
      w = 29 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
     class ColourList: MarkerList
    {
      idc = IDC_BRIEFINGEDITOR_COLOURS;
      x = CENTER_X - 15 * GRID_W;
    };
    class FontsList: MarkerList
    {
      idc = IDC_BRIEFINGEDITOR_FONTS;
      x = CENTER_X + 15 * GRID_W;
    };
    class ThirdParamValue: ctrlEdit
    {
      idc = IDC_BRIEFINGEDITOR_THIRDPARAMVALUE;
      x = CENTER_X + 15 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
      w = 30 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class AddTAG: ctrlButton
    {
      text = "$STR_ENH_BRIEFINGEDITOR_ADDTAG";
      x = CENTER_X + 46 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
      w = 33 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_briefingEditor_addTAG";
    };
    class TemplateList: ctrlCombo
    {
      idc = IDC_BRIEFINGEDITOR_TEMPLATES;
      x = CENTER_X * 0.5 * 158 * GRID_W * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 97 * GRID_H;
      w = 158 * GRID_W;
      h = CTRL_DEFAULT_H;
      onLBSelChanged = "['load', _this # 0] call ENH_fnc_briefingEditor_handleTemplates";
    };
    class CreateTemplate: ctrlButton
    {
      text = "$STR_ENH_BRIEFINGEDITOR_CREATETEMPLATE";
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W + 1 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
      w = 33 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "['add', _this # 0] call ENH_fnc_briefingEditor_handleTemplates";
    };
    class DeleteTemplate: ctrlButtonPictureKeepAspect
    {
      idc = IDC_ESE_DELETETEMPLATE;
      text = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
      tooltip = "$STR_ENH_ESE_DELETETEMPLATE";
      x = CENTER_X * 0.5 * 160 * GRID_W * GRID_W + 35 * GRID_W;
      y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      colorBackground[] = {0, 0, 0, 0};
      colorBackgroundDisabled[] = {0, 0, 0, 0};
      onButtonClick = "['remove', _this # 0] call ENH_fnc_briefingEditor_handleTemplates";
    };
    class Export: ctrlButton
    {
      text = "$STR_ENH_BRIEFINGEDITOR_EXPORT";
      x = CENTER_X + 12 * GRID_W;
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