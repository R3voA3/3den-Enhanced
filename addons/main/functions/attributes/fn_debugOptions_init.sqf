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

//To prevent issues in multiplayer games started from multiplayer editor
if (!is3DENPreview) exitWith {};

//Small delay to give scenario time to fully initialize
waitUntil {sleep 1; !isNull player};

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
    0 spawn
    {
        private _zeusModule = (createGroup sideLogic) createUnit ["ModuleCurator_F", [0, 0, 0], [], 10, "NONE"];
        player assignCurator _zeusModule;
        //Add Interface EHs (Workaround)
        _zeusModule addCuratorEditableObjects [entities "", true];
        _zeusModule addEventHandler ["CuratorFeedbackMessage", {_this call BIS_fnc_showCuratorFeedbackMessage;}];
        _zeusModule addEventHandler ["CuratorPinged", {_this call BIS_fnc_curatorPinged;}];
        _zeusModule addEventHandler ["CuratorObjectPlaced", {_this call BIS_fnc_curatorObjectPlaced;}];
        _zeusModule addEventHandler ["CuratorObjectEdited", {_this call BIS_fnc_curatorObjectEdited;}];
        _zeusModule addEventHandler ["CuratorWaypointPlaced", {_this call BIS_fnc_curatorWaypointPlaced;}];
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
    0 spawn
    {
        waitUntil {!isNull MISSIONDISPLAY};
        disableSerialization;

        //Make sure that controls are not created twice when restart button is pressed
        if (isNull (MISSIONDISPLAY displayCtrl 992)) then
        {
            private _ctrlFPS = MISSIONDISPLAY ctrlCreate ["RscStructuredText", 992];
            _ctrlFPS ctrlSetPosition
            [
                0.94625 * safeZoneW + safeZoneX,
                0.962 * safeZoneH + safeZoneY,
                0.0525 * safeZoneW,
                0.056 * safeZoneH
            ];
            _ctrlFPS ctrlCommit 0;
        };
        private _ctrlFPS = MISSIONDISPLAY displayCtrl 992;

        while {true} do
        {
            _ctrlFPS ctrlSetStructuredText parseText format
            [
                "<t size='0.6'>FPS(avg.): %1<br/>FPS(min.): %2</t>",
                round diag_fps,
                round diag_fpsMin
            ];
            sleep DELAY;
        };
    };
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
    //Enable icons in 2D and 3D
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

    //Add the icon for all existing groups
    allGroups apply
    {
        _x spawn ENH_debugOptions_showGroups_initGroup;
    };

    //Add the icon whenever a group get's created
    addMissionEventHandler ["GroupCreated",
    {
        params ["_group"];
        _group spawn ENH_debugOptions_showGroups_initGroup;
    }];

    //Show group info when hovering over an icon (2D/3D)
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
            format ["%1 (%2)", groupID _group, if (vehicle leader _group isNotEqualTo leader _group) then {[configFile >> "CfgVehicles" >> typeOf vehicle leader _group ] call BIS_fnc_displayName} else {"-"}],
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

    //Remove the hint whenever the mouse is leaving the icon area (2D/3D)
    addMissionEventHandler ["GroupIconOverLeave",
    {
        hintSilent "";
    }];

    //Toggle group's waypoints whenever clicking on an icon
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

            //Create poly markers
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
                private _arrowColour = format ["#(rgb,8,8,3)color(%1,%2,%3,1)", random(1), random(1), random(1)];
                private _path = [];
                private _marker = createMarkerLocal [format ["ENH_DebugPath_%1", str _leader], _leader];
                _marker setMarkerShapeLocal "polyline";
                _marker setMarkerColorLocal configName selectRandom _cfgMarkerColors;

                private _posOld = getPosWorld _leader;

                while {alive _leader} do
                {
                    if ((_leader distance _posOld) > 50) then
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
    } forEach (8 allObjects 7); //All triggers

    findDisplay 12 displayCtrl 51 ctrlAddEventHandler ["MouseMoving",
    {
        params ["_ctrlMap", "_xPos", "_yPos"];

        ENH_DebugOptions_DrawTriggers_CursorPosition = _ctrlMap posScreenToWorld [_xPos, _yPos];
    }];
};

if (GETVALUE("DynSimDebug") && dynamicSimulationSystemEnabled) then
{
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

    ENH_dynSimDebug_infoTexts =
    [
        [{format ["ENABLED UNITS (DYNAMIC SIMULATION ONLY): %1 / %2", UNITS_ENABLED, ALL_UNITS]}],
        [{format ["ENABLED GROUPS (DYNAMIC SIMULATION ONLY): %1 / %2", GROUPS_ENABLED, ALL_GROUPS]}],
        [{format ["ENABLED VEHICLES (DYNAMIC SIMULATION ONLY): %1 / %2", VEHICLES_ENABLED, ALL_VEHICLES]}],
        [{format ["UNITS THAT CAN TRIGGER SIMULATION: %1", CAN_TRIGGER_UNITS]}],
        [{format ["TRIGGER DISTANCE UNITS AND GROUPS: %1 m", DISTANCE_GROUPS_UNITS]}, [1, 1, 0, 1]],
        [{format ["TRIGGER DISTANCE VEHICLES: %1 m", DISTANCE_VEHICLES]}, [0, 1, 0, 1]],
        [{format ["TRIGGER DISTANCE EMPTY VEHICLES: %1 m", DISTANCE_EMPTY_VEHICLES]}, [0, 1, 1, 1]],
        [{format ["TRIGGER DISTANCE PROPS: %1 m", DISTANCE_PROPS]}, [1, 0, 1, 1]],
        [{format ["DISTANCE COEFICIENT: x%1", DISTANCE_COEF]}],
        [{format ["OBJECT VIEW DISTANCE: %1 m", OBJ_VIEW_DISTANCE]}, [1, 0, 0, 1]],
        [{format ["RECOMMENDED OBJECT VIEW DISTANCE: %1 m", selectMax [DISTANCE_GROUPS_UNITS * DISTANCE_COEF, DISTANCE_VEHICLES * DISTANCE_COEF, DISTANCE_EMPTY_VEHICLES, DISTANCE_PROPS] * 0.8]}],
        [{"VISIT ""https://community.bistudio.com/wiki/Arma_3:_Dynamic_Simulation"" FOR MORE INFORMATION."}]
    ];

    findDisplay 12 displayCtrl 51 ctrlAddEventHandler ["Draw",
    {
        params ["_ctrlMap"];

        {
            if (_x isKindOf "CAManBase" && {canTriggerDynamicSimulation _x}) then
            {
                _ctrlMap drawEllipse [_x, DISTANCE_GROUPS_UNITS, DISTANCE_GROUPS_UNITS, 0, [1, 1, 0, 1], ""];//Groups and Units
                _ctrlMap drawEllipse [_x, DISTANCE_VEHICLES, DISTANCE_VEHICLES, 0, [0, 1, 0, 1], ""];//Vehicles
                _ctrlMap drawEllipse [_x, DISTANCE_EMPTY_VEHICLES, DISTANCE_EMPTY_VEHICLES, 0, [0, 1, 1, 1], ""];//Empty Vehicles
                _ctrlMap drawEllipse [_x, DISTANCE_PROPS, DISTANCE_PROPS, 0, [1, 0, 1, 1], ""];//Props
                _ctrlMap drawEllipse [_x, OBJ_VIEW_DISTANCE, OBJ_VIEW_DISTANCE, 0, [1, 0, 0, 1], ""];//Props
            };

            if (dynamicSimulationEnabled _x || {dynamicSimulationEnabled group _x}) then
            {
                //Crew members inherit simulation from vehicle
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

        //Update stats markers
        private _startY = worldSize;

        {
            _x params [["_textCode", {}], ["_textColor", [1, 1, 1, 1]]];
            _ctrlMap drawIcon
            [
                "\A3\ui_f\data\map\markers\military\box_CA.paa",
                _textColor,
                [worldSize + 100, _startY, 0],
                15,
                15,
                0,
                call _textCode,
                2
            ];
            _startY = _startY - 100;
        } forEach ENH_dynSimDebug_infoTexts;
    }];
};

diag_log "3den Enhanced: Debug Options initialized.";