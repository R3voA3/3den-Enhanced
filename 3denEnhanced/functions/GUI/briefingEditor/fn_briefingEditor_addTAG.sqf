/*
  Author: R3vo

  Date: 2019-06-20

  Description:
  Used by ENH_BriefingEditor GUI. Triggers when "Add TAG" button is clicked.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;

private _display = uiNamespace getVariable ["ENH_BriefingEditor_Display", displayNull];

#define BRIEFINGTEXT ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT)
#define VALUE1 ctrlText CTRL(IDC_BRIEFINGEDITOR_FIRSTPARAMVALUE)
#define VALUE2 ctrlText CTRL(IDC_BRIEFINGEDITOR_SECONDPARAMVALUE)
#define VALUE3 ctrlText CTRL(IDC_BRIEFINGEDITOR_THIRDPARAMVALUE)
#define COLOURHTML CTRL(IDC_BRIEFINGEDITOR_COLOURS) lbData lbCurSel CTRL(IDC_BRIEFINGEDITOR_COLOURS)
#define FONT CTRL(IDC_BRIEFINGEDITOR_FONTS) lbText lbCurSel CTRL(IDC_BRIEFINGEDITOR_FONTS)
#define MARKER CTRL(IDC_BRIEFINGEDITOR_MARKERS) lbData lbCurSel CTRL(IDC_BRIEFINGEDITOR_MARKERS)

private _chars = BRIEFINGTEXT splitString "";
private _TAGIndex = lbCurSel CTRL(IDC_BRIEFINGEDITOR_TAGS);
private _textNew = "";
ctrlTextSelection CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) params ["_start", "_length", "_text"];

//Exit if text is empty and tag is not image
if (_text isEqualTo "" && _TAGIndex != 0) exitWith {};

switch (_TAGIndex) do
{
  case 0:
  {
    _textNew = "<br/>";
  };
  case 1:
  {
    _textNew = format ["<marker name='%1'>%2</marker>", MARKER, _text];
  };
  case 2:
  {
    _textNew = format ["<img image='%1' width='%2' height='%3'/>", VALUE1, parseNumber VALUE2, parseNumber VALUE3];
  };
  case 3:
  {
    _textNew = format ["<font color='%1' size='%2' face='%3'>%4</font>", COLOURHTML, VALUE1, FONT, _text];
  };
  case 4:
  {
    _textNew = format ["<execute expression='%1'>%2</execute>", VALUE1, _text];
  };
  case 5:
  {
    _textNew = format ["<executeClose expression='%1'>%2</executeClose>", VALUE1, _text];
  };
};

// Handle the case when selection was made from right to left
if (_length < 0) then
{
  _start = _start - abs (_length);
};

private _end = _start + abs (_length) - 1;

//Insert new text right behind selection
_chars insert [_end + 1, [_textNew]];

//Delete selected text
_chars deleteRange [_start, count _text];

CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText (_chars joinString "");
CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetTextSelection [_start, count _textNew];
ctrlSetFocus CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT);
call ENH_fnc_briefingEditor_htmlHighlight;