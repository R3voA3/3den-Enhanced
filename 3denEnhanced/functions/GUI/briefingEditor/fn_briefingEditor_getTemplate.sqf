/*
  Author: R3vo

  Description:
  Retrieves the template information and fills the editor with its data.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;

params ["_ctrlLB", "_selectedIndex"];

private _display = ctrlparent _ctrlLB;
private _briefingTitle = _ctrlLB lbText _selectedIndex;
private _briefingText = _ctrlLB lbData _selectedIndex;

CTRL(30) ctrlSetText _briefingTitle;
CTRL(20) ctrlSetText "Diary";//Set it to diary by default
CTRL(10) ctrlSetText _briefingText;