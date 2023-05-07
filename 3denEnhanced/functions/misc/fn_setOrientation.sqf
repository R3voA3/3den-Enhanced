/*
  Author: R3vo, improved by dixon13

  Description:
  Sets the orientation of all selected objects. Checks if rotation attribute has 1 dimension or 3.

  Parameter(s):
  NUMBER: -1: random
          -2: reverse
         >-1: Direction in degrees

  Returns:
  -
*/

if (!is3DEN) exitWith {false};

private _input = param [0, 0, [0]];

private _entities1DimRotation = get3DENSelected "Marker" + get3DENSelected "Trigger";
private _entities3DimRotation = get3DENSelected "Object" + get3DENSelected "Logic";

if (_entities1DimRotation isEqualTo [] && _entities3DimRotation isEqualTo []) exitWith
{
  ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
};

[localize "STR_ENH_FOLDER_ORIENT", nil, "a3\ui_f\data\gui\rsc\rscdisplayarsenal\compass_ca.paa"] collect3DENHistory
{
  switch _input do
  {
    case -2://reverse
    {
      {
        private _dir = (_x get3DENAttribute "rotation") # 0;
        _x set3DENAttribute ["rotation", _dir + 180];
      } forEach _entities1DimRotation;

      {
        private _dir = (_x get3DENAttribute "rotation") # 0;
        _dir set [2, (_dir # 2) + 180];
        _x set3DENAttribute ["rotation", _dir];
      } forEach _entities3DimRotation;
    };
    case -1://randomise
    {
      {
        private _dir = random 360;
        _x set3DENAttribute ["rotation", _dir];
      } forEach _entities1DimRotation;

      {
        private _dir = (_x get3DENAttribute "rotation") # 0;
        _dir set [2, random 360];
        _x set3DENAttribute ["rotation", _dir];
      } forEach _entities3DimRotation;
    };
    default
    {
      {
        _x set3DENAttribute ["rotation", _input];
      } forEach _entities1DimRotation;

      {
        private _dir = (_x get3DENAttribute "rotation") # 0;
        _dir set [2, _input];
        _x set3DENAttribute ["rotation", _dir];
      } forEach _entities3DimRotation;
    };
  };
};





// Triggers and markers have one dimensional rotation. All other entities have three dimensions or no rotation attribute
_fnc_setOrientation =
{
  params [["_entity", objNull], ["_degrees", 0]];

  private _currentRotation = _entity get3DENAttribute "rotation" select 0;

  if (_currentRotation isEqualType []) then
  {
    _entity set3DENAttribute ["rotation", [_currentRotation # 0, _currentRotation # 1, _degrees]];
  }
  else
  {
    _entity set3DENAttribute ["rotation", _degrees];
  };
};

[localize "STR_ENH_FOLDER_ORIENT", nil, "a3\ui_f\data\gui\rsc\rscdisplayarsenal\compass_ca.paa"] collect3DENHistory
{
  switch _input do
  {
    case -2://reverse
    {
      {
        private _dir = (_x get3DENAttribute "rotation") # 0;
        if (_dir isEqualType []) then
        {
          _dir set [2, (_dir # 2) + 180];
          _x set3DENAttribute ["rotation", _dir];
        }
        else
        {
          _x set3DENAttribute ["rotation", _dir + 180];
        };
      } forEach _entities;
    };
    case -1://randomise
    {
      {
        private _dir = random 360;
        [_x, _dir] call _fnc_setOrientation;
      } forEach _entities;
    };
    default
    {
      {
        [_x, _dir] call _fnc_setOrientation;
      } forEach _entities;
    };
  };
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;