/*
	Author: linkion and R3vo

	Description:
	Apply the Virtual Arsenal Manager selection to an 3DEN object.

	Parameter(s):
	0: Object - 3DEN Object to apply attribute(s) to
	1: true - whether to apply ace arsenal attribute

	Returns:
	_selectHashMap

	Usage:
	_selectHashMap = [_display, _object] call ENH_fnc_VAM_loadObject;
*/

params ["_display", "_object"];

private _returnSelectHashMap = createHashMap;

if (_aceBool && isClass(configFile >> "CfgPatches" >> "ace_arsenal")) then {
  private _buttonOk = format ["Ace Arsenal (%1 Selected)", count (keys ([_object] call _fnc_getAceArsenalAttr))];
  private _buttonCancel = format ["BI Arsenal (%1 Selected)", count (keys ([_object] call _fnc_getBIArsenalAttr))];
  private _returnAce = false;
  ["Detected that ace is loaded, choose which arsenal to edit", "Which to Edit?", [_buttonOK, {_returnAce = true}], [_buttonCancel, {_returnAce = false}], _display] call BIS_fnc_3DENShowMessage;
  if (_returnAce) then {
    [_object] call _fnc_getAceArsenalAttr
  } else {
    [_object] call _fnc_getBIArsenalAttr
  };
} else {
  [_object] call _fnc_getBIArsenalAttr
};

private _fnc_getAceArsenalAttr = {
  params ["_object"];

  private _returnSelectHashMap = createHashMap;

  if (_aceBool && isClass(configFile >> "CfgPatches" >> "ace_arsenal")) then {
    private _aceAttribute = _object get3DENAttribute ["ace_arsenal_attribute", [keys _selectHashMap, 0]];
    if ((count _aceAttribute) == 0) then {

    };
    {
      // Current result is saved in variable _x
      private _itemVal = (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap]) get toLower _x;
      _returnSelectHashMap insert [toLower(_x), _itemVal];
    } forEach _aceAttribute;
  };

  _returnSelectHashMap
};

private _fnc_getBIArsenalAttr = {
  params ["_object"];
  private _biAttribute = _object get3DENAttribute ["ammoBox"];
  {
    {
      {
        private _itemVal = (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap]) get toLower _x;
        _returnSelectHashMap insert [toLower(_x), _itemVal];
      } forEach (_x select 0);
    } forEach _x;
  } forEach (_biAttribute select 0);

  _returnSelectHashMap
};