#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-09-30

    Description:
    Handles the favorites panel in Eden Editor.

    Parameter(s):
    0: STRING - Action to be taken
    1: ARRAY - Arguments

    Returns:
    BOOLEAN - True
*/

#define FAVORITES_DATA (profileNamespace getVariable ["ENH_HashMap_Favorites", createHashMap])

disableSerialization;
params [["_mode", "onLoad"], ["_arguments", []]];

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

switch _mode do
{
    case "onLoad":
    {
        private _ctrlTV =  _display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_TREE;

        _ctrlTV ctrlAddEventHandler ["TreeMouseMove",
        {
            params ["_ctrlTV", "_path"];
            ["showPreview", [_ctrlTV, _path]] call ENH_fnc_favoritesList;
        }];

        _ctrlTV ctrlAddEventHandler ["TreeMouseHold",
        {
            params ["_ctrlTV", "_path"];
            ["showPreview", [_ctrlTV, _path]] call ENH_fnc_favoritesList;
        }];

        _ctrlTV ctrlAddEventHandler ["MouseExit",
        {
            ["hidePreview", []] call ENH_fnc_favoritesList;
        }];

        _ctrlTV ctrlAddEventHandler ["TreeSelChanged",
        {
            ["treeSelChanged", []] call ENH_fnc_favoritesList;
        }];

        _display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_BUTTON_DELETE ctrlAddEventHandler ["ButtonClick",
        {
            ["delete", []] call ENH_fnc_favoritesList;
        }];

        _display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_BUTTON_EXPAND ctrlAddEventHandler ["ButtonClick",
        {
            ["expand"] call ENH_fnc_favoritesList;
        }];

        _display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_BUTTON_COLLAPSE ctrlAddEventHandler ["ButtonClick",
        {
            ["collapse"] call ENH_fnc_favoritesList;
        }];

        [_display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_SEARCH, _display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_BUTTON_SEARCH] call ENH_fnc_initSearchControls;


        ["updateTreeView"] call ENH_fnc_favoritesList;
    };
    case "contextMenu":
    {
        private _savedData = FAVORITES_DATA;

        // Get all unique selected entities that are not already in the favorites list
        [["Object", "Marker", "Logic"]] call ENH_fnc_all3DENSelected apply
        {
            private _entity = _x;
            private _data = [];
            private _class = "";

            if (_entity isEqualType "") then
            {
                _class = _entity get3DENAttribute "itemClass" select 0;
                _data =
                [
                    "marker",
                    ["rectangle", "ellipse", "icon"] select (_entity get3DENAttribute "markerType" select 0)
                ];
            }
            else
            {
                _class = typeOf _entity;

                if (_class isKindOf "Logic") then
                {
                    _data = ["module"];
                }
                else
                {
                    _data = ["object"];
                };
            };

            // Add entry to list (insertOnly)
            _savedData set [_class, _data, true];
        };

        profileNamespace setVariable ["ENH_HashMap_Favorites", _savedData];
        saveProfileNamespace;

        ["updateTreeView"] call ENH_fnc_favoritesList;
    };
    case "showPreview":
    {
        _arguments params ["_ctrlTV", "_path"];

        private _ctrlStaticPreviewBackground = _display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_PREVIEW_BG;
        private _ctrlStaticPreview = _display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_PREVIEW_PICTURE;
        private _class = _ctrlTV tvData _path;

        if (_class == "") exitWith
        {
            ["hidePreview", []] call ENH_fnc_favoritesList;
        };

        private _picture = getText (configFile >> "CfgVehicles" >> _class >> "editorPreview");

        if (_picture == "") exitWith
        {
            ["hidePreview", []] call ENH_fnc_favoritesList;
        };

        _ctrlStaticPreview ctrlSetText _picture;

        (getTextureInfo _picture) params ["_width", "_height"];
        private _imageHeight = 27;
        private _imageWidthCalculated = ((_imageHeight * GRID_W) * _width / _height);
        private _xPos = safeZoneX + safeZoneW - 62 * GRID_W - _imageWidthCalculated;
        private _yPos = (getMousePosition select 1) min (safeZoneY + safeZoneH * 0.80);

        _ctrlStaticPreview ctrlSetPositionX _xPos;
        _ctrlStaticPreview ctrlSetPositionY _yPos;
        _ctrlStaticPreview ctrlSetPositionW _imageWidthCalculated;
        _ctrlStaticPreview ctrlSetPositionH (_imageHeight * GRID_H);

        _ctrlStaticPreview ctrlCommit 0;

        _ctrlStaticPreviewBackground ctrlSetPosition
        [
            (ctrlPosition _ctrlStaticPreview select 0) - GRID_W,
            (ctrlPosition _ctrlStaticPreview select 1) - GRID_H,
            (ctrlPosition _ctrlStaticPreview select 2) + 2 * GRID_W,
            (ctrlPosition _ctrlStaticPreview select 3) + 2 * GRID_H
        ];

        _ctrlStaticPreviewBackground ctrlCommit 0;

        _ctrlStaticPreviewBackground ctrlShow true;
        _ctrlStaticPreview ctrlShow true;
    };
    case "hidePreview":
    {
        (_display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_PREVIEW_PICTURE) ctrlShow false;
        (_display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_PREVIEW_BG) ctrlShow false;
    };
    case "treeSelChanged":
    {
        private _ctrlTV = findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_TREE;
        private _selectedPath = tvCurSel _ctrlTV;

        // Category selected, not an item
        if (count _selectedPath < 2) exitWith
        {
            _display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_BUTTON_DELETE ctrlEnable false;
        };

        _display3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_BUTTON_DELETE ctrlEnable true;

        private _savedData = FAVORITES_DATA;

        private _class = _ctrlTV tvData _selectedPath;
        private _type = _savedData get _class select 0;
        private _shape = _savedData get _class select 1;

        set3DENAttachedCursorEntity createHashMapFromArray [["type", _type], ["classname", _class], ["markershape", _shape]];
    };
    case "delete":
    {
        private _ctrlTV = findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_TREE;
        private _selection = tvSelection _ctrlTV;
        private _savedData = FAVORITES_DATA;

        if (_selection isEqualTo []) exitWith {};

        {
            private _class = _ctrlTV tvData _x;
            _savedData deleteAt _class;
        } forEach _selection;

        profileNamespace setVariable ["ENH_HashMap_Favorites", _savedData];
        saveProfileNamespace;

        ["updateTreeView"] call ENH_fnc_favoritesList;
    };
    case "updateTreeView":
    {
        private _ctrlTV = findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_TREE;

        // Reset search otherwise we might end up with duplicates
        findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_SEARCH ctrlSetText "";

        tvClear _ctrlTV;

        _ctrlTV tvAdd [[], localize "$STR_3DEN_MARKER_TEXTPLURAL"];
        _ctrlTV tvAdd [[], localize "$STR_3DEN_LOGIC_TEXTPLURAL"];
        _ctrlTV tvAdd [[], localize "$STR_3DEN_OBJECT_TEXTPLURAL"];

        {
            private _key = _x;
            _y params [["_entityType", ""], ["_markerType", ""]];

            private _indexFolder = 0;
            private _displayName = "";
            private _color = [1, 1, 1, 1];
            private _icon = "";
            private _addonIcon = "";

            switch _entityType do
            {
                case "object";
                case "module":
                {
                    private _config = configFile >> "CfgVehicles" >> _key;

                    if !(isClass _config) then {continue};

                    _displayName = getText (_config >> "displayName");
                    _addonIcon = (_config call ENH_fnc_getConfigSourceAddon) param [2, ""];

                    _color = switch true do
                    {
                        case (_key isKindOf "Static");
                        case (_key isKindOf "Thing"): {[8] call BIS_fnc_sideColor};
                        case (_entityType == "module"): {[1, 1, 1, 1]};
                        default {[getNumber (_config >> "side")] call BIS_fnc_sideColor};
                    };

                    _icon = getText (_config >> "icon");

                    if (!fileExists _icon) then
                    {
                        _icon = getText (configFile >> "CfgVehicleIcons" >> _icon);
                    };

                    _indexFolder = [1, 2] select (_entityType == "object");
                };
                case "marker":
                {
                    private _config = configFile >> "CfgMarkers" >> _key;

                    if (!isClass _config) then {continue};

                    _displayName = getText (_config >> "name");
                    _addonIcon = (_config call ENH_fnc_getConfigSourceAddon) param [2, ""];
                    _color = (getArray (_config >> "color")) call BIS_fnc_parseNumberSafe;
                    _icon = getText (_config >> "icon");
                    _indexFolder = 0;
                };
            };

            private _indexItem = _ctrlTV tvAdd [[_indexFolder], _displayName];

            _ctrlTV tvSetData [[_indexFolder, _indexItem], _key];
            _ctrlTV tvSetTooltip [[_indexFolder, _indexItem], _displayName + "\n" + _key];
            _ctrlTV tvSetPictureRight [[_indexFolder, _indexItem], _addonIcon];

            if (fileExists _icon) then
            {
                _ctrlTV tvSetPicture [[_indexFolder, _indexItem], _icon];
                _ctrlTV tvSetPictureColor [[_indexFolder, _indexItem], _color];
            }
            else
            {
                _ctrlTV tvSetPicture [[_indexFolder, _indexItem], "\a3\modules_f\data\portraitmodule_ca.paa"];
            };
        } forEach FAVORITES_DATA;

        _ctrlTV tvSortAll [[], false];
    };
    case "collapse":
    {
        tvCollapseAll (findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_TREE);
    };
    case "expand":
    {
        tvExpandAll (findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_FAVORITES_TREE);
    };
};

true
