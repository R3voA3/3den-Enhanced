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

private _display = findDisplay 140000;
private _ctrlTV = CTRL(1500);
private _ctrlProgress = CTRL(1800);
private _tooltip = localize "STR_ENH_FUNCTIONS_FILLTEXTURELB_TOOLTIP";
private _textureCount = count (uiNamespace getVariable  "ENH_TextureFinder_TexturesFound");
private _index = 0;
private _counter = 0;

//Disable update button and search
CTRL(1900) ctrlEnable false;
CTRL(1600) ctrlEnable false;

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

//Re-enable after list was filled
CTRL(1900) ctrlEnable true;
CTRL(1600) ctrlEnable true;