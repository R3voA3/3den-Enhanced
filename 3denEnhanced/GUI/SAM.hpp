#define DIALOG_W 160
#define DIALOG_H 90

class ENH_SAM
{
  idd = IDD_SAM;
  movingEnable = true;
  onLoad = "_this call ENH_fnc_SAM_onLoad";
  onUnload = "_this call ENH_fnc_SAM_onUnload";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      text = "$STR_ENH_TOOLS_SAM";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP;
      w = DIALOG_W * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Templates: ctrlStatic
    {
      text = "$STR_ENH_SAM_TEMPLATES";
      x = CENTERED_X(DIALOG_W);
      y = DIALOG_TOP + 6 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Attributes: ctrlStatic
    {
      text = "$STR_ENH_SAM_ATTRIBUTES";
      x = CENTERED_X(DIALOG_W) + 51 * GRID_W;
      y = DIALOG_TOP + 6 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class CreateTemplate: ctrlButton
    {
      text = "$STR_ENH_SAM_CREATETEMPLATE";
      x = CENTERED_X(DIALOG_W) + 98 * GRID_W;
      y = DIALOG_TOP + 6 * GRID_H;
      w = 61 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "ctrlParent (_this # 0) createDisplay 'ENH_SAM_TemplateData'";
    };
    class TemplateList: ctrlListbox
    {
      idc = IDC_SAM_TEMPLATES;
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 12 * GRID_H;
      w = 50 * GRID_W;
      h = 70 * GRID_H;
      onLBSelChanged = "_this call ENH_fnc_SAM_loadTemplate";
    };
    class AttributeList: ctrlTree
    {
      idc = IDC_SAM_ATTRIBUTES;
      idcSearch = 1400;
      x = CENTERED_X(DIALOG_W) + 52 * GRID_W;
      y = DIALOG_TOP + 12 * GRID_H;
      w = 107 * GRID_W;
      h = 70 * GRID_H;
    };
    class DeleteTemplate: ctrlButton
    {
      text = "$STR_ENH_SAM_DELETETEMPLATE";
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 83 * GRID_H;
      w = 50 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_SAM_deleteTemplate";
    };
    class ApplyTemplate: ctrlButton
    {
      text = "$STR_ENH_SAM_APPLYTEMPLATE";
      x = CENTERED_X(DIALOG_W) + GRID_W;
      y = DIALOG_TOP + 89 * GRID_H;
      w = 50 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_SAM_applyTemplate";
    };
    class Search: ctrlEdit
    {
      idc = IDC_SAM_SEARCH;
      tooltip = __EVAL(format ["%1+%2", toUpper localize "STR_DIK_CONTROL", "F"]);
      x = CENTERED_X(DIALOG_W) + 52 * GRID_W;
      y = DIALOG_TOP + 83 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class SearchIcon: ctrlStaticPictureKeepAspect
    {
      text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
      x = CENTERED_X(DIALOG_W) + 77 * GRID_W;
      y = DIALOG_TOP + 83 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Collapse: ctrlButtonCollapseAll
    {
      x = CENTERED_X(DIALOG_W) + 82 * GRID_W;
      y = DIALOG_TOP + 83 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick  = "tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
    };
    class Expand: ctrlButtonExpandAll
    {
      x = CENTERED_X(DIALOG_W) + 87 * GRID_W;
      y = DIALOG_TOP + 83 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick  = "tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
    };
    class ApplyAttribute: ctrlButton
    {
      text = "$STR_ENH_SAM_APPLYATTRIBUTE";
      x = CENTERED_X(DIALOG_W) + 52 * GRID_W;
      y = DIALOG_TOP + 89 * GRID_H;
      w = 40 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_SAM_applyAttribute";
    };
    /* class Export: ctrlButton
    {
      text = "$STR_ENH_SAM_EXPORT";
      x = CENTERED_X(DIALOG_W) + 118 * GRID_W;
      y = DIALOG_TOP + 89 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_SAM_exportToClipboard";
    }; */
    class Close: ctrlButtonClose
    {
      x = CENTERED_X(DIALOG_W) + 134 * GRID_W;
      y = DIALOG_TOP + 89 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};

class ENH_SAM_TemplateData
{
  idd = IDD_SAM_TEMPLATEDATA;
  movingEnable = true;
  onLoad = "ENH_SAM_TemplateTitle = ''; ENH_SAM_TemplateDescription = ''";
  onUnload = "";
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Background: ctrlStaticBackground
    {
      x = CENTERED_X(60);
      y = DIALOG_TOP + CTRL_DEFAULT_H;
      w = 60 * GRID_W;
      h = 51 * GRID_H;
    };
  };
  class Controls
  {
    class Header: ctrlStaticTitle
    {
      x = CENTERED_X(60);
      y = DIALOG_TOP;
      w = 60 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Title: ctrlStatic
    {
      text = "$STR_ENH_SAM_TEMPLATE_DATA_TITLE";
      x = CENTERED_X(60);
      y = DIALOG_TOP + 6 * GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class TitleValue: ctrlEdit
    {
      idc = IDC_SAM_TEMPLATEDATA_TITLE;
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 12 * GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Description: ctrlStatic
    {
      text = "$STR_ENH_SAM_TEMPLATE_DATA_DESCRIPTION";
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 18 * GRID_H;
      w = 58 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class DescriptionValue: ctrlEditMulti
    {
      idc = IDC_SAM_TEMPLATEDATA_DESCRIPTION;
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 24 * GRID_H;
      w = 58 * GRID_W;
      h = 25 * GRID_H;
    };
    class Cancel: ctrlButtonCancel
    {
      x = CENTERED_X(60) + 34 * GRID_W;
      y = DIALOG_TOP + 50 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class OK: ctrlButtonOK
    {
      x = CENTERED_X(60) + 1 * GRID_W;
      y = DIALOG_TOP + 50 * GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
      onButtonClick = "_this call ENH_fnc_SAM_createTemplate";
    };
  };
};