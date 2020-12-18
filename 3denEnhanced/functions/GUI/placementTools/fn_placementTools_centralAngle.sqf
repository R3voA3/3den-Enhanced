/*
  Author: R3vo

  Description:
  Changes the central angle. Used in the ENH_PatternTools GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

params ["", "_newValue"];

ENH_PlacementTools_CentralAngle = _newValue;
private _angle = ENH_PlacementTools_InitialAngle;
private _angleStep = ENH_PlacementTools_CentralAngle / count ENH_PlacementTools_Selected;

collect3DENHistory
{
  {
    private _pos = ENH_PlacementTools_Center getPos [ENH_PlacementTools_Radius,_angle];
    _x set3DENAttribute ["Position",_pos];
    _x set3DENAttribute ["Rotation",[0,0,_angle]];
    _angle = _angle + _angleStep;
  } forEach ENH_PlacementTools_Selected;
};

(uiNamespace getVariable "ENH_PlacementTools_Display") displayCtrl IDC_PLACEMENTTOOLS_CURRENTVALUE ctrlSetText (str _newValue + " °");