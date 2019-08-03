/*
   Author: R3vo

   Date: 2019-08-03

   Description:
   Garrison one or multiple buildings in the area. Radius and coverage are taken from the custom UI Enh_Garrison.

   Parameter(s):
   CONTROL: Button control

   Returns:
   BOOLEAN: true
*/

disableSerialization;

params ["_ctrlButton"];
private _display = ctrlParent _ctrlButton;

private _ctrlRadius = _display displayCtrl 100;
private _ctrlCoverage = _display displayCtrl 200;

private _positions = [];
private _selectedObjects = call Enh_fnc_all3denSelected;
private _center = (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") # 0;
//_center set [2,0];
private _radius = ctrlText _ctrlRadius;
private _index  = lbCurSel _ctrlCoverage;
private _step   = _ctrlCoverage lbValue _index;

//Save settings
profileNamespace setVariable ['Enh_garrison_lastRadius',_radius];
profileNamespace setVariable ['Enh_garrison_lastCoverage',_index];

//Get nearest buildings
private _buildings = _center nearObjects ["House",parseNumber _radius];

//Get all building positions from nearby buildings
{
	for "_i" from 0 to (count (_x buildingPos -1) - 1) step _step do
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
		_positions = _positions - [_pos];

		if (count _positions == 0) exitWith
		{
			[localize "STR_ENH_garrison_notification"] call BIS_fnc_3DENNotification;
		};
		if(surfaceIsWater _pos) then
		{
			_x set3DENAttribute ["position",ASLToATL _pos];
		}
		else
		{
			_x set3DENAttribute ["position",_pos];
		};

		_x set3DENAttribute ["rotation", [0,0,random 360]];
	} forEach _selectedObjects;
};

_display closeDisplay 0;

true
