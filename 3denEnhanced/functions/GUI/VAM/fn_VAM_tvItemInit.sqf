/*
  Author: linkion and R3vo

  Description:
  Initialize table view for selected item

  Parameter(s):
  tvControl - table view control
  String - item class name of which to display compatible items

  Returns:
  -

  Usage:
  [_ctrlTV, "LMG_Mk200_F"] call ENH_fnc_VAM_tvItemInit;
*/
#define TYPE_MUZZLE 101
#define TYPE_OPTICS 201
#define TYPE_FLASHLIGHT 301
#define TYPE_BIPOD 302

params["_ctrlTV", "_itemClass"];

tvClear _ctrlTV;

private _compatibleItems = [
  [], // optic
  [], // side
  [], // muzzle
  [],  // bipod
  [[], []] // magazines
];

private _selectHashMap = uiNamespace getVariable ["ENH_VAM_selectHashMap", createHashMap];
// from ace_arsenal fnc_fillRightPanel.sqf lines 76-100
// Author: Alganthe

// Retrieve compatible mags
{
    if (_x != "") then {
        private _weaponConfig = (configFile >> "CfgWeapons" >> _x);
        private _index = 4;

        {
            private _subIndex = _forEachIndex min 1;
            {
                ((_compatibleItems select _index) select _subIndex) pushBackUnique (configName (configFile >> "CfgMagazines" >> _x))
            } foreach ([getArray (_weaponConfig >> _x >> "magazines"), getArray (_weaponConfig >> "magazines")] select (_x == "this"));

            // Magazine groups
            {
                private _magazineGroups = createHashMap;

                private _cfgMagazines = configFile >> "CfgMagazines";

                {
                    private _magList = [];
                    {
                        private _magazines = (getArray _x) select {isClass (_cfgMagazines >> _x)}; //filter out non-existent magazines
                        _magazines = _magazines apply {configName (_cfgMagazines >> _x)}; //Make sure classname case is correct
                        _magList append _magazines;
                    } foreach configProperties [_x, "isArray _x", true];

                    _magazineGroups set [toLower configName _x, _magList arrayIntersect _magList];
                } foreach configProperties [(configFile >> "CfgMagazineWells"), "isClass _x", true];

                private _magArray = _magazineGroups get (toLower _x);
                {((_compatibleItems select _index) select _subIndex) pushBackUnique _x} forEach _magArray;
            } foreach ([getArray (_weaponConfig >> _x >> "magazineWell"), getArray (_weaponConfig >> "magazineWell")] select (_x == "this"));


        } foreach getArray (_weaponConfig >> "muzzles");
    };
} foreach [_itemClass];

private _compatibleMagsPrimaryMuzzle = [];
private _compatibleMagsSecondaryMuzzle = [];
private _compatibleScopes = [];
private _compatiblePointers = [];
private _compatibleMuzzles = [];
private _compatibleBipods = [];

_compatibleMagsPrimaryMuzzle = _compatibleItems select 4 select 0;
_compatibleMagsSecondaryMuzzle = _compatibleItems select 4 select 1;


private _AttachTypes = ["scopes", "pointers", "muzzles", "bipods", "primaryMags", "secondaryMags"];

private _typeTranslation = createHashMapFromArray
[
  ["secondaryMags", "STR_A3_GRENADES1"],
  ["primaryMags", "STR_GEAR_MAGAZINES"],
  ["bipods", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_BOTTOMSLOT0"],
  ["muzzles", "STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_FRONTSLOT0"],
  ["pointers", "STR_A3_POINTERS1"],
  ["scopes", "STR_A3_SCOPES1"]
];


private _configCfgWeapons = configFile >> "CfgWeapons";

{
  // Current result is saved in variable _x
  private _weaponConfig = (configFile >> "CfgWeapons" >> _itemClass);
  private _configItemInfo = _configCfgWeapons >> _x >> "ItemInfo";

  switch (getNumber (_configItemInfo >> "type")) do {
    case TYPE_OPTICS: {
      (_compatibleItems select 0) pushBackUnique _x;
    };
    case TYPE_FLASHLIGHT: {
      (_compatibleItems select 1) pushBackUnique _x;
    };
    case TYPE_MUZZLE: {
      (_compatibleItems select 2) pushBackUnique _x;
    };
    case TYPE_BIPOD: {
      (_compatibleItems select 3) pushBackUnique _x;
    };
  };

} forEach ([_itemClass] call ENH_fnc_compatibleItems);

{
  private _indexEquipment = _ctrlTV tvAdd [[], localize (_typeTranslation get _x)];
  _ctrlTV tvSetPicture [[_indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
} forEach _AttachTypes;

{
  private _typeIndex = _forEachIndex;
  if (_forEachIndex == 4) then {
    continue;
  };
  {
    (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap] get toLower(_x)) params ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort", "_class"];

    if (typeName _displayName != "STRING" || _displayName isEqualTo "") then {
      continue;
    };
    _displayName = _displayName+"";
    _class = _class+"";
    _descriptionShort = _descriptionShort+"";

    private _indexEquipment = _ctrlTV tvAdd [[_typeIndex], _displayName];

    _ctrlTV tvSetData [[_typeIndex, _indexEquipment], _class];
    if (toLower(_x) in (keys _selectHashMap)) then {
      _ctrlTV tvSetPicture [[_typeIndex, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa"];
      _ctrlTV tvSetValue [[_typeIndex, _indexEquipment], 1];
    } else {
      _ctrlTV tvSetPicture [[_typeIndex, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
      _ctrlTV tvSetValue [[_typeIndex, _indexEquipment], 0];
    };
    _ctrlTV tvSetTooltip [[_typeIndex, _indexEquipment], _descriptionShort];
  } forEach _x;
} forEach _compatibleItems;

{
  private _typeIndex = _AttachTypes find "primaryMags";
  (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap] get toLower(_x)) params ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort", "_class"];

  private _indexEquipment = _ctrlTV tvAdd [[_typeIndex], _displayName];

  _ctrlTV tvSetData [[_typeIndex, _indexEquipment], _class];
  if (toLower(_x) in (keys _selectHashMap)) then {
    _ctrlTV tvSetPicture [[_typeIndex, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa"];
    _ctrlTV tvSetValue [[_typeIndex, _indexEquipment], 1];
  } else {
    _ctrlTV tvSetPicture [[_typeIndex, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
    _ctrlTV tvSetValue [[_typeIndex, _indexEquipment], 0];
  };
  _ctrlTV tvSetTooltip [[_typeIndex, _indexEquipment], _descriptionShort];
} forEach _compatibleMagsPrimaryMuzzle;

{
  private _typeIndex = _AttachTypes find "secondaryMags";
  (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap] get toLower(_x)) params ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort", "_class"];

  private _indexEquipment = _ctrlTV tvAdd [[_typeIndex], _displayName];

  _ctrlTV tvSetData [[_typeIndex, _indexEquipment], _class];
  if (toLower(_x) in (keys _selectHashMap)) then {
    _ctrlTV tvSetPicture [[_typeIndex, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa"];
    _ctrlTV tvSetValue [[_typeIndex, _indexEquipment], 1];
  } else {
    _ctrlTV tvSetPicture [[_typeIndex, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
    _ctrlTV tvSetValue [[_typeIndex, _indexEquipment], 0];
  };
  _ctrlTV tvSetTooltip [[_typeIndex, _indexEquipment], _descriptionShort];
} forEach _compatibleMagsSecondaryMuzzle;

_ctrlTV ctrlAddEventHandler ["TreeSelChanged",
{
  params["_ctrl", "_path"];

  private _picture = ((uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap]) getOrDefault [toLower (_ctrl tvData _path), [""]]) select 1; //What am I doing here :D Revisit later


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
}];