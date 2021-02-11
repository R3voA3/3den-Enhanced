/*
  Author: R3vo

  Date: 2019-06-05

  Description:
  Is called by Eden event handler onSelectionChange. Content of this function may be altered by ENH_Config.hpp.

  Parameter(s):
  -

  Returns:
  -
*/

#if __has_include("\userconfig\ENH_Config.hpp")
#include "\userconfig\ENH_Config.hpp"
#endif

#ifndef ENH_HIDE_INTERFACE
call ENH_fnc_statusbar_entityCounter;
#endif