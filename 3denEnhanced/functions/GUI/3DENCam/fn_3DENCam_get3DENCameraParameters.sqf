/*
  Author: R3vo

  Date: 2020-01-16

  Description:
  Saves current 3DEN camera parameters to profileNamespace.

  Parameter(s):
  0: CONTROL - Control to get parent display

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

params ["_ctrl"];

private _cam3DEN = get3DENCamera;
private _cam3DENSavedPositions = profileNamespace getVariable ["ENH_Cam3DENSavedPositions",[]];

private _display = ctrlParent _ctrl;
private _description = ctrlText CTRL(IDC_3DENCAMPOS_DESCRIPTION);

if (_description isEqualTo localize "STR_ENH_3DENCAM_DESCRIPTION" || _description isEqualTo "") then
{
  _description = format ["#%1",(lnbSize CTRL(IDC_3DENCAMPOS_LIST) # 0) + 1];
};

_cam3DENSavedPositions pushBack [worldName,getPos _cam3DEN,vectorDir _cam3DEN,vectorUp _cam3DEN,_description,systemTime];

profileNamespace setVariable ["ENH_Cam3DENSavedPositions",_cam3DENSavedPositions];

//Update list
_ctrl call ENH_fnc_3DENCam_updateList;