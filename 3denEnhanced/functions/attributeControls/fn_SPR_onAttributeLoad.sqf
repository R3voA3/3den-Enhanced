/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the SPR attribute. Called when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute value

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];
_value params ["_respawnTime","_tickets","_respawnType","_canDie"];

[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"s"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"s",_respawnTime] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 102,_ctrlGroup controlsGroupCtrl 103,""] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 102,_ctrlGroup controlsGroupCtrl 103,"",_tickets] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 104) lbAdd localize "STR_3DEN_ATTRIBUTES_RESPAWN_INSTANT_TEXT";
(_ctrlGroup controlsGroupCtrl 104) lbAdd localize "STR_ENH_SPR_RULESET_RANDOMPOSITION";
(_ctrlGroup controlsGroupCtrl 104) lbSetTooltip [1,localize "STR_ENH_SPR_RULESET_RANDOMPOSITION_TOOLTIP"];
(_ctrlGroup controlsGroupCtrl 104) lbAdd localize "STR_ENH_SPR_RULESET_NEARESTPOSITION";
(_ctrlGroup controlsGroupCtrl 104) lbSetTooltip [2,localize "STR_ENH_SPR_RULESET_RANDOMPOSITION_TOOLTIP"];
(_ctrlGroup controlsGroupCtrl 104) lbSetCurSel _respawnType;

(_ctrlGroup controlsGroupCtrl 105) cbSetChecked _canDie;

true