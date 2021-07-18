/*
  Author: R3vo

  Date: 2021-07-14

  Description:
  Snippet from a3\3den\ui\attributes\ammobox.sqf. Is executed when Eden Editor is started. Workaround to get rid of the initial lag
  and loading screen when opening an entity with inventory for the first time.

  Parameter(s):
  -

  Returns:
  -
*/

if ((uiNamespace getVariable ["AmmoBox_list", []]) isNotEqualTo []) exitWith {};

//--- Get weapons and magazines from curator addons
private _types =
[
  ["AssaultRifle","Shotgun","Rifle","SubmachineGun"],
  ["MachineGun"],
  ["SniperRifle"],
  ["Launcher","MissileLauncher","RocketLauncher"],
  ["Handgun"],
  ["UnknownWeapon"],
  ["AccessoryMuzzle","AccessoryPointer","AccessorySights","AccessoryBipod"],
  ["Uniform"],
  ["Vest"],
  ["Backpack"],
  ["Headgear","Glasses"],
  ["Binocular","Compass","FirstAidKit","GPS","LaserDesignator","Map","Medikit","MineDetector","NVGoggles","Radio","Toolkit","Watch","UAVTerminal"]
];

private _CfgWeapons = configfile >> "CfgWeapons";
private _list = [[],[],[],[],[],[],[],[],[],[],[],[]];

//--- Weapons, magazines and items
private _magazines = []; //--- Store magazines in an array and mark duplicates, so nthey don't appear in the list of all items

private _glassesArray = "true" configClasses (configFile >> "CfgGlasses");
private _weaponsArray = "true" configClasses _CfgWeapons;
private _vehiclesArray = "true" configClasses (configFile >> "CfgVehicles");
{
  private _weaponCfg = _x;
  private _weapon = toLower configName _weaponCfg;

  _weapon call BIS_fnc_itemType params ["_weaponTypeCategory", "_weaponTypeSpecific"];

  {
    if (_weaponTypeSpecific in _x) exitWith
    {
      if !(_weaponTypeCategory isEqualTo "VehicleWeapon") then
      {
        private _weaponPublic = getNumber (_weaponCfg >> "scope") isEqualTo 2;
        private _listType = _list select _forEachIndex;

        if (_weaponPublic) then
        {
          _listType pushback
          [
            ([gettext (_weaponCfg >> "displayName")] + (((_weaponCfg >> "linkeditems") call BIS_fnc_returnchildren) apply { getText (_CfgWeapons >> getText (_x >> "item") >> "displayName") })) joinString " + ",
            _weapon,
            getText (_weaponCfg >> "picture"),
            parseNumber (getnumber (_weaponCfg >> "type") in [4096,131072]),
            false
          ];
        };

        //--- Add magazines compatible with the weapon
        if (_weaponPublic || _weapon in ["throw", "put"]) then
        {
          {
            private _muzzle = if (_x == "this") then { _weaponCfg } else { _weaponCfg >> _x };
            private _magazinesList = getArray (_muzzle >> "magazines");

            // Add magazines from magazine wells
            { { _magazinesList append (getArray _x) } forEach configproperties [configFile >> "CfgMagazineWells" >> _x, "isArray _x"] } forEach getArray (_muzzle >> "magazineWell");

            {
              private _mag = toLower _x;

              if (_listType findIf { _x select 1 == _mag } < 0) then
              {
                private _magCfg = configFile >> "CfgMagazines" >> _mag;

                if (getNumber (_magCfg >> "scope") isEqualTo 2) then
                {
                  _listType pushback
                  [
                    getText (_magCfg >> "displayName"),
                    _mag,
                    getText (_magCfg >> "picture"),
                    2,
                    _mag in _magazines
                  ];

                  _magazines pushback _mag;
                };
              };
            }
            forEach _magazinesList;
          }
          forEach getArray (_weaponCfg >> "muzzles");
        };
      };
    };
  }
  forEach _types;

}
forEach _weaponsArray;

//--- Backpacks
{
  private _weaponCfg = _x;
  private _weapon = toLower configName _weaponCfg;

  _weapon call BIS_fnc_itemType params ["", "_weaponTypeSpecific"];

  {
    if (_weaponTypeSpecific in _x) exitWith
    {
      if (getnumber (_weaponCfg >> "scope") == 2) then
      {
        _list select _forEachIndex pushback
        [
          gettext (_weaponCfg >> "displayName"),
          _weapon,
          gettext (_weaponCfg >> "picture"),
          3,
          false
        ];
      };
    };
  }
  forEach _types;
}
forEach _vehiclesArray;

//--- Glasses
{
  private _weaponCfg = _x;
  private _weapon = toLower configName _weaponCfg;

  if (getnumber (_weaponCfg >> "scope") == 2) then
  {
    _list select 10 pushback
    [
      gettext (_weaponCfg >> "displayName"),
      _weapon,
      gettext (_weaponCfg >> "picture"),
      3,
      false
    ];
  };
}
forEach _glassesArray;

uiNamespace setVariable ["AmmoBox_list", _list];