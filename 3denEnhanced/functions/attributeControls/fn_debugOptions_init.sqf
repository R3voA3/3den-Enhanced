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

//To prevent issues in multiplayer games started from multiplayer editor
if (!is3DENPreview || isMultiplayer) exitWith {};

//Start the script later. Sometimes player unit is changed when "Play the Character" is selected from the context menu a bit later
sleep 0.5;

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

if GETVALUE("ShowUnits") then
{
  [] spawn
  {
    #define TO_PERCENT_ROUND(VALUE) round ((VALUE) * 100)
    private _markerUnitsArray = [];

    {
      private _sideColour = [side _x, true] call BIS_fnc_sideColor;
      private _displayName = getText (configfile >> 'CfgVehicles' >> (typeOf _x) >> 'displayName');

      _name = "ENH_previewMarker_" + str _forEachIndex;
      _name = createMarker [_name, position _x];
      _name setMarkerType 'mil_box';
      _name setMarkerText _displayName;
      _name setMarkerColor _sideColour;

      _markerUnitsArray pushBack [_name, _x, _displayName],;
    } forEach entities [["AllVehicles"], [], false, true];//All vehicles without crew and dead entities

    while {true} do
    {
      waitUntil{sleep 0.2; visibleMap};//Only updated markers when visible
      {
        sleep 0.05;//A bit more performance friendly
        _x params ["_marker", "_entity"];
        _displayName = _x # 2 + " " + str TO_PERCENT_ROUND(1 - damage _entity) + "%";//Add health of unit to marker name in %
        _marker setMarkerText _displayName;
        _marker setMarkerPos getPos _entity;
      } forEach _markerUnitsArray;//[markerName, entity, displayName]
    };
  };
};

if GETVALUE("BulletTracking") then
{
  [player] spawn BIS_fnc_traceBullets;
};

if GETVALUE("Zeus") then
{
  [] spawn
  {
    //waitUntil {!isNull player};
    private _zeusModule = (creategroup sideLogic) createUnit ["ModuleCurator_F", [0, 0, 0], [], 10, "NONE"];
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
      sleep 1;
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

if GETVALUE("KILLINDFOR") then
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

if GETVALUE("KillCurser") then
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

if GETVALUE("DrawIcons") then
{
  ENH_DebugOptions_CfgVehicles = configFile >> "CfgVehicles";
  ["ENH_EH_DrawUnitInfo_ID", "onEachFrame",
    {
      {
        drawIcon3D
        [
          "",/* getText (ENH_DebugOptions_CfgVehicles >> typeOf _x >> "icon"), */
          (side _x call BIS_fnc_sideColor),
          _x modelToWorldVisual [0, 0, 0],
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
      } count ((ASLToAGL getPosASL player nearEntities [["CAManBase", "Air", "Car", "Tank"], RADIUS]) - [player]);
    }
  ] call BIS_fnc_addStackedEventHandler;
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

if GETVALUE("ShowWaypoints") then
{
  _markerColors = "true" configClasses (configFile >> "CfgMarkerColors") apply {configName _x};
  private _color = "";

  private _waypoints = [];
  {
    _color = selectRandom _markerColors;
    {
      _x params ["_group", "_wpIndex"];

      _marker = createMarker
      [
        format ["ENH_debugWaypoints_%1_%2", _group, _wpIndex],
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
    "Log active Scripts",
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",
    "true",
    "true",
    {call ENH_fnc_activeScripts},
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
  {
    private _target = leader _x;
    if (expectedDestination _target # 1 != "DoNotPlan" && alive _target) then
    {
      _target spawn
      {
        scriptName 'ENH_Attribute_DebugPath';
        private _arrow = objNull;
        private _arrowColour = format ['#(rgb,8,8,3)color(%1,%2,%3,1)', random(1), random(1), random(1)];
        private _path = [];
        private _marker = createMarker [format ['ENH_DebugPath_%1', str _this], _this];
        _marker setMarkerShape "polyline";
        _marker setMarkerColor configName selectRandom ("true" configClasses (configFile >> "CfgMarkerColors"));

        private _posOld = getPos _this;

        while {alive _this} do
        {
          if ((_this distance _posOld) > 20) then
          {
            if (GETVALUE("DebugPath") > 1) then
            {
              _arrow = createVehicle ['Sign_Arrow_Direction_Blue_F', position _this, [], 0, 'CAN_COLLIDE'];
              _arrow setObjectTexture [0, _arrowColour];
              sleep 0.1;
              _arrow setDir (_arrow getDir _this);
            };
          _path append [getPos _this # 0, getPos _this # 1];
          _posOld = getPos _this;
          if (count _path > 3) then {_marker setMarkerPolyline _path};
          if (count _path == 500) then {_path deleteRange [0, 2]};
          sleep 0.1;
          };
        };
      };
    };
  } forEach allGroups;
};