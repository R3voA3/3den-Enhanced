/*
   Author: Revo

   Description:
   Checks Eden preferences and enables certain features accordingly.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

#define MARKERS 			profileNamespace getVariable ["Enh_ShowUnits",false]
#define BULLETTRACING 		profileNamespace getVariable ["Enh_BulletTracing",false]
#define ZEUS				profileNamespace getVariable ["Enh_Zeus",false]
#define ARSENAL 			profileNamespace getVariable ["Enh_Arsenal",false]
#define GARAGE 				profileNamespace getVariable ["Enh_Garage",false]
#define INVULNERABILITY 	profileNamespace getVariable ["Enh_Invulnerability",false]
#define CAPTIVE 			profileNamespace getVariable ["Enh_CaptiveMode",false]
#define STAMINA 			profileNamespace getVariable ["Enh_DisableStamina",false]
#define AWARENESS 			profileNamespace getVariable ["Enh_Awareness",false]
#define FPS 			    profileNamespace getVariable ["Enh_FPS",false]
#define KILLWEST 			profileNamespace getVariable ["Enh_KillWest",false]
#define KILLEAST 			profileNamespace getVariable ["Enh_KillEast",false]
#define KILLINDEP 			profileNamespace getVariable ["Enh_KillIndep",false]
#define KILLCIV				profileNamespace getVariable ["Enh_KillCiv",false]
#define KILLCURSOR			profileNamespace getVariable ["Enh_KillCursor",false]
#define PATHDEBUGGING		profileNamespace getVariable ["Enh_PathDebugging",[]]

#define MISSIONDISPLAY 		(findDisplay 46)

if (isMultiplayer) exitWith {false};//To prevent issues in multiplayer games started from multiplayer editor

private ["_zeusModule","_pos","_ctrlData","_ctrlFPS","_markerUnitsArray","_sideColour","_displayName","_marker","_entity","_object","_arrow"];

if (INVULNERABILITY) then {player allowDamage false; (vehicle player) allowDamage false};
if (CAPTIVE) then {player setCaptive true};
if (STAMINA) then {player enableStamina false};
if (BULLETTRACING) then {[player] spawn BIS_fnc_traceBullets};

if (ZEUS) then
{
	[] spawn
	{
		waitUntil {!isNull player};
		_zeusModule = (creategroup sideLogic) createUnit ["ModuleCurator_F",[0,0,0],[],10,"NONE"];
		player assignCurator _zeusModule;
		//Add Interface EHs (Workaround)
		_zeusModule addCuratorEditableObjects [entities "", true];
		_zeusModule addeventhandler ["curatorFeedbackMessage",{_this call bis_fnc_showCuratorFeedbackMessage;}];
		_zeusModule addeventhandler ["curatorPinged",{_this call bis_fnc_curatorPinged;}];
		_zeusModule addeventhandler ["curatorObjectPlaced",{_this call bis_fnc_curatorObjectPlaced;}];
		_zeusModule addeventhandler ["curatorObjectEdited",{_this call bis_fnc_curatorObjectEdited;}];
		_zeusModule addeventhandler ["curatorWaypointPlaced",{_this call bis_fnc_curatorWaypointPlaced;}];
		_zeusModule addeventhandler ["curatorObjectDoubleClicked",{(_this select 1) call bis_fnc_showCuratorAttributes;}];
		_zeusModule addeventhandler ["curatorGroupDoubleClicked",{(_this select 1) call bis_fnc_showCuratorAttributes;}];
		_zeusModule addeventhandler ["curatorWaypointDoubleClicked",{(_this select 1) call bis_fnc_showCuratorAttributes;}];
		_zeusModule addeventhandler ["curatorMarkerDoubleClicked",{(_this select 1) call bis_fnc_showCuratorAttributes;}];
	};
};

if (ARSENAL) then {["AmmoboxInit",[player,true]] spawn BIS_fnc_arsenal};

if (GARAGE) then
{

	player addAction ["Garage",
	{
		if (!isNil "BIS_fnc_garage_center") then {deleteVehicle BIS_fnc_garage_center};
		BIS_fnc_garage_center = createVehicle ["Land_HelipadEmpty_F",player getPos [10,getDir player],[],0,"CAN_COLLIDE"];
		["Open",true] call BIS_fnc_garage;
	}];
};

if (AWARENESS) then
{
	[] spawn 
	{
		while {true} do
		{
			hintSilent  format
			[
			"AWARENESS\n\nWEST: %1%2\nEAST: %3%4\nINDEPENDENT: %5%6\nCIVILIAN: %7%8",
			(WEST knowsAbout player) * 100 / 4,
			"%",
			(EAST knowsAbout player) * 100 / 4,
			"%",
			(INDEPENDENT knowsAbout player) * 100 / 4,
			"%",
			(CIVILIAN knowsAbout player) * 100 / 4,
			"%"
			]; 
			sleep 1;
		};
	};
	/* [] spawn
	{
		waitUntil {!isNull MISSIONDISPLAY};
		disableSerialization;
		if (isNull (MISSIONDISPLAY displayCtrl 991)) then//Make sure that controls are not created twice when restart button is pressed
		{
			_ctrlData = MISSIONDISPLAY ctrlCreate ["RscStructuredText",991];

			_ctrlData ctrlSetPosition
			[
				0.8675 * safezoneW + safezoneX,
				0.528 * safezoneH + safezoneY,
				0.118125 * safezoneW,
				0.3 * safezoneH
			];
			_ctrlData ctrlCommit 0;
		};

		_ctrlData = MISSIONDISPLAY displayCtrl 991;

		while {true} do
		{
			_ctrlData ctrlSetStructuredText parseText format
			[
				"<t size='1.2'>Awareness</t><br/>WEST: %1%2<br/>EAST: %3%4<br/>INDEPENDENT: %5%6<br/>CIVILIAN: %7%8<br/>",
				(WEST knowsAbout player) * 100 / 4,
				"%",
				(EAST knowsAbout player) * 100 / 4,
				"%",
				(INDEPENDENT knowsAbout player) * 100 / 4,
				"%",
				(CIVILIAN knowsAbout player) * 100 / 4,
				"%"
			];
			sleep 1;
		};
	}; */


	/* 	Revo_Script = [] spawn  
	{ 
	while {true} do  
	{ 
		private _unit = (player nearEntities ["SoldierEB", 1000]) param [0,objNull];
		(_unit targetKnowledge player) params ["_knownGroup","_knownUnit","_lastSeen","_lastDanger","_side","_posError","_pos"]; 
		private _data = format  
		[ 
		"Known by Group: %1\nKnown by the Unit: %2\nLast Seen: %3\nLast time endangered: %4\nSide: %5\nAim Position: %6", 
		_knownGroup,
		_knownUnit,
		_lastSeen,
		_lastDanger,
		side _unit,
		_pos
		]; 
		hintSilent _data; 
		sleep 0.05; 
	}; 
	}; */
};

if (FPS) then
{
	[] spawn
	{
		waitUntil {!isNull MISSIONDISPLAY};
		disableSerialization;
		if (isNull (MISSIONDISPLAY displayCtrl 992)) then//Make sure that controls are not created twice when restart button is pressed
		{
			_ctrlFPS = MISSIONDISPLAY ctrlCreate ["RscStructuredText",992];
			_ctrlFPS ctrlSetPosition
			[
				0.94625 * safezoneW + safezoneX,
				0.962 * safezoneH + safezoneY,
				0.0525 * safezoneW,
				0.056 * safezoneH
			];
			_ctrlFPS ctrlCommit 0;
		};
		_ctrlFPS = MISSIONDISPLAY displayCtrl 992;

		while {true} do
		{
			_ctrlFPS ctrlSetStructuredText parsetext format
			[
				"<t size='0.6'>FPS(avg.): %1<br/>FPS(min.): %2</t>",
				round diag_fps,
				round diag_fpsmin
			];
			sleep 1;
		};
	};
};

if (KILLWEST) then
{
	player addAction [
		localize "STR_ENH_functions_onePreviewDebug_killWest",
		"{if (side _x == WEST) then {_x setDamage 1}} forEach allUnits - [player]"
	];
};

if (KILLEAST) then
{
	player addAction [
		localize "STR_ENH_functions_onePreviewDebug_killEast",
		"{if (side _x == EAST) then {_x setDamage 1}} forEach allUnits - [player]"
	];
};

if (KILLINDEP) then
{
	player addAction [
		localize "STR_ENH_functions_onePreviewDebug_killIndep",
		"{if (side _x == INDEPENDENT) then {_x setDamage 1}} forEach allUnits - [player]"
	];
};

if (KILLCIV) then
{
	player addAction [
		localize "STR_ENH_functions_onePreviewDebug_killCiv",
		"{if (side _x == CIVILIAN) then {_x setDamage 1}} forEach allUnits - [player]"
	];
};

if (KILLCURSOR) then {player addAction [localize "STR_ENH_functions_onePreviewDebug_killCursorTarget",{cursorObject setDamage 1}]};

if (MARKERS) then
{
	[] spawn
	{
		#define TO_PERCENT_ROUND(VALUE) round ((VALUE) * 100)
		waitUntil {time > 2};//Give the game a bit of time to fully initialise the mission.
		_markerUnitsArray = [];

		{
			_sideColour = [side _x,true] call BIS_fnc_sideColor;
			_displayName = getText (configfile >> 'CfgVehicles' >> (typeOf _x) >> 'displayName');

			_name = "Enh_previewMarker_" + str _forEachIndex;
			_name = createMarkerLocal [_name,position _x];
			_name setMarkerTypeLocal 'mil_box';
			_name setMarkerTextLocal _displayName;
			_name setMarkerColorLocal _sideColour;

			_markerUnitsArray pushBack [_name,_x,_displayName],;
		} forEach entities [["AllVehicles"],[],false,true];//All vehicles without crew and dead entities

		while {true} do
		{
			waitUntil{sleep 1; visibleMap};//Only updated markers when visible
			{
				sleep 0.05;//A bit more performance friendly
				_x params ["_marker","_entity"];
				_displayName = _x # 2 + " " + str TO_PERCENT_ROUND(1 - damage _entity) + "%";//Add health of unit to marker name in %
				_marker setMarkerTextLocal _displayName;
				_marker setMarkerPosLocal getPos _entity;
			} forEach _markerUnitsArray;//[markerName,entity,displayName]
		};
	};
};

true