/*
  Author: R3vo

  Description:
  Initializes the ENH_Pattern GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

disableSerialization;
params ["_display"];

#define IDC_PLACEMENTTOOLS_ORIENTATION 100
#define IDC_PLACEMENTTOOLS_REVERSEORIENTATION 110
#define IDC_PLACEMENTTOOLS_RANDOMORIENTATION 120
#define IDC_PLACEMENTTOOLS_SPACINGDIRECTION 130
#define IDC_PLACEMENTTOOLS_CENTERX 140
#define IDC_PLACEMENTTOOLS_CENTERY 150

["ShowPanelLeft", false] call BIS_fnc_3DENInterface;

if (isNil "ENH_PlacementTools_Center") then
{
  ENH_PlacementTools_Center = if (get3DENActionState "ToggleMap" == 1) then
  {
    (findDisplay IDD_3DEN displayCtrl 51 ctrlMapScreenToWorld [0.5, 0.5]) + [0]; //ctrlMapScreenToWorld only returns [x, y], add another 0 to have [x, y, z]
  }
  else
  {
    screenToWorld [0.5, 0.5];
  };
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
  (_display displayCtrl _idc) ctrlSetText str (ENH_PlacementTools_Settings get _setting);
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

(_display displayCtrl IDC_PLACEMENTTOOLS_CENTERX) ctrlSetText str (ENH_PlacementTools_Center select 0);
(_display displayCtrl IDC_PLACEMENTTOOLS_CENTERY) ctrlSetText str (ENH_PlacementTools_Center select 1);

ENH_fnc_placementTools_stringToNumeric =
{
  params [["_input", ""]];

  if (_input isEqualType 0) exitWith {_input};

  if (_input isEqualTo "0") exitWith {0};

  parseNumber _input;
};

// Add EHs to controls
(_display displayCtrl IDC_PLACEMENTTOOLS_CENTERX) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Center set [0, _numericValue];
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_CENTERY) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Center set [1, _numericValue];
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_RADIUS) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Settings set ["Radius", _numericValue];

  call ENH_fnc_circularPattern_new;
}];


(_display displayCtrl IDC_PLACEMENTTOOLS_INITIALANGLE) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Settings set ["InitialAngle", _numericValue];

  call ENH_fnc_circularPattern_new;
}];


(_display displayCtrl IDC_PLACEMENTTOOLS_CENTRALANGLE) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Settings set ["CentralAngle", _numericValue];

  call ENH_fnc_circularPattern_new;
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_SPACING) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Settings set ["Spacing", _numericValue];

  call ENH_fnc_placementTools_spacing_new;
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_SPACINGDIRECTION) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Settings set ["SpacingDirection", _numericValue];

  call ENH_fnc_placementTools_spacing_new;
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_ORIENTATION) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  systemChat str _numericValue;

  _numericValue call ENH_fnc_setOrientation; // Doesn't work for triggers
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_A) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Settings set ["A", _numericValue];

  call ENH_fnc_fillArea_new; // Doesn't work for triggers
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_B) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Settings set ["B", _numericValue];

  call ENH_fnc_fillArea_new; // Doesn't work for triggers
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_NUMCOLUMNS) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Settings set ["NumColumns", _numericValue];

  call ENH_fnc_grid_new;
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_SPACEX) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Settings set ["SpaceX", _numericValue];

  call ENH_fnc_grid_new;
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_SPACEY) ctrlAddEventHandler ["editChanged",
{
  params ["_ctrlEdit", "_input"];
  private _numericValue = _input call ENH_fnc_placementTools_stringToNumeric;
  ENH_PlacementTools_Settings set ["SpaceY", _numericValue];

  call ENH_fnc_grid_new;
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_RANDOMORIENTATION) ctrlAddEventHandler ["buttonClick",
{
  -1 call ENH_fnc_setOrientation; // Doesn't work for triggers
}];

(_display displayCtrl IDC_PLACEMENTTOOLS_REVERSEORIENTATION) ctrlAddEventHandler ["buttonClick",
{
  -2 call ENH_fnc_setOrientation; // Doesn't work for triggers
}];

// Add EHs to all edit controls for input modifiers
{
  _x ctrlAddEventHandler ["keyDown",
  {
    params ["_ctrlEdit", "_key", "_shift", "_ctrl", "_alt"];

    // PageUp, PageDown
    if !(_key in [201, 209]) exitWith {};

    private _modifier = call
    {
      if (_ctrl && _shift) exitWith {0.001};
      if (_ctrl && _alt) exitWith {0.01};
      if (_ctrl) exitWith {0.1};
      1
    };

    _modifier = if (_key == 209) then {_modifier * -1} else {_modifier};

    private _numericValue = (ctrlText _ctrlEdit) call ENH_fnc_placementTools_stringToNumeric;

    _ctrlEdit ctrlSetText str (_numericValue + _modifier);
  }];

  _x ctrlSetToolTip "PAGE UP/DOWN: +-1\nPAGE UP/DOWN + CTRL: +-0.1\nPAGE UP/DOWN + CTRL + ALT: +-0.01\nPAGE UP/DOWN + CTRL + ALT + SHIFT: +-0.001";
} forEach (allControls _display select {ctrlType _x == 2});

ENH_fnc_placementTools_spacing_new =
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

ENH_fnc_circularPattern_new =
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

ENH_fnc_fillArea_new =
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

ENH_fnc_grid_new =
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