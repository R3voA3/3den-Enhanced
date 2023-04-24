/*
	Author: linkion and R3vo

	Description:
	Apply the Virtual Arsenal Manager selection to an 3DEN object.

	Parameter(s):
	0: Object - 3DEN Object to apply attribute(s) to
	1: true - whether to apply ace arsenal attribute

	Returns:
	-

	Usage:
	[_box, true, true] call ENH_fnc_VAM_applyAttribute;
*/

params["_object", "_aceBool", "_biBool"];

private _selectHashMap = uiNamespace getVariable ["ENH_VAM_selectHashMap", createHashMap];


if (_aceBool && isClass(configFile >> "CfgPatches" >> "ace_arsenal")) then {
  _object set3DENAttribute ["ace_arsenal_attribute", [keys _selectHashMap, 0]];
};

if (_biBool) then {
  private _weapons = [];
  private _magazines = [];
  private _items = [];
  private _backpacks = [];

  {
    // Current result is saved in variable _x
    _y params ["", "", "", "", "_category", "", "", "_class"];
    switch (toLower(_category)) do {
      case "weapon": {
        _weapons pushBack _class;
      };
      case "mine";
      case "magazine": {
        _magazins pushBack _class;
      };
      case "items";
      case "equipment": {
        if (_class isEqualTo "Backpack") then {
          _backpacks pushBack _class;
        } else {
          _items pushBack _class;
        };
      };
    };
  } forEach _selectHashMap;

  private _value = str
  [
    [
      [_weapons, []],
      [_magazines, []],
      [_items, []],
      [_backpacks, []]
    ],
    true
  ];

  _object set3DENAttribute ["ammoBox", _value];
};