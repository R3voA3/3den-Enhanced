/*
  Author: R3vo

  Date: 2019-07-15

  Description:
  Used by the ambient animations attribute. Called when attribute is loaded.

  Parameter(s):
  0: CONTROL - Controls group
  1: ARRAY - Attribute value

  Returns:
  -
*/

#define ANIMSETS [["", 0],\
["ACCESSING_COMPUTER", 0],\
["BRIEFING", 0],\
["BRIEFING_POINT_LEFT", 0],\
["BRIEFING_POINT_RIGHT", 0],\
["BRIEFING_POINT_TABLE", 0],\
["BRIEFING_START", 0],\
["DANCE_1", 0],\
["DANCE_2", 0],\
["GUARD", 1],\
["HANDS_HELD_HIGH", 1],\
["HIDING_1", 0],\
["HIDING_2", 0],\
["IDLE_1", 0],\
["IDLE_2", 0],\
["INJURED_ARMS", 0],\
["INJURED_CHEST", 0],\
["INJURED_GENERAL", 0],\
["INJURED_HEAD", 0],\
["INJURED_LEGS", 0],\
["KNEEL", 0],\
["KNEEL", 0],\
["KNEEL_TREAT", 0],\
["LEAN", 0],\
["LEAN_ON_TABLE", 0],\
["LISTENING_1", 0],\
["LISTENING_2", 0],\
["LISTEN_BRIEFING", 1],\
["PHOTO", 0],\
["PRONE_INJURED", 0],\
["PRONE_INJURED_U1", 1],\
["PRONE_INJURED_U2", 1],\
["RELAX_1", 1],\
["RELAX_2", 1],\
["RELAX_3", 1],\
["RELAX_4", 1],\
["REPAIR_VEH_KNEEL", 1],\
["REPAIR_VEH_PRONE", 1],\
["REPAIR_VEH_STAND", 1],\
["SHIELD_FROM_SUN", 0],\
["SHOCKED_1", 0],\
["SHOCKED_2", 0],\
["SIT1", 0],\
["SIT2", 0],\
["SIT3", 0],\
["SIT_AT_TABLE", 0],\
["SIT_HANDCUFFED", 1],\
["SIT_HIGH1", 0],\
["SIT_HIGH2", 0],\
["SIT_LOW", 0],\
["SIT_LOW_U", 1],\
["SIT_SAD1", 0],\
["SIT_SAD2", 0],\
["SIT_U1", 1],\
["SIT_U2", 1],\
["SIT_U3", 1],\
["STAND", 0],\
["STAND_IA", 0],\
["STAND_IDLE", 1],\
["STAND_PISTOL", 0],\
["STAND_TALKING", 1],\
["STAND_U1", 1],\
["STAND_U2", 1],\
["STAND_U3", 1],\
["UAV_JAMMING", 1],\
["VICTIM", 0],\
["WAKING", 0],\
["WARMUP", 1],\
["WARMUP_1", 1],\
["WARMUP_2", 1],\
["WARMUP_KNEELING", 0],\
["WATCH1", 0],\
["WATCH2", 0],\
["WORKING_AT_DESK", 0]]\

params ["_ctrlGroup", "_value"];
_value params ["_animSet", "_anims", "_canExit", "_attach"];
private _unarmedStr = localize "STR_ENH_AMBIENTANIMATIONS_UNARMED";
private _ctrlLB = (_ctrlGroup controlsGroupCtrl 100);
{
  _x params ["_animSetPreset", "_unarmed"];
  _ctrlLB lbAdd _animSetPreset;

  if (_animSet isEqualTo _animSetPreset) then
  {
    _ctrlLB lbSetCurSel _forEachIndex;
  };
  //Adds tooltip depending on preset
  _ctrlLB lbSetTooltip [_forEachIndex, format ["%1 %2.", _unarmedStr, localize (["STR_ENH_NO", "STR_ENH_YES"] select _unarmed)]];
} forEach ANIMSETS;

(_ctrlGroup controlsGroupCtrl 101) cbSetChecked _canExit;
(_ctrlGroup controlsGroupCtrl 102) cbSetChecked _attach;

//Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["buttonClick",
{
  private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

  (_ctrlGroup controlsGroupCtrl 100) lbSetCurSel 0;
  (_ctrlGroup controlsGroupCtrl 101) cbSetChecked false;
  (_ctrlGroup controlsGroupCtrl 102) cbSetChecked false;
}];