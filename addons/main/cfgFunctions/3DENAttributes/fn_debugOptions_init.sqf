#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Activates 3den Enhanced debug options according to attribute settings.

    Parameter(s):
    -

    Returns:
    -
*/

#define GETVALUE(ATTRIBUTE) (profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_' + ATTRIBUTE, "Preferences" get3DENMissionAttribute ("ENH_DebugOptions_" + ATTRIBUTE)])
#define MISSIONDISPLAY (call BIS_fnc_displayMission)
#define RADIUS 150
#define DELAY 0.1
#define HINT_REFRESH_INTERVAL 30
#define COLOR_TRIGGER 0.1, 0.1, 0.9, 1

#define UNITS_ENABLED ({simulationEnabled _x && dynamicSimulationEnabled group _x} count allUnits)
#define ALL_UNITS ({dynamicSimulationEnabled group _x} count allUnits)
#define GROUPS_ENABLED ({simulationEnabled leader _x && dynamicSimulationEnabled _x} count allGroups)
#define VEHICLES_ENABLED ({simulationEnabled _x && dynamicSimulationEnabled _x} count vehicles)
#define ALL_VEHICLES ({dynamicSimulationEnabled _x} count vehicles)
#define ALL_GROUPS ({dynamicSimulationEnabled _x} count allGroups)
#define CAN_TRIGGER_UNITS ({canTriggerDynamicSimulation _x} count allUnits)

#define DISTANCE_GROUPS_UNITS (dynamicSimulationDistance "Group")
#define DISTANCE_VEHICLES (dynamicSimulationDistance "Vehicle")
#define DISTANCE_EMPTY_VEHICLES (dynamicSimulationDistance "EmptyVehicle")
#define DISTANCE_PROPS (dynamicSimulationDistance "Prop")
#define DISTANCE_COEF (dynamicSimulationDistanceCoef "IsMoving")
#define OBJ_VIEW_DISTANCE (round (getObjectViewDistance select 0))

#define HINT_TEXT_TRIGGER\
"<t size='1.1' align='center'>Trigger Information</t><br/>\
<t align='left'>Name:<t/><t align='right'>%1</t><br/>\
<t align='left'>Text:<t/><t align='right'>%2</t><br/>\
<t align='left'>Type:<t/><t align='right'>%3</t><br/>\
<t align='left'>Activated:<t/><t align='right'>%4</t><br/>\
<t align='left'>Interval:<t/><t align='right'>%5</t><br/>\
\
<t size='1.3' align='center'>Statements</t><br/>\
\
<t align='left'>Condition:<t/><t align='right'>%6</t><br/>\
<t align='left'>On Activation:<t/><t align='right'>%7</t><br/>\
<t align='left'>On Deactivation:<t/><t align='right'>%8</t><br/>\
\
<t size='1.1' align='center'>Activation</t><br/>\
\
<t align='left'>By:<t/><t align='right'>%9</t><br/>\
<t align='left'>Type:<t/><t align='right'>%10</t><br/>\
<t align='left'>Repeatable:<t/><t align='right'>%11</t><br/>\
\
<t size='1.1' align='center'>Transformation</t><br/>\
\
<t align='left'>Position:<t/><t align='right'>%12</t><br/>\
<t align='left'>A:<t/><t align='right'>%13</t><br/>\
<t align='left'>B:<t/><t align='right'>%14</t><br/>\
<t align='left'>Angle:<t/><t align='right'>%15</t><br/>\
<t align='left'>Is Rectangle:<t/><t align='right'>%16</t><br/>\
<t align='left'>C (Height):<t/><t align='right'>%17</t><br/>\
\
<t size='1.1' align='center'>Timer</t><br/>\
\
<t align='left'>Timer Values:<t/><t align='right'>%18</t><br/>\
<t align='left'>Is Countdown:<t/><t align='right'>%19</t><br/>\
<t align='left'>Current Timeout:<t/><t align='right'>%20</t><br/>\
\
<t size='1.1' align='center'>Special</t><br/>\
\
<t align='left'>Attached Vehicle/Object:<t/><t align='right'>%21</t><br/>\
<t align='left'>List:<t/><t align='right'>%22</t><br/>"

#define HINT_TEXT_GROUP\
"<t size='1.1' align='center'>Group Information</t><br/>\
<t align='left'>Callsign:<t/><t align='right'>%1</t><br/>\
<t align='left'>Leader:<t/><t align='right'>%2</t><br/>\
<t align='left'>No. of Units:<t/><t align='right'>%3</t><br/>\
<t align='left'>Delete when Empty:<t/><t align='right'>%4</t><br/>\
\
<t size='1.1' align='center'>Group Status</t><br/>\
\
<t align='left'>Health:<t/><t align='right'>%5</t><br/>\
<t align='left'>Fleeing:<t/><t align='right'>%6</t><br/>\
<t align='left'>Attack Enabled:<t/><t align='right'>%7</t><br/>\
<t align='left'>Combat Behaviour:<t/><t align='right'>%8</t><br/>\
<t align='left'>Combat Mode:<t/><t align='right'>%9</t><br/>\
<t align='left'>Formation:<t/><t align='right'>%10</t><br/>\
<t align='left'>Speed:<t/><t align='right'>%11</t><br/>\
\
<t size='1.1' align='center'>Waypoints</t><br/>\
\
<t align='left'>No. of Waypoints:<t/><t align='right'>%12</t><br/>\
<t align='left'>Current Waypoint:<t/><t align='right'>%13</t><br/>\
<t align='left'>Unit Speed:<t/><t align='right'>%14</t><br/>\
\
<t size='1.1' align='center'>Additional Options</t><br/>\
\
<t align='left'>Show Waypoints:<t/><t align='right'>LEFT CLICK</t><br/>\
<t align='left'>Delete Group:<t/><t align='right'>CTRL + LEFT CLICK</t><br/>"

#define HINT_TEXT_FPS\
"<t size='1.1' align='center'>FPS</t><br/>\
<t align='left'>AVG:<t/><t align='right'>%1</t><br/>\
<t align='left'>MIN:<t/><t align='right'>%2</t><br/>"

#define HINT_TEXT_SIMULATION\
"<t size='1.1' align='center'>Dynamic Simulation Information</t><br/>\
<t align='left' color='#ffffff'>Enabled Units (DS):<t/><t align='right'>%1/%2</t><br/>\
<t align='left' color='#ffffff'>Enabled Groups (DS):<t/><t align='right'>%3/%4</t><br/>\
<t align='left' color='#ffffff'>Enabled Vehicles (DS)<t/><t align='right'>%5/%6</t><br/>\
<t align='left' color='#ffffff'>Units that can Trigger DS:<t/><t align='right'>%7</t><br/>\
<t align='left' color='#ffff00'>Trigger Distance Units/groups:<t/><t align='right'>%8 m</t><br/>\
<t align='left' color='#00FF00'>Trigger Distance Vehicles:<t/><t align='right'>%9 m</t><br/>\
<t align='left' color='#00ffff'>Trigger Distance Empty vehicles:<t/><t align='right'>%10 m</t><br/>\
<t align='left' color='#ff00ff'>Trigger Distance Props:<t/><t align='right'>%11 m</t><br/>\
<t align='left' color='#ffffff'>Distance Coef.:<t/><t align='right'>%12x</t><br/>\
<t align='left' color='#ff0000'>Object View Distance:<t/><t align='right'>%13 m</t><br/>\
<t align='left' color='#ffffff'>Recommended Object View Distance:<t/><t align='right'>%14 m</t><br/>"

if (!is3DENPreview) exitWith {};

// Small delay to give scenario time to fully initialize
waitUntil {sleep 1; !isNull player};

// Handle hint drawing with debug information
ENH_DebugOptions_HintContent = createHashMap;

addMissionEventHandler ["EachFrame",
{
    hintSilent parseText (values ENH_DebugOptions_HintContent joinString "<br/><br/>");
}];

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
        localize "STR_ENH_MAIN_DEBUGOPTIONS_GARAGE_DISPLAYNAME",
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
    spawn
    {
        private _zeusModule = (createGroup sideLogic) createUnit ["ModuleCurator_F", [0, 0, 0], [], 10, "NONE"];
        player assignCurator _zeusModule;
        // Add Interface EHs (Workaround)
        _zeusModule addCuratorEditableObjects [entities "", true];
        _zeusModule addEventHandler ["CuratorFeedbackMessage", {call BIS_fnc_showCuratorFeedbackMessage;}];
        _zeusModule addEventHandler ["CuratorPinged", {call BIS_fnc_curatorPinged;}];
        _zeusModule addEventHandler ["CuratorObjectPlaced", {call BIS_fnc_curatorObjectPlaced;}];
        _zeusModule addEventHandler ["CuratorObjectEdited", {call BIS_fnc_curatorObjectEdited;}];
        _zeusModule addEventHandler ["CuratorWaypointPlaced", {call BIS_fnc_curatorWaypointPlaced;}];
        _zeusModule addEventHandler ["CuratorObjectDoubleClicked", {(_this select 1) call BIS_fnc_showCuratorAttributes;}];
        _zeusModule addEventHandler ["CuratorGroupDoubleClicked", {(_this select 1) call BIS_fnc_showCuratorAttributes;}];
        _zeusModule addEventHandler ["CuratorWaypointDoubleClicked", {(_this select 1) call BIS_fnc_showCuratorAttributes;}];
        _zeusModule addEventHandler ["CuratorMarkerDoubleClicked", {(_this select 1) call BIS_fnc_showCuratorAttributes;}];
    };
};

if GETVALUE("Invulnerability") then
{
    {
        _x allowDamage false;
    } forEach units player;

    (objectParent player) allowDamage false;
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
    addMissionEventHandler ["EachFrame",
    {
        private _debugText = format
        [
            HINT_TEXT_FPS,
            round diag_fps,
            round diag_fpsMin
        ];

        ENH_DebugOptions_HintContent set ["FPS", _debugText];
    }];
};

if GETVALUE("KillBLUFOR") then
{
    [
        player,
        localize "STR_ENH_MAIN_DEBUGOPTIONS_KILLBLUFOR_DISPLAYNAME",
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
        localize "STR_ENH_MAIN_DEBUGOPTIONS_KILLOPFOR_DISPLAYNAME",
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

if GETVALUE("KillIndependent") then
{
    [
        player,
        localize "STR_ENH_MAIN_DEBUGOPTIONS_KILLINDEPENDENT_DISPLAYNAME",
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

if GETVALUE("KillCivilian") then
{
    [
        player,
        localize "STR_ENH_MAIN_DEBUGOPTIONS_KILLCIVILIAN_DISPLAYNAME",
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
        localize "STR_ENH_MAIN_DEBUGOPTIONS_KILLCURSOR_DISPLAYNAME",
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
        private _text = format
        [
            HINT_TEXT_GROUP,
            format ["%1 (%2)", groupID _group, if (objectParent leader _group isNotEqualTo leader _group) then {[configOf (objectParent leader _group)] call BIS_fnc_displayName} else {"-"}],
            name leader _group,
            count units _group,
            isGroupDeletedWhenEmpty _group,
            units _group apply {str round ((1 - damage _x)* 100) + " %"},
            fleeing leader _group,
            attackEnabled _group,
            combatBehaviour _group,
            combatMode _group,
            formation _group,
            speedMode _group,
            count waypoints _group,
            waypointType [_group, currentWaypoint _group],
            units _group apply {str round speed _x + " km/h"}
        ];

        ENH_DebugOptions_HintContent set ["ShowGroups", _text];
    }];

    // Remove the hint whenever the mouse is leaving the icon area (2D/3D)
    addMissionEventHandler ["GroupIconOverLeave",
    {
        ENH_DebugOptions_HintContent deleteAt "ShowGroups";
    }];

    // Toggle group's waypoints whenever clicking on an icon
    addMissionEventHandler ["GroupIconClick",
    {
        params
        [
            "", "_group", "",
            "", "", "",
            "_shift", "_control", "_alt"
        ];

        if (!_shift && !_control && !_alt) then
        {
            allMapMarkers select {"ENH_debugWaypoints" in _x} apply {deleteMarker _x};
            if (missionNamespace getVariable ["ENH_debugWaypoints_CurrentGroup", groupNull] isEqualTo _group) exitWith {ENH_debugWaypoints_CurrentGroup = groupNull};

            private _path = [getPosATL leader _group select 0, getPosATL leader _group select 1];
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
    localize "STR_ENH_MAIN_DEBUGOPTIONS_DELETECORPSE_DISPLAYNAME",
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
    addMissionEventHandler ["EachFrame",
    {
        ((player nearEntities [["CAManBase"], RADIUS]) - [player]) apply
        {
            private _beg = ASLToAGL eyePos _x;
            drawLine3D [_beg, (_beg vectorAdd (eyeDirection _x vectorMultiply 1)), [0, 1, 0, 1]];
            drawLine3D [_beg, (_beg vectorAdd (_x weaponDirection currentWeapon _x vectorMultiply 1)), [1, 0, 0, 1]];
            false;
        };
    }];
};

if GETVALUE("Teleport") then
{
    [
        player,
        localize "STR_ENH_MAIN_DEBUGOPTIONS_TELEPORT",
        "\a3\Modules_F_Curator\Data\portraitLightning_ca.paa",
        "\a3\Modules_F_Curator\Data\portraitLightning_ca.paa",
        "true",
        "true",
        {},
        {},
        {player setPos screenToWorld [CENTER_X, 0.6]}, // Center of action icon
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
        localize "STR_ENH_MAIN_DEBUGOPTIONS_SKIPTIME",
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
        localize "STR_ENH_MAIN_DEBUGOPTIONS_TIMEMULTIPLIER",
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
        localize "STR_ENH_MAIN_VARIABLEVIEWER_HEADER",
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
        localize "STR_ENH_MAIN_DEBUGOPTIONS_LOGSCRIPTS_DISPLAYNAME",
        "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",
        "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",
        "true",
        "true",
        {
            private _export = "------------------------------------------------ACTIVE SQF SCRIPTS------------------------------------------------" + endl;

            {
                _x params ["_scriptName", "_fileName", "_isRunning", "_currentLine"];
                _export = _export + _scriptName + " - ";
                _export = _export + _fileName + " - ";
                _export = _export + str _isRunning + " - ";
                _export = _export + str _currentLine + endl;
            } forEach diag_activeSQFScripts;

            _export = _export + "---------------------------------------------------ACTIVE FSMs----------------------------------------------------" + endl;

            {
                _x params ["_scriptName", "_state", "_timeOut"];
                _export = _export + _scriptName + " - ";
                _export = _export + _state + " - ";
                _export = _export + str _timeOut + endl;
            } forEach diag_activeMissionFSMs;

            _export = _export + "-----------------------------------------------ACTIVE MISSION EHs-------------------------------------------------" + endl;

            private _counts = diag_allMissionEventHandlers select {_x isEqualType 0};
            private _types = diag_allMissionEventHandlers select {_x isEqualType ""};

            {
                if (_x > 0) then
                {
                    _export = _export + format ["%1x %2%3", _x, _types select _forEachIndex, endl];
                };
            } forEach _counts;

            uiNamespace setVariable ["display3DENCopy_data", ["", _export]];
            (call BIS_fnc_displayMission) createDisplay "display3denCopy";
        },
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
        if ((expectedDestination _leader param [1, "DoNotPlan"]) != "DoNotPlan" && alive _leader) then
        {
            [_leader, _cfgMarkerColors, _is3DEnabled] spawn
            {
                scriptName "ENH_Attribute_DebugPath";
                params ["_leader", "_cfgMarkerColors", "_is3DEnabled"];
                private _arrow = objNull;
                private _arrowColor = format ["#(rgb,8,8,3)color(%1,%2,%3,1)", random(1), random(1), random(1)];
                private _path = [];
                private _marker = createMarkerLocal [format ["ENH_DebugPath_%1", str _leader], _leader];
                _marker setMarkerShapeLocal "polyline";
                _marker setMarkerColorLocal configName selectRandom _cfgMarkerColors;

                private _posOld = getPosWorld _leader;

                while {alive _leader} do
                {
                    if ((_leader distance _posOld) > 50) then
                    {
                        if _is3DEnabled then
                        {
                            _arrow = createVehicle ["Sign_Arrow_Direction_Blue_F", position _leader, [], 0, "CAN_COLLIDE"];
                            _arrow setObjectTexture [0, _arrowColor];
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

if (GETVALUE("DrawTriggers") || {GETVALUE("DynSimDebug") && {dynamicSimulationSystemEnabled}}) then
{
    findDisplay IDD_MAIN_MAP displayCtrl IDC_MAP ctrlAddEventHandler ["Draw",
    {
        params ["_ctrlMap"];

        if (GETVALUE("DynSimDebug") && {dynamicSimulationSystemEnabled}) then
        {
            {
                if (_x isKindOf "CAManBase" && {canTriggerDynamicSimulation _x}) then
                {
                    _ctrlMap drawEllipse [_x, DISTANCE_GROUPS_UNITS, DISTANCE_GROUPS_UNITS, 0, [1, 1, 0, 1], ""];// Groups and Units
                    _ctrlMap drawEllipse [_x, DISTANCE_VEHICLES, DISTANCE_VEHICLES, 0, [0, 1, 0, 1], ""];// Vehicles
                    _ctrlMap drawEllipse [_x, DISTANCE_EMPTY_VEHICLES, DISTANCE_EMPTY_VEHICLES, 0, [0, 1, 1, 1], ""];// Empty Vehicles
                    _ctrlMap drawEllipse [_x, DISTANCE_PROPS, DISTANCE_PROPS, 0, [1, 0, 1, 1], ""];// Props
                    _ctrlMap drawEllipse [_x, OBJ_VIEW_DISTANCE, OBJ_VIEW_DISTANCE, 0, [1, 0, 0, 1], ""];// Props
                };

                if (dynamicSimulationEnabled _x || {dynamicSimulationEnabled group _x}) then
                {
                    // Crew members inherit simulation from vehicle
                    if !(isNull objectParent _x) then {continue};

                    if !(_x getVariable ["ENH_DynSim_Registered", false]) then
                    {
                        private _icon = getText (configOf _x >> "icon");

                        if !(fileExists _icon) then
                        {
                            _icon = getText (configFile >> "CfgVehicleIcons" >> _icon);
                        };

                        if !(fileExists _icon) then
                        {
                            _icon = "a3\ui_f\data\map\vehicleicons\iconvehicle_ca.paa";
                        };

                        _x setVariable ["ENH_DynSim_Registered", true];
                        _x setVariable ["ENH_DynSim_ConfigName", configName configOf _x];
                        _x setVariable ["ENH_DynSim_Icon", _icon];
                        _x setVariable ["ENH_DynSim_Color", [side _x] call BIS_fnc_sideColor];
                    };

                    private _color = _x getVariable "ENH_DynSim_Color";
                    _color set [3, [0.5, 1] select (simulationEnabled _x)];

                    _ctrlMap drawIcon
                    [
                        _x getVariable "ENH_DynSim_Icon",
                        _x getVariable "ENH_DynSim_Color",
                        getPosWorldVisual _x,
                        25,
                        25,
                        getDir _x,
                        _x getVariable "ENH_DynSim_ConfigName",
                        2
                    ];
                };
            } forEach vehicles + allUnits;

            private _debugText = format
            [
                HINT_TEXT_SIMULATION,
                UNITS_ENABLED,
                ALL_UNITS,
                GROUPS_ENABLED,
                ALL_GROUPS,
                VEHICLES_ENABLED,
                ALL_VEHICLES,
                CAN_TRIGGER_UNITS,
                DISTANCE_GROUPS_UNITS,
                DISTANCE_VEHICLES,
                DISTANCE_EMPTY_VEHICLES,
                DISTANCE_PROPS,
                DISTANCE_COEF,
                OBJ_VIEW_DISTANCE,
                selectMax [DISTANCE_GROUPS_UNITS * DISTANCE_COEF, DISTANCE_VEHICLES * DISTANCE_COEF, DISTANCE_EMPTY_VEHICLES, DISTANCE_PROPS] * 0.8
            ];

            ENH_DebugOptions_HintContent set ["DynSimDebug", _debugText];
        };

        if GETVALUE("DrawTriggers") then
        {
            private _debugText = "";

            // Draw triggers
            {
                private _trigger = _x;
                triggerArea _trigger params ["_a", "_b", "_angle", "_isRectangle"];

                _ctrlMap drawIcon
                [
                    "a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa",
                    [COLOR_TRIGGER],
                    _trigger,
                    24,
                    24,
                    _angle
                ];

                if (_isRectangle) then
                {
                    _ctrlMap drawRectangle [_trigger, _a, _b, _angle, [COLOR_TRIGGER], ""];
                }
                else
                {
                    _ctrlMap drawEllipse [_trigger, _a, _b, _angle, [COLOR_TRIGGER], ""];
                };

                // Display trigger information when hovering
                private _mousePos = _ctrlMap getVariable ["ENH_MouseWorldPos", [0, 0]];

                if (_mousePos isNotEqualTo [0, 0] && {_mousePos inArea _trigger}) then
                {
                    _debugText = format
                    [
                        HINT_TEXT_TRIGGER,
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
                    ENH_DebugOptions_HintContent set ["DrawTriggers", _debugText];
                };
            } forEach (8 allObjects 7); // All triggers

            // Only delete if mouse is in none of the triggers
            if (_debugText == "") then
            {
                ENH_DebugOptions_HintContent deleteAt "DrawTriggers";
            };
        };
    }];
};

diag_log "3den Enhanced: Debug Options initialized.";
