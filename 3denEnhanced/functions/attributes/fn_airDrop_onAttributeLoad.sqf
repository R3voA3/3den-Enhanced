/*
  Author: R3vo

  Date: 2019-07-15

  Description:
  Used by the airdrop attribute. Called when attribute is loaded.

  Parameter(s):
  0: CONTROL - Controls group
  1: ARRAY - Attribute value

  Returns:
  -
*/

params ["_ctrlGroup", "_value"];
_value params ["_classes", "_center", "_condition", "_alt", "_r", "_side"];

if (_classes isEqualType "") then
{
  (_ctrlGroup controlsGroupCtrl 100) ctrlSetText _classes;
}
else
{
  //Change classes from type array to type string
  private _valueClasses = "";

  {
    private _add = if (_foreachindex == 0) then {_x} else {format [", %1", _x]};
    _valueClasses= _valueClasses + _add;
  } foreach _classes;

  (_ctrlGroup controlsGroupCtrl 100) ctrlSetText _valueClasses;
};

(_ctrlGroup controlsGroupCtrl 101) ctrlSetText str _center;
(_ctrlGroup controlsGroupCtrl 102) ctrlSetText _condition;

[_ctrlGroup controlsGroupCtrl 103, _ctrlGroup controlsGroupCtrl 104, "m"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 103, _ctrlGroup controlsGroupCtrl 104, "m", _alt] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 105, _ctrlGroup controlsGroupCtrl 106, "m"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 105, _ctrlGroup controlsGroupCtrl 106, "m", _r] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 107) lbSetCurSel ([west, east, independent, civilian] find _side);

//Add reset event to reset button
(_ctrlGroup controlsGroupCtrl 5) ctrlAddEventHandler ["buttonClick",
{
  private _ctrlGroup = ctrlParentControlsGroup (_this select 0);

  (_ctrlGroup controlsGroupCtrl 100) ctrlSetText "";
  (_ctrlGroup controlsGroupCtrl 101) ctrlSetText "[0, 0, 0]";
  (_ctrlGroup controlsGroupCtrl 102) ctrlSetText "false";

  [_ctrlGroup controlsGroupCtrl 103, _ctrlGroup controlsGroupCtrl 104, "m", 500] call BIS_fnc_initSliderValue;
  [_ctrlGroup controlsGroupCtrl 105, _ctrlGroup controlsGroupCtrl 106, "m", 200] call BIS_fnc_initSliderValue;

  (_ctrlGroup controlsGroupCtrl 107) lbSetCurSel 0;
}];