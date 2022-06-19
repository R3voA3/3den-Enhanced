/*
  Author: R3vo

  Description:
  Checks Eden preferences and enables features accordingly.

  Parameter(s):
  -

  Returns:
  -
*/

#define GETVALUE(ATTRIBUTE) ("Preferences" get3DENMissionAttribute ("ENH_DebugOptions_" + ATTRIBUTE))
#define MISSIONDISPLAY (call BIS_fnc_displayMission)
#define RADIUS 150
#define DELAY 0.1

private _states =
[
  GETVALUE("Arsenal"),
  GETVALUE("Garage"),
  GETVALUE("ShowUnits"),
  GETVALUE("BulletTracking"),
  GETVALUE("Zeus"),
  GETVALUE("Invulnerability"),
  GETVALUE("Captive"),
  GETVALUE("Stamina"),
  GETVALUE("FPS"),
  GETVALUE("KillBLUFOR"),
  GETVALUE("KillOPFOR"),
  GETVALUE("KillINDFOR"),
  GETVALUE("KillCIVFOR"),
  GETVALUE("KillCursor"),
  GETVALUE("DrawIcons"),
  GETVALUE("DeleteCorpse"),
  GETVALUE("ShowWaypoints"),
  GETVALUE("NoRecoil"),
  GETVALUE("NoSway"),
  GETVALUE("NoReload"),
  GETVALUE("DrawViewDirection"),
  GETVALUE("Teleport"),
  GETVALUE("SkipTime"),
  GETVALUE("TimeMultiplier"),
  GETVALUE("VariableViewer"),
  GETVALUE("ActiveScripts"),
  GETVALUE("DebugPath"),
  GETVALUE("DrawTriggers"),
  GETVALUE("DynSimDebug")
];

//To prevent issues in multiplayer games started from multiplayer editor. Also make sure at least one option is activated
if (!is3DENPreview || !(true in _states || 1 in _states || 2 in _states)) exitWith {};

//Start the script later. Sometimes player unit is changed when "Play the Character" is selected from the context menu a bit later
//Additionally give scripts time to create units, waypoints and so on so they are picked up by the debug options script
systemChat format [localize "STR_ENH_DEBUGOPTIONS_INIT_MSG_TIMER", 3];
sleep 1;
systemChat format [localize "STR_ENH_DEBUGOPTIONS_INIT_MSG_TIMER", 2];
sleep 1;
systemChat format [localize "STR_ENH_DEBUGOPTIONS_INIT_MSG_TIMER", 1];
sleep 1;
systemChat localize "STR_ENH_DEBUGOPTIONS_INIT_MSG_INIT";

if (_states select 0) then
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
    {["Open", [true]] call BIS_fnc_arsenal},
    {},
    [],
    1,
    nil,
    false,
    false
  ] call BIS_fnc_holdActionAdd;
};

if (_states select 1) then
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
      BIS_fnc_garage_center = createVehicle ["Land_HelipadEmpty_F", player getPos [10, getDir player], [], 0, "CAN_COLLIDE"];
      ["Open", true] call BIS_fnc_garage;
    },
    {},
    [],
    1,
    nil,
    false,
    false
  ] call BIS_fnc_holdActionAdd;
};

if (_states select 2) then
{
  [] spawn
  {
    #define TO_PERCENT_ROUND(VALUE) round ((VALUE) * 100)
    private _markerUnitsArray = [];

    {
      private _sideColour = [side _x, true] call BIS_fnc_sideColor;
      private _displayName = getText (configfile >> 'CfgVehicles' >> (typeOf _x) >> 'displayName');

      _name = "ENH_debug_groupMarker_" + str _forEachIndex;
      _name = createMarker [_name, position _x];
      _name setMarkerType 'mil_box';
      _name setMarkerText _displayName;
      _name setMarkerColor _sideColour;

      _markerUnitsArray pushBack [_name, _x, _displayName],;
    } forEach entities [["AllVehicles"], [], false, true];//All vehicles without crew and dead entities

    while {true} do
    {
      waitUntil{sleep DELAY; visibleMap};//Only update markers when visible
      {
        sleep DELAY;//A bit more performance friendly
        _x params ["_marker", "_entity"];
        _displayName = _x # 2 + " " + str TO_PERCENT_ROUND(1 - damage _entity) + "%";//Add health of unit to marker name in %
        _marker setMarkerText _displayName;
        _marker setMarkerPos getPosWorld _entity;
      } forEach _markerUnitsArray;//[markerName, entity, displayName]
    };
  };
};

if (_states select 3) then
{
  [player] spawn BIS_fnc_traceBullets;
};

if (_states select 4) then
{
  [] spawn
  {
    private _zeusModule = (creategroup sideLogic) createUnit ["ModuleCurator_F", [0, 0, 0], [], 10, "NONE"];
    player assignCurator _zeusModule;
    //Add Interface EHs (Workaround)
    _zeusModule addCuratorEditableObjects [entities "", true];
    _zeusModule addeventhandler ["curatorFeedbackMessage",{_this call BIS_fnc_showCuratorFeedbackMessage;}];
    _zeusModule addeventhandler ["curatorPinged",{_this call BIS_fnc_curatorPinged;}];
    _zeusModule addeventhandler ["curatorObjectPlaced",{_this call BIS_fnc_curatorObjectPlaced;}];
    _zeusModule addeventhandler ["curatorObjectEdited",{_this call BIS_fnc_curatorObjectEdited;}];
    _zeusModule addeventhandler ["curatorWaypointPlaced",{_this call BIS_fnc_curatorWaypointPlaced;}];
    _zeusModule addeventhandler ["curatorObjectDoubleClicked",{(_this select 1) call BIS_fnc_showCuratorAttributes;}];
    _zeusModule addeventhandler ["curatorGroupDoubleClicked",{(_this select 1) call BIS_fnc_showCuratorAttributes;}];
    _zeusModule addeventhandler ["curatorWaypointDoubleClicked",{(_this select 1) call BIS_fnc_showCuratorAttributes;}];
    _zeusModule addeventhandler ["curatorMarkerDoubleClicked",{(_this select 1) call BIS_fnc_showCuratorAttributes;}];
  };
};

if (_states select 5) then
{
  {
    _x allowDamage false;
  } forEach units player;

  (vehicle player) allowDamage false;
};

if (_states select 6) then
{
  {
    _x setCaptive true;
  } forEach units player;
};

if (_states select 7) then
{
  {
    _x enableStamina false;
  } forEach units player;
};

if (_states select 8) then
{
  [] spawn
  {
    waitUntil {!isNull MISSIONDISPLAY};
    disableSerialization;

    //Make sure that controls are not created twice when restart button is pressed
    if (isNull (MISSIONDISPLAY displayCtrl 992)) then
    {
      private _ctrlFPS = MISSIONDISPLAY ctrlCreate ["RscStructuredText", 992];
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
      sleep DELAY;
    };
  };
};

if (_states select 9) then
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
      {_x setDamage 1} forEach (units west - units player)
    },
    {},
    [],
    1,
    nil,
    false,
    false
  ] call BIS_fnc_holdActionAdd;
};

if (_states select 10) then
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
      {_x setDamage 1} forEach (units east - units player)
    },
    {},
    [],
    1,
    nil,
    false,
    false
  ] call BIS_fnc_holdActionAdd;
};

if (_states select 11) then
{
  [
    player,
    localize "STR_ENH_DEBUGOPTIONS_KILLINDFOR_DISPLAYNAME",
    "\A3\ui_f\data\igui\cfg\mptable\killed_ca.paa",
    "\A3\ui_f\data\igui\cfg\mptable\killed_ca.paa",
    "true",
    "true",
    {
      {_x setDamage 1} forEach (units independent - units player)
    },
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

if (_states select 12) then
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
      {_x setDamage 1} forEach (units civilian - units player)
    },
    {},
    [],
    1,
    nil,
    false,
    false
  ] call BIS_fnc_holdActionAdd;
};

if (_states select 13) then
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

if (_states select 14) then
{
  ENH_DebugOptions_CfgVehicles = configFile >> "CfgVehicles";
  ["ENH_EH_DrawUnitInfo_ID", "onEachFrame",
    {
      {
        drawIcon3D
        [
          "",
          (side _x call BIS_fnc_sideColor),
          _x modelToWorldVisual [0, 0, 0 boundingBox _x select 1 select 2],
          0.5,
          0.5,
          0,
          format
          [
            "%1 (%2 %3 HP, %4, %5 m)",
            getText (ENH_DebugOptions_CfgVehicles >> typeOf _x >> "DisplayName"),
            (1 - damage _x) * 100,
            "%",
            behaviour _x,
            round (player distance _x)
          ],
          true,
          3 * (1 / (getResolution select 3)) * pixelGrid * 0.5
        ];
        true
      } count ((ASLToAGL getPosASL player nearEntities [["AllVehicles"], RADIUS]) - [player]);
    }
  ] call BIS_fnc_addStackedEventHandler;
};

if (_states select 15) then
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

if (_states select 16) then
{
  private _markerColors = "true" configClasses (configFile >> "CfgMarkerColors") apply {configName _x};
  {
    private _path = [];
    private _markerText = "";
    private _color = selectRandom _markerColors;
    {
      _x params ["_group", "_wpIndex"];
      private _marker = createMarkerLocal
      [
        format ["ENH_debugWaypoints_%1_%2", _group, _wpIndex],
        waypointPosition _x
      ];
      private _markerTextNew  = format ["%1/%2/%3/%4", _group, waypointSpeed _x, waypointType _x];
      if (_markerText != _markerTextNew) then
      {
        _marker setMarkerTextLocal (_markerTextNew + str _wpIndex);
        _markerText = _markerTextNew;
      }
      else
      {
        _marker setMarkerTextLocal str _wpIndex;
      };
      _marker setMarkerColorLocal _color;
      _marker setMarkerShapeLocal "ICON";
      _marker setMarkerTypeLocal "mil_dot";
      //_marker setMarkerShadow false;
      _path append [waypointPosition _x select 0, waypointPosition _x select 1];
    } forEach waypoints _x;

    //Create poly markers
    if (count _path < 4) then {continue};
    private _markerPoly = createMarkerLocal [format ["ENH_debugWaypoints_poly_%1", str leader _x], leader _x];
    _markerPoly setMarkerShapeLocal "polyline";
    _markerPoly setMarkerColorLocal _color;
    _markerPoly setMarkerPolylineLocal _path;
  } forEach (allGroups select {count waypoints _x > 1});
};

if (_states select 17) then
{
  player setUnitRecoilCoefficient 0;
};

if (_states select 18) then
{
  player setCustomAimCoef 0;
};

if (_states select 19) then
{
  player addEventHandler ["FiredMan",
  {
    params ["_unit", "_weapon", "_muzzle", "", "", "", "", "_vehicle"];
    if (isNull _vehicle) then
    {
      _unit setAmmo [_weapon, 1000];
      _unit setWeaponReloadingTime [_unit, _muzzle, 0];
    }
    else
    {
      _vehicle setVehicleAmmo 1;
      _vehicle setWeaponReloadingTime [_unit, _muzzle, 0];
    };
  }];
};

if (_states select 20) then
{
  ["ENH_EH_DrawViewDirection_ID", "onEachFrame",
    {
      {
        private _beg = ASLToAGL eyePos _x;
        drawLine3D [_beg, (_beg vectorAdd (eyeDirection _x vectorMultiply 1)), [0, 1, 0, 1]];
        drawLine3D [_beg, (_beg vectorAdd (_x weaponDirection currentWeapon _x vectorMultiply 1)), [1, 0, 0, 1]];
        false;
      } count ((player nearEntities [["CAManBase"], RADIUS]) - [player]);
    }
  ] call BIS_fnc_addStackedEventHandler;
};

if (_states select 21) then
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
    {player setPos screenToWorld [0.5, 0.6]}, //Center of action icon
    {},
    [],
    0.2,
    nil,
    false,
    false
  ] call BIS_fnc_holdActionAdd;
};

if (_states select 22) then
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

if (_states select 23) then
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
      private _valueArray = [0.1, 0.2, 0.3, 0.4, 1, 2, 5, 10, 15, 18, 20, 25, 30, 35, 40, 45, 50, 60, 70, 80, 90, 100, 110, 120];
      setTimeMultiplier (_valueArray select (_this select 4));
      hint format ["%1x", timeMultiplier];
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

if (_states select 24) then
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

if (_states select 25) then
{
  [
    player,
    localize "STR_ENH_DEBUGOPTIONS_LOGSCRIPTS_DISPLAYNAME",
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",
    "true",
    "true",
    {call ENH_fnc_debugOptions_activeScripts},
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

if ((_states select 26) > 0) then
{
  private _cfgMarkerColors = ("true" configClasses (configFile >> "CfgMarkerColors"));
  private _is3DEnabled = GETVALUE("DebugPath") > 1;
  {
    private _leader = leader _x;
    if (expectedDestination _leader # 1 != "DoNotPlan" && alive _leader) then
    {
      [_leader, _cfgMarkerColors, _is3DEnabled] spawn
      {
        scriptName "ENH_Attribute_DebugPath";
        params ["_leader", "_cfgMarkerColors", "_is3DEnabled"];
        private _arrow = objNull;
        private _arrowColour = format ["#(rgb,8,8,3)color(%1,%2,%3,1)", random(1), random(1), random(1)];
        private _path = [];
        private _marker = createMarkerLocal [format ["ENH_DebugPath_%1", str _leader], _leader];
        _marker setMarkerShapeLocal "polyline";
        _marker setMarkerColorLocal configName selectRandom _cfgMarkerColors;

        private _posOld = getPosWorld _leader;

        while {alive _leader} do
        {
          if ((_leader distance _posOld) > 20) then
          {
            if (_is3DEnabled) then
            {
              _arrow = createVehicle ["Sign_Arrow_Direction_Blue_F", position _leader, [], 0, "CAN_COLLIDE"];
              _arrow setObjectTexture [0, _arrowColour];
              _arrow setDir (_posOld getDir _leader);
            };
            _path append [getPosWorld _leader # 0, getPosWorld _leader # 1];
            _posOld = getPosWorld _leader;
            if (count _path > 3) then {_marker setMarkerPolylineLocal _path};
            if (count _path == 500) then {_path deleteRange [0, 2]};
            sleep DELAY;
          };
        };
      };
    };
  } forEach allGroups;
};

if (_states select 27) then
{
  {
    private _colour = format ["#(rgb,8,8,3)color(%1,%2,%3,0.3)", random(1), random(1), random(1)];
    private _borderPos = [];
    triggerArea _x params ["_a", "_b"];
    if (_a <= 1 || _b <= 1) then {continue};
    for "_i" from 0 to 360 step 5 do
    {
      private _distance = _a min _b;
      private _initialPos = position _x;
      while {_initialPos inArea _x} do
      {
        _initialPos = _x getPos [_distance, _i];
        _borderPos = +_initialPos;
        _distance = _distance + 0.05;
      };
      for "_hOffset" from 0 to 15 step 5 do
      {
        ATLToASL _borderPos params ["_x", "_y", "_z"];
        private _arrow = createSimpleObject ["Sign_Sphere25cm_F", [_x, _y, _z + _hOffset + 0.1], true];
        _arrow setObjectTexture [0, _colour];
      };
    };
  } forEach (allMissionObjects "EmptyDetector");
};

if (_states select 28 && dynamicSimulationSystemEnabled) then
{
  #define UNITS_ENABLED {simulationEnabled _x && dynamicSimulationEnabled group _x} count allUnits
  #define ALL_UNITS {dynamicSimulationEnabled group _x} count allUnits
  #define GROUPS_ENABLED {simulationEnabled leader _x && dynamicSimulationEnabled _x} count allGroups
  #define ALL_GROUPS {dynamicSimulationEnabled _x} count allGroups

  #define DISTANCE_GROUPS_UNITS dynamicSimulationDistance "Group"
  #define DISTANCE_VEHICLES dynamicSimulationDistance "Vehicle"
  #define DISTANCE_EMPTY_VEHICLES dynamicSimulationDistance "EmptyVehicle"
  #define DISTANCE_PROPS dynamicSimulationDistance "Prop"
  #define DISTANCE_COEF dynamicSimulationDistanceCoef "IsMoving"

  ENH_dynSimDebug_Text = "<t size='1.3' align='center'>Dynamic Simulation Stats</t>   <br/>
<t align='left'>Enabled Units:<t/>              <t align='right'>%1 / %2</t>        <br/>
<t align='left'>Enabled Groups:<t/>             <t align='right'>%3 / %4</t>        <br/>

<t size='1.3' align='center'>Settings</t>                                           <br/>

<t align='left'>Distance (Units/Groups):<t/>    <t align='right' color='#FFFF00'>%5 m</t>           <br/>
<t align='left'>Distance (Vehicles):<t/>        <t align='right' color='#00FF00'>%6 m</t>           <br/>
<t align='left'>Distance (Empty Vehicles):<t/>  <t align='right' color='#00FFFF'>%7 m</t>           <br/>
<t align='left'>Distance (Props):<t/>           <t align='right' color='#FF00FF'>%8 m</t>           <br/>
<t align='left'>Distance Coef. (isMoving):<t/>  <t align='right'>x%9</t>           <br/>
<t align='left'>View Distance:<t/>              <t align='right' color='#FF0000'>%10 m</t>          <br/>
<t align='left'>View Distance too large:<t/>    <t align='right'>%11</t><br/>
<t align='left'>Recommended View Distance:<t/>  <t align='right'>~%12 m</t>";

  ENH_dynSimDebug_markerUnitsArray = [];

  {
    private _leader = leader _x;
    _marker = "ENH_dynSimDebugMarker_" + str _forEachIndex;
    _marker = createMarker [_marker, position _leader];
    if (isPlayer _leader) then
    {
      _marker setMarkerType "mil_dot";
      _marker setMarkerText name _leader;
      _marker setMarkerColor "ColorRed";
      _marker setMarkerSize [1.5, 1.5];
    }
    else
    {
      _marker setMarkerType "mil_box";
      _marker setMarkerText (getText (configfile >> "CfgVehicles" >> typeOf vehicle _leader >> "displayName"));
      _marker setMarkerColor ([side _leader, true] call BIS_fnc_sideColor);
    };
    ENH_dynSimDebug_markerUnitsArray pushBack [_marker, _leader];
  } forEach allGroups;

  addMissionEventHandler ["EachFrame",
  {
    private _recommendedViewDistance = selectMax [DISTANCE_GROUPS_UNITS * DISTANCE_COEF, DISTANCE_VEHICLES * DISTANCE_COEF, DISTANCE_EMPTY_VEHICLES, DISTANCE_PROPS] * 0.8;
    hintSilent parseText format
    [
      ENH_dynSimDebug_Text,
      UNITS_ENABLED,
      ALL_UNITS,
      GROUPS_ENABLED,
      ALL_GROUPS,
      DISTANCE_GROUPS_UNITS,
      DISTANCE_VEHICLES,
      DISTANCE_EMPTY_VEHICLES,
      DISTANCE_PROPS,
      DISTANCE_COEF,
      viewDistance,
      viewDistance > _recommendedViewDistance,
      _recommendedViewDistance
    ];
    if (visibleMap) then
    {
      ENH_dynSimDebug_markerUnitsArray apply
      {
        _x params ["_marker", "_leader"];
        _marker setMarkerPos getPosWorld _leader;
        _marker setMarkerAlpha ([0.2, 1] select simulationEnabled _leader);
      };
    };
  }];

  findDisplay 12 displayCtrl 51 ctrlAddEventHandler ["Draw",
  {
    params ["_ctrlMap"];
    _ctrlMap drawEllipse [player, DISTANCE_GROUPS_UNITS, DISTANCE_GROUPS_UNITS, 0, [1, 1, 0, 1], ""];//Groups and Units
    _ctrlMap drawEllipse [player, DISTANCE_VEHICLES, DISTANCE_VEHICLES, 0, [0, 1, 0, 1], ""];//Vehicles
    _ctrlMap drawEllipse [player, DISTANCE_EMPTY_VEHICLES, DISTANCE_EMPTY_VEHICLES, 0, [0, 1, 1, 1], ""];//Empty Vehicles
    _ctrlMap drawEllipse [player, DISTANCE_PROPS, DISTANCE_PROPS, 0, [1, 0, 1, 1], ""];//Props
    _ctrlMap drawEllipse [player, viewDistance, viewDistance, 0, [1, 0, 0, 1], ""];//Props
  }];
};