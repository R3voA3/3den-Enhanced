/*
  Author: R3vo

  Date: 2019-06-20

  Description:
  Used by ENH_BriefingEditor GUI. Triggers when "Add TAG" button is clicked.

  Parameter(s):
  0: CONTROL - Button control

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;

#define SELECTEDINDEX lbCurSel CTRL(IDC_BRIEFINGEDITOR_TAGS)
#define BRIEFINGTEXT ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT)
#define VALUE1 ctrlText CTRL(IDC_BRIEFINGEDITOR_FIRSTPARAMVALUE)
#define VALUE2 ctrlText CTRL(IDC_BRIEFINGEDITOR_SECONDPARAMVALUE)
#define VALUE3 ctrlText CTRL(IDC_BRIEFINGEDITOR_THIRDPARAMVALUE)
#define COLOURHTML CTRL(IDC_BRIEFINGEDITOR_COLOURS) lbData lbCurSel CTRL(IDC_BRIEFINGEDITOR_COLOURS)
#define FONT CTRL(IDC_BRIEFINGEDITOR_FONTS) lbText lbCurSel CTRL(IDC_BRIEFINGEDITOR_FONTS)
#define MARKER CTRL(IDC_BRIEFINGEDITOR_MARKERS) lbData lbCurSel CTRL(IDC_BRIEFINGEDITOR_MARKERS)

switch (SELECTEDINDEX) do
{
  case 0:
  {
    CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText BRIEFINGTEXT + "<br></br>";
  };
  case 1:
  {
    CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText BRIEFINGTEXT + format ["<marker name='%1'>%2</marker>",MARKER,VALUE1];
  };
  case 2:
  {
    CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText BRIEFINGTEXT + format ["<img image='%1' width='%2' height='%3'/>",VALUE1,parseNumber VALUE2,parseNumber VALUE3];
  };
  case 3:
  {
    CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText BRIEFINGTEXT + format ["<font color='%1' size='%2' face='%3'>%4</font>",COLOURHTML,VALUE1,FONT,VALUE2];
  };
  case 4:
  {
    CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText BRIEFINGTEXT + format ["<execute expression='%1'>%2</execute>",VALUE1,VALUE2];

  };
  case 5:
  {
    CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText BRIEFINGTEXT + format ["<executeClose expression='%1'>%2</executeClose>",VALUE1,VALUE2];
  };
};