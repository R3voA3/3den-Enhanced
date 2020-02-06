/*
   Author: Revo

   Description:
   Checks Eden preferences and enables certain features accordingly.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

private _enabledOptions =  profileNamespace getVariable ["Enh_DebugOptions_Settings",[]];

if (_enabledOptions isEqualTo []) exitWith {false};

#define MARKERS 			0
#define BULLETTRACING 		1
#define ZEUS				2
#define ARSENAL 			3
#define GARAGE 				4
#define INVULNERABILITY 	5
#define CAPTIVE 			6
#define STAMINA 			7
#define AWARENESS 			8
#define FPS 			    9
#define killBLUFOR 			10
#define killOPFOR 			11
#define killINDFOR 			12
#define killCIVFOR			13
#define KILLCURSOR			14
#define SHOWUNITS_3D 		15
#define MISSIONDISPLAY 		(call BIS_fnc_displayMission)

//To prevent issues in multiplayer games started from multiplayer editor
if (isMultiplayer) exitWith {false};

//Start the script later. Sometimes player unit is changed when "Play the Character" is selected from the context menu a bit later
waitUntil {time > 0.5};

if (INVULNERABILITY in _enabledOptions) then
{
	{
		_x allowDamage false;
	} forEach units player;
	 
	(vehicle player) allowDamage false;
};

if (CAPTIVE in _enabledOptions) then
{
	player setCaptive true;
};

if (STAMINA in _enabledOptions) then
{
	{
		_x enableStamina false;
	} forEach units player;
};

if (BULLETTRACING in _enabledOptions) then
{
	[player] spawn BIS_fnc_traceBullets;
};

if (ZEUS in _enabledOptions) then
{
	[] spawn
	{
		waitUntil {!isNull player};
		private _zeusModule = (creategroup sideLogic) createUnit ["ModuleCurator_F",[0,0,0],[],10,"NONE"];
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

if (ARSENAL in _enabledOptions) then
{
	["AmmoboxInit",[player,true]] spawn BIS_fnc_arsenal;
};

if (GARAGE in _enabledOptions) then
{

	player addAction ["Garage",
	{
		if (!isNil "BIS_fnc_garage_center") then {deleteVehicle BIS_fnc_garage_center};
		BIS_fnc_garage_center = createVehicle ["Land_HelipadEmpty_F",player getPos [10,getDir player],[],0,"CAN_COLLIDE"];
		["Open",true] call BIS_fnc_garage;
	}];
};

if (AWARENESS in _enabledOptions) then
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
};

if (FPS in _enabledOptions) then
{
	[] spawn
	{
		waitUntil {!isNull MISSIONDISPLAY};
		disableSerialization;

		//Make sure that controls are not created twice when restart button is pressed
		if (isNull (MISSIONDISPLAY displayCtrl 992)) then
		{
			private _ctrlFPS = MISSIONDISPLAY ctrlCreate ["RscStructuredText",992];
			_ctrlFPS ctrlSetPosition
			[
				0.94625 * safezoneW + safezoneX,
				0.962 * safezoneH + safezoneY,
				0.0525 * safezoneW,
				0.056 * safezoneH
			];
			_ctrlFPS ctrlCommit 0;
		};
		private _ctrlFPS = MISSIONDISPLAY displayCtrl 992;

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

if (killBLUFOR in _enabledOptions) then
{
	player addAction [
		localize "STR_ENH_functions_onePreviewDebug_killBLUFOR",
		"{if (side _x == WEST) then {_x setDamage 1}} forEach allUnits - [player]"
	];
};

if (killOPFOR in _enabledOptions) then
{
	player addAction [
		localize "STR_ENH_functions_onePreviewDebug_killOPFOR",
		{{if (side _x == EAST) then {_x setDamage 1}} forEach allUnits - [player]}
	];
};

if (killINDFOR in _enabledOptions) then
{
	player addAction [
		localize "STR_ENH_functions_onePreviewDebug_killINDFOR",
		{{if (side _x == INDEPENDENT) then {_x setDamage 1}} forEach allUnits - [player]}
	];
};

if (killCIVFOR in _enabledOptions) then
{
	player addAction [
		localize "STR_ENH_functions_onePreviewDebug_killCIVFOR",
		{{if (side _x == CIVILIAN) then {_x setDamage 1}} forEach allUnits - [player]}
	];
};

if (KILLCURSOR in _enabledOptions) then 
{
	player addAction [
		localize "STR_ENH_functions_onePreviewDebug_killCursorTarget",
		{cursorObject setDamage 1}
	];
};

if (MARKERS in _enabledOptions) then
{
	[] spawn
	{
		#define TO_PERCENT_ROUND(VALUE) round ((VALUE) * 100)
		private _markerUnitsArray = [];

		{
			private _sideColour = [side _x,true] call BIS_fnc_sideColor;
			private _displayName = getText (configfile >> 'CfgVehicles' >> (typeOf _x) >> 'displayName');

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
				sleep 1;//A bit more performance friendly
				_x params ["_marker","_entity"];
				_displayName = _x # 2 + " " + str TO_PERCENT_ROUND(1 - damage _entity) + "%";//Add health of unit to marker name in %
				_marker setMarkerTextLocal _displayName;
				_marker setMarkerPosLocal getPos _entity;
			} forEach _markerUnitsArray;//[markerName,entity,displayName]
		};
	};
};

if (SHOWUNITS_3D in _enabledOptions) then
{
	Enh_DebugOptions_CfgVehicles = configFile >> "CfgVehicles";
	#define RADIUS 250

	["Enh_EH_DrawDLCIcons_ID", "onEachFrame",
		{
			{
				drawIcon3D
				[
					getText (Enh_DebugOptions_CfgVehicles >> typeOf _x >> "icon"),
					(side _x call BIS_fnc_sideColor),
					_x modelToWorldVisual [0,0,0.5],
					0.5,
					0.5,
					0,
					format
					[
						"%1 (%2 %3 HP, %4, %5 %6)",
						getText (Enh_DebugOptions_CfgVehicles >> typeOf _x >> "DisplayName"),
						(1 - damage _x) * 100,
						"%",
						behaviour _x,
						(_x knowsAbout player) * 100 / 4,
						"%"
					],
					true
				];
				false;
			} count (ASLToAGL getPosASL player nearEntities [["Man","Air","Car","Tank"],RADIUS]);
		}
	] call BIS_fnc_addStackedEventHandler;
};

true