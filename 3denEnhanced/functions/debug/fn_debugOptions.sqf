/*
   Author: Revo

   Description:
   Checks Eden preferences and enables certain features accordingly.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

private _enabledOptions =  profileNamespace getVariable ["ENH_DebugOptions_Settings",[]];

if (_enabledOptions isEqualTo []) exitWith {false};

#define MARKERS 			0
#define BULLETTRACING 		1
#define ZEUS				2
#define ARSENAL 			3
#define GARAGE 				4
#define INVULNERABILITY 	5
#define CAPTIVE 			6
#define STAMINA 			7
#define FPS 			    8
#define KILLBLUFOR 			9
#define KILLOPFOR 			10
#define KILLINDFOR 			11
#define KILLCIVFOR			12
#define KILLCURSOR			13
#define SHOWUNITS_3D 		14
#define REMOVECORPSE 		15
#define SHOWWAYPOINTS 		16
#define NORECOIL			17
#define NOSWAY				18
#define UNLIMITEDAMMO		19
#define NORELOADTIME		20
#define DRAWVIEWDIR			21
#define TELEPORT			22
#define SKIPTIME			23
#define TIMEMULTIPLIER		24
#define VARIABLEVIEWER		25

#define MISSIONDISPLAY 		(call BIS_fnc_displayMission)
#define RADIUS 150

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
	{
		_x setCaptive true;
	} forEach units player;
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
	[
		player,
		localize "STR_A3_ARSENAL",
		"\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\arsenal_ca.paa",
		"\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\arsenal_ca.paa",
		"true",
		"true",
		{},
		{},
		{["Open",[true]] call BIS_fnc_arsenal},
		{},
		[],
		1,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
};

if (GARAGE in _enabledOptions) then
{
	[
		player,
		localize "STR_ENH_DEBUGOPTIONS_GARAGE_DISPLAYNAME",
		"\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\garage_ca.paa",
		"\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\garage_ca.paa",
		"true",
		"true",
		{},
		{},
		{
			if (!isNil "BIS_fnc_garage_center") then {deleteVehicle BIS_fnc_garage_center};
			BIS_fnc_garage_center = createVehicle ["Land_HelipadEmpty_F",player getPos [10,getDir player],[],0,"CAN_COLLIDE"];
			["Open",true] call BIS_fnc_garage;
		},
		{},
		[],
		1,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
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

if (KILLBLUFOR in _enabledOptions) then
{
	[
		player,
		localize "STR_ENH_DEBUGOPTIONS_KILLBLUFOR_DISPLAYNAME",
		"\A3\ui_f\data\igui\cfg\mptable\killed_ca.paa",
		"\A3\ui_f\data\igui\cfg\mptable\killed_ca.paa",
		"true",
		"true",
		{},
		{},
		{
			{
				if (side _x == WEST) then
				{
					_x setDamage 1;
				}
			} forEach allUnits - units player},
		{},
		[],
		1,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
};

if (KILLOPFOR in _enabledOptions) then
{
	[
		player,
		localize "STR_ENH_DEBUGOPTIONS_KILLOPFOR_DISPLAYNAME",
		"\A3\ui_f\data\igui\cfg\mptable\killed_ca.paa",
		"\A3\ui_f\data\igui\cfg\mptable\killed_ca.paa",
		"true",
		"true",
		{},
		{},
		{
			{
				if (side _x == EAST) then
				{
					_x setDamage 1;
				}
			} forEach allUnits - units player},
		{},
		[],
		1,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
};

if (KILLINDFOR in _enabledOptions) then
{
	[
		player,
		localize "STR_ENH_DEBUGOPTIONS_KILLINDFOR_DISPLAYNAME",
		"\A3\ui_f\data\igui\cfg\mptable\killed_ca.paa",
		"\A3\ui_f\data\igui\cfg\mptable\killed_ca.paa",
		"true",
		"true",
		{
			{
				if (side _x == INDEPENDENT) then
				{
					_x setDamage 1;
				}
			} forEach allUnits - units player},
		{},
		{},
		{},
		[],
		1,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
};

if (KILLCIVFOR in _enabledOptions) then
{
	[
		player,
		localize "STR_ENH_DEBUGOPTIONS_KILLCIVFOR_DISPLAYNAME",
		"\A3\ui_f\data\igui\cfg\mptable\killed_ca.paa",
		"\A3\ui_f\data\igui\cfg\mptable\killed_ca.paa",
		"true",
		"true",
		{},
		{},
		{
			{
				if (side _x == CIVILIAN) then
				{
					_x setDamage 1;
				}
			} forEach allUnits - units player},
		{},
		[],
		1,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
};

if (KILLCURSOR in _enabledOptions) then
{
	[
		player,
		localize "STR_ENH_DEBUGOPTIONS_KILLCURSOR_DISPLAYNAME",
		"A3\Ui_f\data\IGUI\RscCustomInfo\Sensors\Targets\NVTarget_ca.paa",
		"A3\Ui_f\data\IGUI\RscCustomInfo\Sensors\Targets\NVTarget_ca.paa",
		"!isNull cursorObject",
		"true",
		{},
		{},
		{cursorObject setDamage 1},
		{},
		[],
		1,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
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

			_name = "ENH_previewMarker_" + str _forEachIndex;
			_name = createMarker [_name,position _x];
			_name setMarkerType 'mil_box';
			_name setMarkerText _displayName;
			_name setMarkerColor _sideColour;

			_markerUnitsArray pushBack [_name,_x,_displayName],;
		} forEach entities [["AllVehicles"],[],false,true];//All vehicles without crew and dead entities

		while {true} do
		{
			waitUntil{sleep 0.2; visibleMap};//Only updated markers when visible
			{
				sleep 0.2;//A bit more performance friendly
				_x params ["_marker","_entity"];
				_displayName = _x # 2 + " " + str TO_PERCENT_ROUND(1 - damage _entity) + "%";//Add health of unit to marker name in %
				_marker setMarkerText _displayName;
				_marker setMarkerPos getPos _entity;
			} forEach _markerUnitsArray;//[markerName,entity,displayName]
		};
	};
};

if (SHOWUNITS_3D in _enabledOptions) then
{
	ENH_DebugOptions_CfgVehicles = configFile >> "CfgVehicles";
	["ENH_EH_DrawUnitInfo_ID", "onEachFrame",
		{
			{
				drawIcon3D
				[
					getText (ENH_DebugOptions_CfgVehicles >> typeOf _x >> "icon"),
					(side _x call BIS_fnc_sideColor),
					_x modelToWorldVisual [0,0,0.5],
					0.5,
					0.5,
					0,
					format
					[
						"%1 (%2 %3 HP, %4, %5 %6, %7 m)",
						getText (ENH_DebugOptions_CfgVehicles >> typeOf _x >> "DisplayName"),
						(1 - damage _x) * 100,
						"%",
						behaviour _x,
						(_x knowsAbout player) * 100 / 4,
						"%",
						round (player distance _x)
					],
					true
				];
				false;
			} count (ASLToAGL getPosASL player nearEntities [["CAManBase","Air","Car","Tank"],RADIUS]);
		}
	] call BIS_fnc_addStackedEventHandler;
};

if (REMOVECORPSE in _enabledOptions) then
{
	[
	player,
	localize "STR_ENH_DEBUGOPTIONS_DELETECORPSE_DISPLAYNAME",
	"\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa",
	"\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa",
	"true",
	"true",
	{},
	{},
	{allDeadMen apply {deleteVehicle _x}},
	{},
	[],
	1,
	nil,
	false,
	false
	] call BIS_fnc_holdActionAdd;
};

if (SHOWWAYPOINTS in _enabledOptions) then
{
	_markerColors = "true" configClasses (configFile >> "CfgMarkerColors") apply {configName _x};
	private _color = "";

	private _waypoints = [];
	{	
		_color = selectRandom _markerColors;
		{
			_x params ["_group","_wpIndex"];

			_marker = createMarker
			[
				format ["ENH_debugWaypoints_%1_%2",_group,_wpIndex],
				waypointPosition _x
			];
			
			_marker setMarkerColor _color;
			_marker setMarkerShape "ICON";
			_marker setMarkerType "mil_dot";
			_marker setMarkerText format
			[
				"%1/%2/%3/%4",
				_group,
				_wpIndex,
				waypointSpeed _x,
				waypointType _x
			];
		} forEach waypoints _x;
	} forEach allGroups;
};

if (NORECOIL in _enabledOptions) then
{
	player setUnitRecoilCoefficient 0;
};

if (NOSWAY in _enabledOptions) then
{
	player setCustomAimCoef 0;
};

if (UNLIMITEDAMMO in _enabledOptions) then
{
	player addEventHandler ["FiredMan",
	{
		params ["_unit","_weapon","_muzzle","_mode","_ammo","_magazine","_projectile","_vehicle"];
		if (isNull _vehicle) then
		{
			_unit setAmmo [_weapon,1000];
			_unit setWeaponReloadingTime [_unit,_muzzle,0];
			
		}
		else
		{
			_vehicle setVehicleAmmo 1;
			_vehicle setWeaponReloadingTime [_unit,_muzzle,0];
		};
	}];
};

if (NORELOADTIME in _enabledOptions) then
{
	player addEventHandler ["FiredMan",
	{
		params ["_unit","_weapon","_muzzle","_mode","_ammo","_magazine","_projectile","_vehicle"];
		if (isNull _vehicle) then
		{
			_unit setWeaponReloadingTime [_unit,_muzzle,0];
			
		}
		else
		{
			_vehicle setWeaponReloadingTime [_unit,_muzzle,0];
		};
	}];
};

if (DRAWVIEWDIR in _enabledOptions) then
{
	["ENH_EH_DrawViewDirection_ID", "onEachFrame",
		{
			{
				private _beg = ASLToAGL eyePos _x;
				private _endE = (_beg vectorAdd (eyeDirection _x vectorMultiply 3));
				private _endW = (_beg vectorAdd (_x weaponDirection currentWeapon _x vectorMultiply 3));
				drawLine3D [ _beg,_endE, [0,1,0,1]];
				drawLine3D [_beg,_endW, [1,0,0,1]];
				false;
			} count (player nearEntities [["CAManBase"],RADIUS] select {!isPlayer _x});
		}
	] call BIS_fnc_addStackedEventHandler;
};

if (TELEPORT in _enabledOptions) then
{
	[
		player,
		localize "STR_ENH_DEBUGOPTIONS_TELEPORT",
		"\a3\Modules_F_Curator\Data\portraitLightning_ca.paa",
		"\a3\Modules_F_Curator\Data\portraitLightning_ca.paa",
		"true",
		"true",
		{},
		{},
		{player setPos screenToWorld [0.5,0.6]},//Center of action icon
		{},
		[],
		0.2,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
};

if (SKIPTIME in _enabledOptions) then
{
	[
		player,
		localize "STR_ENH_DEBUGOPTIONS_SKIPTIME",
		"\a3\Modules_F_Curator\Data\portraitSkiptime_ca.paa",
		"\a3\Modules_F_Curator\Data\portraitSkiptime_ca.paa",
		"true",
		"true",
		{},
		{
			skipTime 1;
			hint (dayTime call BIS_fnc_timeToString);
		},
		{},
		{},
		[],
		10,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
};

if (TIMEMULTIPLIER in _enabledOptions) then
{
	[
		player,
		localize "STR_ENH_DEBUGOPTIONS_TIMEMULTIPLIER",
		"\a3\Modules_F_Curator\Data\portraitTimeAcceleration_ca.paa",
		"\a3\Modules_F_Curator\Data\portraitTimeAcceleration_ca.paa",
		"true",
		"true",
		{},
		{
			private _valueArray = [0.1,0.2,0.3,0.4,1,2,5,10,15,18,20,25,30,35,40,45,50,60,70,80,90,100,110,120];
			setTimeMultiplier (_valueArray select (_this select 4));
			hint format ["%1x",timeMultiplier];
		},
		{},
		{},
		[],
		10,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
};

if (VARIABLEVIEWER in _enabledOptions) then
{
	[
		player,
		localize "STR_ENH_VARIABLEVIEWER_HEADER",
		"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",
		"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",
		"true",
		"true",
		{(call BIS_fnc_displayMission) createDisplay "ENH_VariableViewer"},
		{},
		{},
		{},
		[],
		0.2,
		nil,
		false,
		false
	] call BIS_fnc_holdActionAdd;
};

true