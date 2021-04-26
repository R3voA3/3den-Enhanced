/*
  Author: R3vo

  Description:
  Used by the ENH_TexturFinder GUI. Fills the GUI with all found textures. Spawned onLoad of the GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
private _display = findDisplay IDD_TEXTUREFINDER;
private _ctrlTV = CTRL(IDC_TEXTUREFINDER_TEXTURELIST);
private _tooltip = localize "STR_ENH_FUNCTIONS_FILLTEXTURELB_TOOLTIP";
private _index = 0;
private _indexType = 0;

_ctrlTV tvAdd [[], "PAA"];
_ctrlTV tvAdd [[], "JPG"];

(uiNamespace getVariable ["ENH_TextureFinder_TexturesFound", []]) apply
{
  _indexType = parseNumber (".jpg" in _x);
  _index = _ctrlTV tvAdd [[_indexType], _x];
  _ctrlTV tvSetPictureRight [[_indexType, _index], _x];//This is soo slow =(
  _ctrlTV tvSetTooltip [[_indexType, _index], _tooltip];
};

_ctrlTV tvSortAll [[], false];