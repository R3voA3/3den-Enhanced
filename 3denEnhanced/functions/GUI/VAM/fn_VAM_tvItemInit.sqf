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
  [[], []], // magazines
  [], // optic
  [], // side
  [], // muzzle
  []  // bipod
];
// from ace_arsenal fnc_fillRightPanel.sqf lines 76-100
// Author: Alganthe

// Retrieve compatible mags
{
    if (_x != "") then {
        private _weaponConfig = (configFile >> "CfgWeapons" >> _x);
        private _index = _forEachIndex;

        {
            private _subIndex = _forEachIndex min 1;
            {
                ((_compatibleItems select 0) select _subIndex) pushBackUnique (configName (configFile >> "CfgMagazines" >> _x))
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
                {((_compatibleItems select 0) select _subIndex) pushBackUnique _x} forEach _magArray;
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

_compatibleMagsPrimaryMuzzle = _compatibleItems select 0 select 0;
_compatibleMagsSecondaryMuzzle = _compatibleItems select 0 select 1;
_compatibleScopes = _compatibleItems select 1;
_compatiblePointers = _compatibleItems select 2;
_compatibleMuzzles = _compatibleItems select 3;
_compatibleBipods = _compatibleItems select 4;

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
      (_compatibleItems select 1) pushBackUnique _x;
    };
    case TYPE_FLASHLIGHT: {
      (_compatibleItems select 2) pushBackUnique _x;
    };
    case TYPE_MUZZLE: {
      (_compatibleItems select 3) pushBackUnique _x;
    };
    case TYPE_BIPOD: {
      (_compatibleItems select 4) pushBackUnique _x;
    };
  };

} forEach ([_itemClass] call ENH_fnc_compatibleItems);

{
  _ctrlTV tvAdd [[], localize (_typeTranslation get _x)];
} forEach _AttachTypes;


{
  private _typeIndex = _AttachTypes find "scopes";
  private _indexEquipment = _ctrlTV tvAdd [[_typeIndex], _x];
} forEach _compatibleScopes;

{
  private _typeIndex = _AttachTypes find "pointers";
  private _indexEquipment = _ctrlTV tvAdd [[_typeIndex], _x];
} forEach _compatiblePointers;

{
  private _typeIndex = _AttachTypes find "muzzles";
  private _indexEquipment = _ctrlTV tvAdd [[_typeIndex], _x];
} forEach _compatibleMuzzles;

{
  private _typeIndex = _AttachTypes find "bipods";
  private _indexEquipment = _ctrlTV tvAdd [[_typeIndex], _x];
} forEach _compatibleBipods;

{
  private _typeIndex = _AttachTypes find "primaryMags";
  private _indexEquipment = _ctrlTV tvAdd [[_typeIndex], _x];
} forEach _compatibleMagsPrimaryMuzzle;

{
  private _typeIndex = _AttachTypes find "secondaryMags";
  private _indexEquipment = _ctrlTV tvAdd [[_typeIndex], _x];
} forEach _compatibleMagsSecondaryMuzzle;