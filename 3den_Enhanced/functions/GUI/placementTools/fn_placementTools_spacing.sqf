/*
	Author: Revo

	Description:
	Changes the spacing. Used in the Enh_PatternTools GUI.

	Parameter(s):
	-
	Returns:
	BOOLEAN - true
*/

params ["_control", "_newValue"];

_newPos = Enh_PlacementTools_Center;
Enh_PlacementTools_Spacing = _newValue;

collect3DENHistory
{
	{
		_x set3DENAttribute ["Position",_newPos];
		_newPos = _newPos getPos [_newValue,0];
	} forEach Enh_PlacementTools_Selected;
};

(uiNamespace getVariable "Enh_PlacementTools_Display") displayCtrl 120 ctrlSetText (str _newValue + " m");