/*
  Author: R3vo

  Date: 2021-06-18

  Description:
  Used by ENH_BriefingEditor GUI. Converts text from edit box and updates structured text control.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

private _display = uiNamespace getVariable ["ENH_BriefingEditor_Display", displayNull];
private _text = ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) splitString "";
private _stringFinal = [];
private _highlight = false;
private _h = (ctrlTextHeight CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT)) + 5 * GRID_H max 60 * GRID_H;

{
  if (_x == "<") then {_highlight = true};

  if (_highlight) then
  {
    _text = text _x setAttributes ["color", "#2A8DFF"];
    _stringFinal pushBack _text;
  }
  else
  {
    _stringFinal pushBack _x;
  };
  if (_x == ">") then {_highlight = false};
} forEach _text;

CTRL(IDC_BRIEFINGEDITOR_HIGHLIGHT) ctrlSetStructuredText composeText _stringFinal;
CTRL(IDC_BRIEFINGEDITOR_HIGHLIGHT) ctrlSetPositionH _h;
CTRL(IDC_BRIEFINGEDITOR_HIGHLIGHT) ctrlCommit 0;

CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetPositionH _h;
CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlCommit 0;