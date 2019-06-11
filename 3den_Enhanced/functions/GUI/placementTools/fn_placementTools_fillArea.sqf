/*
	Author: Revo

	Description:
	Places selected eden entities randomly in an area. Used in the Enh_PatternTools GUI.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

params ["_control", "_newValue"];

if (isNil "Enh_PlacementTools_AreaTrigger") then
{
	Enh_PlacementTools_AreaTrigger = create3DENEntity ["Trigger","EmptyDetectorArea10x10",Enh_PlacementTools_Center];
};

Enh_PlacementTools_AreaTrigger set3DENAttribute ["Position",Enh_PlacementTools_Center];
Enh_PlacementTools_AreaTrigger set3DENAttribute ["Size3",[Enh_PlacementTools_A,Enh_PlacementTools_B,1]];

collect3DENHistory
{
	{
		private _randomPos = 
		[
			Enh_PlacementTools_Center # 0 + random Enh_PlacementTools_A - random Enh_PlacementTools_A,
			Enh_PlacementTools_Center # 1 + random Enh_PlacementTools_B - random Enh_PlacementTools_B,
			0
		];
		_x set3DENAttribute ["Position",_randomPos];
	} forEach Enh_PlacementTools_Selected;
};

(uiNamespace getVariable "Enh_PlacementTools_Display") displayCtrl 120 ctrlSetText format ["%1 m / %2 m",Enh_PlacementTools_A,Enh_PlacementTools_B];

true