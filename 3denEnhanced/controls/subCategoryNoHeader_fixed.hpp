#define CTRL_H(H) H * 4.5 * GRID_H

class SubCategoryNoHeader1;
class ENH_SubCategoryNoHeader1_Fixed: SubCategoryNoHeader1
{
  attributeLoad = "";
  attributeSave = "";
  h = (2.5 * GRID_H) + CTRL_H(1);
  class Controls
  {
    class Group: ctrlControlsGroup
    {
      idc = 101;
      x = 5 * GRID_W;
      y = 0.3 * 5 * GRID_H;
      w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W) * GRID_W;
      h = CTRL_H(1);
      class Controls
      {
        class Title: ctrlStatic
        {
          idc = 100;
          w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - (5 * pixelW) - (2 * pixelW);
          x = (5 * pixelW) + (2 * pixelW);
          h = CTRL_H(1);
          colorText[] = {1,1,1,0};
          colorBackground[] = {1,1,1,0};
          colorShadow[] = {0,0,0,0};
        };
        class DescriptionDeco: ctrlStatic
        {
          w = 5 * pixelW;
          h = CTRL_H(1);
          colorBackground[] = {1,1,1,0.05};
        };
        class Description: ctrlStructuredText
        {
          idc = 102;
          x = (5 * pixelW) + (2 * pixelW);
          w = (  ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - (5 * pixelW) - (2 * pixelW);
          h = CTRL_H(1);
          colorBackground[] = {1,1,1,0.05};
          shadow = 0;
          class Attributes
          {
            color = "#999999";
            size = 1;
            align = "left";
            colorLink = "";
            font = FONT_NORMAL;
          };
        };
      };
    };
  };
};

class ENH_SubCategoryNoHeader2_Fixed: ENH_SubCategoryNoHeader1_Fixed
{
  h = (2.5 * GRID_H) + CTRL_H(2);
  class Controls
  {
    class Group: ctrlControlsGroup
    {
      idc = 101;
      x = 5 * GRID_W;
      y = 0.3 * 5 * GRID_H;
      w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W) * GRID_W;
      h = CTRL_H(2);
      class Controls
      {
        class Title: ctrlStatic
        {
          idc = 100;
          w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - (5 * pixelW) - (2 * pixelW);
          x = (5 * pixelW) + (2 * pixelW);
          h = CTRL_H(2);
          colorText[] = {1,1,1,0};
          colorBackground[] = {1,1,1,0};
          colorShadow[] = {0,0,0,0};
        };
        class DescriptionDeco: ctrlStatic
        {
          w = 5 * pixelW;
          h = CTRL_H(2);
          colorBackground[] = {1,1,1,0.05};
        };
        class Description: ctrlStructuredText
        {
          idc = 102;
          x = (5 * pixelW) + (2 * pixelW);
          w = (  ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - (5 * pixelW) - (2 * pixelW);
          h = CTRL_H(2);
          colorBackground[] = {1,1,1,0.05};
          shadow = 0;
          class Attributes
          {
            color = "#999999";
            size = 1;
            align = "left";
            colorLink = "";
            font = FONT_NORMAL;
          };
        };
      };
    };
  };
};

class ENH_SubCategoryNoHeader3_Fixed: ENH_SubCategoryNoHeader1_Fixed
{
  h = (2.5 * GRID_H) + CTRL_H(3);
  class Controls
  {
    class Group: ctrlControlsGroup
    {
      idc = 101;
      x = 5 * GRID_W;
      y = 0.3 * 5 * GRID_H;
      w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W) * GRID_W;
      h = CTRL_H(3);
      class Controls
      {
        class Title: ctrlStatic
        {
          idc = 100;
          w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - (5 * pixelW) - (2 * pixelW);
          x = (5 * pixelW) + (2 * pixelW);
          h = CTRL_H(3);
          colorText[] = {1,1,1,0};
          colorBackground[] = {1,1,1,0};
          colorShadow[] = {0,0,0,0};
        };
        class DescriptionDeco: ctrlStatic
        {
          w = 5 * pixelW;
          h = CTRL_H(3);
          colorBackground[] = {1,1,1,0.05};
        };
        class Description: ctrlStructuredText
        {
          idc = 102;
          x = (5 * pixelW) + (2 * pixelW);
          w = (  ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - (5 * pixelW) - (2 * pixelW);
          h = CTRL_H(3);
          colorBackground[] = {1,1,1,0.05};
          shadow = 0;
          class Attributes
          {
            color = "#999999";
            size = 1;
            align = "left";
            colorLink = "";
            font = FONT_NORMAL;
          };
        };
      };
    };
  };
};