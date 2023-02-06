/*
  Author: R3vo

  Description:
  Activates 3den Enhanced debug options according to attribute settings.

  Parameter(s):
  -

  Returns:
  -
*/

#define GETVALUE(ATTRIBUTE) ("Preferences" get3DENMissionAttribute ("ENH_DebugOptions_" + ATTRIBUTE))
#define MISSIONDISPLAY (call BIS_fnc_displayMission)
#define RADIUS 150
#define DELAY 0.1

// To prevent issues in multiplayer games started from multiplayer editor
if (!is3DENPreview) exitWith {};

// Small delay to give scenario time to fully initialize
sleep 3;

if GETVALUE("Arsenal") then
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

if GETVALUE("Garage") then
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

if GETVALUE("BulletTracking") then
{
  [player] spawn BIS_fnc_traceBullets;
};

if GETVALUE("Zeus") then
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

if GETVALUE("Invulnerability") then
{
  {
    _x allowDamage false;
  } forEach units player;

  (vehicle player) allowDamage false;
};

if GETVALUE("Captive") then
{
  {
    _x setCaptive true;
  } forEach units player;
};

if GETVALUE("Stamina") then
{
  {
    _x enableStamina false;
  } forEach units player;
};

if GETVALUE("FPS") then
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

if GETVALUE("KillBLUFOR") then
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

if GETVALUE("KillOPFOR") then
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

if GETVALUE("KillINDFOR") then
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

if GETVALUE("KillCIVFOR") then
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

if GETVALUE("KillCursor") then
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

if GETVALUE("ShowGroups") then
{
  // Enable icons in 2D and 3D
  setGroupIconsVisible [true, true];
  setGroupIconsSelectable true;

  ENH_debugOptions_showGroups_initGroup =
  {
    scriptName "ENH_debugOptions_showGroups_initGroup";
    params
    [
      ["_group", grpNull, [grpNull]]
    ];

    if (isNull _group) exitWith {};

    private _start = diag_tickTime;
    waitUntil {sleep 1; units _group isNotEqualTo [] || diag_tickTime - _start > 5};
    if (units _group isEqualTo []) exitWith {};

    private _icon = switch (side _group call BIS_fnc_sideID) do
    {
      case 0: {"o_inf"};
      case 1: {"b_inf"};
      case 2: {"n_inf"};
      case 3: {"c_unknown"};
      default {"badge"};
    };

    private _color = [side _group, false] call BIS_fnc_sideColor;
    _group addGroupIcon [_icon, [0, 0]];
    _group setGroupIconParams [_color, groupID _group, linearConversion [1, 15, count units _group, 0.5, 3, false], true];
  };

  // Add the icon for all existing groups
  allGroups apply
  {
    _x spawn ENH_debugOptions_showGroups_initGroup;
  };

  // Add the icon whenever a group get's created
  addMissionEventHandler ["GroupCreated",
  {
    params ["_group"];
    _group spawn ENH_debugOptions_showGroups_initGroup;
  }];

  // Show group info when hovering over an icon (2D/3D)
  addMissionEventHandler ["GroupIconOverEnter",
  {
    params
    [
      "_is3D", "_group", "_waypointId",
      "_posX", "_posY",
      "_shift", "_control", "_alt"
    ];
    hintSilent parseText format
    [
      "<t align='left' font='EtelkaMonospacePro'><br/><t size='1.2'>General Information:</t><br/>Callsign: %1<br/>Leader: %2<br/>No. of Units: %3<br/>Delete when Empty: %4<br/><br/><t size='1.2'>Group Status:</t><br/>Health: %5<br/>Fleeing: %6<br/>Attack Enabled: %7<br/>Combat Behaviour: %8<br/>Combat Mode: %9<br/>Formation: %10<br/>Speed: %11<br/><br/><t size='1.2'>Waypoints:</t><br/>No. of Waypoints: %12<br/>Current Waypoint: %13<br/>Speed: %14<br/><br/><t size='1.2'>Additional Options:</t><br/>- Left click on an icon to toggle group waypoints<br/>- CTRL + Left Click to delete a group</t>",
      format ["%1 (%2)",groupID _group, if (vehicle leader _group isNotEqualTo leader _group) then {[configFile >> "CfgVehicles" >> typeOf vehicle leader _group ] call BIS_fnc_displayName} else {"-"}],
      name leader _group,
      count units _group,
      isGroupDeletedWhenEmpty _group,
      units _group apply {str round ((1 - damage _x)* 100) + " %"},
      fleeing leader _x,
      attackEnabled _group,
      combatBehaviour _group,
      combatMode _group,
      formation _group,
      speedMode _group,
      count waypoints _group,
      waypointType [_group, currentWaypoint _group],
      units _group apply {str round speed _x + " km/h"}
    ];
  }];

  // Remove the hint whenever the mouse is leaving the icon area (2D/3D)
  addMissionEventHandler ["GroupIconOverLeave",
  {
    hintSilent "";
  }];

  // Toggle group's waypoints whenever clicking on an icon
  addMissionEventHandler ["GroupIconClick",
  {
    params
    [
      "_is3D", "_group", "_waypointId",
      "_mouseButton", "_posX", "_posY",
      "_shift", "_control", "_alt"
    ];

    if (!_shift && !_control && !_alt) then
    {
      allMapMarkers select {"ENH_debugWaypoints" in _x} apply {deleteMarker _x};
      if (missionNamespace getVariable ["ENH_debugWaypoints_CurrentGroup", groupNull] isEqualTo _group) exitWith {ENH_debugWaypoints_CurrentGroup = groupNull};

      private _path = [getPosATL leader _group select 0, getPosATL leader _group select 1];
      private _markerText = "";
      {
        _x params ["_group", "_wpIndex"];
        private _marker = createMarkerLocal
        [
          format ["ENH_debugWaypoints_%1_%2", _group, _wpIndex],
          waypointPosition _x
        ];
        _marker setMarkerTextLocal waypointType [_group, _wpIndex];
        _marker setMarkerShapeLocal "ICON";
        _marker setMarkerTypeLocal "mil_dot";
        _marker setMarkerShadowLocal true;

        _path append [waypointPosition _x select 0, waypointPosition _x select 1];
      } forEach waypoints _group;

      // Create poly markers
      if (count _path < 4) then {continue};
      private _markerPoly = createMarkerLocal [format ["ENH_debugWaypoints_poly_%1", str leader _group], leader _group];
      _markerPoly setMarkerShapeLocal "polyline";
      _markerPoly setMarkerColorLocal _color;
      _markerPoly setMarkerPolylineLocal _path;
      ENH_debugWaypoints_CurrentGroup = _group;
    };
    if (!_shift && _control && !_alt) then
    {
      units _group apply {deleteVehicle _x};
      deleteGroup _group;
    };
  }];
};

if GETVALUE("DeleteCorpse") then
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

if GETVALUE("NoRecoil") then
{
  player setUnitRecoilCoefficient 0;
};

if GETVALUE("NoSway") then
{
  player setCustomAimCoef 0;
};

if GETVALUE("NoReload") then
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

if GETVALUE("DrawViewDirection") then
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

if GETVALUE("Teleport") then
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

if GETVALUE("SkipTime") then
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

if GETVALUE("TimeMultiplier") then
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

if GETVALUE("VariableViewer") then
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

if GETVALUE("ActiveScripts") then
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

if (GETVALUE("DebugPath") > 0) then
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

if GETVALUE("DrawTriggers") then
{
  // Might want to also draw them in 2D/3D, but currently, getting all trigger objects in a scenario on each frame is super slow
  //https://discord.com/channels/105462288051380224/108187245529268224/1013445559211794513
  /* {
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
  } forEach (allMissionObjects "EmptyDetector"); */
  ENH_DebugOptions_DrawTriggers_CursorPosition = [0, 0, 0];
  {
    findDisplay 12 displayCtrl 51 ctrlAddEventHandler ["Draw",
    {
      params ["_ctrlMap"];
      private _trigger = _x;
      triggerArea _trigger params ["_a", "_b", "_angle", "_isRectangle"];

      if (!_isRectangle) then
      {
        _ctrlMap drawEllipse [_trigger, _a, _b, _angle, [0, 0, 0, 1], "#(rgb,8,8,3)color(0.3,0.3,0.3,0.3)"];
      }
      else
      {
        _ctrlMap drawRectangle [_trigger, _a, _b, _angle, [0, 0, 0, 1], "#(rgb,8,8,3)color(0.3,0.3,0.3,0.3)"];
      };

      if (ENH_DebugOptions_DrawTriggers_CursorPosition inArea _trigger) then
      {
        if (vehicleVarName _trigger != "") then
        {
          ENH_DebugOptions_DrawTriggers_HintText = "<t size='1.3' align='center'>Trigger Information</t><br/>
<t align='left'>Name:<t/><t align='right'>%1</t><br/>
<t align='left'>Text:<t/><t align='right'>%2</t><br/>
<t align='left'>Type:<t/><t align='right'>%3</t><br/>
<t align='left'>Activated:<t/><t align='right'>%4</t><br/>
<t align='left'>Interval:<t/><t align='right'>%5</t><br/>

<t size='1.3' align='center'>Statements</t><br/>

<t align='left'>Condition:<t/><t align='right'>%6</t><br/>
<t align='left'>On Activation:<t/><t align='right'>%7</t><br/>
<t align='left'>On Deactivation:<t/><t align='right'>%8</t><br/>

<t size='1.3' align='center'>Activation</t><br/>

<t align='left'>By:<t/><t align='right'>%9</t><br/>
<t align='left'>Type:<t/><t align='right'>%10</t><br/>
<t align='left'>Repeatable:<t/><t align='right'>%11</t><br/>

<t size='1.3' align='center'>Transformation</t><br/>

<t align='left'>Position:<t/><t align='right'>%12</t><br/>
<t align='left'>A:<t/><t align='right'>%13</t><br/>
<t align='left'>B:<t/><t align='right'>%14</t><br/>
<t align='left'>Angle:<t/><t align='right'>%15</t><br/>
<t align='left'>Is Rectangle:<t/><t align='right'>%16</t><br/>
<t align='left'>C (Height):<t/><t align='right'>%17</t><br/>

<t size='1.3' align='center'>Timer</t><br/>

<t align='left'>Timer Values:<t/><t align='right'>%18</t><br/>
<t align='left'>Is Countdown:<t/><t align='right'>%19</t><br/>
<t align='left'>Current Timeout:<t/><t align='right'>%20</t><br/>

<t size='1.3' align='center'>Special</t><br/>

<t align='left'>Attached Vehicle/Object:<t/><t align='right'>%21</t><br/>
<t align='left'>List:<t/><t align='right'>%22</t><br/>";

          hintSilent parseText format
          [
            ENH_DebugOptions_DrawTriggers_HintText,
            vehicleVarName _trigger,
            triggerText _trigger,
            triggerType _trigger,
            triggerActivated _trigger,
            triggerInterval _trigger,
            triggerStatements _trigger select 0,
            triggerStatements _trigger select 1,
            triggerStatements _trigger select 2,
            triggerActivation _trigger select 0,
            triggerActivation _trigger select 1,
            triggerActivation _trigger select 2,
            getPosWorld _trigger,
            triggerArea _trigger select 0,
            triggerArea _trigger select 1,
            triggerArea _trigger select 2,
            triggerArea _trigger select 3,
            triggerArea _trigger select 4,
            [triggerTimeout _trigger select 0, triggerTimeout _trigger select 1, triggerTimeout _trigger select 2],
            triggerTimeout _trigger select 3,
            triggerTimeoutCurrent _trigger,
            triggerAttachedVehicle _trigger,
            list _trigger
          ];
        }
        else
        {
          hintSilent "No variable name was given to this trigger. Detailed information are not available.";
        };
      };
    }];
  } forEach (8 allObjects 7); // All triggers

  findDisplay 12 displayCtrl 51 ctrlAddEventHandler ["mouseMoving",
  {
    params ["_ctrlMap", "_xPos", "_yPos"];

    ENH_DebugOptions_DrawTriggers_CursorPosition = _ctrlMap posScreenToWorld [_xPos, _yPos];
  }];
};

if (GETVALUE("DynSimDebug") && dynamicSimulationSystemEnabled) then
{
  #define UNITS_ENABLED {simulationEnabled _x && dynamicSimulationEnabled group _x} count allUnits
  #define ALL_UNITS {dynamicSimulationEnabled group _x} count allUnits
  #define GROUPS_ENABLED {simulationEnabled leader _x && dynamicSimulationEnabled _x} count allGroups
  #define OBJECTS_ENABLED {simulationEnabled _x} count vehicles
  #define ALL_OBJECTS count vehicles
  #define ALL_GROUPS {dynamicSimulationEnabled _x} count allGroups
  #define CAN_TRIGGER_UNITS {canTriggerDynamicSimulation _x} count allUnits
  #define CAN_TRIGGER_VEHICLES {canTriggerDynamicSimulation _x} count vehicles

  #define DISTANCE_GROUPS_UNITS dynamicSimulationDistance "Group"
  #define DISTANCE_VEHICLES dynamicSimulationDistance "Vehicle"
  #define DISTANCE_EMPTY_VEHICLES dynamicSimulationDistance "EmptyVehicle"
  #define DISTANCE_PROPS dynamicSimulationDistance "Prop"
  #define DISTANCE_COEF dynamicSimulationDistanceCoef "IsMoving"
  #define DISTANCE_GROUPS_UNITS dynamicSimulationDistance "Group"
  #define DISTANCE_VEHICLES dynamicSimulationDistance "Vehicle"
  #define DISTANCE_EMPTY_VEHICLES dynamicSimulationDistance "EmptyVehicle"
  #define DISTANCE_PROPS dynamicSimulationDistance "Prop"
  #define DISTANCE_COEF dynamicSimulationDistanceCoef "IsMoving"

  ENH_dynSimDebug_Text = "<t size='1.5' align='left'>Dynamic Simulation Stats</t>   <br/><br/>

<t size='1.3' align='left'>Enabled/Disabled Entities</t>   <br/>

<t align='left'>Enabled Units:<t/>              <t align='right'>%1 / %2</t>        <br/>
<t align='left'>Enabled Groups:<t/>             <t align='right'>%3 / %4</t>        <br/>
<t align='left'>Enabled Objects/Vehicles:<t/>   <t align='right'>%5 / %6</t>        <br/><br/>

<t size='1.3' align='left'>Can Trigger Dyn. Simulation</t><br/>

<t align='left'>No. of units:<t/>               <t align='right'>%7</t>             <br/>
<t align='left'>No. of vehicles:<t/>            <t align='right'>%8</t>             <br/><br/>

<t size='1.3' align='left'>Settings</t>                                           <br/>

<t align='left'>Distance (Units/Groups):<t/>    <t align='right' color='#FFFF00'>%9 m</t>           <br/>
<t align='left'>Distance (Vehicles):<t/>        <t align='right' color='#00FF00'>%10 m</t>           <br/>
<t align='left'>Distance (Empty Vehicles):<t/>  <t align='right' color='#00FFFF'>%11 m</t>           <br/>
<t align='left'>Distance (Props):<t/>           <t align='right' color='#FF00FF'>%12 m</t>           <br/>
<t align='left'>Distance Coef. (isMoving):<t/>  <t align='right'>x%13</t>           <br/>
<t align='left'>View Distance:<t/>              <t align='right' color='#FF0000'>%14 m</t>          <br/>
<t align='left'>View Distance too large:<t/>    <t align='right'>%15</t><br/>
<t align='left'>Recommended View Distance:<t/>  <t align='right'>~%16 m</t>";

  ENH_dynSimDebug_markerUnitsArray = [];

  {
    _marker = "ENH_dynSimDebugMarker_" + str _forEachIndex;
    _marker = createMarker [_marker, getPosWorld _x];

    _marker setMarkerType "mil_box";
    _marker setMarkerText configName configOf _x;
    _marker setMarkerColor ([side _x, true] call BIS_fnc_sideColor);

    ENH_dynSimDebug_markerUnitsArray pushBack [_marker, _x];
  } forEach vehicles + allUnits;

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
      OBJECTS_ENABLED,
      ALL_OBJECTS,
      CAN_TRIGGER_UNITS,
      CAN_TRIGGER_VEHICLES,
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
    {
      _ctrlMap drawEllipse [_x, DISTANCE_GROUPS_UNITS, DISTANCE_GROUPS_UNITS, 0, [1, 1, 0, 1], ""];//Groups and Units
      _ctrlMap drawEllipse [_x, DISTANCE_VEHICLES, DISTANCE_VEHICLES, 0, [0, 1, 0, 1], ""];//Vehicles
      _ctrlMap drawEllipse [_x, DISTANCE_EMPTY_VEHICLES, DISTANCE_EMPTY_VEHICLES, 0, [0, 1, 1, 1], ""];//Empty Vehicles
      _ctrlMap drawEllipse [_x, DISTANCE_PROPS, DISTANCE_PROPS, 0, [1, 0, 1, 1], ""];//Props
      _ctrlMap drawEllipse [_x, viewDistance, viewDistance, 0, [1, 0, 0, 1], ""];//Props
    } forEach (allUnits select {canTriggerDynamicSimulation _x});
  }];
};