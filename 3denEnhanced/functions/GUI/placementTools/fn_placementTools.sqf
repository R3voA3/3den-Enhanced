/*
  Author: R3vo

  Description:
  Initializes the ENH_Pattern GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

disableSerialization;

params
[
  ["_display", displayNull],
  ["_mode", "onLoad"],
  ["_params", []]
];

switch _mode do
{
  case "createDisplay":
  {
    ENH_PlacementTools_Selected = [["Object", "Logic", "Trigger", "Marker"]] call ENH_fnc_all3DENSelected;

    if (ENH_PlacementTools_Selected isEqualTo []) exitWith {["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification};

    findDisplay IDD_DISPLAY3DEN createDisplay "ENH_PlacementTools";
  };
  case "onLoad":
  {
    ["ShowPanelLeft", false] call BIS_fnc_3DENInterface;

    ENH_PlacementTools_Center = if (get3DENActionState "ToggleMap" == 1) then
    {
      (findDisplay IDD_DISPLAY3DEN displayCtrl 51 ctrlMapScreenToWorld [0.5, 0.5]) + [0];
    }
    else
    {
      screenToWorld [0.5, 0.5];
    };

    if (isNil "ENH_PlacementTools_Settings") then
    {
      ENH_PlacementTools_Settings = createHashmapFromArray
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

    //Draw an icon where the center is
    ENH_PlacementTools_CenterIcon_EH = addMissionEventHandler ["Draw3D",
    {
      drawIcon3D["", [1, 0.1, 1, 1], ENH_PlacementTools_Center, 1, 1, 0, "X"];
    }];

    {
      _x params ["_idc", "_setting"];
      CTRL(_idc) ctrlSetText str (ENH_PlacementTools_Settings get _setting);
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

    CTRL(IDC_PLACEMENTTOOLS_CENTERX) ctrlSetText str (ENH_PlacementTools_Center select 0);
    CTRL(IDC_PLACEMENTTOOLS_CENTERY) ctrlSetText str (ENH_PlacementTools_Center select 1);

    //Add EHs to controls
    CTRL(IDC_PLACEMENTTOOLS_CENTERX) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Center set [0, _numericValue];
    }];

    CTRL(IDC_PLACEMENTTOOLS_CENTERY) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Center set [1, _numericValue];
    }];

    CTRL(IDC_PLACEMENTTOOLS_RADIUS) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Settings set ["Radius", _numericValue];

      [nil, "circular"] call ENH_fnc_placementTools;
    }];

    CTRL(IDC_PLACEMENTTOOLS_INITIALANGLE) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Settings set ["InitialAngle", _numericValue];

      [nil, "circular"] call ENH_fnc_placementTools;
    }];

    CTRL(IDC_PLACEMENTTOOLS_CENTRALANGLE) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Settings set ["CentralAngle", _numericValue];

      [nil, "circular"] call ENH_fnc_placementTools;
    }];

    CTRL(IDC_PLACEMENTTOOLS_SPACING) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Settings set ["Spacing", _numericValue];

      [nil, "line"] call ENH_fnc_placementTools;
    }];

    CTRL(IDC_PLACEMENTTOOLS_SPACINGDIRECTION) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Settings set ["SpacingDirection", _numericValue];

      [nil, "line"] call ENH_fnc_placementTools;
    }];

    CTRL(IDC_PLACEMENTTOOLS_ORIENTATION) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      _numericValue call ENH_fnc_setOrientation;
    }];

    CTRL(IDC_PLACEMENTTOOLS_A) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Settings set ["A", _numericValue];

      [nil, "fill"] call ENH_fnc_placementTools;
    }];

    CTRL(IDC_PLACEMENTTOOLS_B) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Settings set ["B", _numericValue];

      [nil, "fill"] call ENH_fnc_placementTools;
    }];

    CTRL(IDC_PLACEMENTTOOLS_NUMCOLUMNS) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Settings set ["NumColumns", _numericValue];

      [nil, "grid"] call ENH_fnc_placementTools;
    }];

    CTRL(IDC_PLACEMENTTOOLS_SPACEX) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Settings set ["SpaceX", _numericValue];

      [nil, "grid"] call ENH_fnc_placementTools;
    }];

    CTRL(IDC_PLACEMENTTOOLS_SPACEY) ctrlAddEventHandler ["editChanged",
    {
      params ["_ctrlEdit", "_input"];
      private _numericValue = [nil, "strToNum", [_input]] call ENH_fnc_placementTools;
      ENH_PlacementTools_Settings set ["SpaceY", _numericValue];

      [nil, "grid"] call ENH_fnc_placementTools;
    }];

    CTRL(IDC_PLACEMENTTOOLS_RANDOMORIENTATION) ctrlAddEventHandler ["buttonClick",
    {
      -1 call ENH_fnc_setOrientation;
    }];

    CTRL(IDC_PLACEMENTTOOLS_REVERSEORIENTATION) ctrlAddEventHandler ["buttonClick",
    {
      -2 call ENH_fnc_setOrientation;
    }];

    //Add EHs to all edit controls for input modifiers
    {
      _x ctrlAddEventHandler ["keyDown",
      {
        params ["_ctrlEdit", "_key", "_shift", "_ctrl", "_alt"];

        //PageUp, PageDown
        if !(_key in [201, 209]) exitWith {};

        private _modifier = call
        {
          if (_ctrl && _shift) exitWith {0.001};
          if (_ctrl && _alt) exitWith {0.01};
          if (_ctrl) exitWith {0.1};
          1
        };

        _modifier = if (_key == 209) then {_modifier * -1} else {_modifier};

        private _numericValue = [nil, "strToNum", [ctrlText _ctrlEdit]] call ENH_fnc_placementTools;

        _ctrlEdit ctrlSetText str (_numericValue + _modifier);
      }];

      _x ctrlSetToolTip "PAGE UP/DOWN: +-1\nPAGE UP/DOWN + CTRL: +-0.1\nPAGE UP/DOWN + CTRL + ALT: +-0.01\nPAGE UP/DOWN + CTRL + ALT + SHIFT: +-0.001";
    } forEach (allControls _display select {ctrlType _x == 2});
  };
  case "onUnload":
  {
    delete3DENEntities [ENH_PlacementTools_AreaTrigger];
    removeMissionEventHandler ["draw3D", ENH_PlacementTools_CenterIcon_EH];

    ENH_PlacementTools_CenterIcon_EH = nil;
    ENH_PlacementTools_AreaTrigger = nil;

    ["ShowPanelLeft", true] call BIS_fnc_3DENInterface;
  };
  case "line":
  {
    private _newPos = ENH_PlacementTools_Center;
    collect3DENHistory
    {
      {
        _x set3DENAttribute ["Position", _newPos];
        _newPos = _newPos getPos
        [
          ENH_PlacementTools_Settings get "Spacing",
          ENH_PlacementTools_Settings get "SpacingDirection"
        ];
      } forEach ENH_PlacementTools_Selected;
    };
  };
  case "circular":
  {
    private _radius = ENH_PlacementTools_Settings get "Radius";
    private _initialAngle = ENH_PlacementTools_Settings get "InitialAngle";
    private _centralAngle = ENH_PlacementTools_Settings get "CentralAngle";
    private _angleStep = _centralAngle / count ENH_PlacementTools_Selected;
    private _center = ENH_PlacementTools_Center;

    private _angle = _initialAngle;

    collect3DENHistory
    {
      {
        _pos = _center getPos [_radius, _angle];
        _x set3DENAttribute ["Position", _pos];
        _x set3DENAttribute ["Rotation", [0, 0, _angle]];
        _angle = _angle + _angleStep;
      } forEach ENH_PlacementTools_Selected;
    };
  };
  case "fill":
  {
    if (isNil "ENH_PlacementTools_AreaTrigger") then
    {
      ENH_PlacementTools_AreaTrigger = create3DENEntity ["Trigger", "EmptyDetectorArea10x10", ENH_PlacementTools_Center];
    };

    private _A = ENH_PlacementTools_Settings get "A";
    private _B = ENH_PlacementTools_Settings get "B";

    ENH_PlacementTools_AreaTrigger set3DENAttribute ["Position", ENH_PlacementTools_Center];
    ENH_PlacementTools_AreaTrigger set3DENAttribute ["Size3", [_A, _B, 1]];

    collect3DENHistory
    {
      {
        private _randomPos =
        [
          ENH_PlacementTools_Center # 0 + random _A - random _A,
          ENH_PlacementTools_Center # 1 + random _B - random _B,
          0
        ];
        _x set3DENAttribute ["Position", _randomPos];
      } forEach ENH_PlacementTools_Selected;
    };
  };
  case "grid":
  {
    private _startPos = ENH_PlacementTools_Center;
    private _offset = [0, 0, 0];
    private _counterColumns = 0;
    private _wantedColumns = ENH_PlacementTools_Settings get "NumColumns";
    private _spaceX = ENH_PlacementTools_Settings get "SpaceX";
    private _spaceY = ENH_PlacementTools_Settings get "SpaceY";

    collect3DENHistory
    {
      {
        if (_counterColumns == _wantedColumns) then//Check if column is full, if yes, manipulate start position and open an new column
        {
          _startPos = _startPos vectorAdd [0, _spaceY, 0];
          _offset = [0, 0, 0];
          _counterColumns = 0;
        };

        _x set3DENAttribute ["Position", _startPos vectorAdd _offset];
        _offset = _offset vectorAdd [_spaceX, 0, 0];
        _counterColumns = _counterColumns + 1;
      } forEach ENH_PlacementTools_Selected;
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