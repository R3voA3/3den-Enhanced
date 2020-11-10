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

disableSerialization;

params ["_ctrl"];
private _display = ctrlParent _ctrl;
private _configIndex = lbCurSel (_display displayCtrl 1700);
private _modeIndex = lbCurSel (_display displayCtrl 1800);
private _ctrlTV = _display displayCtrl 1500;
private _ctrlEdit = _display displayCtrl 1400;
private _ctrlBiki = _display displayCtrl 1900;
private _counter = 0;

(_display displayCtrl 1700) ctrlEnable true;
(_display displayCtrl 1700) ctrlSetFade 0;
(_display displayCtrl 1700) ctrlCommit 0;

if (getNumber (missionConfigfile >> "allowFunctionsRecompile") == 0) then
{
  (_display displayCtrl 1600) ctrlEnable false;
  (_display displayCtrl 1601) ctrlEnable false;
}
else
{
  (_display displayCtrl 1600) ctrlEnable true;
  (_display displayCtrl 1601) ctrlEnable true;
};

profileNamespace setVariable ["ENH_FunctionsViewer_ConfigIndex",_configIndex];
profileNamespace setVariable ["ENH_FunctionsViewer_ModeIndex",_modeIndex];
private _lastViewed = uiNamespace getVariable ["ENH_FunctionsViewer_LastViewed",[]];


private _fnc_addCustomFiles =
{
  (_display displayCtrl 1700) ctrlEnable false;
  (_display displayCtrl 1700) ctrlSetFade 0.5;
  (_display displayCtrl 1700) ctrlCommit 0;
  (_display displayCtrl 1600) ctrlEnable false;
  (_display displayCtrl 1601) ctrlEnable false;
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
      };
    } forEach  addonFiles [_addonPath,_extension];
  } forEach allAddonsInfo;
  _ctrlTV tvSort [[],false];
};

tvClear _ctrlTV;

switch (_modeIndex) do
{
  case 0:
  {
    private _rootIndex = _ctrlTV tvAdd [[],["configFile","missionConfigFile","campaignConfigFile"] select _configIndex];
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
          _addonIndex = _ctrlTV tvAdd [[_rootIndex],_addon];
          //_ctrlTV tvSetPictureRight [[_rootIndex,_addonIndex],_logo]; Adding icons hits the performance quite hard
        };

        if !(_addonOld isEqualTo _addon) then
        {
          _categories = [];
          _addonOld = _addon;
          _categories pushBack _category;
          _categoryIndex = _ctrlTV tvAdd [[_rootIndex,_addonIndex],_category];
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
            _categoryIndex = _ctrlTV tvAdd [[_rootIndex,_addonIndex],_category];
          };
        };
        _fncIndex = _ctrlTV tvAdd [[_rootIndex,_addonIndex,_categoryIndex],_fncShort];
        _counter = _counter + 1;
        private _fullPath = [_rootIndex,_addonIndex,_categoryIndex,_fncIndex];
        _ctrlTV tvSetTooltip [_fullPath,format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4",_preInit,_preStart,_postInit,_recompile]];//Do not localize
        _ctrlTV tvSetData [_fullPath,format ["['%1','%2']",_fncLong,_path]];
        if (_ctrlTV tvText _fullPath isEqualTo _lastViewed) then
        {
          _ctrlTV tvSetCurSel _fullPath;
          [_ctrlTV,_fullPath] call ENH_fnc_functionsViewer_onTreeSelChanged;
        };
      };
      true
    } count ENH_FunctionsData;

    //Sort
    for "_i" from 0 to ((_ctrlTV tvCount []) - 1) do
    {
      _ctrlTV tvSort [[_i],false];
      for "_j" from 0 to ((_ctrlTV tvCount [_i]) - 1) do
      {
        _ctrlTV tvSort [[_i,_j],false];
        for "_k" from 0 to ((_ctrlTV tvCount [_i,_j]) - 1) do
        {
          _ctrlTV tvSort [[_i,_j,_k],false];
        };
      };
    };
    _ctrlTV tvExpand [0];
    _ctrlEdit ctrlEnable true;
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
          //_ctrlTV tvSetPictureRight [[_categoryIndex],_logo]; Adding icons hits the performance quite hard
        };
        private _fncIndex = _ctrlTV tvAdd [[_categoryIndex],_fncShort];
        _counter = _counter + 1;
        private _fullPath = [_categoryIndex,_fncIndex];
        _ctrlTV tvSetTooltip [_fullPath,format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4",_preInit,_preStart,_postInit,_recompile]];//Do not localize
        _ctrlTV tvSetData [_fullPath,format ["['%1','%2']",_fncLong,_path]];
        if (_ctrlTV tvText _fullPath isEqualTo _lastViewed) then
        {
          _ctrlTV tvSetCurSel _fullPath;
          [_ctrlTV,_fullPath] call ENH_fnc_functionsViewer_onTreeSelChanged;
        };
        _ctrlTV tvSort [[_categoryIndex],false];
      };
      true
    } count ENH_FunctionsData;
    _ctrlTV tvSort [[],false];
    _ctrlEdit ctrlEnable true;
  };
  case 2:
  {
    {
      _x params ["_configStr","","","_fncShort","_fncLong","_path","_preInit","_preStart","_postInit","_recompile","_logo"];
      if (_configStr == (["configFile","missionConfigFile","campaignConfigFile"] select _configIndex)) then
      {
        private _fncIndex = _ctrlTV tvAdd [[],_fncShort];
        _counter = _counter + 1;
        _ctrlTV tvSetTooltip [[_fncIndex],format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4",_preInit,_preStart,_postInit,_recompile]];//Do not localize
        _ctrlTV tvSetData [[_fncIndex],format ["['%1','%2']",_fncLong,_path]];
        //_ctrlTV tvSetPictureRight [[_fncIndex],_logo]; Adding icons hits the performance quite hard
        if (_ctrlTV tvText [_fncIndex] isEqualTo _lastViewed) then
        {
          _ctrlTV tvSetCurSel [_fncIndex];
          [_ctrlTV,[_fncIndex]] call ENH_fnc_functionsViewer_onTreeSelChanged;
        };
      };
      true
    } count ENH_FunctionsData;
    _ctrlTV tvSort [[],false];
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

(_display displayCtrl 1405) ctrlSetText str _counter;