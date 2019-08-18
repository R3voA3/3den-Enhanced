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

#define ANIMSETS [["","STR_ENH_no"],["BRIEFING","STR_ENH_no"],["BRIEFING_POINT_LEFT","STR_ENH_no"],["BRIEFING_POINT_RIGHT","STR_ENH_no"],["BRIEFING_POINT_TABLE","STR_ENH_no"],["GUARD","STR_ENH_yes"],["HANDS_HELD_HIGH","STR_ENH_yes"],["KNEEL","STR_ENH_no"],["KNEEL_TREAT","STR_ENH_no"],["LEAN","STR_ENH_no"],["LEAN_ON_TABLE","STR_ENH_no"],["LISTEN_BRIEFING","STR_ENH_yes"],["PRONE_INJURED","STR_ENH_no"],["PRONE_INJURED_U1","STR_ENH_yes"],["PRONE_INJURED_U2","STR_ENH_yes"],["REPAIR_VEH_KNEEL","STR_ENH_yes"],["REPAIR_VEH_PRONE","STR_ENH_yes"],["REPAIR_VEH_STAND","STR_ENH_yes"],["SHIELD_FROM_SUN","STR_ENH_no"],["SIT1","STR_ENH_no"],["SIT2","STR_ENH_no"],["SIT3","STR_ENH_no"],["SIT_AT_TABLE","STR_ENH_no"],["SIT_HANDCUFFED","STR_ENH_yes"],["SIT_HIGH1","STR_ENH_no"],["SIT_HIGH2","STR_ENH_no"],["SIT_LOW","STR_ENH_no"],["SIT_LOW_U","STR_ENH_yes"],["SIT_SAD1","STR_ENH_no"],["SIT_SAD2","STR_ENH_no"],["SIT_U1","STR_ENH_yes"],["SIT_U2","STR_ENH_yes"],["SIT_U3","STR_ENH_yes"],["STAND","STR_ENH_no"],["STAND_IA","STR_ENH_no"],["STAND_IDLE","STR_ENH_yes"],["STAND_PISTOL","STR_ENH_no"],["STAND_TALKING","STR_ENH_yes"],["STAND_U1","STR_ENH_yes"],["STAND_U2","STR_ENH_yes"],["STAND_U3","STR_ENH_yes"],["WARMUP","STR_ENH_no"],["WARMUP_KNEELING","STR_ENH_no"],["WATCH1","STR_ENH_no"],["WATCH2","STR_ENH_no"],["WORKING_AT_DESK","STR_ENH_no"]]

params ["_ctrlGroup","_value"];
_value params ["_animSet","_anims","_canExit","_attach"];
private _ctrlLB = (_ctrlGroup controlsGroupCtrl 100);
{
   _x params ["_animSetPreset","_unarmedStr"];
   _ctrlLB lbAdd _animSetPreset;

   if (_animSet isEqualTo _animSetPreset) then
   {
      _ctrlLB lbSetCurSel _forEachIndex;
   };
   //Adds tooltip depending on preset
   _ctrlLB lbSetTooltip [_forEachIndex,format ["%1 %2.",localize "STR_ENH_ambientAnimations_unarmed",localize _unarmedStr]];
} forEach ANIMSETS;

(_ctrlGroup controlsGroupCtrl 101) cbSetChecked _canExit;
(_ctrlGroup controlsGroupCtrl 102) cbSetChecked _attach;

true