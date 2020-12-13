/*
  Author: R3vo

  Date: 2019-07-22

  Description:
  Used by ENH_FunctionsViewer GUI. Fill the tree view control.

  Parameter(s):
  0: CONTROL - Any control used to get the display

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"
#define LAST_VIEWED (profileNamespace getVariable ["ENH_FunctionsViewer_LastViewed",""])

disableSerialization;
params ["_ctrl"];

private _display = ctrlParent _ctrl;
private _configIndex = lbCurSel CTRL(IDC_FUNCTIONSVIEWER_FILTERCONFIG);
private _modeIndex = lbCurSel CTRL(IDC_FUNCTIONSVIEWER_FILTERMODE);
private _ctrlTV = CTRL(IDC_FUNCTIONSVIEWER_LIST);
private _counter = 0;

//Disable BIKI Button
if (_configIndex > 0 || _modeIndex > 2) then {CTRL(IDC_FUNCTIONSVIEWER_BIKI) ctrlEnable true};

//Setup buttons according to mode and config index
CTRL(IDC_FUNCTIONSVIEWER_FILTERCONFIG) ctrlEnable true;
CTRL(IDC_FUNCTIONSVIEWER_FILTERCONFIG) ctrlSetFade 0;
CTRL(IDC_FUNCTIONSVIEWER_FILTERCONFIG) ctrlCommit 0;
CTRL(IDC_FUNCTIONSVIEWER_SEARCH) ctrlSetText "";

if (getNumber (missionConfigfile >> "allowFunctionsRecompile") == 0) then
{
  CTRL(IDC_FUNCTIONSVIEWER_RECOMPILESELECTED) ctrlEnable false;
  CTRL(IDC_FUNCTIONSVIEWER_RECOMPILEALL) ctrlEnable false;
}
else
{
  CTRL(IDC_FUNCTIONSVIEWER_RECOMPILESELECTED) ctrlEnable true;
  CTRL(IDC_FUNCTIONSVIEWER_RECOMPILEALL) ctrlEnable true;
};

profileNamespace setVariable ["ENH_FunctionsViewer_ConfigIndex",_configIndex];
profileNamespace setVariable ["ENH_FunctionsViewer_ModeIndex",_modeIndex];
profileNamespace setVariable ["ENH_FunctionsViewer_LoadFileIndex",lbCurSel CTRL(2200)];

private _fnc_addCustomFiles =
{
  CTRL(IDC_FUNCTIONSVIEWER_FILTERCONFIG) ctrlEnable false;
  CTRL(IDC_FUNCTIONSVIEWER_FILTERCONFIG) ctrlSetFade 0.5;
  CTRL(IDC_FUNCTIONSVIEWER_FILTERCONFIG) ctrlCommit 0;
  CTRL(IDC_FUNCTIONSVIEWER_RECOMPILESELECTED) ctrlEnable false;
  CTRL(IDC_FUNCTIONSVIEWER_RECOMPILEALL) ctrlEnable false;
  params ["_ctrlTV","_extension"];
  {
    private _addonPath = _x # 0;
    {
      if !("fn_" in _x) then
      {
        private _fileName = _x splitString "\";
        _fileName = _fileName select (count _fileName - 1);
        private _index = _ctrlTV tvAdd [[],_fileName];
        _counter = _counter + 1;
        _ctrlTV tvSetData [[_index],str [_fileName,_x]];
        _ctrlTV tvSetTooltip [[_index],_addonPath];
        if (_x isEqualTo LAST_VIEWED) then {_ctrlTV tvSetCurSel [_index]};
      };
    } forEach addonFiles [_addonPath,_extension];
  } forEach allAddonsInfo;
};

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
      _x params ["_configStr","_addon","_category","_fncShort","_fncLong","_path","_preInit","_preStart","_postInit","_recompile","_logo"];
      if (_configStr == (["configFile","missionConfigFile","campaignConfigFile"] select _configIndex)) then
      {
        if (_addonOld isEqualTo []) then {_addonOld = _addon};
        if (_addon in _addons) then
        {
          _addonIndex = _addons find _addon;
        }
        else
        {
          _addons pushBack _addon;
          _addonIndex = _ctrlTV tvAdd [[],_addon];
          _ctrlTV tvSetPictureRight [[_addonIndex],_logo];
        };

        if !(_addonOld isEqualTo _addon) then
        {
          _categories = [];
          _addonOld = _addon;
          _categories pushBack _category;
          _categoryIndex = _ctrlTV tvAdd [[_addonIndex],_category];
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
            _categoryIndex = _ctrlTV tvAdd [[_addonIndex],_category];
          };
        };
        _fncIndex = _ctrlTV tvAdd [[_addonIndex,_categoryIndex],_fncShort];
        _counter = _counter + 1;
        _ctrlTV tvSetTooltip [[_addonIndex,_categoryIndex,_fncIndex],format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4",_preInit,_preStart,_postInit,_recompile]];//Do not localize
        _ctrlTV tvSetData [[_addonIndex,_categoryIndex,_fncIndex],format ["['%1','%2']",_fncLong,_path]];
        if (_path isEqualTo LAST_VIEWED) then
        {
          _ctrlTV tvSetCurSel [_addonIndex,_categoryIndex,_fncIndex];//Triggers onTreeSelChanged
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
      _x params ["_configStr","","_category","_fncShort","_fncLong","_path","_preInit","_preStart","_postInit","_recompile","_logo"];

      if (_configStr == (["configFile","missionConfigFile","campaignConfigFile"] select _configIndex)) then
      {
        if (_categoryOld isEqualTo []) then {_categoryOld = _category};
        if (_category in _categories) then
        {
          _categoryIndex = _categories find _category;
        }
        else
        {
          _categories pushBack _category;
          _categoryIndex = _ctrlTV tvAdd [[],_category];
          _ctrlTV tvSetPictureRight [[_categoryIndex],_logo];
        };
        private _fncIndex = _ctrlTV tvAdd [[_categoryIndex],_fncShort];
        _counter = _counter + 1;
        _ctrlTV tvSetTooltip [[_categoryIndex,_fncIndex],format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4",_preInit,_preStart,_postInit,_recompile]];//Do not localize
        _ctrlTV tvSetData [[_categoryIndex,_fncIndex],format ["['%1','%2']",_fncLong,_path]];
        if (_path isEqualTo LAST_VIEWED) then
        {
          _ctrlTV tvSetCurSel [_categoryIndex,_fncIndex];//Triggers onTreeSelChanged
        };
      };
      true
    } count ENH_FunctionsData;
  };
  case 2:
  {
    {
      _x params ["_configStr","","","_fncShort","_fncLong","_path","_preInit","_preStart","_postInit","_recompile","_logo"];
      if (_configStr == (["configFile","missionConfigFile","campaignConfigFile"] select _configIndex)) then
      {
        private _fncIndex = _ctrlTV tvAdd [[],_fncShort];
        _ctrlTV tvSetPictureRight [[_fncIndex],_logo];
        _ctrlTV tvSetTooltip [[_fncIndex],format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4",_preInit,_preStart,_postInit,_recompile]];//Do not localize
        _ctrlTV tvSetData [[_fncIndex],format ["['%1','%2']",_fncLong,_path]];
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
    [_ctrlTV,".sqf"] call _fnc_addCustomFiles;
  };
  case 4:
  {
    [_ctrlTV,".inc"] call _fnc_addCustomFiles;
  };
  case 5:
  {
    [_ctrlTV,".hpp"] call _fnc_addCustomFiles;
  };
};

_ctrlTV tvSortAll [[],false];

CTRL(IDC_FUNCTIONSVIEWER_NUMFUNCTIONS) ctrlSetText str _counter;