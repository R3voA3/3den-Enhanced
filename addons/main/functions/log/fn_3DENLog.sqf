#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-12-03

    Description:
    Logs data to clipboard.

    Parameter(s):
    0: STRING - Action to be taken. Can be:
        "IDS":                Logs Eden Editor IDs of selected objects to clipboard
        "CLASSES":        Logs classes of selected objects to clipboard
        "FACTIONS":        Logs factions of selected objects to clipboard
        "GRIDPOS":        Logs grid positions of selected objects to clipboard
        "2D":                 Logs positions in 2D format of selected objects to clipboard
        "3D":                 Logs positions in 3D format of selected objects to clipboard
        "VARNAMES":        Logs variable neames of selected objects to clipboard
        "OBJECTINFO": Collects various information about selected objects and opens Display3DENCopy

    Returns:
    -
*/

params [["_mode", ""]];

if (_mode == "") exitWith {};

private _export = "";
private _selection = [["Object", "Logic", "Trigger", "Marker", "Waypoint"]] call ENH_fnc_all3DENSelected;

switch _mode do
{
    case "IDS":
    {
        private _IDs = _selection apply {get3DENEntityID _x};
        _export = [_IDs, false] call ENH_fnc_exportWithLB;
    };
    case "CLASSES":
    {
        private _classes = [];
        {
            _classes pushBackUnique ((_x get3DENAttribute "ItemClass") # 0);
        } forEach _selection;
        _export = [_classes, false] call ENH_fnc_exportWithLB;
    };
    case "FACTIONS":
    {
        private _factions = [];
        {
            _factions pushBackUnique faction _x;
        } forEach (get3DENSelected "object");
        _export = [_factions, false] call ENH_fnc_exportWithLB;
    };
    case "GRIDPOS":
    {
        private _posArray = [];
        _selection = [] call ENH_fnc_all3DENSelected;

        if (_selection isEqualTo []) then
        {
            (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") params ["_pos3D"];
            _posArray pushBack mapGridPosition _pos3D;
        }
        else
        {
            {
                _posArray pushBackUnique mapGridPosition ((_x get3DENAttribute "Position") # 0);
            } forEach _selection;
        };
        _export = [_posArray, false] call ENH_fnc_exportWithLB;
    };
    case "2D":
    {
        private _posArray = [];
        private _pos = [];
        {
            _pos = ((_x get3DENAttribute "Position") # 0);
            _pos resize 2;
            _posArray pushBack _pos;
        } forEach _selection;
        _export = [_posArray, false] call ENH_fnc_exportWithLB;
    };
    case "3D":
    {
        private _posArray = [];
        {
            _posArray pushBack ((_x get3DENAttribute "Position") # 0);
        } forEach _selection;

        _export = [_posArray, false] call ENH_fnc_exportWithLB;
    };
    case "VARNAMES":
    {
        private _varNames = [];
        _selection append ([["Group"]] call ENH_fnc_all3DENSelected);
        private _markers = [["Marker"]] call ENH_fnc_all3DENSelected;

        {
            _varNames pushBack ((_x get3DENAttribute "Name") # 0);
        } forEach _selection;

        if (_markers isNotEqualTo []) then
        {
            {
                _varNames pushBack ((_x get3DENAttribute "MarkerName") # 0);
            } forEach _markers;
        };
        _export = [_varNames select {_x != ""}, false] call ENH_fnc_exportWithLB;
    };
    case "OBJECTINFO":
    {
        private _text = "";
        {
            private _class = typeOf _x;
            private _vehClass = getText (configFile >> "CfgVehicles" >> _class >> "vehicleClass");
            private _name = (configFile >> "CfgVehicles" >> _class) call BIS_fnc_displayName;
            private _size = boundingBoxReal _x;
            private _p1 = _size # 0;
            private _p2 = _size # 1;
            private _maxWidth = abs ((_p2 # 0) - (_p1 # 0));
            private _maxLength = abs ((_p2 # 1) - (_p1 # 1));
            private _maxHeight = abs ((_p2 # 2) - (_p1 # 2));
            _size = str [_maxWidth, _maxLength, _maxHeight];

            private _parents = str ([configFile >> "CfgVehicles" >> _class, true] call BIS_fnc_returnParents);
            private _modelInfo = str getModelInfo _x;

            private _kind = "N/A";
            private _obj = _x;
            {
                if (_obj isKindOf _x) then {_kind = _x};
            } forEach ["Air", "Land", "Sea", "Tank", "Man"];

            private _selectionNames = selectionNames _x;

            _selectionNamesFormatted = "";
            {
                if (_forEachIndex != (count _selectionNames) - 1 ) then
                {
                    _selectionNamesFormatted = _selectionNamesFormatted + _x + ", " + endl;
                }
                else
                {
                    _selectionNamesFormatted = _selectionNamesFormatted + _x;
                };
            } forEach _selectionNames;

            private _objType = switch (getObjectType _x) do
            {
                case 1:
                {
                    ("1 - Primary - " + localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_PRIMARY");
                };
                case 2:
                {
                    ("2 - Network - " + localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_NETWORK");
                };
                case 4:
                {
                    ("4 - Temporary - " + localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_TEMPORARY");
                };
                case 8:
                {
                    ("8 - TypeVehicle - " + localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_TYPEVEHICLE");
                };
                case 16:
                {
                    ("16 - TypeTempVehicle - " + localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_TYPETEMPVEHICLE");
                };
                case 32:
                {
                    ("32 - LandDecal - " + localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_LANDDECAL");
                };
            };
            private _materials = str getObjectMaterials _x;
            private _textures = str getObjectTextures _x;
            private _animationNames = str animationNames _x;

            _text =  _text +
            ([
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_NAME" + endl + _name + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_CLASS" + endl + _class + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_VEHICLECLASS" + endl + _vehClass + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_KINDOF" + endl + _kind + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_SIZE" + endl + _size + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_SELECTIONNAMES"  + endl + _selectionNamesFormatted + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_PARENTS" + endl + _parents + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_MODELINFO" + endl + _modelInfo + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_OBJECTTYPE" + endl + _objType + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_MATERIALS" + endl + _materials + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_TEXTURES" + endl + _textures + endl,
                    localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_ANIMATIONNAMES" + endl + _animationNames + endl,
                    endl + endl + endl + endl
                ] joinString endl);
        } forEach (get3DENSelected "Object");

        if (true) exitWith
        {
            // Set variable used by Display3denCopy and create the display
            uiNamespace setVariable ["Display3DENCopy_data", [localize "STR_ENH_MAIN_CONTEXTMENU_LOGOBJECTINFO", _text]];
            findDisplay IDD_DISPLAY3DEN createDisplay "Display3denCopy";
            nil
        };
    };
};

if (_export != "") then
{
    copyToClipboard _export;
    ["ENH_DataCopied"] call BIS_fnc_3DENNotification;
    nil
};
