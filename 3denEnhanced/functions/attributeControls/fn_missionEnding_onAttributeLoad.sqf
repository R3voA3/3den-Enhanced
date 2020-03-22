/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the mission ending attribute. Called when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute values

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];
_value params ["_condition","_debriefing","_isWin","_playMusic"];

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText _condition;

[_ctrlGroup controlsGroupCtrl 101,_debriefing] call ENH_fnc_initDebriefingCombo;

(_ctrlGroup controlsGroupCtrl 102) cbSetChecked _isWin;
(_ctrlGroup controlsGroupCtrl 103) cbSetChecked _isWin;

true