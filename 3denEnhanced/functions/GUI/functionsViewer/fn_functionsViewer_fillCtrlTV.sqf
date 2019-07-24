/*
   Author: R3vo

   Date: 2019-07-22

   Description:
   Used by Enh_FunctionsViewer GUI. Fill the tree view control.

   Parameter(s):
   0: NUMBER - Can be 0 - Full list with addons and categories
					  1 - Only categories
					  2 - Only functions, search control disabled
   1: NUMBER - Can be 0 - configFile
					  1 - missionConfigFile
					  2 - campaignConfigFile
   2: CONTROL - Tree view control
   3: CONTROL - Edit control (search)
   4: ARRAY - Functions data from Enh_fnc_functionsViewer_returnFunctionsData

   Returns:
   BOOLEAN: true / false
*/

disableSerialization;

params ["_ctrl"];
private _display = ctrlParent _ctrl;
private _configIndex = lbCurSel (_display displayCtrl 1700); 
private _modeIndex = lbCurSel (_display displayCtrl 1800); 
private _ctrlTV = _display displayCtrl 1500;
private _ctrlEdit = _display displayCtrl 1400;
private _ctrlBiki = _display displayCtrl 1900;

profileNamespace setVariable ["Enh_FunctionsViewer_ConfigIndex",_configIndex];
profileNamespace setVariable ["Enh_FunctionsViewer_ModeIndex",_modeIndex];

//Disable biki button if missionConfigFile or campaignConfigFile functions are viewed
switch (_configIndex) do
{
	case 0:
	{
		_ctrlBiki ctrlSetFade 0;
	};
	case 1;
	case 2: 
	{
		_ctrlBiki ctrlSetFade 1;
	};
};
_ctrlBiki ctrlCommit 0;

tvClear _ctrlTV;

switch (_modeIndex) do
{
	case 0:
	{
		private _rootIndex = _ctrlTV tvAdd [[],["configFile","missionConfigFile","campaignConfigFile"] select _configIndex];
		private _addons = [];
		private _categoryIndex = 0;
		private _fncIndex = 0;
		private _addonOld = [];
		private _categories = [];
		{
			_x params ["_configStr","_addon","_tag","_category","_fncShort","_fncLong","_path","_preInit","_preStart","_postInit","_recompile"];
			if (_configStr == (["configFile","missionConfigFile","campaignConfigFile"] select _configIndex)) then
			{
				private _addonIndex = 0;
				if (_addonOld isEqualTo []) then {_addonOld = _addon};
				_addonIndex = if (_addon in _addons) then
				{
					_addons find _addon;
				}
				else
				{
					_addons pushBack _addon;
					_ctrlTV tvAdd [[_rootIndex],_addon];
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
				_ctrlTV tvSetTooltip [[_rootIndex,_addonIndex,_categoryIndex,_fncIndex],format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4",_preInit,_preStart,_postInit,_recompile]];//Do not localize
				_ctrlTV tvSetData [[_rootIndex,_addonIndex,_categoryIndex,_fncIndex],format ["['%1','%2']",_fncLong,_path]];
			};
		} forEach Enh_FunctionsData;

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
		_ctrlEdit ctrlEnable true;
	};
	case 1:
	{
		private _categories = [];
		private _categoryOld = [];
		{
			_x params ["_configStr","_addon","_tag","_category","_fncShort","_fncLong","_path","_preInit","_preStart","_postInit","_recompile"];

			if (_configStr == (["configFile","missionConfigFile","campaignConfigFile"] select _configIndex)) then 
			{
				if (_categoryOld isEqualTo []) then {_categoryOld = _category};
				private _categoryIndex = if (_category in _categories) then
				{
					_categories find _category;
				}
				else
				{
					_categories pushBack _category;
					_ctrlTV tvAdd [[],_category];
				};
				private _fncIndex = _ctrlTV tvAdd [[_categoryIndex],_fncShort];

				_ctrlTV tvSetTooltip [[_categoryIndex,_fncIndex],format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4",_preInit,_preStart,_postInit,_recompile]];//Do not localize
				_ctrlTV tvSetData [[_categoryIndex,_fncIndex],format ["['%1','%2']",_fncLong,_path]];
				_ctrlTV tvSort [[_categoryIndex],false];
			};
		} forEach Enh_FunctionsData;
		_ctrlTV tvSort [[],false];
		_ctrlEdit ctrlEnable true;
	};
	case 2:
	{
		{
			_x params ["_configStr","_addon","_tag","_category","_fncShort","_fncLong","_path","_preInit","_preStart","_postInit","_recompile"];
			if (_configStr == (["configFile","missionConfigFile","campaignConfigFile"] select _configIndex)) then 
			{
				private _fncIndex = _ctrlTV tvAdd [[],_fncShort];
				_ctrlTV tvSetTooltip [[_fncIndex],format ["PreInit:%1 PreStart:%2 PostInit:%3 Recompile:%4",_preInit,_preStart,_postInit,_recompile]];//Do not localize
				_ctrlTV tvSetData [[_fncIndex],format ["['%1','%2']",_fncLong,_path]];
			};
		} forEach Enh_FunctionsData;
		_ctrlTV tvSort [[],false];
		_ctrlEdit ctrlEnable false;
	};
};

//Reopen last viewed function and select it
private _lastViewed = uiNamespace getVariable ["Enh_FunctionsViewer_LastViewed",[]];

if !(_lastViewed isEqualTo []) then 
{
	_ctrlTV tvSetCurSel _lastViewed;
	[_ctrlTV,_lastViewed] call Enh_fnc_functionsViewer_onTreeSelChanged;
};

true