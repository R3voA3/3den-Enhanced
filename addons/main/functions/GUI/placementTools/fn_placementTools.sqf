#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Initializes the ENH_Pattern GUI.

    Parameter(s):
    -

    Returns:
    -
*/

disableSerialization;

params
[
    ["_display", displayNull],
    ["_mode", "onLoad"],
    ["_params", []]
];

switch _mode do
{
    case "createUI":
    {
        findDisplay IDD_DISPLAY3DEN ctrlCreate ["ENH_PlacementToolsGroup", IDC_PLACEMENTTOOLS];
    };
    case "getCenter":
    {
        if (get3DENActionState "ToggleMap" == 1) then
        {
            (findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_MAP ctrlMapScreenToWorld [CENTER_X, CENTER_Y]) + [0];
        }
        else
        {
            screenToWorld [CENTER_X, CENTER_Y];
        };
    };
    case "onLoad":
    {
        ["ShowPanelLeft", false] call BIS_fnc_3DENInterface;

        addMissionEventHandler ["EachFrame",
        {
            private _placementToolsUI = findDisplay IDD_DISPLAY3DEN displayCtrl IDC_PLACEMENTTOOLS;
            private _leftPanelVisible = profileNamespace getVariable ["display3DEN_panelLeft", true];

            if (isNull _placementToolsUI) exitWith
            {
                removeMissionEventHandler [_thisEvent, _thisEventHandler];
            };

            if _leftPanelVisible then
            {
                _placementToolsUI ctrlSetPositionX (safeZoneX + 61 * GRID_W);
            }
            else
            {
                _placementToolsUI ctrlSetPositionX (safeZoneX + GRID_W);
            };
            _placementToolsUI ctrlCommit 0;
        }];

        // Delete controls when preview is started
        add3DENEventHandler ["OnMissionPreview",
        {
            ctrlDelete (findDisplay IDD_DISPLAY3DEN displayCtrl IDC_PLACEMENTTOOLS);
            remove3DENEventHandler [_thisEvent, _thisEventHandler];
        }];

        if (isNil "ENH_PlacementTools_Settings") then
        {
            ENH_PlacementTools_Settings = createHashMapFromArray
            [
                ["Radius", 50],
                ["InitialAngle", 0],
                ["CentralAngle", 360],
                ["Spacing", 10],
                ["SpacingDirection", 0],
                ["NumColumns", 2],
                ["SpaceX", 2],
                ["SpaceY", 2],
                ["A", 100],
                ["B", 100]
            ];
        };

        // Draw an icon where the center is
        addMissionEventHandler ["Draw3D",
        {
            drawIcon3D ["", [1, 0.1, 1, 1], [nil, "getCenter"] call ENH_fnc_placementTools, 1, 1, 0, "X"];
            findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_MAP drawIcon ["", [1, 0.1, 1, 1], [nil, "getCenter"] call ENH_fnc_placementTools, 1, 1, 0, "X"];

            if (isNull (findDisplay IDD_DISPLAY3DEN displayCtrl IDC_PLACEMENTTOOLS)) exitWith
            {
                removeMissionEventHandler [_thisEvent, _thisEventHandler];
            };
        }];

        {
            _x params ["_idc", "_setting"];
            CTRL_idc ctrlSetText str (ENH_PlacementTools_Settings get _setting);
        } forEach
        [
            [IDC_PLACEMENTTOOLS_RADIUS, "Radius"],
            [IDC_PLACEMENTTOOLS_INITIALANGLE, "InitialAngle"],
            [IDC_PLACEMENTTOOLS_CENTRALANGLE, "CentralAngle"],
            [IDC_PLACEMENTTOOLS_SPACING, "Spacing"],
            [IDC_PLACEMENTTOOLS_SPACINGDIRECTION, "SpacingDirection"],
            [IDC_PLACEMENTTOOLS_NUMCOLUMNS, "NumColumns"],
            [IDC_PLACEMENTTOOLS_SPACEX, "SpaceX"],
            [IDC_PLACEMENTTOOLS_SPACEY, "SpaceY"],
            [IDC_PLACEMENTTOOLS_A, "A"],
            [IDC_PLACEMENTTOOLS_B, "B"]
        ];

        CTRL(IDC_PLACEMENTTOOLS_RADIUS) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            ENH_PlacementTools_Settings set ["Radius", _numericValue];

            [nil, "circular"] call ENH_fnc_placementTools;
        }];

        CTRL(IDC_PLACEMENTTOOLS_INITIALANGLE) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            ENH_PlacementTools_Settings set ["InitialAngle", _numericValue];

            [nil, "circular"] call ENH_fnc_placementTools;
        }];

        CTRL(IDC_PLACEMENTTOOLS_CENTRALANGLE) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            ENH_PlacementTools_Settings set ["CentralAngle", _numericValue];

            [nil, "circular"] call ENH_fnc_placementTools;
        }];

        CTRL(IDC_PLACEMENTTOOLS_SPACING) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            ENH_PlacementTools_Settings set ["Spacing", _numericValue];

            [nil, "line"] call ENH_fnc_placementTools;
        }];

        CTRL(IDC_PLACEMENTTOOLS_SPACINGDIRECTION) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            ENH_PlacementTools_Settings set ["SpacingDirection", _numericValue];

            [nil, "line"] call ENH_fnc_placementTools;
        }];

        CTRL(IDC_PLACEMENTTOOLS_ORIENTATION) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            _numericValue call ENH_fnc_setOrientation;
        }];

        CTRL(IDC_PLACEMENTTOOLS_A) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            ENH_PlacementTools_Settings set ["A", _numericValue];

            [nil, "fill"] call ENH_fnc_placementTools;
        }];

        CTRL(IDC_PLACEMENTTOOLS_B) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            ENH_PlacementTools_Settings set ["B", _numericValue];

            [nil, "fill"] call ENH_fnc_placementTools;
        }];

        CTRL(IDC_PLACEMENTTOOLS_NUMCOLUMNS) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            ENH_PlacementTools_Settings set ["NumColumns", _numericValue];

            [nil, "grid"] call ENH_fnc_placementTools;
        }];

        CTRL(IDC_PLACEMENTTOOLS_SPACEX) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            ENH_PlacementTools_Settings set ["SpaceX", _numericValue];

            [nil, "grid"] call ENH_fnc_placementTools;
        }];

        CTRL(IDC_PLACEMENTTOOLS_SPACEY) ctrlAddEventHandler ["EditChanged",
        {
            params ["", "_input"];
            private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
            ENH_PlacementTools_Settings set ["SpaceY", _numericValue];

            [nil, "grid"] call ENH_fnc_placementTools;
        }];

        CTRL(IDC_PLACEMENTTOOLS_RANDOMORIENTATION) ctrlAddEventHandler ["ButtonClick",
        {
            -1 call ENH_fnc_setOrientation;
        }];

        CTRL(IDC_PLACEMENTTOOLS_REVERSEORIENTATION) ctrlAddEventHandler ["ButtonClick",
        {
            -2 call ENH_fnc_setOrientation;
        }];

        // Add EHs to all edit controls for input modifiers
        {
            _x ctrlAddEventHandler ["KeyDown",
            {
                params ["_ctrlEdit", "_key", "_shift", "_ctrl", "_alt"];

                // PageUp, PageDown
                if !(_key in [201, 209]) exitWith {};

                private _modifier = call
                {
                    if (_ctrl && _shift) exitWith {0.001};
                    if (_ctrl && _alt) exitWith {0.01};
                    if _ctrl exitWith {0.1};
                    1
                };

                _modifier = if (_key == 209) then {_modifier * -1} else {_modifier};

                private _numericValue = [nil, "strToNum", [ctrlText _ctrlEdit]] call ENH_fnc_placementTools;

                _ctrlEdit ctrlSetText str (_numericValue + _modifier);
            }];

            _x ctrlSetTooltip "PAGE UP/DOWN: +-1\nPAGE UP/DOWN + CTRL: +-0.1\nPAGE UP/DOWN + CTRL + ALT: +-0.01\nPAGE UP/DOWN + CTRL + ALT + SHIFT: +-0.001";
        } forEach (allControls _display select {ctrlType _x == 2});
    };
    case "onUnload":
    {
        ["ShowPanelLeft", true] call BIS_fnc_3DENInterface;

        if (!isNil "ENH_PlacementTools_AreaTrigger") then
        {
            delete3DENEntities [ENH_PlacementTools_AreaTrigger];
        };
    };
    case "line":
    {
        private _newPos = [nil, "getCenter"] call ENH_fnc_placementTools;
        collect3DENHistory
        {
            {
                _x set3DENAttribute ["Position", _newPos];
                _newPos = _newPos getPos
                [
                    ENH_PlacementTools_Settings get "Spacing",
                    ENH_PlacementTools_Settings get "SpacingDirection"
                ];
            } forEach ([["Object", "Logic", "Trigger", "Marker"]] call ENH_fnc_all3DENSelected);
        };
    };
    case "circular":
    {
        private _radius = ENH_PlacementTools_Settings get "Radius";
        private _initialAngle = ENH_PlacementTools_Settings get "InitialAngle";
        private _centralAngle = ENH_PlacementTools_Settings get "CentralAngle";
        private _angleStep = _centralAngle / (count ([["Object", "Logic", "Trigger", "Marker"]] call ENH_fnc_all3DENSelected) max 1);
        private _center = [nil, "getCenter"] call ENH_fnc_placementTools;

        private _angle = _initialAngle;

        collect3DENHistory
        {
            {
                _pos = _center getPos [_radius, _angle];
                _x set3DENAttribute ["Position", _pos];
                _x set3DENAttribute ["Rotation", [0, 0, _angle]];
                _angle = _angle + _angleStep;
            } forEach ([["Object", "Logic", "Trigger", "Marker"]] call ENH_fnc_all3DENSelected);
        };
    };
    case "fill":
    {
        if (isNil "ENH_PlacementTools_AreaTrigger") then
        {
            ENH_PlacementTools_AreaTrigger = create3DENEntity ["Trigger", "EmptyDetectorArea10x10", [nil, "getCenter"] call ENH_fnc_placementTools];
        };

        private _A = ENH_PlacementTools_Settings get "A";
        private _B = ENH_PlacementTools_Settings get "B";

        ENH_PlacementTools_AreaTrigger set3DENAttribute ["Position", [nil, "getCenter"] call ENH_fnc_placementTools];
        ENH_PlacementTools_AreaTrigger set3DENAttribute ["Size3", [_A, _B, 1]];

        collect3DENHistory
        {
            {
                private _center = [nil, "getCenter"] call ENH_fnc_placementTools;
                private _randomPos =
                [
                    _center#0 + random _A - random _A,
                    _center#1 + random _B - random _B,
                    0
                ];
                _x set3DENAttribute ["Position", _randomPos];
            } forEach ([["Object", "Logic", "Trigger", "Marker"]] call ENH_fnc_all3DENSelected);
        };
    };
    case "grid":
    {
        private _startPos = [nil, "getCenter"] call ENH_fnc_placementTools;
        private _offset = [0, 0, 0];
        private _counterColumns = 0;
        private _wantedColumns = ENH_PlacementTools_Settings get "NumColumns";
        private _spaceX = ENH_PlacementTools_Settings get "SpaceX";
        private _spaceY = ENH_PlacementTools_Settings get "SpaceY";

        collect3DENHistory
        {
            {
                if (_counterColumns == _wantedColumns) then// Check if column is full, if yes, manipulate start position and open an new column
                {
                    _startPos = _startPos vectorAdd [0, _spaceY, 0];
                    _offset = [0, 0, 0];
                    _counterColumns = 0;
                };

                _x set3DENAttribute ["Position", _startPos vectorAdd _offset];
                _offset = _offset vectorAdd [_spaceX, 0, 0];
                _counterColumns = _counterColumns + 1;
            } forEach ([["Object", "Logic", "Trigger", "Marker"]] call ENH_fnc_all3DENSelected);
        };
    };
    case "strToNum":
    {
        _params params [["_input", ""]];

        if (_input isEqualType 0) exitWith {_input};
        if (_input isEqualType "") exitWith {parseNumber _input};
        0
    };
};
