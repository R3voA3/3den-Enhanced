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
#define WINDOW_W 140 // Overwrite macro from Eden because they use a different width

#define IDC_TREEVIEW 10
#define IDC_ACE_CHECKBOX 20
#define IDC_PREVIEW_PICTURE 30
#define IDC_ACCTREEVIEW 40
#define IDC_SEARCH 645
#define IDC_PROGRESS_1 40
#define IDC_PROGRESS_2 50
#define IDC_PROGRESS_3 60
#define IDC_PROGRESS_4 70
#define IDC_PROGRESS_5 80
#define IDC_PROGRESS_TEXT_1 90
#define IDC_PROGRESS_TEXT_2 100
#define IDC_PROGRESS_TEXT_3 110
#define IDC_PROGRESS_TEXT_4 120
#define IDC_PROGRESS_TEXT_5 130

private _display = findDisplay 313 createDisplay "RscDisplayEmpty";

// Get check is mods var is existing. If not get it
if (uiNamespace getVariable ["ENH_VIM_allAddons", []] isEqualTo []) then
{
  call ENH_fnc_getAllItems;
};

// Create translation hashmap
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

// this would be a hashmap for what the user has selected,
// I don't like the idea of having the UI store our data.
// perhaps could be used to be saved into the profile and loaded
uiNamespace setVariable ["ENH_VAM_selectHashMap", createHashMap];
/// Gave up on nested hashmaps
/// instead will be a hashmap of just item classes with
/// ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort", "_class"] array as value.

private _ctrlBackground = _display ctrlCreate ["ctrlStatic", -1];

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

_ctrlSearch = _display ctrlCreate ["ctrlEdit", IDC_SEARCH];
_ctrlSearch ctrlSetPosition
[
 CENTER_X - 0.5 * WINDOW_W * GRID_W + GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 11 * GRID_H,
 WINDOW_W * GRID_W - 13 * GRID_W,
 5 * GRID_H
];

_ctrlTV = _display ctrlCreate ["RscTreeSearch", IDC_TREEVIEW];
_ctrlTV ctrlSetFont FONT_NORMAL;
_ctrlTV ctrlSetFontHeight (4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5); // Replace with macro
_ctrlTV ctrlSetPosition
[
 CENTER_X - 0.5 * WINDOW_W * GRID_W + GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 17 * GRID_H,
 WINDOW_W * GRID_W - 2 * GRID_W,
 WINDOW_HAbs / 2 - 17 * GRID_H
];

_ctrlAccTV = _display ctrlCreate ["RscTreeSearch", IDC_ACCTREEVIEW];
_ctrlAccTV ctrlSetFont FONT_NORMAL;
_ctrlAccTV ctrlSetFontHeight (4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5); // Replace with macro
_ctrlAccTV ctrlSetPosition
[
 CENTER_X - 0.5 * WINDOW_W * GRID_W + GRID_W,
 CENTER_Y - 0 * WINDOW_HAbs + 17 * GRID_H,
 WINDOW_W * GRID_W - 2 * GRID_W,
 WINDOW_HAbs / 2 - 17 * GRID_H
];

_ctrlTV ctrlSetBackgroundColor [0, 0, 0, 0];

_ctrlPicture = _display ctrlCreate ["ctrlStaticPictureKeepAspect", IDC_PREVIEW_PICTURE];
_ctrlPicture ctrlSetPosition
[
 CENTER_X - (WINDOW_W * GRID_W - 2 * GRID_W) / 2,
 CENTER_Y - 0.5 * WINDOW_HAbs + 17 * GRID_H + WINDOW_HAbs / 2 - 16 * GRID_H - GRID_H,
 (WINDOW_W * GRID_W - 2 * GRID_W) / 2,
 WINDOW_HAbs / 2 - 17 * GRID_H
];

_ctrlFooter = _display ctrlCreate ["ctrlStaticFooter", -1];
_ctrlFooter ctrlSetPosition
[
 CENTER_X - 0.5 * WINDOW_W * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 3 * GRID_H + WINDOW_HAbs,
 WINDOW_W * GRID_W,
 7 * GRID_H
];

_ctrlButtonClose = _display ctrlCreate ["ctrlButtonClose", 1];
_ctrlButtonClose ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 26 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 4 * GRID_H + WINDOW_HAbs,
 25 * GRID_W,
 5 * GRID_H
];

_ctrlButtonExport = _display ctrlCreate ["ctrlButton", -1];
_ctrlButtonExport ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 52 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 4 * GRID_H + WINDOW_HAbs,
 25 * GRID_W,
 5 * GRID_H
];

_ctrlButtonExport ctrlSetText "Export";

_ctrlButtonApply = _display ctrlCreate ["ctrlButton", -1];
_ctrlButtonApply ctrlSetPosition
[
 CENTER_X - 0.5 * WINDOW_W * GRID_W + 1 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 4 * GRID_H + WINDOW_HAbs,
 25 * GRID_W,
 5 * GRID_H
];

_ctrlProgress_1 = _display ctrlCreate ["ctrlProgress", IDC_PROGRESS_1];
_ctrlProgress_1 ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 68 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 18 * GRID_H + WINDOW_HAbs / 2 - 18 * GRID_H,
 67 * GRID_W,
 5 * GRID_H
];

_ctrlProgressText_1 = _display ctrlCreate ["ctrlStatic", IDC_PROGRESS_TEXT_1];
_ctrlProgressText_1 ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 68 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 18 * GRID_H + WINDOW_HAbs / 2 - 18 * GRID_H,
 67 * GRID_W,
 5 * GRID_H
];

_ctrlProgress_2 = _display ctrlCreate ["ctrlProgress", IDC_PROGRESS_2];
_ctrlProgress_2 ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 68 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 18 * GRID_H + WINDOW_HAbs / 2 - 12 * GRID_H,
 67 * GRID_W,
 5 * GRID_H
];

_ctrlProgressText_2 = _display ctrlCreate ["ctrlStatic", IDC_PROGRESS_TEXT_2];
_ctrlProgressText_2 ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 68 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 18 * GRID_H + WINDOW_HAbs / 2 - 12 * GRID_H,
 67 * GRID_W,
 5 * GRID_H
];

_ctrlProgress_3 = _display ctrlCreate ["ctrlProgress", IDC_PROGRESS_3];
_ctrlProgress_3 ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 68 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 18 * GRID_H + WINDOW_HAbs / 2 - 6 * GRID_H,
 67 * GRID_W,
 5 * GRID_H
];

_ctrlProgressText_3 = _display ctrlCreate ["ctrlStatic", IDC_PROGRESS_TEXT_3];
_ctrlProgressText_3 ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 68 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 18 * GRID_H + WINDOW_HAbs / 2 - 6 * GRID_H,
 67 * GRID_W,
 5 * GRID_H
];

_ctrlProgress_4 = _display ctrlCreate ["ctrlProgress", IDC_PROGRESS_4];
_ctrlProgress_4 ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 68 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 18 * GRID_H + WINDOW_HAbs / 2,
 67 * GRID_W,
 5 * GRID_H
];

_ctrlProgressText_4 = _display ctrlCreate ["ctrlStatic", IDC_PROGRESS_TEXT_4];
_ctrlProgressText_4 ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 68 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 18 * GRID_H + WINDOW_HAbs / 2,
 67 * GRID_W,
 5 * GRID_H
];

_ctrlProgress_5 = _display ctrlCreate ["ctrlProgress", IDC_PROGRESS_5];
_ctrlProgress_5 ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 68 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 18 * GRID_H + WINDOW_HAbs / 2 + 6 * GRID_H,
 67 * GRID_W,
 5 * GRID_H
];

_ctrlProgressText_5 = _display ctrlCreate ["ctrlStatic", IDC_PROGRESS_TEXT_5];
_ctrlProgressText_5 ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 68 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 18 * GRID_H + WINDOW_HAbs / 2 + 6 * GRID_H,
 67 * GRID_W,
 5 * GRID_H
];

_ctrlProgress_1 progressSetPosition random 1;
_ctrlProgress_2 progressSetPosition random 1;
_ctrlProgress_3 progressSetPosition random 1;
_ctrlProgress_4 progressSetPosition random 1;
_ctrlProgress_5 progressSetPosition random 1;

/* _ctrlProgress_1 ctrlSetTextColor [1, 1, 1, 0.5];
_ctrlProgress_2 ctrlSetTextColor [1, 1, 1, 0.5];
_ctrlProgress_3 ctrlSetTextColor [1, 1, 1, 0.5];
_ctrlProgress_4 ctrlSetTextColor [1, 1, 1, 0.5]; */

_ctrlProgressText_1 ctrlSetShadow 0;
_ctrlProgressText_1 ctrlSetFont "RobotoCondensedBold";
_ctrlProgressText_1 ctrlSetTextColor [0,0,0,1];
_ctrlProgressText_1 ctrlSetText toUpper "Ballistic Protection";

_ctrlProgressText_2 ctrlSetShadow 0;
_ctrlProgressText_2 ctrlSetFont "RobotoCondensedBold";
_ctrlProgressText_2 ctrlSetTextColor [0,0,0,1];
_ctrlProgressText_2 ctrlSetText toUpper "WEIGHT";

_ctrlProgressText_3 ctrlSetShadow 0;
_ctrlProgressText_3 ctrlSetFont "RobotoCondensedBold";
_ctrlProgressText_3 ctrlSetTextColor [0,0,0,1];
_ctrlProgressText_3 ctrlSetText toUpper "LOAD";

_ctrlProgressText_4 ctrlSetShadow 0;
_ctrlProgressText_4 ctrlSetFont "RobotoCondensedBold";
_ctrlProgressText_4 ctrlSetTextColor [0,0,0,1];
_ctrlProgressText_4 ctrlSetText toUpper "EXPOSIVE RESISTANCE";

_ctrlProgressText_5 ctrlSetShadow 0;
_ctrlProgressText_5 ctrlSetFont "RobotoCondensedBold";
_ctrlProgressText_5 ctrlSetTextColor [0,0,0,1];
_ctrlProgressText_5 ctrlSetText toUpper "RANGE";

_ctrlButtonApply ctrlSetTooltip "Sets the Equipment Storage attribute to current selection of all selected entities that support it.";

_ctrlButtonApply ctrlAddEventHandler ["ButtonClick",
{
 params["_ctrlButton"];

 private _selectedObjects = get3DENSelected "Object";
 private _useACE = cbChecked ((ctrlParent _ctrlButton) displayCtrl IDC_ACE_CHECKBOX);
  private _useBI = true; // TODO: add second checkbox for using BI virt Arsenal, since some groups don't use BI at all.

 _selectedObjects apply
 {
  [_x, _useACE, _useBI] call ENH_fnc_VAM_applyAttribute;
 };

 ["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
}];

private _selectedObjects = get3DENSelected "Object";

_ctrlButtonApply ctrlSetText format ["Apply (%1)", count _selectedObjects];

// If no object was selected, we cannot apply the attribute
_ctrlButtonApply ctrlEnable !(_selectedObjects isEqualTo []);

_ctrlButtonCollapseAll = _display ctrlCreate ["ctrlButtonCollapseAll", -1];
_ctrlButtonCollapseAll ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 6 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 11 * GRID_H,
 5 * GRID_W,
 5 * GRID_H
];

_ctrlButtonExpandAll = _display ctrlCreate ["ctrlButtonExpandAll", -1];
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

_ctrlACECheckbox = _display ctrlCreate ["ctrlCheckbox", IDC_ACE_CHECKBOX];
_ctrlACECheckbox ctrlSetPosition
[
 CENTER_X - 0.5 * WINDOW_W * GRID_W + 22 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs - 3 * GRID_H + WINDOW_HAbs,
 5 * GRID_W,
 5 * GRID_H
];

_ctrlACEText = _display ctrlCreate ["ctrlStatic", -1];
_ctrlACEText ctrlSetPosition
[
 CENTER_X - 0.5 * WINDOW_W * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs - 3 * GRID_H + WINDOW_HAbs,
 25 * GRID_W,
 5 * GRID_H
];

_ctrlACEText ctrlSetText "ACE Arsenal";

// Hide checkbox and text if no ACE is loaded
private _isACELoaded = isClass(configFile >> "CfgPatches" >> "ace_arsenal");

_ctrlACEText ctrlEnable _isACELoaded;
_ctrlACECheckbox ctrlEnable _isACELoaded;
_ctrlACEText ctrlSetTextColor [1, 1, 1, [0.5, 1 ] select _isACELoaded];

// Focus search box
ctrlSetFocus _ctrlSearch;

// Commit all changes
allControls _display apply { _x ctrlCommit 0};

// Perhaps rewrite this
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
  _ctrlTV tvSetTooltip [[_indexAddon, _indexCategory, _indexEquipment], _descriptionShort];
} foreach (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap]);

// Make this a separate function
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

 ctrlParent _ctrl displayCtrl IDC_PREVIEW_PICTURE ctrlSetText _picture;

 // check if it's a single entry or a folder
 if ((_ctrl tvCount _path) == 0) then
 {
  private _ctrlAccTV = (ctrlParent _ctrl) displayCtrl IDC_ACCTREEVIEW;
  [_ctrlAccTV, _ctrl tvData _path] call ENH_fnc_VAM_tvItemInit;

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
    // I guess we should use UI macros
  if (_mouseX < 0.2 + 0.02 * (count _path - 1)) then
  {

   if ((_ctrl tvValue _path) == 0) then {
    [_ctrl, 1] call ENH_fnc_VAM_switchNodeState;
   } else {
    [_ctrl, 0] call ENH_fnc_VAM_switchNodeState;
   };
  };
 };

 // Update Stats (To be moved into separate function)

 private _ctrlProgress_1  = ctrlParent _ctrl displayCtrl IDC_PROGRESS_1;
 private _ctrlProgress_2  = ctrlParent _ctrl displayCtrl IDC_PROGRESS_2;
 private _ctrlProgress_3  = ctrlParent _ctrl displayCtrl IDC_PROGRESS_3;
 private _ctrlProgress_4  = ctrlParent _ctrl displayCtrl IDC_PROGRESS_4;
 private _ctrlProgress_5  = ctrlParent _ctrl displayCtrl IDC_PROGRESS_5;

 private _ctrlProgressText_1  = ctrlParent _ctrl displayCtrl IDC_PROGRESS_TEXT_1;
 private _ctrlProgressText_2  = ctrlParent _ctrl displayCtrl IDC_PROGRESS_TEXT_2;
 private _ctrlProgressText_3  = ctrlParent _ctrl displayCtrl IDC_PROGRESS_TEXT_3;
 private _ctrlProgressText_4  = ctrlParent _ctrl displayCtrl IDC_PROGRESS_TEXT_4;
 private _ctrlProgressText_5  = ctrlParent _ctrl displayCtrl IDC_PROGRESS_TEXT_5;

 // No item selected
 if (count _path != 3) then
 {
	_ctrlProgress_1 ctrlShow false;
	_ctrlProgress_2 ctrlShow false;
	_ctrlProgress_3 ctrlShow false;
	_ctrlProgress_4 ctrlShow false;
	_ctrlProgress_5 ctrlShow false;

	_ctrlProgressText_1 ctrlShow false;
	_ctrlProgressText_2 ctrlShow false;
	_ctrlProgressText_3 ctrlShow false;
	_ctrlProgressText_4 ctrlShow false;
	_ctrlProgressText_5 ctrlShow false;
 }
 else
 {
	_ctrlProgress_1 ctrlShow true;
	_ctrlProgress_2 ctrlShow true;
	_ctrlProgress_3 ctrlShow true;
	_ctrlProgress_4 ctrlShow true;
	_ctrlProgress_5 ctrlShow true;

	_ctrlProgressText_1 ctrlShow true;
	_ctrlProgressText_2 ctrlShow true;
	_ctrlProgressText_3 ctrlShow true;
	_ctrlProgressText_4 ctrlShow true;
	_ctrlProgressText_5 ctrlShow true;


	_ctrlProgress_1 progressSetPosition random 1;
	_ctrlProgress_2 progressSetPosition random 1;
	_ctrlProgress_3 progressSetPosition random 1;
	_ctrlProgress_4 progressSetPosition random 1;
	_ctrlProgress_5 progressSetPosition random 1;
 };
}];

// Make separate function
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