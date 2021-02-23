/*
  Author: R3vo

  Description:
  Changes the radius. Used in the ENH_PatternTools GUI.

  Parameter(s):
  -

  Returns:
  -
*/

params ["", "_newValue"];

ENH_PlacementTools_Radius = _newValue;
private _angle = ENH_PlacementTools_InitialAngle;
private _angleStep = ENH_PlacementTools_CentralAngle / count ENH_PlacementTools_Selected;

collect3DENHistory
{
  {
    private _pos = ENH_PlacementTools_Center getPos [_newValue, _angle];
    _x set3DENAttribute ["Position", _pos];
    _x set3DENAttribute ["Rotation", [0, 0, _angle]];
    _angle = _angle + _angleStep;
  } forEach ENH_PlacementTools_Selected;
};

(uiNamespace getVariable "ENH_PlacementTools_Display") displayCtrl IDC_PLACEMENTTOOLS_CURRENTVALUE ctrlSetText (str _newValue + " m");