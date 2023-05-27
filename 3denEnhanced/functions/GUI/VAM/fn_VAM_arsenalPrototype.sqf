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

#define WINDOW_W 140
#define IDC_TREEVIEW 10
#define IDC_ACCTREEVIEW 15
#define IDC_ACE_CHECKBOX 20
#define IDC_BI_CHECKBOX 25
#define IDC_PREVIEW_PICTURE 30
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
uiNamespace setVariable ["ENH_VAM_display", _display];

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
 WINDOW_HAbs - 24 * GRID_H
];

_ctrlAccTV = _display ctrlCreate ["RscTreeSearch", IDC_ACCTREEVIEW];
_ctrlAccTV ctrlSetFont FONT_NORMAL;
_ctrlAccTV ctrlSetFontHeight (4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5); // Replace with macro
_ctrlAccTV ctrlSetPosition
[
 CENTER_X - 0.5 * WINDOW_W * GRID_W + GRID_W,
 CENTER_Y - 0 * WINDOW_HAbs + 17 * GRID_H,
 WINDOW_W * GRID_W - 2 * GRID_W,
 WINDOW_HAbs / 2 - 24 * GRID_H
];

_ctrlAccTV ctrlAddEventHandler ["TreeSelChanged",
{
  params["_ctrl", "_path"];

  private _picture = ((uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap]) getOrDefault [toLower (_ctrl tvData _path), [""]]) select 1; //What am I doing here :D Revisit later


  // check if it's a single entry or a folder
  if ((_ctrl tvCount _path) == 0) then {
    if ((_ctrl tvValue _path) == 0) then
    {
      [_ctrl, 1] call ENH_fnc_VAM_switchNodeState;
    }
    else
    {
      [_ctrl, 0] call ENH_fnc_VAM_switchNodeState;
    }
  } else {
    private _mouseX = getMousePosition select 0;

    // if clicked on check box
    // Don't know any other way to do this - linkion -------V
      // I guess we should use UI macros
    if (_mouseX < 0.2 + 0.02 * (count _path - 1)) then {
      if ((_ctrl tvValue _path) == 0) then {
        [_ctrl, 1] call ENH_fnc_VAM_switchNodeState;
      } else {
        [_ctrl, 0] call ENH_fnc_VAM_switchNodeState;
      };
    };
    [] call ENH_fnc_VAM_loadSelectHashMap;
  };
}];

_ctrlTV ctrlSetBackgroundColor [0, 0, 0, 0];

_ctrlPictureBackground = _display ctrlCreate ["ctrlStaticBackground", -1];
_ctrlPictureBackground ctrlSetPosition
[
 CENTER_X - WINDOW_W * GRID_W / 2 - (WINDOW_W * GRID_W) / 2 - GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 5 * GRID_H,
 (WINDOW_W * GRID_W) / 2,
 (WINDOW_W * GRID_H) / 2
];

_ctrlHeaderPreview = _display ctrlCreate ["ctrlStaticTitle", -1];
_ctrlHeaderPreview ctrlSetPosition
[
 CENTER_X - WINDOW_W * GRID_W / 2 - (WINDOW_W * GRID_W) / 2 - GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 5 * GRID_H,
 (WINDOW_W * GRID_W) / 2,
 5 * GRID_H
];

_ctrlHeaderPreview ctrlSetText "Preview";

//_ctrlPictureBackground ctrlSetBackgroundColor [(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77]), (profilenamespace getvariable ['GUI_BCG_RGB_G',0.51]), (profilenamespace getvariable ['GUI_BCG_RGB_B',0.08]), COLOR_ACTIVE_RGB_A];
//_ctrlPictureBackground ctrlSetText "PREVIEW";

_ctrlPicture = _display ctrlCreate ["ctrlStaticPictureKeepAspect", IDC_PREVIEW_PICTURE];
_ctrlPicture ctrlSetPosition
[
 CENTER_X - WINDOW_W * GRID_W / 2 - (WINDOW_W * GRID_W) / 2 + 6 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H,
 (WINDOW_W * GRID_W) / 2.5,
 (WINDOW_W * GRID_H) / 2.5
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

_ctrlButtonSave = _display ctrlCreate ["ctrlButton", -1];
_ctrlButtonSave ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 78 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 4 * GRID_H + WINDOW_HAbs,
 25 * GRID_W,
 5 * GRID_H
];

_ctrlButtonSave ctrlSetText "Save Preset";

_ctrlButtonSave ctrlAddEventHandler ["ButtonClick",
{
  params["_ctrlButton"];

  private _displayInput = ctrlParent _ctrlButton createDisplay "Display3DENRename";

  _displayInput displayCtrl 1 ctrlAddEventHandler ["ButtonClick",
  {
    params ["_ctrlButton"];
    systemChat str ctrlText (ctrlParent _ctrlButton displayCtrl 101);
  }];
}];

_ctrlButtonLoad = _display ctrlCreate ["ctrlButton", -1];
_ctrlButtonLoad ctrlSetPosition
[
 CENTER_X + 0.5 * WINDOW_W * GRID_W - 104 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 4 * GRID_H + WINDOW_HAbs,
 25 * GRID_W,
 5 * GRID_H
];

_ctrlButtonLoad ctrlSetText "Test Load Object";

_ctrlButtonLoad ctrlAddEventHandler ["ButtonClick", {
  params["_ctrlButton"];
  // load arsenal from 3den selection
  [ctrlParent _ctrlButton, (get3DENSelected "Object") select 0] call ENH_fnc_VAM_loadObject;
  //format["loadMap: %1", keys ([ctrlParent _ctrlButton, (get3DENSelected "Object") select 0] call ENH_fnc_VAM_loadObject)] call BIS_fnc_3DENNotification;
  //private _selectedItemHashMap = [ctrlParent _ctrlButton, (get3DENSelected "Object") select 0] call ENH_fnc_VAM_loadObject;
  //format["%1", keys (uiNamespace getVariable ["ENH_VAM_selectHashMap", createHashMap])] call BIS_fnc_3DENNotification;
  //[_ctrlTV, _selectedItemHashMap] call ENH_fnc_VAM_loadSelectHashMap;
}];

_ctrlButtonApply = _display ctrlCreate ["ctrlButton", -1];
_ctrlButtonApply ctrlSetPosition
[
 CENTER_X - 0.5 * WINDOW_W * GRID_W + 1 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 4 * GRID_H + WINDOW_HAbs,
 25 * GRID_W,
 5 * GRID_H
];

_ctrlStatsBackground = _display ctrlCreate ["ctrlStaticBackground", -1];
_ctrlStatsBackground ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 5 * GRID_H,
 (WINDOW_W * GRID_W) / 2,
 (WINDOW_W * GRID_H) / 2
];

_ctrlHeaderStats = _display ctrlCreate ["ctrlStaticTitle", -1];
_ctrlHeaderStats ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 5 * GRID_H,
 (WINDOW_W * GRID_W) / 2,
 5 * GRID_H
];

_ctrlHeaderStats ctrlSetText "Statistics";

_ctrlProgress_1 = _display ctrlCreate ["ctrlProgress", IDC_PROGRESS_1];
_ctrlProgress_1 ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + 2 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H,
 68 * GRID_W,
 10 * GRID_H
];

_ctrlProgressText_1 = _display ctrlCreate ["ctrlStatic", IDC_PROGRESS_TEXT_1];
_ctrlProgressText_1 ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + 2 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H,
 68 * GRID_W,
 10 * GRID_H
];

_ctrlProgress_2 = _display ctrlCreate ["ctrlProgress", IDC_PROGRESS_2];
_ctrlProgress_2 ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + 2 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H + 13 * GRID_H,
 68 * GRID_W,
 10 * GRID_H
];

_ctrlProgressText_2 = _display ctrlCreate ["ctrlStatic", IDC_PROGRESS_TEXT_2];
_ctrlProgressText_2 ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + 2 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H + 13 * GRID_H,
 68 * GRID_W,
 10 * GRID_H
];

_ctrlProgress_3 = _display ctrlCreate ["ctrlProgress", IDC_PROGRESS_3];
_ctrlProgress_3 ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + 2 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H + 26 * GRID_H,
 68 * GRID_W,
 10 * GRID_H
];

_ctrlProgressText_3 = _display ctrlCreate ["ctrlStatic", IDC_PROGRESS_TEXT_3];
_ctrlProgressText_3 ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + 2 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H + 26 * GRID_H,
 68 * GRID_W,
 10 * GRID_H
];

_ctrlProgress_4 = _display ctrlCreate ["ctrlProgress", IDC_PROGRESS_4];
_ctrlProgress_4 ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + 2 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H + 39 * GRID_H,
 68 * GRID_W,
 10 * GRID_H
];

_ctrlProgressText_4 = _display ctrlCreate ["ctrlStatic", IDC_PROGRESS_TEXT_4];
_ctrlProgressText_4 ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + 2 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H + 39 * GRID_H,
 68 * GRID_W,
 10 * GRID_H
];

_ctrlProgress_5 = _display ctrlCreate ["ctrlProgress", IDC_PROGRESS_5];
_ctrlProgress_5 ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + 2 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H + 52 * GRID_H,
 68 * GRID_W,
 10 * GRID_H
];

_ctrlProgressText_5 = _display ctrlCreate ["ctrlStatic", IDC_PROGRESS_TEXT_5];
_ctrlProgressText_5 ctrlSetPosition
[
 CENTER_X + WINDOW_W * GRID_W / 2 + 2 * GRID_W,
 CENTER_Y - 0.5 * WINDOW_HAbs + 12 * GRID_H + 52 * GRID_H,
 68 * GRID_W,
 10 * GRID_H
];

_ctrlProgress_1 progressSetPosition random 1;
_ctrlProgress_2 progressSetPosition random 1;
_ctrlProgress_3 progressSetPosition random 1;
_ctrlProgress_4 progressSetPosition random 1;
_ctrlProgress_5 progressSetPosition random 1;

_ctrlProgressText_1 ctrlSetShadow 0;
_ctrlProgressText_1 ctrlSetFont "PuristaLight";
_ctrlProgressText_1 ctrlSetTextColor [0,0,0,1];
_ctrlProgressText_1 ctrlSetText toUpper "Ballistic Protection";

_ctrlProgressText_2 ctrlSetShadow 0;
_ctrlProgressText_2 ctrlSetFont "PuristaLight";
_ctrlProgressText_2 ctrlSetTextColor [0,0,0,1];
_ctrlProgressText_2 ctrlSetText toUpper "WEIGHT";

_ctrlProgressText_3 ctrlSetShadow 0;
_ctrlProgressText_3 ctrlSetFont "PuristaLight";
_ctrlProgressText_3 ctrlSetTextColor [0,0,0,1];
_ctrlProgressText_3 ctrlSetText toUpper "LOAD";

_ctrlProgressText_4 ctrlSetShadow 0;
_ctrlProgressText_4 ctrlSetFont "PuristaLight";
_ctrlProgressText_4 ctrlSetTextColor [0,0,0,1];
_ctrlProgressText_4 ctrlSetText toUpper "EXPOSIVE RESISTANCE";

_ctrlProgressText_5 ctrlSetShadow 0;
_ctrlProgressText_5 ctrlSetFont "PuristaLight";
_ctrlProgressText_5 ctrlSetTextColor [0,0,0,1];
_ctrlProgressText_5 ctrlSetText toUpper "RANGE";

_ctrlButtonApply ctrlSetTooltip "Sets the Equipment Storage attribute to current selection of all selected entities that support it.";

_ctrlButtonApply ctrlAddEventHandler ["ButtonClick",
{
  params["_ctrlButton"];

  private _selectedObjects = get3DENSelected "Object";

  private _useACE = false; // default false for without ace
  private _useBI = true; // default true for without ace
  if (isClass(configFile >> "CfgPatches" >> "ace_arsenal")) then {
    _useACE = cbChecked ((ctrlParent _ctrlButton) displayCtrl IDC_ACE_CHECKBOX);
    _useBI = cbChecked ((ctrlParent _ctrlButton) displayCtrl IDC_BI_CHECKBOX);
  };

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

_ctrlBICheckbox = _display ctrlCreate ["ctrlCheckbox", IDC_BI_CHECKBOX];
_ctrlBICheckbox ctrlSetPosition
[
  CENTER_X - 0.5 * WINDOW_W * GRID_W + 22 * GRID_W,
  CENTER_Y - 0.5 * WINDOW_HAbs - 7 * GRID_H + WINDOW_HAbs,
  5 * GRID_W,
  5 * GRID_H
];

_ctrlBIText = _display ctrlCreate ["ctrlStatic", -1];
_ctrlBIText ctrlSetPosition
[
  CENTER_X - 0.5 * WINDOW_W * GRID_W,
  CENTER_Y - 0.5 * WINDOW_HAbs - 7 * GRID_H + WINDOW_HAbs,
  25 * GRID_W,
  5 * GRID_H
];

_ctrlBIText ctrlSetText "BI Arsenal";

// Hide checkbox and text if no ACE is loaded
private _isACELoaded = isClass(configFile >> "CfgPatches" >> "ace_arsenal");

_ctrlBIText ctrlEnable _isACELoaded;
_ctrlBICheckbox ctrlEnable _isACELoaded;
_ctrlBIText ctrlSetTextColor [1, 1, 1, [0.5, 1 ] select _isACELoaded];

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

// initialize ENH_VAM_selectHashMap
uiNamespace setVariable ["ENH_VAM_selectHashMap", createHashMap];



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

  uiNamespace setVariable ["ENH_VAM_selectedItemTVPath", _path];
  uiNamespace setVariable ["ENH_VAM_selectedItem",
    (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap]) getOrDefault [toLower (_ctrl tvData _path), [""]]
  ];

  // check if it's a single entry or a folder
  if ((_ctrl tvCount _path) == 0) then
  {
    // check if item that can have attachments, then display attachment tree
    private _itemTypesWAttach = ["AssaultRifle", "MachineGun", "SniperRifle", "Shotgun", "SubmachineGun", "RocketLauncher", "Handgun"];
    private _tempPath = +_path;
    _tempPath deleteAt ((count _tempPath) - 1);
    if ((_ctrl tvData _tempPath) in _itemTypesWAttach) then {
      [true] call ENH_fnc_VAM_openCloseACCTV;
    } else {
      [false] call ENH_fnc_VAM_openCloseACCTV;
    };

    if ((_ctrl tvValue _path) == 0) then {
      [_ctrl, 1] call ENH_fnc_VAM_switchNodeState;
    } else {
      [_ctrl, 0] call ENH_fnc_VAM_switchNodeState;
    };
  }
  else
  {
    private _mouseX = getMousePosition select 0;
    if (_mouseX < 0.2 + 0.02 * (count _path - 1)) then {
      if ((_ctrl tvValue _path) == 0) then {
        [_ctrl, 1] call ENH_fnc_VAM_switchNodeState;
      } else {
        [_ctrl, 0] call ENH_fnc_VAM_switchNodeState;
      };
    };
  };

  [_ctrl] call ENH_fnc_VAM_handleItemStats;
}];

[[], 2] call _fnc_removeEmptyNodes;