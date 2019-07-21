/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the intro text attribute. Called when reset button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;

[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"s",0] call BIS_fnc_initSliderValue;
(_ctrlGroup controlsGroupCtrl 102) ctrlSetText briefingName;
(_ctrlGroup controlsGroupCtrl 103) ctrlSetText ('by ' + profileName);
(_ctrlGroup controlsGroupCtrl 104) ctrlSetText ([daytime,'HH:MM'] call BIS_fnc_TimeToString);
(_ctrlGroup controlsGroupCtrl 105) lbSetCurSel 0;

true