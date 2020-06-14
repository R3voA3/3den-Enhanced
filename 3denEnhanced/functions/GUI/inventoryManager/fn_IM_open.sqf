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

if (isNil "ENH_IM_target") exitWith
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
			"SmokeShell",
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
		{if (isArray (_x >> "muzzles")) then { (configName _x) call bis_fnc_baseWeapon == configName _x} else {true}}}}}) then
		{
			if (_specificType isEqualTo "MissileLauncher") then {_specificType = "RocketLauncher"};//Same type for all launchers

			modParams
			[
				configSourceMod _x,
				["logo"]
			] params [["_addonIcon","",[""]]];

			_itemsCache pushBack
			[
				configName _x,
				getText (_x >> "DisplayName"),
				getText(_x >> "Picture"),
				_addonIcon,
				_category,
				_specificType
			];
		};
		(_allItemsConfigsCount / _forEachIndex) call BIS_fnc_progressLoadingScreen;
	} forEach _allItemConfigs;
	uiNamespace setVariable ["ENH_IM_allItems",_itemsCache];
	"ENH_IM_LoadingScreen" call BIS_fnc_endLoadingScreen;
};

private _ctrlFilter = _display displayCtrl 2100;
[_ctrlFilter,0] call ENH_fnc_IM_filterList;
_display call ENH_fnc_IM_loadAttributeValue;

private _ctrlBackgroundIcon = _display displayCtrl 2000;
private _icon = getText (configFile >> "CfgVehicles" >> typeOf ENH_IM_target >> "icon");
_ctrlBackgroundIcon ctrlSetText _icon;

{
	(_display displayCtrl _x) ctrlEnable false;
} forEach [150,1900,2200];

true