/*
  Author: Revo

  Description:
  Sorts the song list listbox according to input.

  Parameter(s):
  STRING: _sortBy - "TITLE","DURATION","THEME"

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

params [["_sortBy","TITLE",[""]]];
private _display = (findDisplay IDD_3DENRADIO);

switch _sortBy do
{
  case "TITLE":
  {
    CTRL(IDC_3DENRADIO_SONGLIST) lnbSort [0,false];
  };
  case "DURATION":
  {
    CTRL(IDC_3DENRADIO_SONGLIST) lnbSort [1,true];
  };
  case "THEME":
  {
    CTRL(IDC_3DENRADIO_SONGLIST) lnbSort [2,false];
  };
};