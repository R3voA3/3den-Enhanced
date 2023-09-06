/*
  Author: R3vo

  Description:
  Changes the spacing. Used in the ENH_PatternTools GUI.

  Parameter(s):
  -

  Returns:
  -
*/

private _spacing = ENH_PlacementTools_Settings get ["Spacing"];

private _newPos = ENH_PlacementTools_Center;

collect3DENHistory
{
  {
    _x set3DENAttribute ["Position", _newPos];
    _newPos = _newPos getPos [_spacing, 0];
  } forEach ENH_PlacementTools_Selected;
};