/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the ambient animations attribute. Called when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute value

   Returns:
   BOOLEAN: true
*/

#define ANIMSETS ["","BRIEFING","BRIEFING_POINT_LEFT","BRIEFING_POINT_RIGHT","BRIEFING_POINT_TABLE","GUARD","KNEEL","KNEEL_TREAT","LEAN","LEAN_ON_TABLE","LISTEN_BRIEFING","PRONE_INJURED","PRONE_INJURED_U1","PRONE_INJURED_U2","REPAIR_VEH_KNEEL","REPAIR_VEH_PRONE","REPAIR_VEH_STAND","SIT1","SIT2","SIT3","SIT_AT_TABLE","SIT_HIGH1","SIT_HIGH2","SIT_LOW","SIT_LOW_U","SIT_SAD1","SIT_SAD2","SIT_U1","SIT_U2","SIT_U3","STAND","STAND_IA","STAND_U1","STAND_U2","STAND_U3","WATCH1","WATCH2"]

params ["_ctrlGroup","_value"];
_value params ["_animSet","_canExit","_disableCollision","_attach"];
test = [];
{
   (_ctrlGroup controlsGroupCtrl 100) lbAdd _x;

   //Translate all strings except the first one
   if (_forEachIndex > 0) then
   {
      //Localisation string is automatically generated
      (_ctrlGroup controlsGroupCtrl 100) lbSetTooltip [_forEachIndex,localize ("STR_ENH_ambientAnimations_animSet_" + _x)];
   };
   if (_animSet isEqualTo _x) then
   {
      (_ctrlGroup controlsGroupCtrl 100) lbSetCurSel _forEachIndex;
   }
} forEach ANIMSETS;

(_ctrlGroup controlsGroupCtrl 101) cbSetChecked _canExit;
(_ctrlGroup controlsGroupCtrl 102) cbSetChecked _disableCollision;
(_ctrlGroup controlsGroupCtrl 103) cbSetChecked _attach;
true