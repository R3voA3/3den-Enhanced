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

disableSerialization;

params ["_ctrlTV"];
private _categories = [];
private _indexCat = -1;
private _indexItem = -1;
private _cat = "";

{
  _cat = getText (_x >> "editorSubcategory");
  _cat = getText (configFile >> "CfgEditorSubcategories" >> _cat >> "displayName");
  if (_cat == "") then {_cat = "Misc."};
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

  //Add pictures in schedules environment to not slow down the the whole script. Adding images is sooo slow.
  [_ctrlTV, _indexCat, _indexItem, _x] spawn
  {
    (_this select 0) tvSetPictureRight [[_this select 1, _this select 2], getText ((_this select 3) >> "editorPreview")];
  };
} forEach ("getNumber (_x >> 'scope') == 2 && getText (_x >> 'displayName') != '' && getNumber (_x >> 'scopeCurator') == 2" configClasses (configFile >> "CfgVehicles"));