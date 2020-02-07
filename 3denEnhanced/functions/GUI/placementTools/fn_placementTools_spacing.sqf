/*
	Author: Revo

	Description:
	Changes the spacing. Used in the ENH_PatternTools GUI.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

params ["_control", "_newValue"];

_newPos = ENH_PlacementTools_Center;
ENH_PlacementTools_Spacing = _newValue;

collect3DENHistory
{
	{
		_x set3DENAttribute ["Position",_newPos];
		_newPos = _newPos getPos [_newValue,0];
	} forEach ENH_PlacementTools_Selected;
};

(uiNamespace getVariable "ENH_PlacementTools_Display") displayCtrl 120 ctrlSetText (str _newValue + " m");