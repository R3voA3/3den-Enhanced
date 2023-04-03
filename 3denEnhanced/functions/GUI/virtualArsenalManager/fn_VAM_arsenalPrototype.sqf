/*
  Author: linkion and R3vo

  Description:
  WIP

  Parameter(s):
  0: DISPLAY - WIP

  Returns:
 -
*/

_display = (if (is3DEN) then {findDisplay 313} else {[] call BIS_fnc_displayMission}) createDisplay "RscDisplayEmpty";

_edit = _display ctrlCreate ["RscEdit", 645];
_edit ctrlSetPosition [0,0,1,0.04];
_edit ctrlSetBackgroundColor [0,0,0,1];
_edit ctrlCommit 0;

_tv = _display ctrlCreate ["RscTreeSearch", -1];
_tv ctrlSetFont "EtelkaMonospacePro";
_tv ctrlSetFontHeight 0.03;
_tv ctrlSetPosition [0,0.06,1,0.94];
_tv ctrlSetBackgroundColor [0,0,0,1];
_tv ctrlCommit 0;

if (uiNamespace getVariable ["ENH_VIM_allAddons", []] isEqualTo []) then { call ENH_fnc_getAllItems};

private _allAddons = ((uiNamespace getVariable ["ENH_VIM_allAddons", []]) - [["","Unchanged",""],["","",""]]) + [["", "Arma 3", ""]];

// Prefill tree view with layout
{
	_x params [["_addonClass", ""], ["_addonName", ""], ["_addonIcon", ""]];

	private _indexAddon = _tv tvAdd [[], _addonName];
	_tv tvSetPicture [[_indexAddon], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
	{
		private _indexCategory = _tv tvAdd [[_indexAddon], _x];
		_tv tvSetPicture [[_indexAddon, _indexCategory], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
	} foreach (uiNamespace getVariable ["ENH_VIM_types", []]);
} foreach _allAddons;

private _allAddonClasses = [];

_allAddons apply
{
	_allAddonClasses pushBack (_x # 0);
};

// Fill tree view with equipment
{
		_y params ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort", "_class"];

		private _indexAddon = _allAddonClasses find _addonClass;
		private _indexCategory = (uiNamespace getVariable ["ENH_VIM_types", []]) find _category;

		if (_indexCategory < 0) then
		{
			_indexCategory = (uiNamespace getVariable ["ENH_VIM_types", []]) find _specificType;
		};

		private _indexEquipment = _tv tvAdd [[_indexAddon, _indexCategory], _displayName];

		_tv tvSetData [[_indexAddon, _indexCategory, _indexEquipment], _class];
		_tv tvSetPicture [[_indexAddon, _indexCategory, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
		_tv tvSetPictureRight [[_indexAddon, _indexCategory, _indexEquipment], _picture];
    _tv tvSetTooltip [[_indexAddon, _indexCategory, _indexEquipment], _descriptionShort];


} foreach (uiNamespace getVariable ["ENH_VIM_itemsHashMap", []]);

// Remove empty nodes
private _fnc_removeEmptyNodes =
{
	params
	[
		["_path", []],
		["_maxLevel", -1]
	];

	// Exit if path is deeper than wanted level
	if (count _path == _maxLevel && _maxLevel > -1) exitWith {};

	for "_i" from (_tv tvCount _path) to 0 step -1 do
	{
		private _newPath = _path + [_i];

		if (_tv tvCount _newPath == 0) then
		{
			_tv tvDelete _newPath;
		}
		else
		{
			[_newPath, _maxLevel] call _fnc_removeEmptyNodes;
		};
	};
};

[[], 2] call _fnc_removeEmptyNodes;

// Sort TV
_tv tvSortAll [];

_tv ctrlAddEventHandler ["TreeSelChanged",
{
  params["_ctrl", "_path"];

  // check if it's a single entry or a folder
  if ((_ctrl tvCount _path) == 0) then
  {

    if ((_ctrl tvValue _path) == 0) then
    {
      [_ctrl, 1] call ENH_fnc_virtualArsenalManager_switchNodeState;
    }
    else
    {
      [_ctrl, 0] call ENH_fnc_virtualArsenalManager_switchNodeState;
    }
  }
  else
  {
    private _mouseX = getMousePosition select 0;

    // if clicked on check box
    if (_mouseX < 0.05 + 0.025 * (count _path - 1)) then {

			if ((_ctrl tvValue _path) == 0) then {
				[_ctrl, 1] call ENH_fnc_virtualArsenalManager_switchNodeState;
			} else {
				[_ctrl, 0] call ENH_fnc_virtualArsenalManager_switchNodeState;
			};
    };
  };
}];

// Check and uncheck nodes
_tv ctrlAddEventHandler ["keyDown",
{
	params ["_ctrlTV", "_key", "_shift", "_ctrl", "_alt"];

	if (_key == 14) then
	{
		[_ctrlTV, 0] call ENH_fnc_virtualArsenalManager_switchNodeState;
	};
	if (_key in [28, 156]) then
	{
		[_ctrlTV, 1] call ENH_fnc_virtualArsenalManager_switchNodeState;
	};
	if (_key == 59) then
	{
		call ENH_fnc_virtualArsenalManager_exportToSQF;
	};
}];

ENH_fnc_virtualArsenalManager_switchNodeState =
{
	params ["_ctrlTV", "_add"];

	private _selectedPath = tvCurSel _ctrlTV;
	private _picture = ["\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa", "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa"] select _add;

	_ctrlTV tvSetPicture [_selectedPath, _picture];
	_ctrlTV tvSetValue [_selectedPath, _add];

	private _fnc_traverseChildren =
	{
		params ["_path"];

		for "_i" from (_ctrlTV tvCount _path) to 0 step -1 do
		{
			private _newPath = _path + [_i];

			_ctrlTV tvSetPicture [_newPath, _picture];
      _ctrlTV tvSetValue [_newPath, _add];

			if (_ctrlTV tvCount _newPath > 0) then
			{
				[_newPath] call _fnc_traverseChildren;
			};
		};
	};

	private _fnc_traverseParents =
	{
		params ["_path"];

		// traversing backwards from farthest child to first parent
		// to make sure to check uncheck when all children are checked
		for "_i" from 1 to (count _path - 1) step 1 do {
			private _partialCheckedPic = "\a3\ui_f\data\gui\rsccommon\rsccheckbox\checkbox_checked_ca.paa";
			private _newPath = +_path;
			_newPath deleteRange [count _path - _i, count _path];

			_ctrlTV tvSetPicture [_newPath, _partialCheckedPic];
			_ctrlTV tvSetValue [_newPath, 2];

			// check if all children are checked
			private _tempBool = true;
			for "_i" from (_ctrlTV tvCount _newPath) to 0 step -1 do
			{
				private _newPath = _newPath + [_i];
				if (_ctrlTV tvValue _newPath == 0 || _ctrlTV tvValue _newPath == 2) exitWith {
					_tempBool = false;
				};
			};
			// make parent checked
			if (_tempBool) then {
				private _checkedPic = "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa";

				_ctrlTV tvSetPicture [_newPath, _checkedPic];
				_ctrlTV tvSetValue [_newPath, 1];
			};

			// check if all children are unchecked
			private _tempBool = true;
			for "_i" from (_ctrlTV tvCount _newPath) to 0 step -1 do
			{
				private _newPath = _newPath + [_i];
				if (_ctrlTV tvValue _newPath == 1 || _ctrlTV tvValue _newPath == 2) exitWith {
					_tempBool = false;
				};
			};
			// make parent unchecked
			if (_tempBool) then {
				private _uncheckedPic = "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa";

				_ctrlTV tvSetPicture [_newPath, _uncheckedPic];
				_ctrlTV tvSetValue [_newPath, 0];
			};
		};
	};

	[_selectedPath] call _fnc_traverseChildren;
	[_selectedPath] call _fnc_traverseParents;
};

ENH_fnc_virtualArsenalManager_exportToSQF =
{
	private _data =  //[<items>, <weapons>, <magazines>, <backpacks>]
	[
		[],
		[],
		[],
		[]
	];

	private _fnc_traverseChildren =
	{
		params ["_path"];

		for "_i" from 0 to (_ctrlTV tvCount _path) do
		{
			private _newPath = _path + [_i];

			if (count _newPath == 3) then
			{
				if (_ctrlTV tvValue _newPath > 0) then
				{
					private _category = (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap]) get (_ctrlTV tvData _newPath) select 4;
					diag_log _category;
				};
			};

			if (_ctrlTV tvCount _newPath > 0) then
			{
				[_newPath] call _fnc_traverseChildren;
			};
		};
	};

	[[]] call _fnc_traverseChildren;
};

[[], 2] call _fnc_removeEmptyNodes;