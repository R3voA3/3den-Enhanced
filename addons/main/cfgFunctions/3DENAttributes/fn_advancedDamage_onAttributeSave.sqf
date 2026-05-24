#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-02-22

    Description:
    Used by the advanced damage attribute. Called when attribute is saved.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    STRING: Attribute value
*/

params ["_ctrlGroup"];

private _countControls = _ctrlGroup getVariable ["ENH_controlsCount", 0];
private _hitPoints = [];
private _hitPointsDamage = [];

for "_idc" from 20000 to (20000 + _countControls - 1) do
{
    _hitPoints append [ctrlTooltip (_ctrlGroup controlsGroupCtrl _idc)];
    _hitPointsDamage append [sliderPosition (_ctrlGroup controlsGroupCtrl _idc + 10000)];
};

str [_hitPoints, _hitPointsDamage];
