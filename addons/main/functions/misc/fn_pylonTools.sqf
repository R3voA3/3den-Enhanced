#include "\x\enh\addons\main\script_component.hpp"

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

switch _mode do
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
    case "exportToSQF":
    {
        private _value = ((get3DENSelected "object" # 0) get3DENAttribute "Pylons") # 0;
        private _export = "";
        private _pylons = [];

        while {_value != ""} do
        {
            private _index = _value find ";";
            if (_index < 0) then {_index = count _value - 1};
            private _pylon = _value select [0, _index];
            private _turretIndex = _pylon find "[";
            if (_turretIndex >= 0) then
            {
                _pylon = _pylon select [0, _turretIndex];
            };
            _pylons pushBack _pylon;
            _value = _value select [_index + 1, count _value - 1];
        };

        {
            _export = _export + format ["this setPylonLoadout [%1, ""%2""];", _forEachIndex + 1, _x] + endl
        } forEach _pylons;

        uiNamespace setVariable ["display3DENCopy_data", [localize "STR_ENH_MAIN_TOOLS_EXPORTPYLONSTOSQF", _export]];
        findDisplay IDD_DISPLAY3DEN createDisplay "display3denCopy";
    };
};

nil
