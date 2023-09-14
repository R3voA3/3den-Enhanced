#define CTRL_H(H) H * 4.5 * GRID_H

class SubCategoryNoHeader1: Default
{
  class Controls
  {
    class Group: ctrlControlsGroup
    {
      class Controls
      {
        class Title;
        class DescriptionDeco;
        class Description;
      };
    };
  };
};

class ENH_SubCategoryNoHeader1_Fixed: SubCategoryNoHeader1
{
  attributeLoad = "";
  attributeSave = "";
  h = (2.5 * GRID_H) + CTRL_H(1);
  class Controls: Controls
  {
    class Group: Group
    {
      h = CTRL_H(1);
      class Controls: Controls
      {
        class Title: Title
        {
          h = CTRL_H(1);
        };
        class DescriptionDeco: DescriptionDeco
        {
          h = CTRL_H(1);
        };
        class Description: Description
        {
          h = CTRL_H(1);
        };
      };
    };
  };
};

class ENH_SubCategoryNoHeader2_Fixed: ENH_SubCategoryNoHeader1_Fixed
{
  h = (2.5 * GRID_H) + CTRL_H(2);
  class Controls: Controls
  {
    class Group: Group
    {
      h = CTRL_H(2);
      class Controls: Controls
      {
        class Title: ctrlStatic
        {
          h = CTRL_H(2);
        };
        class DescriptionDeco: DescriptionDeco
        {
          h = CTRL_H(2);
        };
        class Description: Description
        {
          h = CTRL_H(2);
        };
      };
    };
  };
};

class ENH_SubCategoryNoHeader3_Fixed: ENH_SubCategoryNoHeader1_Fixed
{
  h = (2.5 * GRID_H) + CTRL_H(3);
  class Controls: Controls
  {
    class Group: Group
    {
      h = CTRL_H(3);
      class Controls: Controls
      {
        class Title: Title
        {
          h = CTRL_H(3);
        };
        class DescriptionDeco: DescriptionDeco
        {
          h = CTRL_H(3);
        };
        class Description: Description
        {
          h = CTRL_H(3);
        };
      };
    };
  };
};