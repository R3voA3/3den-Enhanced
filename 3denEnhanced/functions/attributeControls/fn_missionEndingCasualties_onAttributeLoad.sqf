/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the mission ending attribute. Called when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Array with booleans, attribute value

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];
_value params ["_threshold","_debriefing","_isWin","_side"];

[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,""] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"",_threshold] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 102,_debriefing] call ENH_fnc_initDebriefingCombo;

(_ctrlGroup controlsGroupCtrl 103) cbSetChecked _isWin;
(_ctrlGroup controlsGroupCtrl 104) lbSetCurSel ([west,east,independent,civilian] find _side);

true