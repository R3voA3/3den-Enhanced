/*
   Author: R3vo

   Date: 2020-06-14

   Description:
   Used by the ENH_InventoryManager GUI. Initialises the GUI.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

ENH_IM_ShowTemplates = nil;
ENH_IM_target = get3DENSelected "Object" select 0;

if (isNil "ENH_IM_target" || ENH_IM_target isKindOf "CAManBase" || !(ENH_IM_target call ENH_fnc_hasStorage)) exitWith
{
	["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
	false
};

private _display = findDisplay 313 createDisplay "ENH_InventoryManager";

if ((uiNamespace getVariable ["ENH_IM_allItems",[]]) isEqualTo []) then
{
	uiNamespace setVariable
	[
		"ENH_IM_Types",
		[
			"AssaultRifle",
			"MachineGun",
			"SniperRifle",
			"Shotgun",
			"SubmachineGun",
			"RocketLauncher",
			"Handgun",
			"Grenade",
			"Magazine",
			"Mine",
			"AccessoryBipod",
			"AccessoryMuzzle",
			"AccessoryPointer",
			"AccessorySights",
			"Uniform",
			"Vest",
			"Backpack",
			"Headgear",
			"Glasses",
			"NVGoggles",
			"Item"
		]
	];

	private _cfgWeapons = "getNumber (_x >> 'scope') isEqualTo 2" configClasses (configfile >> "CfgWeapons");
	private _cfgMagazines = "getNumber (_x >> 'scope') isEqualTo 2" configClasses (configFile >> "CfgMagazines");
	private _cfgGlasses = "getNumber (_x >> 'scope') isEqualTo 2" configClasses (configFile >> "CfgGlasses");
	private _cfgVehicles = "getNumber (_x >> 'scope') isEqualTo 2" configClasses (configFile >> "CfgVehicles");

	private _allItemConfigs = _cfgWeapons + _cfgMagazines + _cfgGlasses + _cfgVehicles;
	private _allItemsConfigsCount = count _allItemsConfig;
	["ENH_IM_LoadingScreen"] call BIS_fnc_startLoadingScreen;

	_itemsCache = [];

	{
		(configName _x call BIS_fnc_itemType) params ["_category","_specificType"];
		if (_category != "" && 
		{(_category != "VehicleWeapon") &&
		{(getText (_x >> "picture") != "") &&
		{getText (_x >> "model") != "" &&
		{if (isArray (_x >> "muzzles")) then { (configName _x) call BIS_fnc_baseWeapon == configName _x} else {true}}}}}) then
		{
			if (_specificType isEqualTo "MissileLauncher") then {_specificType = "RocketLauncher"};//Same type for all launchers
			if (_specificType in ["Throw","SmokeShell","Flare"]) then {_specificType = "Grenade"};//Same type for all grenades, flares, chemlights, smoke

			private _addonName = "";
			private _addonIcon = "";
			if (configSourceMod _x != "") then //To prevent "ModParams - Undefined or empty mod directory" rpt spam
			{
				_addonName = modParams [configSourceMod _x, ["name"]] # 0;
				_addonIcon = modParams [configSourceMod _x, ["logoSmall"]] # 0;
			};
	
			_itemsCache pushBack
			[
				configName _x,
				getText (_x >> "DisplayName"),
				getText(_x >> "Picture"),
				_addonIcon,
				_category,
				_specificType,
				configSourceMod _x,
				_addonName
			];
		};
		(_allItemsConfigsCount / _forEachIndex) call BIS_fnc_progressLoadingScreen;
	} forEach _allItemConfigs;
	uiNamespace setVariable ["ENH_IM_allItems",_itemsCache];
	"ENH_IM_LoadingScreen" call BIS_fnc_endLoadingScreen;
};

//Get all addons and add them to filter control
private _ctrlFilterSearch = _display displayCtrl 3300;
private _added = [];

{
	private _addonIcon = _x select 3;
	private _addonClass = _x select 6;
	private _addonName = _x select 7;
	
	if !(_addonClass == "" || {_addonClass in _added}) then
	{
		_added pushBack _addonClass;
		[_ctrlFilterSearch,_addonName,_addonClass,"",_addonIcon] call ENH_fnc_IM_lbAdd;
	};
} forEach (uiNamespace getVariable "ENH_IM_allItems");

[_display displayCtrl 2100,0] call ENH_fnc_IM_filterList;
_display call ENH_fnc_IM_loadAttributeValue;

//Add background icon
private _ctrlBackgroundIcon = _display displayCtrl 2000;
private _icon = getText (configFile >> "CfgVehicles" >> typeOf ENH_IM_target >> "icon");

//Stupid workaround because some vehicles / crates don't have the icon texture in their config...
if !(".paa" in _icon) then
{
	_icon = getText (configfile >> "CfgVehicleIcons" >> _icon);
};
_ctrlBackgroundIcon ctrlSetText _icon;

{
	(_display displayCtrl _x) ctrlEnable false;
} forEach [2900,3000,3100];

true