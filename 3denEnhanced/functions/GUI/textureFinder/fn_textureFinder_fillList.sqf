/*
  Author: Revo

  Description:
  Used by the ENH_TexturFinder GUI. Fills the GUI with all found textures.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

private _display = findDisplay IDD_TEXTUREFINDER;
private _ctrlTV = CTRL(IDC_TEXTUREFINDER_TEXTURELIST);
private _ctrlProgress = CTRL(IDC_TEXTUREFINDER_PROGRESS);
private _tooltip = localize "STR_ENH_FUNCTIONS_FILLTEXTURELB_TOOLTIP";
private _textureCount = count (uiNamespace getVariable  "ENH_TextureFinder_TexturesFound");
private _index = 0;
private _counter = 0;

tvClear _ctrlTV;
_ctrlTV tvAdd [[],"PAA"];
_ctrlTV tvAdd [[],"JPG"];

private _fnc_addToList =
{
  params ["_texturePath","_indexType"];
  _index = _ctrlTV tvAdd [[_indexType],_texturePath];
  _ctrlTV tvSetPictureRight [[_indexType,_index],_texturePath];
  _ctrlTV tvSetTooltip [[_indexType,_index],_tooltip];
  _counter = _counter + 1;
};

{
  if (".paa" in _x) then
  {
    [_x,0] call _fnc_addToList;
  }
  else
  {
    [_x,1] call _fnc_addToList;
  };
  _ctrlProgress progressSetPosition linearConversion [0,_textureCount,_counter,0,1];
} forEach (uiNamespace getVariable ["ENH_TextureFinder_TexturesFound",[]]);

_ctrlTV tvSort [[0],false];
_ctrlTV tvSort [[1],false];