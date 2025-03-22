#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the SPR attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
_value params ["_ruletSet", "_respawnTime", "_canDie", "_restoreLoadout", "_onRespawnCode"];

private _ctrlComboRuleset = _ctrlGroup controlsGroupCtrl 100;

_ctrlComboRuleset lbAdd localize "STR_3DEN_ATTRIBUTES_RESPAWN_NONE_TEXT";
_ctrlComboRuleset lbAdd localize "STR_3DEN_ATTRIBUTES_RESPAWN_INSTANT_TEXT";

private _index = _ctrlComboRuleset lbAdd localize "STR_ENH_MAIN_SPR_RULESET_RANDOMPOSITION";
_ctrlComboRuleset lbSetTooltip [_index, localize "STR_ENH_MAIN_SPR_RULESET_RANDOMPOSITION_TOOLTIP"];

_index = _ctrlComboRuleset lbAdd localize "STR_ENH_MAIN_SPR_RULESET_NEARESTPOSITION";
_ctrlComboRuleset lbSetTooltip [_index, localize "STR_ENH_MAIN_SPR_RULESET_RANDOMPOSITION_TOOLTIP"];

_ctrlComboRuleset ctrlAddEventHandler ["LBSelChanged",
{
    params ["_ctrlComboRuleset", "_selectedIndex"];

    private _state = (_selectedIndex != 0);
    ctrlParentControlsGroup _ctrlComboRuleset controlsGroupCtrl 101 ctrlEnable _state;
    ctrlParentControlsGroup _ctrlComboRuleset controlsGroupCtrl 102 ctrlEnable _state;
    ctrlParentControlsGroup _ctrlComboRuleset controlsGroupCtrl 103 ctrlEnable _state;
    ctrlParentControlsGroup _ctrlComboRuleset controlsGroupCtrl 104 ctrlEnable _state;
    ctrlParentControlsGroup _ctrlComboRuleset controlsGroupCtrl 105 ctrlEnable _state;
}];

_ctrlComboRuleset lbSetCurSel _ruletSet;

[_ctrlGroup controlsGroupCtrl 101, _ctrlGroup controlsGroupCtrl 102, "s"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 101, _ctrlGroup controlsGroupCtrl 102, "s", _respawnTime] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 103) cbSetChecked _canDie;

(_ctrlGroup controlsGroupCtrl 104) cbSetChecked _restoreLoadout;

(_ctrlGroup controlsGroupCtrl 105) ctrlSetText _onRespawnCode;

//Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl 100) lbSetCurSel 0;
    [_ctrlGroup controlsGroupCtrl 101, _ctrlGroup controlsGroupCtrl 102, "s", 20] call BIS_fnc_initSliderValue;
    (_ctrlGroup controlsGroupCtrl 103) cbSetChecked false;
    (_ctrlGroup controlsGroupCtrl 104) cbSetChecked false;
    (_ctrlGroup controlsGroupCtrl 105) ctrlSetText "";
}];
