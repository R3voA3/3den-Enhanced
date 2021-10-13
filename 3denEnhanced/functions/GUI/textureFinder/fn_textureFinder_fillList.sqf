/*
  Author: R3vo

  Description:
  Used by the ENH_TexturFinder GUI. Fills the GUI with all found textures. Spawned onLoad of the GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

#define TINY [0, 512]
#define SMALL [513, 1024]
#define MEDIUM [1025, 8192]
#define LARGE [8193, 65536]
#define VERY_LARGE [65537, 10e37]
#define SIZES [TINY, SMALL, MEDIUM, LARGE, VERY_LARGE]

disableSerialization;
private _display = findDisplay IDD_TEXTUREFINDER;
private _ctrlTV = CTRL(IDC_TEXTUREFINDER_TEXTURELIST);
private _ctrlProgText = CTRL(IDC_TEXTUREFINDER_PROGRESSTEXT);
private _indexItem = 0;
private _indexType = 0;
private _pixelCount = 0;
private _indexSize = 0;
private _counter = 0;
private _shortcutText = localize "STR_ENH_FUNCTIONS_FILLTEXTURELB_TOOLTIP";
private _listStatusText = localize "STR_ENH_TEXTUREFINDER_LISTSTATUS";

tvClear _ctrlTV;

_ctrlTV tvAdd [[], "JPG"];
_ctrlTV tvAdd [[], "PAA"];

[0, 1] apply
{
  _ctrlTV tvAdd [[_x], "XS"];
  _ctrlTV tvAdd [[_x], "S"];
  _ctrlTV tvAdd [[_x], "M"];
  _ctrlTV tvAdd [[_x], "L"];
  _ctrlTV tvAdd [[_x], "XL"];
};

(uiNamespace getVariable ["ENH_TextureFinder_TexturesFound", []]) apply
{
  if (isNull _display) exitWith {uiNamespace setVariable ["ENH_TextureFinder_isFillingList", false]};
  _counter = _counter + 1;
  getTextureInfo _x params ["_w", "_h"];
  _pixelCount = _w * _h;
  _indexSize = SIZES findif {_pixelCount >= _x # 0 && _pixelCount <= _x # 1};
  _indexType = parseNumber (".paa" in _x);
  _ctrlProgText ctrlSetStructuredText parseText format [_listStatusText, _counter, count (uiNamespace getVariable "ENH_TextureFinder_TexturesFound")];
  _indexItem = _ctrlTV tvAdd [[_indexType, _indexSize], _x];
  _ctrlTV tvSetPictureRight [[_indexType, _indexSize, _indexItem], _x];//This is soo slow =(
  _ctrlTV tvSetTooltip [[_indexType, _indexSize, _indexItem], format ["%1\n%2 x %3\n%4", _x, _w, _h, _shortcutText]];
};

//Sort only the groups which contain images, if group is empty delete it
{
  if (isNull _display) exitWith {uiNamespace setVariable ["ENH_TextureFinder_isFillingList", false]};
  private _indexType = _forEachIndex;
  //Loop in reverse order to prevent index shift when deleting
  for "_indexSize" from (count SIZES - 1) to 0 step -1 do
  {
    if ((_ctrlTV tvCount [_indexType, _forEachIndex]) == 0) then
    {
      _ctrlTV tvDelete [_indexType, _forEachIndex];
    }
    else
    {
      _ctrlTV tvSortAll [[_indexType, _forEachIndex], false];
    };
  };
} forEach [0, 1];

CTRL(IDC_TEXTUREFINDER_SEARCH) ctrlEnable true;
CTRL(IDC_TEXTUREFINDER_TEXTURELIST) ctrlEnable true;

/* Old way without sizes
#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

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

_ctrlTV tvSortAll [[], false]; */