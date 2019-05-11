/*
	Author: Revo

	Description:
	Garrison one or multiple buildings in the area with selected eden entities. Used in the Enh_PatternTools GUI.

	Parameter(s):
	-
	Returns:
	BOOLEAN - true
*/

private _positions = [];

if (isNil "Enh_PlacementTools_GarrisonTrigger") then
{
	Enh_PlacementTools_GarrisonTrigger = create3DENEntity ["Trigger","EmptyDetectorArea10x10",Enh_PlacementTools_Center];
};

Enh_PlacementTools_GarrisonTrigger set3DENAttribute ["Position",Enh_PlacementTools_Center];
Enh_PlacementTools_GarrisonTrigger set3DENAttribute ["IsRectangle",false];
Enh_PlacementTools_GarrisonTrigger set3DENAttribute ["Size3",[Enh_PlacementTools_AreaDia,Enh_PlacementTools_AreaDia,1]];

//Get nearest buildings
private _buildings = Enh_PlacementTools_Center nearObjects ["House",Enh_PlacementTools_AreaDia];

//Get all building positions from nearby buildings
{
	for "_i" from 0 to (count (_x buildingPos -1) - 1) step Enh_PlacementTools_Coverage do
	{
		_positions pushBack (_x buildingPos _i);
	};
	false;
} count _buildings;

//Place units inside buildings
collect3DENHistory
{
	{
		private _pos = selectRandom _positions;
		_positions = _positions - [_pos];//Remove selected positions from position pool

		if (_positions isEqualTo []) exitWith
		{
			[localize "STR_ENH_garrison_notification",true,1,false] call Enh_fnc_3DENNotificationNoSound;
		};
		if(surfaceIsWater _pos) then
		{
			_x set3DENAttribute ["Position",ASLToATL _pos];
		}
		else
		{
			_x set3DENAttribute ["Position",_pos];
		};

		_x set3DENAttribute ["Rotation", [0,0,random 360]];
	} forEach Enh_PlacementTools_Selected;
};

(uiNamespace getVariable "Enh_PlacementTools_Display") displayCtrl 130 ctrlSetText str [Enh_PlacementTools_AreaDia,["0%","100 %","50 %","33 %","25 %","20 %","16 %","14 %","12.5 %","11 %","10 %"] select Enh_PlacementTools_Coverage];

true