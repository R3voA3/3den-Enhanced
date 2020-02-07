/*
	Author: Revo

	Description:
	Places selected eden entities randomly in an area. Used in the ENH_PatternTools GUI.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

params ["_control", "_newValue"];

if (isNil "ENH_PlacementTools_AreaTrigger") then
{
	ENH_PlacementTools_AreaTrigger = create3DENEntity ["Trigger","EmptyDetectorArea10x10",ENH_PlacementTools_Center];
};

ENH_PlacementTools_AreaTrigger set3DENAttribute ["Position",ENH_PlacementTools_Center];
ENH_PlacementTools_AreaTrigger set3DENAttribute ["Size3",[ENH_PlacementTools_A,ENH_PlacementTools_B,1]];

collect3DENHistory
{
	{
		private _randomPos = 
		[
			ENH_PlacementTools_Center # 0 + random ENH_PlacementTools_A - random ENH_PlacementTools_A,
			ENH_PlacementTools_Center # 1 + random ENH_PlacementTools_B - random ENH_PlacementTools_B,
			0
		];
		_x set3DENAttribute ["Position",_randomPos];
	} forEach ENH_PlacementTools_Selected;
};

(uiNamespace getVariable "ENH_PlacementTools_Display") displayCtrl 120 ctrlSetText format ["%1 m / %2 m",ENH_PlacementTools_A,ENH_PlacementTools_B];

true