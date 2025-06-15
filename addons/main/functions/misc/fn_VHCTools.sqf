#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-08-29

    Description:
    Tools to customize vehicle appearance in Eden Editor.

    Parameter(s):
    0: STRING - Action to be taken. Can be "copy", "apply", "random"

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
        uiNamespace setVariable ["ENH_VHCData", [typeOf _object, _object get3DENAttribute "VehicleCustomization" select 0, _object get3DENAttribute "ObjectTexture" select 0]];
        ["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
    };
    case "apply":
    {
        private _VHCData = uiNamespace getVariable ["ENH_VHCData", []];
        if (_VHCData isEqualTo []) exitWith {};
        _VHCData params ["_vehicleClass", "_animations", "_texture"];

        {
            if (_vehicleClass isEqualTo typeOf _x) then
            {
                _x set3DENAttribute ["VehicleCustomization", _animations];
                _x set3DENAttribute ["ObjectTexture", _texture];
            };
        } forEach (get3DENSelected "Object");
        ["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
    };
    case "random":
    {
        {
            private _type = typeOf _x;
            private _centerFaction = faction _x;
            private _data = [];

            {
                private _items = [];
                {
                    _displayName = getText (_x >> "displayName");
                    _factions = getArray (_x >> "factions");
                    if (_factions isEqualTo []) then {_factions = [_centerFaction]};
                    if (_displayName != "" && {getNumber (_x >> "scope") > 1 || !isNumber (_x >> "scope")} && {{_x == _centerFaction} count _factions > 0}) then
                    {
                        _items pushBack configName _x;
                        _items pushBack selectRandom [0, 1];
                    };
                } forEach (configProperties [_x, "isClass _x", true]);
                _data pushBack _items;
            } forEach [configFile >> "CfgVehicles" >> _type >> "textureSources", configFile >> "CfgVehicles" >> _type >> "animationSources"];
            _data params ["_textures", "_animations"];
            _textures = _textures select {_x isEqualType ""}; // Only select the textures and ignore the state
            _x set3DENAttribute ["VehicleCustomization", [[], _animations]]; // Only animations are set via this attribute. Textures are handled differently
            _x set3DENAttribute ["ObjectTexture", selectRandom _textures];
        } forEach (get3DENSelected "Object");
        ["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
    };
};

nil
