/*
  Author: R3vo

  Date: 2021-08-28

  Description:
  Tools to handle pylons in Eden Editor

  Parameter(s):
  0: STRING - Action to be taken, can be "copy" or "apply"

  Returns:
  -
*/

params [["_mode", "copy"]];

if (get3DENSelected "Object" isEqualTo []) exitWith {["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification; nil};

switch (_mode) do
{
  case "copy":
  {
    private _object = get3DENSelected "Object" # 0;
    uiNamespace setVariable ["ENH_PylonData", [typeOf _object, _object get3DENAttribute "Pylons"]];
    ["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
  };
  case "apply":
  {
    private _pylonData = uiNamespace getVariable ["ENH_PylonData", []];
    if (_pylonData isEqualTo []) exitWith {};
    _pylonData params ["_vehicleClass", "_data"];

    {
      if (_vehicleClass isEqualTo typeOf _x) then
      {
        _x set3DENAttribute ["Pylons", _data # 0];
      };
    } forEach (get3DENSelected "Object");
    ["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
  };
};

nil