#include "\x\enh\addons\main\script_component.hpp"

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
["GUARD", 0],\
["HANDS_HELD_HIGH", 0],\
["HIDING_1", 0],\
["HIDING_2", 0],\
["IDLE_1", 0],\
["IDLE_2", 0],\
["INJURED_ARMS", 0],\
["INJURED_CHEST", 0],\
["INJURED_GENERAL", 0],\
["INJURED_HEAD", 0],\
["INJURED_LEGS", 0],\
["KNEEL", 1],\
["KNEEL_TREAT", 0],\
["LEAN", 1],\
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
["REPAIR_VEH_KNEEL", 0],\
["REPAIR_VEH_PRONE", 0],\
["REPAIR_VEH_STAND", 0],\
["SHIELD_FROM_SUN", 1],\
["SHOCKED_1", 0],\
["SHOCKED_2", 0],\
["SIT1", 1],\
["SIT2", 1],\
["SIT3", 1],\
["SIT_AT_TABLE", 0],\
["SIT_HANDCUFFED", 0],\
["SIT_HIGH1", 1],\
["SIT_HIGH2", 1],\
["SIT_LOW", 1],\
["SIT_LOW_U", 0],\
["SIT_SAD1", 0],\
["SIT_SAD2", 0],\
["SIT_U1", 0],\
["SIT_U2", 0],\
["SIT_U3", 0],\
["STAND", 1],\
["STAND_IA", 1],\
["STAND_IDLE", 0],\
["STAND_PISTOL", 1],\
["STAND_TALKING", 0],\
["STAND_U1", 0],\
["STAND_U2", 0],\
["STAND_U3", 0],\
["UAV_JAMMING", 1],\
["VICTIM", 0],\
["WAKING", 0],\
["WARMUP", 1],\
["WARMUP_1", 1],\
["WARMUP_2", 0],\
["WARMUP_KNEELING", 1],\
["WATCH1", 1],\
["WATCH2", 1],\
["WORKING_AT_DESK", 0]]\

params ["_ctrlGroup", "_value"];
_value params ["_animSet", "_anims", "_canExit", "_attach"];
private _ctrlLB = (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00);
{
    _x params ["_animSetPreset", "_armed"];
    if (_forEachIndex == 0) then
    {
        _ctrlLB lbAdd localize "STR_DISABLED";
        _ctrlLB lbSetData [0, ""];
    }
    else
    {
        private _index = _ctrlLB lbAdd _animSetPreset;
        _ctrlLB lbSetData [_index, _animSetPreset];
        _ctrlLB lbSetPictureRight [_index, ["", "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\spacearsenal_ca.paa"] select _armed];
    };

    if (_animSet isEqualTo _animSetPreset) then
    {
        _ctrlLB lbSetCurSel _forEachIndex;
    };
} forEach ANIMSETS;

(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) cbSetChecked _canExit;
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) cbSetChecked _attach;

// Add reset event to reset button
(_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_BUTTON_RESET) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) lbSetCurSel 0;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_01) cbSetChecked false;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_02) cbSetChecked false;
}];
