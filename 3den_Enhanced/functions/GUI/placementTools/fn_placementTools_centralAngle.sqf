/*
	Author: Revo

	Description:
	Changes the central angle. Used in the Enh_PatternTools GUI.

	Parameter(s):
	-
	Returns:
	BOOLEAN - true
*/

params ["_control", "_newValue"];

Enh_PlacementTools_CentralAngle = _newValue;
private _angle = Enh_PlacementTools_InitialAngle;
private _angleStep = Enh_PlacementTools_CentralAngle / count Enh_PlacementTools_Selected;

collect3DENHistory
{
	{
		private _pos = Enh_PlacementTools_Center getPos [Enh_PlacementTools_Radius,_angle];
		_x set3DENAttribute ["Position",_pos];
		_x set3DENAttribute ["Rotation",[0,0,_angle]];
		_angle = _angle + _angleStep;
	} forEach Enh_PlacementTools_Selected;
};

(uiNamespace getVariable "Enh_PlacementTools_Display") displayCtrl 120 ctrlSetText (str _newValue + " °");

true