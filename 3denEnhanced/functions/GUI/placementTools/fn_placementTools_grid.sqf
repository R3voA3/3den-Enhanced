/*
  Author: R3vo

  Description:
  Places objects in pattern defined by number of columns and spacing (x, y) in meters. Used in the ENH_PatternTools GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

private _startPos = ENH_PlacementTools_Center;
private _offset = [0, 0, 0];
private _counterColumns = 0;

collect3DENHistory
{
  {
    if (_counterColumns == ENH_PlacementTools_NumColumns) then//Check if column is full, if yes, manipulate start position and open an new column
    {
      _startPos = _startPos vectorAdd [0, ENH_PlacementTools_SpaceY, 0];
      _offset = [0, 0, 0];
      _counterColumns = 0;
    };

    _x set3DENAttribute ["Position", _startPos vectorAdd _offset];
    _offset = _offset vectorAdd [ENH_PlacementTools_SpaceX, 0, 0];
    _counterColumns = _counterColumns + 1;
  } forEach ENH_PlacementTools_Selected;
};