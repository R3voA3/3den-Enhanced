/*
    Author: R3vo

    Date: 2019-07-15

    Description:
    Used by the intro text attribute. Call when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    -
*/

params ["_ctrlGroup", "_value"];
_value params ["_delay", "_line1", "_line2", "_line3", "_introType"];

[_ctrlGroup controlsGroupCtrl 100, _ctrlGroup controlsGroupCtrl 101, "s"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 100, _ctrlGroup controlsGroupCtrl 101, "s", _delay] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 102) ctrlSetText _line1;
(_ctrlGroup controlsGroupCtrl 103) ctrlSetText _line2;
(_ctrlGroup controlsGroupCtrl 104) ctrlSetText _line3;

(_ctrlGroup controlsGroupCtrl 105) lbSetCurSel _introType;

//Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["ButtonClick",
{
    private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

    [_ctrlGroup controlsGroupCtrl 100, _ctrlGroup controlsGroupCtrl 101, "s", 0] call BIS_fnc_initSliderValue;
    (_ctrlGroup controlsGroupCtrl 102) ctrlSetText briefingName;
    (_ctrlGroup controlsGroupCtrl 103) ctrlSetText ('by ' + profileName);
    (_ctrlGroup controlsGroupCtrl 104) ctrlSetText ([daytime, 'HH:MM'] call BIS_fnc_TimeToString);
    (_ctrlGroup controlsGroupCtrl 105) lbSetCurSel 0;
}];