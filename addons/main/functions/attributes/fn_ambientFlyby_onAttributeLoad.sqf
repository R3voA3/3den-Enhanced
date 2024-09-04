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
_value params ["_classes", "_startPos", "_endPos", "_alt", "_speed", "_side", "_delay"];

if (_classes isEqualType "") then
{
    (_ctrlGroup controlsGroupCtrl 100) ctrlSetText _classes;
}
else
{
    //Change classes from type array to type string
    private _valueClasses = "";

    {
        private _add = if (_forEachIndex == 0) then {_x} else {format [", %1", _x]};
        _valueClasses= _valueClasses + _add;
    } forEach _classes;

    (_ctrlGroup controlsGroupCtrl 100) ctrlSetText _valueClasses;
};

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText _valueClasses;

(_ctrlGroup controlsGroupCtrl 101) ctrlSetText str _startPos;
(_ctrlGroup controlsGroupCtrl 102) ctrlSetText str _endPos;

[_ctrlGroup controlsGroupCtrl 103, _ctrlGroup controlsGroupCtrl 104, "m"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 103, _ctrlGroup controlsGroupCtrl 104, "m", _alt] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 105) lbSetCurSel (["limited", "normal", "full"] find _speed);
(_ctrlGroup controlsGroupCtrl 106) lbSetCurSel ([west, east, independent, civilian] find _side);

[_ctrlGroup controlsGroupCtrl 107, _ctrlGroup controlsGroupCtrl 108, "s"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 107, _ctrlGroup controlsGroupCtrl 108, "s", _delay] call BIS_fnc_initSliderValue;

//Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    (_ctrlGroup controlsGroupCtrl 100) ctrlSetText "";

    (_ctrlGroup controlsGroupCtrl 101) ctrlSetText "[0, 0, 0]";
    (_ctrlGroup controlsGroupCtrl 102) ctrlSetText "[0, 0, 0]";

    [_ctrlGroup controlsGroupCtrl 103, _ctrlGroup controlsGroupCtrl 104, "m", 500] call BIS_fnc_initSliderValue;

    (_ctrlGroup controlsGroupCtrl 105) lbSetCurSel 1;
    (_ctrlGroup controlsGroupCtrl 106) lbSetCurSel 0;

    [_ctrlGroup controlsGroupCtrl 107, _ctrlGroup controlsGroupCtrl 108, "s", 300] call BIS_fnc_initSliderValue;
}];
