/*
  Author: Revo

  Description:
  Handles the playlist of 3DENRadio GUI.

  Parameter(s):
  0: STRING - Action to be taken, can be:
    "EXPORT"
    "IMPORT"
    "UPDATE"
    "SAVE"
    "ADDSONG"
    "REMOVESONG"
    "CLEAR"
  1: NUMBER - (Optional, default -1) - Key code used by some functionalities

  Returns:
  -
 */

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

params [["_action","EXPORT",[""]],["_key",-1,[-1]]];
private _display = findDisplay IDD_3DENRADIO;
private _ctrlPL = CTRL(IDC_3DENRADIO_PLAYLIST);
private _ctrlSL = CTRL(IDC_3DENRADIO_SONGLIST);

switch (_action) do
{
  case "UPDATE":
  {
    private _playlist = profileNamespace getVariable ["ENH_3DENRadio_Playlist",[]];
    lbClear _ctrlPL;
    {
      _x params ["_name","_class"];
      private _index = _ctrlPL lbAdd _name;
      _ctrlPL lbSetTooltip [_index,_name];
      _ctrlPL lbSetData [_index,_class];
    } forEach _playlist;

    lbSort _ctrlPL;
  };
  case "ADDSONG":
  {
    if (_key == 57) then
    {
      private _name = _ctrlSL lnbText [(lbCurSel _ctrlSL),0];
      private _class = _ctrlSL lnbData [(lbCurSel _ctrlSL),0];
      private _index = _ctrlPL lbAdd _name;
      _ctrlPL lbSetTooltip [_index,_name];
      _ctrlPL lbSetData [_index,_class];
      "SAVE" call ENH_fnc_3DENRadio_handlePlaylist;
    };
  };
  case "REMOVESONG":
  {
    if (_key == 211) then
    {
      _ctrlPL lbDelete (lbCurSel _ctrlPL);
    };
    "SAVE" call ENH_fnc_3DENRadio_handlePlaylist;
  };
  case "SAVE":
  {
    private _playlist = [];
    for "_i" from 0 to (lbSize _ctrlPL - 1) do
    {
      _playlist pushBack [_ctrlPL lbText _i,_ctrlPL lbData _i];
    };
    profileNamespace setVariable ["ENH_3DENRadio_Playlist",_playlist];
  };
};