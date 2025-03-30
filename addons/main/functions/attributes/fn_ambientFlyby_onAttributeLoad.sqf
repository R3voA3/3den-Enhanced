#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the ambient flyby attribute. Call when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
_value params
[
    "_classes",
    "_startPos",
    "_endPos",
    "_alt",
    "_speed",
    "_side",
    "_delay",
    ["_rndStartOffset", 0],
    ["_rndEndOffset", 0],
    ["_rndDelayOffset", 0]
];

// if (_classes isEqualType "") then
// {
//     (_ctrlGroup controlsGroupCtrl 100) ctrlSetText _classes;
// }
// else
// {
//     //Change classes from type array to type string
//     private _valueClasses = "";

//     {
//         private _add = if (_forEachIndex == 0) then {_x} else {format [", %1", _x]};
//         _valueClasses = _valueClasses + _add;
//     } forEach _classes;

//     (_ctrlGroup controlsGroupCtrl 100) ctrlSetText _valueClasses;
// };

private _ctrlClassesTree = _ctrlGroup controlsGroupCtrl 100;

// Cache stuff
if (uiNamespace getVariable ["ENH_AmbientFlyby_AirClasses", []] isEqualTo []) then
{
    private _vehicleClasses = "getNumber (_x >> 'scope') == 2 && {configName _x isKindOf ['Air', configFile >> 'CfgVehicles']}" configClasses (configFile >> "CfgVehicles");

    private _data = [];

    _vehicleClasses apply
    {
        _data pushBack
        [
            configName _x,
            [_x] call BIS_fnc_displayName,
            getText (_x >> "icon"),
            [[getNumber (_x >> "side")] call BIS_fnc_sideType] call BIS_fnc_sideColor
        ];
    };

    uiNamespace setVariable ["ENH_AmbientFlyby_AirClasses", _data]
};

(uiNamespace getVariable ["ENH_AmbientFlyby_AirClasses", []]) apply
{
    _x params ["_configName", "_displayName", "_icon", "_sideColour"];

    private _isSelected = _configName in _classes;

    private _index = _ctrlClassesTree tvAdd [[], _displayName];
    _ctrlClassesTree tvSetTooltip [[_index], _configName + endl + endl + "Double click to add or remove the item."];// TODO: Translate 2025-03-29 R3vo
    _ctrlClassesTree tvSetPictureRight [[_index], [TEXTURE_UNCHECKED,  TEXTURE_CHECKED] select _isSelected];
    _ctrlClassesTree tvSetValue [[_index], parseNumber _isSelected];
    _ctrlClassesTree tvSetPicture [[_index], _icon];
    _ctrlClassesTree tvSetPictureColor [[_index], _sideColour];
};

_ctrlClassesTree tvSortByValue [[], false];

_ctrlClassesTree ctrlAddEventHandler ["TreeDblClick",
{
    params ["_ctrlClassesTree", "_path"];

    private _newValue = 1 - (_ctrlClassesTree tvValue _path);

    // Flip int
    _ctrlClassesTree tvSetValue [_path, _newValue];
    _ctrlClassesTree tvSetPictureRight [_path, [TEXTURE_UNCHECKED,  TEXTURE_CHECKED] select _newValue];
    _ctrlClassesTree tvSortByValue [[], false];
}];

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText _valueClasses;

(_ctrlGroup controlsGroupCtrl 101) ctrlSetText str _startPos;
(_ctrlGroup controlsGroupCtrl 102) ctrlSetText str _endPos;

(_ctrlGroup controlsGroupCtrl 104) ctrlSetText str _alt;

(_ctrlGroup controlsGroupCtrl 105) lbSetCurSel (["limited", "normal", "full"] find _speed);
(_ctrlGroup controlsGroupCtrl 106) lbSetCurSel ([west, east, independent, civilian] find _side);

(_ctrlGroup controlsGroupCtrl 107) ctrlSetText str _delay;

(_ctrlGroup controlsGroupCtrl 109) ctrlSetText str _rndStartOffset;
(_ctrlGroup controlsGroupCtrl 110) ctrlSetText str _rndStartOffset;
(_ctrlGroup controlsGroupCtrl 111) ctrlSetText str _rndDelayOffset;

//Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["ButtonClick",// TODO: Handle resetting tree view 2025-03-29 R3vo
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl 100) ctrlSetText "";

    (_ctrlGroup controlsGroupCtrl 101) ctrlSetText "[0,0,0]";
    (_ctrlGroup controlsGroupCtrl 102) ctrlSetText "[0,0,0]";

    (_ctrlGroup controlsGroupCtrl 104) ctrlSetText "500";

    (_ctrlGroup controlsGroupCtrl 105) lbSetCurSel 1;
    (_ctrlGroup controlsGroupCtrl 106) lbSetCurSel 0;

    (_ctrlGroup controlsGroupCtrl 107) ctrlSetText "300";

    (_ctrlGroup controlsGroupCtrl 109) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl 110) ctrlSetText "0";
    (_ctrlGroup controlsGroupCtrl 111) ctrlSetText "0";
}];
