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
    NOTHING
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
        if (_selection isEqualTo []) then
        {
            (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") params ["_pos3D"];
            _posArray pushBack [_pos3D#0, _pos3D#1];
        }
        else
        {
            private _pos = [];
            {
                _pos = ((_x get3DENAttribute "Position") # 0);
                _pos resize 2;
                _posArray pushBack _pos;
            } forEach _selection;
        };

        _export = [_posArray, false] call ENH_fnc_exportWithLB;
    };
    case "3D":
    {
        private _posArray = [];
        if (_selection isEqualTo []) then
        {
            (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") params ["_pos3D"];
            _posArray pushBack _pos3D;
        }
        else
        {
            {
                _posArray pushBack ((_x get3DENAttribute "Position") # 0);
            } forEach _selection;
        };

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
        private _text = [];
        {
            private _size = boundingBoxReal _x;
            private _p1 = _size # 0;
            private _p2 = _size # 1;
            private _maxWidth = abs ((_p2 # 0) - (_p1 # 0));
            private _maxLength = abs ((_p2 # 1) - (_p1 # 1));
            private _maxHeight = abs ((_p2 # 2) - (_p1 # 2));

            private _kind = "N/A";
            private _obj = _x;
            {
                if (_obj isKindOf _x) then {_kind = _x};
            } forEach ["Air", "Land", "Sea", "Tank", "Man"];

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

            _text pushBack
            ([
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_NAME", (configFile >> "CfgVehicles") call BIS_fnc_displayName,
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_CLASS", typeOf _x,
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_VEHICLECLASS", getText (configOf _x >> "vehicleClass"),
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_KINDOF", _kind,
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_SIZE", str [_maxWidth, _maxLength, _maxHeight],
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_PARENTS", str ([configOf _x, true] call BIS_fnc_returnParents),
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_OBJECTTYPE", _objType,
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_MODELINFO", str getModelInfo _x,
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_SELECTIONNAMES", str selectionNames _x,
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_MATERIALS", str getObjectMaterials _x,
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_TEXTURES", str getObjectTextures _x,
                localize "STR_ENH_MAIN_FUNCTIONS_LOGOBJECTINFO_ANIMATIONNAMES", str animationNames _x,
                "", "", "", "", ""
            ] joinString endl);
        } forEach (get3DENSelected "Object");

        if (true) exitWith
        {
            // Set variable used by Display3denCopy and create the display
            uiNamespace setVariable ["Display3DENCopy_data", [localize "STR_ENH_MAIN_CONTEXTMENU_LOGOBJECTINFO", _text joinString ""]];
            findDisplay IDD_DISPLAY3DEN createDisplay "Display3denCopy";
            nil
        };
    };
};

if (_export != "") then
{
    copyToClipboard _export;
    ["ENH_DataCopied"] call BIS_fnc_3DENNotification;
};

nil
