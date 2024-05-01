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

//Ace Arsenal apply
if (_aceBool) then {
  _object set3DENAttribute ["ace_arsenal_attribute", [keys _selectHashMap, 0]];
};

//Bohemia Interactive Arsenal apply
if (_biBool) then {
  private _weapons = [];
  private _magazines = [];
  private _items = [];
  private _backpacks = [];

  {
    //Current key is saved in variable _x
    private _configName = toLower(_x);
    _y params ["", "", "", "", ["_category", ""], ["_specificType", ""]];

    switch (true) do
    {
      case (_category isEqualTo "Weapon"):
      {
        _weapons pushBack _configName;
        //_weaponsAmount pushBack _amount;
      };
      case (_category in ["Mine", "Magazine"]):
      {
        _magazines pushBack _configName;
        //_magazinesAmount pushBack _amount;
      };
      case (_category in ["Item", "Equipment"]):
      {
        if (_specificType isEqualTo "Backpack") then
        {
          _backpacks pushBack _configName;
          //_backpacksAmount pushBack _amount;
        }
        else
        {
          _items pushBack _configName;
          //_itemsAmount pushBack _amount;
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
  _object set3DENAttribute ["ammobox", _value];
};