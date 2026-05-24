#include "\x\enh\addons\main\script_component.hpp"

disableSerialization;

params [["_mode", "add"]];

private _tvLocations = findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_SEARCH_TREE;
private _selectedPath = tvCurSel _tvLocations;
private _savedLocations = profileNamespace getVariable ["ENH_LocationList_CustomLocation", createHashMap];
private _savedLocationsWorld = _savedLocations getOrDefault [toUpper worldName, createHashMap];
private _customLocationsRoot = -1;
private _icon = getText (configFile >> "cfg3DEN" >> "Default" >> "Draw" >> "locationList");

switch _mode do
{
    case "add":
    {
        // Let the user define a name
        private _displayInputName = findDisplay IDD_DISPLAY3DEN createDisplay "Display3DENRename";

        _displayInputName displayAddEventHandler ["Unload",
        {
            isNil
            {
                params ["_display"];
                ENH_LocationsList_AddNew_Name = ctrlText CTRL(IDC_DISPLAY3DENRENAME_NAME);
            };
        }];

        waitUntil {isNull _displayInputName};

        if (ENH_LocationsList_AddNew_Name == "") exitWith {};

        // Check if locations folder already exists. Entry with value 42
        for "_i" from 0 to (_tvLocations tvCount [0]) - 1 do
        {
            if (_tvLocations tvValue [0, _i] == -42) exitWith
            {
                _customLocationsRoot = _i;
            };
        };

        // If not, create it
        if (_customLocationsRoot == -1) then
        {
            _customLocationsRoot = _tvLocations tvAdd [[0], localize "STR_ENH_MAIN_LOCATIONLIST_CUSTOMLOCATONS"];
            _tvLocations tvSetValue [[0, _customLocationsRoot], -42];
        };

        private _newEntryIndex = _tvLocations tvAdd [[0, _customLocationsRoot], ENH_LocationsList_AddNew_Name];
        _tvLocations tvSetPicture [[0, _customLocationsRoot, _newEntryIndex], _icon];

        // Get a unique index by finding the largest index + 1
        private _key = 0;
        {
            if (_x > _key) then {_key = _x};
        } forEach _savedLocationsWorld;

        _key = _key + 1;

        _tvLocations tvSetValue [[0, _customLocationsRoot, _newEntryIndex], _key];

        // Save date to profileNamespace
        _savedLocationsWorld set [_key, [getPosWorld get3DENCamera, vectorDir get3DENCamera, vectorUp get3DENCamera, ENH_LocationsList_AddNew_Name]];
        _savedLocations set [toUpper worldName, _savedLocationsWorld];
        profileNamespace setVariable ["ENH_LocationList_CustomLocation", _savedLocations];
        saveProfileNamespace;

        ENH_LocationsList_AddNew_Name = "";
    };
    case "delete":
    {
        // Custom locations have a value > 0
        if (_tvLocations tvValue _selectedPath < 1) exitWith {};

        // Update data in profileNamespace
        private _key = _tvLocations tvValue _selectedPath;
        _savedLocationsWorld deleteAt _key;
        _savedLocations set [toUpper worldName, _savedLocationsWorld];
        profileNamespace setVariable ["ENH_LocationList_CustomLocation", _savedLocations];
        saveProfileNamespace;

        _tvLocations tvDelete _selectedPath;
    };
    case "view":
    {
        private _key = _tvLocations tvValue _selectedPath;
        private _data = _savedLocationsWorld getOrDefault [_key, []];
        if (_data isEqualTo []) exitWith {};

        _data params ["_positionWorld", "_vectorDir", "_vectorUp"];

        get3DENCamera setPosWorld _positionWorld;
        get3DENCamera setVectorDirAndUp [_vectorDir, _vectorUp];
    };
    case "init":
    {
        // Fill list
        if (_savedLocationsWorld isEqualTo []) exitWith {};

        _customLocationsRoot = _tvLocations tvAdd [[0], localize "STR_ENH_MAIN_LOCATIONLIST_CUSTOMLOCATONS"];
        _tvLocations tvSetValue [[0, _customLocationsRoot], -42];

        {
            private _description = _y param [3, "------------------------------------------"];
            private _newEntryIndex = _tvLocations tvAdd [[0, _customLocationsRoot], _description];
            _tvLocations tvSetPicture [[0, _customLocationsRoot, _newEntryIndex], _icon];
            _tvLocations tvSetValue [[0, _customLocationsRoot, _newEntryIndex], _x];
        } forEach _savedLocationsWorld;

        private _fn_addMapObjects =
        {
            params ["_types", "_parentName", ["_isTerrainObject", true]];

            private _locations = call
            ([
                {nearestLocations [[0, 0, 0], _types, worldSize * sqrt 2]},
                {nearestTerrainObjects [[0, 0, 0], _types, worldSize * sqrt 2, false, true]}
            ] select _isTerrainObject);

            if (_locations isEqualTo []) exitWith {};

            private _parentIndex = _tvLocations tvAdd [[0], localize _parentName];
            {
                // Different name handling for locations vs objects
                private _name = "";
                if (_x isEqualType objNull) then
                {
                    _name = getText (configOf _x >> "displayName");
                    if (_name isEqualTo "") then
                    {
                        _name = getModelInfo _x # 0;
                        _name = _name trim [".p3d", 2];
                    };
                }
                else
                {
                    _name = name _x;
                };
                private _index = _tvLocations tvAdd [[0, _parentIndex], _name];

                _tvLocations tvSetData [[0, _parentIndex, _index], str position _x];
                _tvLocations tvSetPicture [[0, _parentIndex, _index], _icon];
            } forEach _locations;
            _tvLocations tvSort [[_parentIndex], false];
        };

        // Add all map objects
        [["Chapel"], "STR_ENH_MAIN_LOCATIONLIST_CHAPELS"] call _fn_addMapObjects;
        [["Church"], "STR_ENH_MAIN_LOCATIONLIST_CHURCHES"] call _fn_addMapObjects;
        [["FuelStation"], "STR_ENH_MAIN_LOCATIONLIST_FUELSTATIONS"] call _fn_addMapObjects;
        [["Powersolar", "Powerwind", "Powerwave"], "STR_ENH_MAIN_LOCATIONLIST_POWERPRODUCTION"] call _fn_addMapObjects;
        [["Shipwreck"], "STR_ENH_MAIN_LOCATIONLIST_SHIPWRECKS"] call _fn_addMapObjects;
        [["Transmitter"], "STR_ENH_MAIN_LOCATIONLIST_TRANSMITTERS"] call _fn_addMapObjects;
        [["Airport"], "STR_ENH_MAIN_LOCATIONLIST_AIRPORTS", false] call _fn_addMapObjects;

        tvExpandAll _tvLocations;
    };
};
