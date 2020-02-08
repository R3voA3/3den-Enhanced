/*
   Author: R3vo

   Date: 2020-01-16

   Description:
   Saves current 3DEN camera parameters to profileNamespace.

   Parameter(s):
   0: CONTROL - Control to get parent display

   Returns:
   BOOLEAN: true
*/

params ["_ctrl"];

private _cam3DEN = get3DENCamera;
private _cam3DENSavedPositions = profileNamespace getVariable ["ENH_Cam3DENSavedPositions",[]];

private _display = ctrlParent _ctrl;
private _description = ctrlText (_display displayCtrl 2000);

if (_description isEqualTo localize "STR_ENH_3DENCAM_DESCRIPTION" || _description isEqualTo "") then
{
	_description = format ["#%1",round random 9999];//We don't wanna save Description... every time
};

private _cam3DENParameters = [worldName,getPos _cam3DEN,vectorDir _cam3DEN,vectorUp _cam3DEN,_description];
_cam3DENSavedPositions pushBack _cam3DENParameters;

profileNamespace setVariable ["ENH_Cam3DENSavedPositions",_cam3DENSavedPositions];

//Update list
_ctrl call ENH_fnc_3DENCam_updateList;

true