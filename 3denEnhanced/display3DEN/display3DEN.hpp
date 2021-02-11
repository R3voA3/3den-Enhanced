class Display3DEN
{
  class ContextMenu: ctrlMenu
  {
    class Items
    {
      #include "contextMenu.hpp"
    };
  };
  class Controls
  {
    #ifndef ENH_HIDE_INTERFACE
      #include "statusbar.hpp"
    #endif
    class MenuStrip: ctrlMenuStrip
    {
      class Items
      {
        items[] += {"ENH_About"};//new main category
        #include "menuStrip_about.hpp"
        #include "menuStrip_tools.hpp"
        #include "menuStrip_help.hpp"
      };
    };
  };
};