/*
  Author: R3vo

  Date: 2019-07-22

  Description:
  Used by ENH_FunctionsViewer GUI. Fill the tree view control.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"
#define LAST_VIEWED (profileNamespace getVariable ["ENH_FunctionsViewer_LastViewed", ""])

disableSerialization;

private _display = uiNamespace getVariable ["ENH_Display_FunctionsViewer", displayNull];
private _configIndex = profileNamespace getVariable ["ENH_FunctionsViewer_ConfigIndex", 0];
private _modeIndex = profileNamespace getVariable ["ENH_FunctionsViewer_ModeIndex", 0];
private _ctrlTV = CTRL(IDC_FUNCTIONSVIEWER_LIST);
private _counter = 0;

tvClear _ctrlTV;

switch (_modeIndex) do
{
  case 0:
  {
    private _addonIndex = 0;
    private _categoryIndex = 0;
    private _fncIndex = 0;
    private _addonOld = [];
    private _addons = [];
    private _categories = [];
    {
      _x params ["_configStr", "_addon", "_category", "_fncShort", "_fncLong", "_path", "_preInit", "_preStart", "_postInit", "_recompile", "_logo"];
      if (_configStr == (["configFile", "missionConfigFile", "campaignConfigFile"] select _configIndex)) then
      {
        if (_addonOld isEqualTo []) then {_addonOld = _addon};
        if (_addon in _addons) then
        {
          _addonIndex = _addons find _addon;
        }
        else
        {
          _addons pushBack _addon;
          _addonIndex = _ctrlTV tvAdd [[], _addon];
          _ctrlTV tvSetPictureRight [[_addonIndex], _logo];
        };

        if !(_addonOld isEqualTo _addon) then
        {
          _categories = [];
          _addonOld = _addon;
          _categories pushBack _category;
          _categoryIndex = _ctrlTV tvAdd [[_addonIndex], _category];
        }
        else
        {
          if (_category in _categories) then
          {
            _categoryIndex = _categories find _category;
          }
          else
          {
            _categories pushBack _category;
            _categoryIndex = _ctrlTV tvAdd [[_addonIndex], _category];
          };
        };
        _fncIndex = _ctrlTV tvAdd [[_addonIndex, _categoryIndex], _fncShort];
        _counter = _counter + 1;
        _ctrlTV tvSetTooltip [[_addonIndex, _categoryIndex, _fncIndex], format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4", _preInit, _preStart, _postInit, _recompile]];//Do not localize
        _ctrlTV tvSetData [[_addonIndex, _categoryIndex, _fncIndex], format ["['%1', '%2']", _fncLong, _path]];
        if (_path isEqualTo LAST_VIEWED) then
        {
          _ctrlTV tvSetCurSel [_addonIndex, _categoryIndex, _fncIndex];//Triggers onTreeSelChanged
        };
      };
      true
    } count ENH_FunctionsData;

    _ctrlTV tvExpand [];
  };
  case 1:
  {
    private _categories = [];
    private _categoryOld = [];
    private _categoryIndex = [];
    {
      _x params ["_configStr", "", "_category", "_fncShort", "_fncLong", "_path", "_preInit", "_preStart", "_postInit", "_recompile", "_logo"];

      if (_configStr == (["configFile", "missionConfigFile", "campaignConfigFile"] select _configIndex)) then
      {
        if (_categoryOld isEqualTo []) then {_categoryOld = _category};
        if (_category in _categories) then
        {
          _categoryIndex = _categories find _category;
        }
        else
        {
          _categories pushBack _category;
          _categoryIndex = _ctrlTV tvAdd [[], _category];
          _ctrlTV tvSetPictureRight [[_categoryIndex], _logo];
        };
        private _fncIndex = _ctrlTV tvAdd [[_categoryIndex], _fncShort];
        _counter = _counter + 1;
        _ctrlTV tvSetTooltip [[_categoryIndex, _fncIndex], format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4", _preInit, _preStart, _postInit, _recompile]];//Do not localize
        _ctrlTV tvSetData [[_categoryIndex, _fncIndex], format ["['%1', '%2']", _fncLong, _path]];
        if (_path isEqualTo LAST_VIEWED) then
        {
          _ctrlTV tvSetCurSel [_categoryIndex, _fncIndex];//Triggers onTreeSelChanged
        };
      };
      true
    } count ENH_FunctionsData;
  };
  case 2:
  {
    {
      _x params ["_configStr", "", "", "_fncShort", "_fncLong", "_path", "_preInit", "_preStart", "_postInit", "_recompile", "_logo"];
      if (_configStr == (["configFile", "missionConfigFile", "campaignConfigFile"] select _configIndex)) then
      {
        private _fncIndex = _ctrlTV tvAdd [[], _fncShort];
        _ctrlTV tvSetPictureRight [[_fncIndex], _logo];
        _ctrlTV tvSetTooltip [[_fncIndex], format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4", _preInit, _preStart, _postInit, _recompile]];//Do not localize
        _ctrlTV tvSetData [[_fncIndex], format ["['%1', '%2']", _fncLong, _path]];
        _counter = _counter + 1;
        if (_path isEqualTo LAST_VIEWED) then
        {
          _ctrlTV tvSetCurSel [_fncIndex];//Triggers onTreeSelChanged
        };
      };
      true
    } count ENH_FunctionsData;
  };
  case 3:
  {
    _ctrlTV tvAdd [[], ".sqf"];
    _ctrlTV tvAdd [[], ".inc"];
    _ctrlTV tvAdd [[], ".hpp"];

    {
      private _addonPath = _x # 0;
      {
        if ("fn_" in _x) then {continue};

        private _extension = _x select [count _x - 4, count _x - 1];
        private _index = [".sqf", ".inc", ".hpp"] find _extension;
        private _fileName = _x splitString "\";
        _fileName = _fileName select (count _fileName - 1);

        private _itemIndex = _ctrlTV tvAdd [[_index], _fileName];
        _ctrlTV tvSetData [[_index, _itemIndex], str [_fileName, _x]];
        _ctrlTV tvSetTooltip [[_index, _itemIndex], _addonPath];

        if (_x isEqualTo LAST_VIEWED) then {_ctrlTV tvSetCurSel [_index, _itemIndex]};
        _counter = _counter + 1;
      } forEach (addonFiles [_addonPath, ".sqf"] + addonFiles [_addonPath, ".inc"] + addonFiles [_addonPath, ".hpp"]);
    } forEach allAddonsInfo;
  };
};

_ctrlTV tvSortAll [[], false];

//Clear search ones and reapply previous value to trigger tree view update
private _ctrlSearch = CTRL(IDC_FUNCTIONSVIEWER_SEARCH);
private _previousSearchText = ctrlText _ctrlSearch;

if (_previousSearchText != "") then
{
  _ctrlSearch ctrlSetText "";

  //Small delay, otherwise tree view is not updated properly
  [_ctrlSearch, _previousSearchText] spawn
  {
    sleep 0.01;
    _this#0 ctrlSetText _this#1;
  };
};

call ENH_fnc_functionsViewer_setUpMenuStrip;

CTRL(IDC_FUNCTIONSVIEWER_NUMFUNCTIONS) ctrlSetText str _counter;