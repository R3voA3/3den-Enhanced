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

#define ANIMSETS [["","STR_ENH_NO"],["BRIEFING","STR_ENH_NO"],["BRIEFING_POINT_LEFT","STR_ENH_NO"],["BRIEFING_POINT_RIGHT","STR_ENH_NO"],["BRIEFING_POINT_TABLE","STR_ENH_NO"],["GUARD","STR_ENH_YES"],["HANDS_HELD_HIGH","STR_ENH_YES"],["KNEEL","STR_ENH_NO"],["KNEEL_TREAT","STR_ENH_NO"],["LEAN","STR_ENH_NO"],["LEAN_ON_TABLE","STR_ENH_NO"],["LISTEN_BRIEFING","STR_ENH_YES"],["PRONE_INJURED","STR_ENH_NO"],["PRONE_INJURED_U1","STR_ENH_YES"],["PRONE_INJURED_U2","STR_ENH_YES"],["REPAIR_VEH_KNEEL","STR_ENH_YES"],["REPAIR_VEH_PRONE","STR_ENH_YES"],["REPAIR_VEH_STAND","STR_ENH_YES"],["SHIELD_FROM_SUN","STR_ENH_NO"],["SIT1","STR_ENH_NO"],["SIT2","STR_ENH_NO"],["SIT3","STR_ENH_NO"],["SIT_AT_TABLE","STR_ENH_NO"],["SIT_HANDCUFFED","STR_ENH_YES"],["SIT_HIGH1","STR_ENH_NO"],["SIT_HIGH2","STR_ENH_NO"],["SIT_LOW","STR_ENH_NO"],["SIT_LOW_U","STR_ENH_YES"],["SIT_SAD1","STR_ENH_NO"],["SIT_SAD2","STR_ENH_NO"],["SIT_U1","STR_ENH_YES"],["SIT_U2","STR_ENH_YES"],["SIT_U3","STR_ENH_YES"],["STAND","STR_ENH_NO"],["STAND_IA","STR_ENH_NO"],["STAND_IDLE","STR_ENH_YES"],["STAND_PISTOL","STR_ENH_NO"],["STAND_TALKING","STR_ENH_YES"],["STAND_U1","STR_ENH_YES"],["STAND_U2","STR_ENH_YES"],["STAND_U3","STR_ENH_YES"],["WARMUP","STR_ENH_NO"],["WARMUP_KNEELING","STR_ENH_NO"],["WATCH1","STR_ENH_NO"],["WATCH2","STR_ENH_NO"],["WORKING_AT_DESK","STR_ENH_NO"]]

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
   _ctrlLB lbSetTooltip [_forEachIndex,format ["%1 %2.",localize "STR_ENH_AMBIENTANIMATIONS_UNARMED",localize _unarmedStr]];
} forEach ANIMSETS;

(_ctrlGroup controlsGroupCtrl 101) cbSetChecked _canExit;
(_ctrlGroup controlsGroupCtrl 102) cbSetChecked _attach;

true