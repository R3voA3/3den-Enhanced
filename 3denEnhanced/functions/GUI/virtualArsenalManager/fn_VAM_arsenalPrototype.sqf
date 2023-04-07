/*
	Author: linkion and R3vo

	Description:
	WIP

	Parameter(s):
	0: DISPLAY - WIP

	Returns:
 -
*/

#include "\a3\3DEN\UI\macros.inc"

_display = (if (is3DEN) then {findDisplay 313} else {[] call BIS_fnc_displayMission}) createDisplay "RscDisplayEmpty";

// this would be a hashmap for what the user has selected,
// I don't like the idea of having the UI store our data.
// perhaps could be used to be saved into the profile and loaded
uiNamespace setVariable ["ENH_VAM_selectHashMap", createHashMap];
/// Gave up on nested hashmaps
/// instead will be a hashmap of just item classes with
/// ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort", "_class"] array as value.

private _ctrlBackground = _display ctrlCreate ["ctrlStatic", -1];

#define WINDOW_W 140 // Overwrite macro from Eden because they use a different width

_ctrlBackground ctrlSetPosition
[
	CENTER_X - 0.5 * WINDOW_W * GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs + 10 * GRID_H,
	WINDOW_W * GRID_W,
	WINDOW_HAbs
];

_ctrlBackground ctrlSetBackgroundColor [COLOR_BACKGROUND_RGBA];

private _ctrlTitle = _display ctrlCreate ["ctrlStaticTitle", -1];

_ctrlTitle ctrlSetPosition
[
	CENTER_X - 0.5 * WINDOW_W * GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs + 5 * GRID_H,
	WINDOW_W * GRID_W,
	5 * GRID_H
];

_ctrlTitle ctrlSetText "STR_ENH_TOOLS_LIMIT_ARSENAL";
_ctrlTitle ctrlCommit 0;

_ctrlSearch = _display ctrlCreate ["ctrlEdit", 645];
_ctrlSearch ctrlSetPosition
[
	CENTER_X - 0.5 * WINDOW_W * GRID_W + GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs + 11 * GRID_H,
	WINDOW_W * GRID_W - 13 * GRID_W,
	5 * GRID_H
];

_ctrlTV = _display ctrlCreate ["RscTreeSearch", 10];
_ctrlTV ctrlSetFont FONT_NORMAL;
_ctrlTV ctrlSetFontHeight (4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5);
_ctrlTV ctrlSetPosition
[
	CENTER_X - 0.5 * WINDOW_W * GRID_W + GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs + 17 * GRID_H,
	WINDOW_W * GRID_W - 2 * GRID_W,
	WINDOW_HAbs / 2 - 17 * GRID_H
];

_ctrlTV ctrlSetBackgroundColor [0, 0, 0, 0];

_ctrlPicture = _display ctrlCreate ["ctrlStaticPictureKeepAspect", 10];//["ctrlStaticPictureKeepAspect", 10];
_ctrlPicture ctrlSetPosition
[
	CENTER_X - (WINDOW_W * GRID_W - 2 * GRID_W) / 2,
	CENTER_Y - 0.5 * WINDOW_HAbs + 17 * GRID_H + WINDOW_HAbs / 2 - 17 * GRID_H - GRID_H,
	(WINDOW_W * GRID_W - 2 * GRID_W) / 2,
	WINDOW_HAbs / 2 - 17 * GRID_H
];

_ctrlFooter = _display ctrlCreate ["ctrlStaticFooter", -1];//["ctrlStaticPictureKeepAspect", 10];
_ctrlFooter ctrlSetPosition
[
	CENTER_X - 0.5 * WINDOW_W * GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs + 3 * GRID_H + WINDOW_HAbs,
	WINDOW_W * GRID_W,
	7 * GRID_H
];

_ctrlButtonClose = _display ctrlCreate ["ctrlButtonClose", 1];//["ctrlStaticPictureKeepAspect", 10];
_ctrlButtonClose ctrlSetPosition
[
	CENTER_X + 0.5 * WINDOW_W * GRID_W - 26 * GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs + 4 * GRID_H + WINDOW_HAbs,
	25 * GRID_W,
	5 * GRID_H
];

_ctrlButtonExport = _display ctrlCreate ["ctrlButton", -1];//["ctrlStaticPictureKeepAspect", 10];
_ctrlButtonExport ctrlSetPosition
[
	CENTER_X + 0.5 * WINDOW_W * GRID_W - 52 * GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs + 4 * GRID_H + WINDOW_HAbs,
	25 * GRID_W,
	5 * GRID_H
];

_ctrlButtonExport ctrlSetText "Export";

_ctrlButtonApply = _display ctrlCreate ["ctrlButton", -1];//["ctrlStaticPictureKeepAspect", 10];
_ctrlButtonApply ctrlSetPosition
[
	CENTER_X - 0.5 * WINDOW_W * GRID_W + 1 * GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs + 4 * GRID_H + WINDOW_HAbs,
	25 * GRID_W,
	5 * GRID_H
];

_ctrlButtonApply ctrlSetTooltip "Sets the Equipment Storage attribute to current selection of all selected entities that support it.";

_ctrlButtonApply ctrlAddEventHandler ["ButtonClick",
{
	params["_ctrlButton"];

	private _selectedObjects = get3DENSelected "Object";
	private _useACE = cbChecked ((ctrlParent _ctrlButton) displayCtrl 20);

	systemChat str _selectedObjects;
	systemChat str _useACE;

	_selectedObjects apply
	{
		[_x, _useACE] call ENH_fnc_VAM_applyAttribute;
	};

	["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
}];


private _selectedObjects = get3DENSelected "Object";

_ctrlButtonApply ctrlSetText format ["Apply (%1)", count _selectedObjects];

// If no object was selected, we cannot apply the attribute
_ctrlButtonApply ctrlEnable !(_selectedObjects isEqualTo []);

_ctrlButtonCollapseAll = _display ctrlCreate ["ctrlButtonCollapseAll", -1];//["ctrlStaticPictureKeepAspect", 10];
_ctrlButtonCollapseAll ctrlSetPosition
[
	CENTER_X + 0.5 * WINDOW_W * GRID_W - 6 * GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs + 11 * GRID_H,
	5 * GRID_W,
	5 * GRID_H
];

_ctrlButtonExpandAll = _display ctrlCreate ["ctrlButtonExpandAll", -1];//["ctrlStaticPictureKeepAspect", 10];
_ctrlButtonExpandAll ctrlSetPosition
[
	CENTER_X + 0.5 * WINDOW_W * GRID_W - 11 * GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs + 11 * GRID_H,
	5 * GRID_W,
	5 * GRID_H
];

_ctrlButtonCollapseAll ctrlAddEventHandler ["ButtonClick",
{
	params["_ctrlButton"];
	tvCollapseAll (ctrlParent _ctrlButton displayCtrl 10);
}];

_ctrlButtonExpandAll ctrlAddEventHandler ["ButtonClick",
{
	params["_ctrlButton"];
	tvExpandAll (ctrlParent _ctrlButton displayCtrl 10);
}];

_ctrlACECheckbox = _display ctrlCreate ["ctrlCheckbox", 20];
_ctrlACECheckbox ctrlSetPosition
[
	CENTER_X - 0.5 * WINDOW_W * GRID_W + 27 * GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs - 3 * GRID_H + WINDOW_HAbs,
	5 * GRID_W,
	5 * GRID_H
];

_ctrlACEText = _display ctrlCreate ["ctrlStatic", -1];
_ctrlACEText ctrlSetPosition
[
	CENTER_X - 0.5 * WINDOW_W * GRID_W + 1 * GRID_W,
	CENTER_Y - 0.5 * WINDOW_HAbs - 3 * GRID_H + WINDOW_HAbs,
	25 * GRID_W,
	5 * GRID_H
];

_ctrlACEText ctrlSetText "ACE Arsenal";

// Focus search box
ctrlSetFocus _ctrlSearch;

// Commit all changes
allControls _display apply { _x ctrlCommit 0};

if (uiNamespace getVariable ["ENH_VIM_allAddons", []] isEqualTo []) then { call ENH_fnc_getAllItems};

// Category Translation
// Category Translation
private _categoryTranslation = createHashMapFromArray
[
	["AssaultRifle", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_ASSAULTRIFLES0"],
	["MachineGun", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_MACHINEGUNS0"],
	["SniperRifle", "STR_A3_SNIPER1"],
	["Shotgun", "STR_ENH_VIM_SHOTGUNS"],
	["SubmachineGun", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_SUBMACHINEGUNS0"],
	["RocketLauncher", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_LAUNCHERS0"],
	["Handgun", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_PISTOLS0"],
	["Grenade", "STR_A3_GRENADES1"],
	["Magazine", "STR_GEAR_MAGAZINES"],
	["Mine", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_EXPLOSIVES0"],
	["AccessoryBipod", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_BOTTOMSLOT0"],
	["AccessoryMuzzle", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_FRONTSLOT0"],
	["AccessoryPointer", "STR_A3_POINTERS1"],
	["AccessorySights", "STR_A3_SCOPES1"],
	["Uniform", "STR_A3_CFGVEHICLECLASSES_UNIFORMS0"],
	["Vest", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_VESTS0"],
	["Backpack", "STR_A3_CFGVEHICLECLASSES_BACKPACKS0"],
	["Headgear", "STR_A3_RSCDISPLAYARSENAL_TAB_HEADGEAR"],
	["Glasses", "STR_A3_RSCDISPLAYARSENAL_TAB_GOGGLES"],
	["NVGoggles", "STR_A3_RSCDISPLAYARSENAL_TAB_NVGS"],
	["Item", "STR_A3_CFGVEHICLECLASSES_ITEMS0"]
];

private _allAddons = ((uiNamespace getVariable ["ENH_VIM_allAddons", []]) - [["", "Unchanged", ""], ["", "", ""]]) + [["", "Arma 3", ""]];

// Prefill tree view with layout
{
	_x params [["_addonClass", ""], ["_addonName", ""], ["_addonIcon", ""]];

	private _indexAddon = _ctrlTV tvAdd [[], _addonName];
	_ctrlTV tvSetPicture [[_indexAddon], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
	_ctrlTV tvSetPictureRight [[_indexAddon], _addonIcon];
	_ctrlTV tvSetData [[_indexAddon], _addonClass];
	{
		private _indexCategory = _ctrlTV tvAdd [[_indexAddon], localize (_categoryTranslation get _x)];
		_ctrlTV tvSetPicture [[_indexAddon, _indexCategory], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
		_ctrlTV tvSetData [[_indexAddon, _indexCategory], _x];
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

		private _indexEquipment = _ctrlTV tvAdd [[_indexAddon, _indexCategory], _displayName];

		_ctrlTV tvSetData [[_indexAddon, _indexCategory, _indexEquipment], _class];
		_ctrlTV tvSetPicture [[_indexAddon, _indexCategory, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
		//_ctrlTV tvSetPictureRight [[_indexAddon, _indexCategory, _indexEquipment], _picture];
		_ctrlTV tvSetTooltip [[_indexAddon, _indexCategory, _indexEquipment], _descriptionShort];


} foreach (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap]);

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

	for "_i" from (_ctrlTV tvCount _path) to 0 step -1 do
	{
		private _newPath = _path + [_i];

		if (_ctrlTV tvCount _newPath == 0) then
		{
			_ctrlTV tvDelete _newPath;
		}
		else
		{
			[_newPath, _maxLevel] call _fnc_removeEmptyNodes;
		};
	};
};

[[], 2] call _fnc_removeEmptyNodes;

// Sort TV
_ctrlTV tvSortAll [];

_ctrlTV ctrlAddEventHandler ["TreeSelChanged",
{
	params["_ctrl", "_path"];

	private _picture = ((uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap]) getOrDefault [toLower (_ctrl tvData _path), [""]]) select 1; //What am I doing here :D Revisit later

	ctrlParent _ctrl displayCtrl 10 ctrlSetText _picture;

	// check if it's a single entry or a folder
	if ((_ctrl tvCount _path) == 0) then
	{

		if ((_ctrl tvValue _path) == 0) then
		{
			[_ctrl, 1] call ENH_fnc_VAM_switchNodeState;
		}
		else
		{
			[_ctrl, 0] call ENH_fnc_VAM_switchNodeState;
		}
	}
	else
	{
		private _mouseX = getMousePosition select 0;

		// if clicked on check box
		// Don't know any other way to do this - linkion -------V
		if (_mouseX < 0.2 + 0.02 * (count _path - 1)) then // This doesn't work reliably
		{

			if ((_ctrl tvValue _path) == 0) then {
				[_ctrl, 1] call ENH_fnc_VAM_switchNodeState;
			} else {
				[_ctrl, 0] call ENH_fnc_VAM_switchNodeState;
			};
		};
	};
}];

// Check and uncheck nodes
_ctrlTV ctrlAddEventHandler ["keyDown",
{
	params ["_ctrlTV", "_key", "_shift", "_ctrl", "_alt"];

	if (_key == 14) then
	{
		[_ctrlTV, 0] call ENH_fnc_VAM_switchNodeState;
	};
	if (_key in [28, 156]) then
	{
		[_ctrlTV, 1] call ENH_fnc_VAM_switchNodeState;
	};
	if (_key == 59) then
	{
		call ENH_fnc_VAM_exportToSQF;
	};
}];



ENH_fnc_VAM_exportToSQF =
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