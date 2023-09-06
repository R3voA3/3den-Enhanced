/*
  Author: R3vo

  Date: 2021-04-05

  Description:
  Fills the tree view control with all objects available in Eden editor.

  Parameter(s):
  0: CONTROL - Tree View

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"
#define CLASSES ("getNumber (_x >> 'scope') == 2 && getNumber (_x >> 'scopeCurator') == 2" configClasses (configFile >> "CfgVehicles"))
disableSerialization;

params ["_ctrlTV"];

private _cat = "";
private _categories = [];
private _color = [];
private _icon = "";
private _indexCat = -1;
private _indexItem = -1;
private _sideID = -1;

CLASSES apply
{
  _sideID = getNumber (_x >> "side");

  if (_sideID == 3 && getText (_x >> "faction") == "default") then {_sideID = 8};
  _color = _sideID call BIS_fnc_sideColor;

  _cat = getText (configFile >> "CfgEditorSubcategories" >> getText (_x >> "editorSubcategory") >> "displayName");

  if (_cat == "") then {_cat = localize "STR_A3_RSCDISPLAYWELCOME_EXPA_PARC_LIST6_TITLE"};
  _indexCat = _categories find _cat;

  if (_indexCat > -1) then
  {
    _indexItem = _ctrlTV tvAdd [[_indexCat], getText (_x >> 'displayName')];
  }
  else
  {
    _indexCat = _ctrlTV tvAdd [[], _cat];
    _indexItem = _ctrlTV tvAdd [[_indexCat], getText (_x >> 'displayName')];
    _categories pushBack _cat;
  };

  _ctrlTV tvSetData [[_indexCat, _indexItem], configName _x];
  _ctrlTV tvSetTooltip [[_indexCat, _indexItem], configName _x];
  _ctrlTV tvSetPictureColor [[_indexCat, _indexItem], _color];
};

_ctrlTV tvSortAll [[], false];

_ctrlTV ctrlAddEventHandler ["treeMouseHold",
{
  params ["_ctrlTV", "_path"];
  private _ctrlPreview = (ctrlparent _ctrlTV displayCtrl IDC_BATCHREPLACE_PREVIEW);
  private _class = _ctrlTV tvData _path;
  private _picture = (getText (configFile >> "CfgVehicles" >> _class >> "editorPreview"));

  _ctrlPreview ctrlShow !(_picture == "");
  _ctrlPreview ctrlSetText _picture;
}];

_ctrlTV ctrlAddEventHandler ["treeMouseMove",
{
  params ["_ctrlTV", "_path"];
  private _ctrlPreview = (ctrlparent _ctrlTV displayCtrl IDC_BATCHREPLACE_PREVIEW);
  private _class = _ctrlTV tvData _path;
  private _picture = getText (configFile >> "CfgVehicles" >> _class >> "editorPreview");

  _ctrlPreview ctrlShow !(_picture == "");
  _ctrlPreview ctrlSetText _picture;
}];