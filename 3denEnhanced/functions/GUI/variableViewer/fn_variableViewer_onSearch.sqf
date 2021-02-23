/*
  Author: R3vo

  Date: 2020-02-11

  Description:
  Used by the ENH_VariableViewer GUI. Used to search the listNBox.

  Parameter(s):
  0: CONTROL - Button control

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"
#define TEXTURE_SEARCH_START "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa"
#define TEXTURE_SEARCH_END "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa"

disableSerialization;
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _ctrlLNB = CTRL(IDC_VARIABLEVIEWER_LIST);
private _lbSize = lbSize _ctrlLNB;
private _searchFor = toLower ctrlText CTRL(IDC_VARIABLEVIEWER_SEARCH);

if (isNil "ENH_VariableViewer_SearchStarted") then
{
  if (_searchFor isEqualTo "") exitWith {false};
  private _toDelete = [];
  CTRL(IDC_VARIABLEVIEWER_SEARCHBUTTON) ctrlSetText TEXTURE_SEARCH_END;

  for "_i" from 0 to _lbSize -1 do
  {
    if !(_searchFor in toLower (_ctrlLNB lnbText [_i, 0])) then
    {
      _toDelete pushBack _i;
    };
  };

  //Delete highest index first so indexes won't change after deletion
  reverse _toDelete;
  {
    _ctrlLNB lnbDeleteRow _x;
  } forEach _toDelete;
  ENH_VariableViewer_SearchStarted = true;
  CTRL(IDC_VARIABLEVIEWER_VARIABLECOUNT) ctrlSetText format ["#%1", lnbSize _ctrlLNB # 0];
}
else
{
  CTRL(IDC_VARIABLEVIEWER_SEARCH) ctrlSetText "";
  CTRL(IDC_VARIABLEVIEWER_SEARCHBUTTON) ctrlSetText TEXTURE_SEARCH_START;

  _display call ENH_fnc_variableViewer_fillLNB;
  ENH_VariableViewer_SearchStarted = nil;
};