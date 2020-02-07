/*
   Author: R3vo

   Date: 2019-07-29

   Description:
   Sets the increment size. Used in the ENH_PatternTools GUI. Called when toolbox selection was changed.

   Parameter(s):
   0: CONTROL - Control tool box

   Returns:
   BOOLEAN: true
*/

params ["_ctrlToolbox","_selectedIndex"];

private _display = ctrlParent _ctrlToolbox;
private _stepSize = _ctrlToolbox lbValue _selectedIndex;

missionNamespace setVariable ["ENH_PlacementTools_stepSizeIndex",_selectedIndex];

//Set slider speed
{
   (_display displayCtrl _x) sliderSetSpeed [_stepSize,_stepSize];
} forEach [10,20,30,40,50,60,70,80,90,100,110,130,140,150];

true