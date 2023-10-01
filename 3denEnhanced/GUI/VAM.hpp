class ENH_VAM
{
  idd = IDD_VAM;
  onLoad = "";
  movingEnable = true;
  class ControlsBackground
  {
    DISABLE_BACKGROUND
    class Header: ctrlStaticTitle
    {
      text = "Virtual Arsenal Manager";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Background: ctrlStaticBackground
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = WINDOW_HAbs - 3 * CTRL_DEFAULT_H;
    };
    class LabelItems: ctrlStatic
    {
      text = "Items";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + CTRL_DEFAULT_H + GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H;
      font = FONT_BOLD;
      sizeEx = SIZEEX_PURISTA(SIZEEX_L);
    };
    class LabelCompatibleItems: LabelItems
    {
      text = "Compatible Items";
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES / 2) * GRID_W;
    };
    class Footer: ctrlStaticFooter
    {
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = WINDOW_W_ATTRIBUTES * GRID_W;
      h = CTRL_DEFAULT_H + 2 * GRID_H;
    };
  };
  class Controls
  {
			class ButtonExpandAllItems: ctrlButtonExpandAll
			{
					idc = IDC_VAM_BUTTON_EXPAND_ITEMS;
					x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 46 * GRID_W;
					y = WINDOW_TOPAbs + WINDOW_HAbs - 11 * CTRL_DEFAULT_H - 2 * GRID_H;
					w = 5 * GRID_W;
					h = CTRL_DEFAULT_H;
			};
			class ButtonCollapseAllItems: ctrlButtonCollapseAll
			{
					idc = IDC_VAM_BUTTON_COLLAPSE_ITEMS;
					x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 41 * GRID_W;
					y = WINDOW_TOPAbs + WINDOW_HAbs - 11 * CTRL_DEFAULT_H - 2 * GRID_H;
					w = 5 * GRID_W;
					h = CTRL_DEFAULT_H;
			};
    class SearchItems: ctrlEdit
    {
      idc = IDC_VAM_SEARCH_ITEMS;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 11 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = 35 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonSearchItems: ctrlButtonSearch
    {
      idc = IDC_VAM_BUTTON_SEARCH_ITEMS;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 36 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 11 * CTRL_DEFAULT_H - 2 * GRID_H;
      w = 5 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class Items: ctrlTree
    {
      idc = IDC_VAM_TREEVIEW;
      idcSearch = IDC_VAM_SEARCH_ITEMS;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + 2 * GRID_H;
      w = WINDOW_W_ATTRIBUTES / 2 * GRID_W - 1.5 * GRID_W;
      h = WINDOW_HAbs - 14 * CTRL_DEFAULT_H;
      borderSize = 0;
      colorBorder[] = {0, 0, 0, 0};
      colorBackground[] = {COLOR_TAB_RGBA};
    };
				class ButtonExpandAllCompatibleItems: ButtonExpandAllItems
				{
						idc = IDC_VAM_BUTTON_EXPAND_COMPATIBLE_ITEMS;
						x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES / 2) * GRID_W + 0.5 * GRID_W + 45 * GRID_W;
				};
				class ButtonCollapseAllCompatibleItems: ButtonCollapseAllItems
				{
						idc = IDC_VAM_BUTTON_COLLAPSE_COMPATIBLE_ITEMS;
					 x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES / 2) * GRID_W + 0.5 * GRID_W + 40 * GRID_W;
				};
    class SearchCompatibleItems: SearchItems
    {
      idc = IDC_VAM_SEARCH_COMPATIBLE_ITEMS;
						x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES / 2) * GRID_W + 0.5 * GRID_W;
    };
    class ButtonSearchCompatibleItems: ButtonSearchItems
    {
      idc = IDC_VAM_BUTTON_SEARCH_COMPATIBLE_ITEMS;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES / 2) * GRID_W + 0.5 * GRID_W + 35 * GRID_W;
    };
    class CompatibleItems: Items
    {
      idc = IDC_VAM_TREEVIEW_COMP_ITEMS;
      idcSearch = IDC_VAM_SEARCH_COMPATIBLE_ITEMS;
						x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (WINDOW_W_ATTRIBUTES / 2) * GRID_W + 0.5 * GRID_W;
    };
    class GroupStatistics: ctrlControlsGroup
    {
      idc = -1;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 9 * CTRL_DEFAULT_H - 4 * GRID_H;
      w = WINDOW_W_ATTRIBUTES / 2 * GRID_W;
      h = 6 * CTRL_DEFAULT_H;
      class Controls
      {
        class LabelStat1: ctrlStatic
        {
									idc = IDC_VAM_PROGRESS_TEXT_1;
          text = "Compatible Items";
          x = 0;
          y = 0;
										w = WINDOW_W_ATTRIBUTES / 2 * GRID_W - 4 * GRID_W;
          h = 3 * GRID_H;
          sizeEx = SIZEEX_PURISTA(SIZEEX_S);
        };
        class LabelStat2: LabelStat1
        {
									idc = IDC_VAM_PROGRESS_TEXT_2;
          text = "Compatible Items";
          y = 6 * GRID_H;
        };
        class LabelStat3: LabelStat1
        {
									idc = IDC_VAM_PROGRESS_TEXT_3;
          text = "Compatible Items";
          y = 12 * GRID_H;
        };
        class LabelStat4: LabelStat1
        {
									idc = IDC_VAM_PROGRESS_TEXT_4;
          text = "Compatible Items";
          y = 18 * GRID_H;
        };
        class LabelStat5: LabelStat1
        {
									idc = IDC_VAM_PROGRESS_TEXT_5;
          text = "Compatible Items";
          y = 24 * GRID_H;
        };
        class ProgressStat1: ctrlProgress
        {
									idc = IDC_VAM_PROGRESS_1;
          x = GRID_W + 4 * pixelW;
          y = 4 * GRID_H;
          w = WINDOW_W_ATTRIBUTES / 2 * GRID_W - 4 * GRID_W;
          h = GRID_H;
        };
        class ProgressStat2: ProgressStat1
        {
									idc = IDC_VAM_PROGRESS_2;
          y = 10 * GRID_H;
        };
        class ProgressStat3: ProgressStat1
        {
									idc = IDC_VAM_PROGRESS_3;
          y = 16 * GRID_H;
        };
        class ProgressStat4: ProgressStat1
        {
									idc = IDC_VAM_PROGRESS_4;
          y = 22 * GRID_H;
        };
        class ProgressStat5: ProgressStat1
        {
									idc = IDC_VAM_PROGRESS_5;
          y = 28 * GRID_H;
        };
      };
    };
				class Preview: ctrlStaticPictureKeepAspect
    {
      idc = IDC_VAM_PREVIEW_PICTURE;
						text = "a3\data_f_warlords\data\preview_empty.jpg";
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - WINDOW_W_ATTRIBUTES / 2 * GRID_W - GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 10 * CTRL_DEFAULT_H;
      w = WINDOW_W_ATTRIBUTES / 2 * GRID_W;
      h = 5 * CTRL_DEFAULT_H - GRID_H;
    };
				class ToolboxType: ctrlToolbox
    {
      idc = IDC_VAM_TYPETOOLBOX;
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - WINDOW_W_ATTRIBUTES / 2 * GRID_W - GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 4 * CTRL_DEFAULT_H - 3 * GRID_H;
      w = WINDOW_W_ATTRIBUTES / 2 * GRID_W;
      h = CTRL_DEFAULT_H;
						columns = 2;
						strings[] = {"BI Arsenal", "ACE Arsenal"};
    };
				class ButtonApply: ctrlButton
    {
					idc = IDC_VAM_BUTTON_APPLY;
      x = CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
				class ButtonLoadObject: ctrlButton
    {
					text = "Load Object";
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 104 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
				class ButtonPresets: ctrlButton
    {
					text = "Presets";
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 78 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
				class ButtonExport: ctrlButton
    {
					text = "Export";
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 52 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
    class ButtonClose: ctrlButtonClose
    {
      x = CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W;
      y = WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H;
      w = 25 * GRID_W;
      h = CTRL_DEFAULT_H;
    };
  };
};