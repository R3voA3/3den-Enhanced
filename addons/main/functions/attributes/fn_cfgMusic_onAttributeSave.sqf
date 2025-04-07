#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the CfgMusic attribute.

    Parameter(s):
    0: CONTROL - Controls group

    Returns:
    ARRAY: Attribute value, array of CfgMusic classes
*/

params ["_ctrlGroup"];

private _ctrlClassesTree = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;
private _classes = [];

for "_i" from 0 to (_ctrlClassesTree tvCount []) - 1 do
{
    if (_ctrlClassesTree tvValue [_i] > 0) then
    {
        _classes pushBack (_ctrlClassesTree tvData [_i]);
    };
};

_classes
