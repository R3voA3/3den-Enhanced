#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-02-22

    Description:
    Used by the advanced damage attribute. Called when attribute is loaded. It automatically create a set of controls for every
    available hitpoint and resizes the controls group accordingly. The IDCs have to be that large to make sure they are not in conflict with other controls created
    by Eden Editor.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
parseSimpleArray _value params ["_hitpoints", "_damage"];

private _display = ctrlParent _ctrlGroup;

// Adjust group positions
_ctrlGroup ctrlSetPositionY (2.5 * CTRL_DEFAULT_H); // For description
_ctrlGroup ctrlSetPositionH ((count _hitpoints max 1) * (CTRL_DEFAULT_H + 5 * pixelH));
_ctrlGroup ctrlCommit 0;

// Some objects such as B_static_AA_F have not hitpoints. In that case display a message
if (_hitpoints isEqualTo []) exitWith
{
    private _ctrlHintNoHitPoints = _display ctrlCreate ["ctrlStructuredText", -1, _ctrlGroup];
    _ctrlHintNoHitPoints ctrlSetPosition [5 * GRID_W, 0, (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 5) * GRID_W, CTRL_DEFAULT_H];
    _ctrlHintNoHitPoints ctrlCommit 0;
    _ctrlHintNoHitPoints ctrlSetBackgroundColor [1, 1, 1, 0.05];
    private _txt = text localize "STR_ENH_MAIN_ADVANCEDDAMAGE_NOHITPOINTS";
    _txt setAttributes ["align", "center", "size", "1.2"];
    _ctrlHintNoHitPoints ctrlSetStructuredText composeText [_txt];
};

private _counter = 0;

{
    _counter = _counter + 1;
    private _ctrlLabel = _display ctrlCreate ["ENH_3DEN_Attribute_Control_AttributeTitle", 20000 + _forEachIndex, _ctrlGroup];

    // String is build like this to prevent error when checking for missing localization keys
    private _name = format ["%1_%2_%3_%4_%5", "STR", "ENH", "MAIN", "DAMAGE", toUpper _x];

    _ctrlLabel ctrlSetText (if (isLocalized _name) then {localize _name} else {_x});
    _ctrlLabel ctrlSetTooltip _x;
    _ctrlLabel ctrlSetPosition [0, CTRL_DEFAULT_H * _forEachIndex + 5 * pixelH * _forEachIndex, ATTRIBUTE_TITLE_W * GRID_W, CTRL_DEFAULT_H];
    _ctrlLabel ctrlCommit 0;

    private _ctrlSlider = _display ctrlCreate ["ctrlXSliderH", 30000 + _forEachIndex, _ctrlGroup];
    _ctrlSlider ctrlSetPosition [ATTRIBUTE_TITLE_W * GRID_W, CTRL_DEFAULT_H * _forEachIndex + 5 * pixelH * _forEachIndex, (ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W, CTRL_DEFAULT_H];
    _ctrlSlider ctrlCommit 0;

    private _ctrlEdit = _display ctrlCreate ["ctrlEdit", 40000 + _forEachIndex, _ctrlGroup];
    _ctrlEdit ctrlSetPosition [(ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W, CTRL_DEFAULT_H * _forEachIndex + 5 * pixelH * _forEachIndex, EDIT_W * GRID_W, CTRL_DEFAULT_H];
    _ctrlEdit ctrlCommit 0;

    [_ctrlSlider, _ctrlEdit] call BIS_fnc_initSliderValue;
    [_ctrlSlider, _ctrlEdit, "%", _damage # _forEachIndex] call BIS_fnc_initSliderValue;
} forEach _hitpoints;

_ctrlGroup setVariable ["ENH_controlsCount", _counter];
