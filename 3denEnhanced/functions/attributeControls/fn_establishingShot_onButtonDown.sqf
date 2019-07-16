/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the establishing shot attribute. Called when reset button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText str [0,0,0];
(_ctrlGroup controlsGroupCtrl 101) ctrlSetText (getText (configfile >> 'CfgWorlds' >> worldName >> 'description'));

[_ctrlGroup controlsGroupCtrl 102,_ctrlGroup controlsGroupCtrl 103,"m",500] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 104,_ctrlGroup controlsGroupCtrl 105,"m",200] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 106,_ctrlGroup controlsGroupCtrl 107,"°",60] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 108) lbSetCurSel 0;

true