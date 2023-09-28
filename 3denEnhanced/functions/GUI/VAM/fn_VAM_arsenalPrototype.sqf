/*
 Author: linkion and R3vo

 Description:
 WIP

 Parameter(s):
 0: DISPLAY - WIP

 Returns:
 -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

private _display = findDisplay IDD_DISPLAY3DEN createDisplay "ENH_VAM";
uiNamespace setVariable ["ENH_VAM_display", _display];

private _ctrlTVItems = CTRL(IDC_VAM_TREEVIEW);
private _selectedObjects = get3DENSelected "Object";

//Get check is mods var is existing. If not get it
if (uiNamespace getVariable ["ENH_ESE_allAddons", []] isEqualTo []) then
{
  call ENH_fnc_getAllItems;
};

//Create translation hashmap
private _categoryTranslation = createHashMapFromArray
[
 ["AssaultRifle", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_ASSAULTRIFLES0"],
 ["MachineGun", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_MACHINEGUNS0"],
 ["SniperRifle", "STR_A3_SNIPER1"],
 ["Shotgun", "STR_ENH_ESE_SHOTGUNS"],
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

_ctrlTVItems ctrlAddEventHandler ["TreeSelChanged",
{
  params["_ctrlTVItems", "_path"];

  private _picture = ((uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap]) getOrDefault [toLower (_ctrlTVItems tvData _path), [""]]) select 1; //What am I doing here :D Revisit later


  //check if it's a single entry or a folder
  if ((_ctrlTVItems tvCount _path) == 0) then {
    if ((_ctrlTVItems tvValue _path) == 0) then
    {
      [_ctrlTVItems, 1] call ENH_fnc_VAM_switchNodeState;
    }
    else
    {
      [_ctrlTVItems, 0] call ENH_fnc_VAM_switchNodeState;
    }
  } else {
    private _mouseX = getMousePosition select 0;

    //if clicked on check box
    //Don't know any other way to do this - linkion -------V
      //I guess we should use UI macros
    if (_mouseX < 0.2 + 0.02 * (count _path - 1)) then {
      if ((_ctrlTVItems tvValue _path) == 0) then {
        [_ctrlTVItems, 1] call ENH_fnc_VAM_switchNodeState;
      } else {
        [_ctrlTVItems, 0] call ENH_fnc_VAM_switchNodeState;
      };
    };
    [] call ENH_fnc_VAM_loadSelectHashMap;
  };
}];

CTRL(IDC_VAM_BUTTON_PRESETS) ctrlAddEventHandler ["ButtonClick",
{
  params["_ctrlButton"];

  private _display = ctrlParent _ctrlButton;

  [_display] call ENH_fnc_VAM_openPresetsMenu;
}];

CTRL(IDC_VAM_BUTTON_LOAD) ctrlAddEventHandler ["ButtonClick",
{
  params["_ctrlButton"];
  [ctrlParent _ctrlButton, (get3DENSelected "Object") select 0] call ENH_fnc_VAM_loadObject;
}];

private _ctrlButtonApply = CTRL(IDC_VAM_BUTTON_APPLY);

_ctrlButtonApply ctrlAddEventHandler ["ButtonClick",
{
  params["_ctrlButton"];

  private _selectedObjects = get3DENSelected "Object";

  private _useACE = cbChecked ((ctrlParent _ctrlButton) displayCtrl IDC_VAM_ACE_CHECKBOX);
  private _useBI = cbChecked ((ctrlParent _ctrlButton) displayCtrl IDC_VAM_BI_CHECKBOX);

  _selectedObjects apply
  {
    [_x, _useACE, _useBI] call ENH_fnc_VAM_applyAttribute;
  };
}];

_ctrlButtonApply ctrlSetText format ["Apply (%1)", count _selectedObjects];

//If no object was selected, we cannot apply the attribute
_ctrlButtonApply ctrlEnable !(_selectedObjects isEqualTo []);

CTRL(IDC_VAM_BUTTON_COLLAPSE) ctrlAddEventHandler ["ButtonClick",
{
 params["_ctrlButton"];
 tvCollapseAll (ctrlParent _ctrlButton displayCtrl IDC_VAM_TREEVIEW);
 tvCollapseAll (ctrlParent _ctrlButton displayCtrl IDC_VAM_TREEVIEW_COMP_ITEMS);
}];

CTRL(IDC_VAM_BUTTON_EXPAND) ctrlAddEventHandler ["ButtonClick",
{
 params["_ctrlButton"];
 tvExpandAll (ctrlParent _ctrlButton displayCtrl IDC_VAM_TREEVIEW);
 tvExpandAll (ctrlParent _ctrlButton displayCtrl IDC_VAM_TREEVIEW_COMP_ITEMS);
}];

//Focus search box
ctrlSetFocus CTRL(IDC_VAM_SEARCH);

//Perhaps rewrite this
private _allAddons = ((uiNamespace getVariable ["ENH_ESE_allAddons", []]) - [["", "Unchanged", ""], ["", "", ""]]) + [["", "Arma 3", ""]];

//Prefill tree view with layout
{
 _x params [["_addonClass", ""], ["_addonName", ""], ["_addonIcon", ""]];

 private _indexAddon = _ctrlTVItems tvAdd [[], _addonName];
 _ctrlTVItems tvSetPicture [[_indexAddon], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
 _ctrlTVItems tvSetPictureRight [[_indexAddon], _addonIcon];
 _ctrlTVItems tvSetData [[_indexAddon], _addonClass];
 {
  private _indexCategory = _ctrlTVItems tvAdd [[_indexAddon], localize (_categoryTranslation get _x)];
  _ctrlTVItems tvSetPicture [[_indexAddon, _indexCategory], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
  _ctrlTVItems tvSetData [[_indexAddon, _indexCategory], _x];
 } foreach (uiNamespace getVariable ["ENH_ESE_types", []]);
} foreach _allAddons;

private _allAddonClasses = [];

_allAddons apply
{
 _allAddonClasses pushBack (_x # 0);
};

//Fill tree view with equipment
{
  _y params ["_displayName", "", "_addonClass", "", "_category", "_specificType", "_descriptionShort", "_class"];

  private _indexAddon = _allAddonClasses find _addonClass;
  private _indexCategory = (uiNamespace getVariable ["ENH_ESE_types", []]) find _category;

  if (_indexCategory < 0) then
  {
   _indexCategory = (uiNamespace getVariable ["ENH_ESE_types", []]) find _specificType;
  };

  private _indexEquipment = _ctrlTVItems tvAdd [[_indexAddon, _indexCategory], _displayName];

  _ctrlTVItems tvSetData [[_indexAddon, _indexCategory, _indexEquipment], _class];
  _ctrlTVItems tvSetPicture [[_indexAddon, _indexCategory, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
  _ctrlTVItems tvSetTooltip [[_indexAddon, _indexCategory, _indexEquipment], _descriptionShort];
} foreach (uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap]);

//initialize ENH_VAM_selectHashMap
uiNamespace setVariable ["ENH_VAM_selectHashMap", createHashMap];

//Make this a separate function
private _fnc_removeEmptyNodes =
{
 params
 [
  ["_path", []],
  ["_maxLevel", -1]
 ];

 //Exit if path is deeper than wanted level
 if (count _path == _maxLevel && _maxLevel > -1) exitWith {};

 for "_i" from (_ctrlTVItems tvCount _path) to 0 step -1 do
 {
  private _newPath = _path + [_i];

  if (_ctrlTVItems tvCount _newPath == 0) then
  {
   _ctrlTVItems tvDelete _newPath;
  }
  else
  {
   [_newPath, _maxLevel] call _fnc_removeEmptyNodes;
  };
 };
};

[[], 2] call _fnc_removeEmptyNodes;

//Sort TV
_ctrlTVItems tvSortAll [];

_ctrlTVItems ctrlAddEventHandler ["TreeSelChanged",
{
  params["_ctrlTVItems", "_path"];

  private _picture = ((uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap]) getOrDefault [toLower (_ctrlTVItems tvData _path), [""]]) select 1; //What am I doing here :D Revisit later

  ctrlParent _ctrlTVItems displayCtrl IDC_VAM_PREVIEW_PICTURE ctrlSetText _picture;

  uiNamespace setVariable ["ENH_VAM_selectedItemTVPath", _path];
  uiNamespace setVariable ["ENH_VAM_selectedItem",
    (uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap]) getOrDefault [toLower (_ctrlTVItems tvData _path), [""]]
  ];

  //check if it's a single entry or a folder
  if ((_ctrlTVItems tvCount _path) == 0) then
  {
    //check if item that can have attachments, then display attachment tree
    private _itemTypesWAttach = ["AssaultRifle", "MachineGun", "SniperRifle", "Shotgun", "SubmachineGun", "RocketLauncher", "Handgun"];
    private _tempPath = +_path;
    _tempPath deleteAt ((count _tempPath) - 1);
    if ((_ctrlTVItems tvData _tempPath) in _itemTypesWAttach) then {
      [true] call ENH_fnc_VAM_openCloseACCTV;
    } else {
      [false] call ENH_fnc_VAM_openCloseACCTV;
    };

    if ((_ctrlTVItems tvValue _path) == 0) then {
      [_ctrlTVItems, 1] call ENH_fnc_VAM_switchNodeState;
    } else {
      [_ctrlTVItems, 0] call ENH_fnc_VAM_switchNodeState;
    };
  }
  else
  {
    private _mouseX = getMousePosition select 0;
    if (_mouseX < 0.2 + 0.02 * (count _path - 1)) then {
      if ((_ctrlTVItems tvValue _path) == 0) then {
        [_ctrlTVItems, 1] call ENH_fnc_VAM_switchNodeState;
      } else {
        [_ctrlTVItems, 0] call ENH_fnc_VAM_switchNodeState;
      };
    };
  };

  [ctrlParent _ctrlTVItems displayCtrl IDC_VAM_TREEVIEW_COMP_ITEMS, _ctrlTVItems tvData _path] call ENH_fnc_VAM_tvItemInit;
  [_ctrlTVItems] call ENH_fnc_VAM_handleItemStats;
}];