#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2022-04-11

    Description:
    Moves selected entities into selected layer.

    Parameter(s):
    0: CONTROL - Button control

    Returns:
    BOOLEAN
*/

params ["_ctrlButton"];

private _ctrlTV = ctrlParent _ctrlButton displayCtrl IDC_MOVETOLAYER_TREE;

if (tvCurSel _ctrlTV isEqualTo []) exitWith {false};

private _layerID = _ctrlTV tvValue (tvCurSel _ctrlTV);

collect3DENHistory
{
    {
        _x set3DENLayer _layerID;
    } forEach ([] call ENH_fnc_all3DENSelected);
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true
