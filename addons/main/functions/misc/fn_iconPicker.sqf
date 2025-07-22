#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-07

    Description:
    An icon picker UI. The selected icon is saved in the uiNamespace variable "ENH_IconPicker_Icon" when the
    UI was closed by pressing OK.

    Parameter(s):
    0: DISPLAY - Parent display
    1: CONTROL - Target control. The selected image will be set as text to this control when UI is closed
    2: ARRAY - Default icons to fill the UI with
    3: STRING - Default icon. This icon will be selected when the UI is opened
    4: NUMBER - Margin size in pixel count
    5: NUMBER - Number of icons displayed in one row. The UI's width is adjusted accordingly
    6: NUMBER - Size of each tile in GRID_W
    7: NUMBER - Maximum height of the UI in GRID_H

    Return Value:
    BOOL - True on success, false if failed
*/

params
[
    ["_parentDisplay", findDisplay IDD_DISPLAY3DEN],
    ["_targetControl", controlNull],
    ["_icons", []],
    ["_defaultIcon", ""],
    ["_tileRowCount", 5],
    ["_tileWGridCount", 15],
    ["_tileHGridCount", 15],
    ["_maxHeightGridCount", 100]
];

// Init the UI if it doesn't exist
if (isNull (uiNamespace getVariable ["ENH_DisplayIconPicker", displayNull])) then
{
    private _displayIconPicker = _parentDisplay createDisplay (["RscDisplayEmpty", "ENH_DisplayEmpty"] select (isClass (configFile >> "ENH_DisplayEmpty")));

    _displayIconPicker displayAddEventHandler ["Unload",
    {
        params ["_displayIconPicker", "_exitCode"];

        if (_exitCode == 1) then
        {
            private _ctrlIcon = _displayIconPicker getVariable "targetControl";
            private _iconPath = _displayIconPicker getVariable "selectedIcon";

            _ctrlIcon ctrlSetText _iconPath;
        };
    }];

    private _marginH = GRID_H;
    private _marginW = GRID_W;
    private _scrollBarW = GRID_W;
    private _tileW = _tileWGridCount * GRID_W;
    private _tileH = _tileHGridCount * GRID_H;

    private _totalHeight = _maxHeightGridCount * GRID_H;
    private _totalWidth = _marginW + 2 * _scrollBarW + (_tileRowCount * (_tileW + _marginW)) max 84 * GRID_W;

    _displayIconPicker ctrlCreate ["ctrlStaticBackgroundDisable", -1];
    _displayIconPicker ctrlCreate ["ctrlStaticBackgroundDisableTiles", -1];

    private _ctrlTitle = _displayIconPicker ctrlCreate ["ctrlStaticTitle", -1];
    _ctrlTitle ctrlSetPosition [CENTER_X - _totalWidth * 0.5, 0.5 - _totalHeight * 0.5 - CTRL_DEFAULT_H, _totalWidth, _totalHeight];

    private _ctrlFooterBackground = _displayIconPicker ctrlCreate ["ctrlStaticBackground", -1];
    _ctrlFooterBackground ctrlSetPosition [CENTER_X - _totalWidth * 0.5, 0.5 + _totalHeight * 0.5, _totalWidth, CTRL_DEFAULT_H + 2 * GRID_H + _marginH];

    private _ctrlFooter = _displayIconPicker ctrlCreate ["ctrlStaticFooter", -1];
    _ctrlFooter ctrlSetPosition [CENTER_X - _totalWidth * 0.5, 0.5 + _totalHeight * 0.5 + _marginH, _totalWidth, CTRL_DEFAULT_H + 2 * GRID_H];

    private _buttonY = CENTER_X + _totalHeight * 0.5 + _marginH + GRID_H;
    private _buttonW = 25 * GRID_W;

    private _ctrlButtonCancel = _displayIconPicker ctrlCreate ["ctrlButtonCancel", 2];
    _ctrlButtonCancel ctrlSetPosition [CENTER_X + _totalWidth * 0.5 - (25 + 1) * GRID_W, _buttonY, _buttonW, CTRL_DEFAULT_H];

    private _ctrlButtonOK = _displayIconPicker ctrlCreate ["ctrlButtonOK", 1];
    _ctrlButtonOK ctrlSetPosition [CENTER_X + _totalWidth * 0.5 - (25 + 1 + 25 + 1) * GRID_W, _buttonY, _buttonW, CTRL_DEFAULT_H];

    private _ctrlBackground = _displayIconPicker ctrlCreate ["ctrlStaticBackground", -1];
    _ctrlBackground ctrlSetPosition [CENTER_X - _totalWidth * 0.5, 0.5 - _totalHeight * 0.5, _totalWidth, _totalHeight];

    private _ctrlControlsGroup = _displayIconPicker ctrlCreate ["ctrlControlsGroup", -1];
    _ctrlControlsGroup ctrlSetPosition [CENTER_X - _totalWidth * 0.5, 0.5 - _totalHeight * 0.5, _totalWidth, _totalHeight];
    _displayIconPicker setVariable ["CtrlGroup", _ctrlControlsGroup];

    private _ctrlSearch = _displayIconPicker ctrlCreate ["ctrlEdit", -1];
    _ctrlSearch ctrlSetPosition [CENTER_X + _totalWidth * 0.5 - (25 + 1 + 25 + 1 + 5 + 1 + 25) * GRID_W, _buttonY, _buttonW, CTRL_DEFAULT_H];

    private _ctrlButtonSearch = _displayIconPicker ctrlCreate ["ctrlButtonSearch", -1];
    _ctrlButtonSearch ctrlSetPosition [CENTER_X + _totalWidth * 0.5 - (25 + 1 + 25 + 1 + 5 + 1) * GRID_W, _buttonY, 5 * GRID_W, CTRL_DEFAULT_H];

    private _fnc_createFrame =
    {
        params [["_ctrlTile", controlNull]];

        private _displayIconPicker = ctrlParent _ctrlTile;

        // Code wise it's easier to just delete the old frame than reusing it
        _displayIconPicker getVariable ["framePieces", []] apply
        {
            ctrlDelete _x;
        };

        private _ctrlControlsGroup = ctrlParentControlsGroup _ctrlTile;
        private _ctrlFrameLeft = _displayIconPicker ctrlCreate ["ctrlStatic", -1, _ctrlControlsGroup];
        private _ctrlFrameTop = _displayIconPicker ctrlCreate ["ctrlStatic", -1, _ctrlControlsGroup];
        private _ctrlFrameRight = _displayIconPicker ctrlCreate ["ctrlStatic", -1, _ctrlControlsGroup];
        private _ctrlFrameBottom = _displayIconPicker ctrlCreate ["ctrlStatic", -1, _ctrlControlsGroup];

        _displayIconPicker setVariable ["framePieces", [_ctrlFrameLeft, _ctrlFrameTop, _ctrlFrameRight, _ctrlFrameBottom]];

        ctrlPosition _ctrlTile params ["_tileX", "_tileY", "_tileW", "_tileH"];

        private _marginW = _displayIconPicker getVariable "marginW";
        private _marginH = _displayIconPicker getVariable "marginH";

        private _frameColor =
        [
            profileNamespace getVariable ["GUI_BCG_RGB_R", 0.77],
            profileNamespace getVariable ["GUI_BCG_RGB_G", 0.51],
            profileNamespace getVariable ["GUI_BCG_RGB_B", 0.08],
            1
        ];

        _ctrlFrameLeft ctrlSetPosition
        [
            _tileX - _marginW,
            _tileY,
            _marginW,
            _tileH
        ];

        _ctrlFrameTop ctrlSetPosition
        [
            _tileX - _marginW,
            _tileY - _marginH,
            _tileW + 2 * _marginW,
            _marginH
        ];

        _ctrlFrameRight ctrlSetPosition
        [
            _tileX + _tileW,
            _tileY,
            _marginW,
            _tileH
        ];

        _ctrlFrameBottom ctrlSetPosition
        [
            _tileX - _marginW,
            _tileY + _tileH,
            _tileW + 2 * _marginW,
            _marginH
        ];

        [_ctrlFrameLeft, _ctrlFrameTop, _ctrlFrameRight, _ctrlFrameBottom] apply
        {
            _x ctrlSetBackgroundColor _frameColor;
            _x ctrlCommit 0;
        };
    };

    // Store everything for later
    _displayIconPicker setVariable ["targetControl", _targetControl];
    _displayIconPicker setVariable ["group", _ctrlControlsGroup];
    _displayIconPicker setVariable ["icons", _icons];
    _displayIconPicker setVariable ["marginW", _marginW];
    _displayIconPicker setVariable ["marginH", _marginH];
    _displayIconPicker setVariable ["tileW", _tileW];
    _displayIconPicker setVariable ["tileH", _tileH];
    _displayIconPicker setVariable ["tileRowCount", _tileRowCount];
    _displayIconPicker setVariable ["parameters", _this];
    _displayIconPicker setVariable ["fn_createFrame", _fnc_createFrame];

    uiNamespace setVariable ["ENH_DisplayIconPicker", _displayIconPicker];

    _ctrlSearch ctrlAddEventHandler ["EditChanged",
    {
        params ["_ctrlEdit", "_text"];

        private _displayIconPicker = ctrlParent _ctrlEdit;
        private _filteredIcons = (_displayIconPicker getVariable ["icons", []]) select
        {
            toLower _text in toLower _x
        };
        private _parameters = _displayIconPicker getVariable "parameters";

        _parameters set [2, _filteredIcons];
        _parameters call ENH_fnc_iconPicker;
    }];

    allControls _displayIconPicker apply {_x ctrlCommit 0};

    [_ctrlSearch, _ctrlButtonSearch] call ENH_fnc_initSearchControls;
};

// Fill the UI, also used for filtering
private _currentColumnCount = 0;
private _currentRowCount = 0;

private _displayIconPicker = uiNamespace getVariable ["ENH_DisplayIconPicker", displayNull];
private _ctrlControlsGroup = _displayIconPicker getVariable "group";

allControls _ctrlControlsGroup apply {ctrlDelete _x};

{
    if !(fileExists _x) then
    {
        ["3den Enhanced: Tried to add file that does not exist to icon picker."] call BIS_fnc_error;
        continue;
    };

    private _marginH = _displayIconPicker getVariable "marginH";
    private _marginW = _displayIconPicker getVariable "marginW";
    private _tileH = _displayIconPicker getVariable "tileH";
    private _tileW = _displayIconPicker getVariable "tileW";
    private _tileRowCount =_displayIconPicker getVariable "tileRowCount";

    private _xPos = _currentRowCount * (_tileW + _marginW) + _marginW;
    private _yPos = _currentColumnCount * (_tileH + _marginH) + _marginH;

    private _ctrlTileBackGround = _displayIconPicker ctrlCreate ["ctrlStaticBackground", -1, _ctrlControlsGroup];
    _ctrlTileBackGround ctrlSetPosition [_xPos, _yPos, _tileW, _tileH];
    _ctrlTileBackGround ctrlSetBackgroundColor [0.1, 0.1, 0.1, 1];

    private _ctrlTile = _displayIconPicker ctrlCreate ["ctrlActivePictureKeepAspect", -1, _ctrlControlsGroup];
    _ctrlTile ctrlSetPosition [_xPos, _yPos, _tileW, _tileH];

    _ctrlTile ctrlSetText _x;
    _ctrlTile ctrlSetTooltip _x;
    _ctrlTile ctrlSetTextColor [1, 1, 1, 1];
    _ctrlTile ctrlCommit 0;

    _ctrlTile ctrlAddEventHandler ["ButtonClick",
    {
        params ["_ctrlTile"];

        private _displayIconPicker = ctrlParent _ctrlTile;
        _displayIconPicker setVariable ["selectedIcon", ctrlText _ctrlTile];

        [_ctrlTile] call (_displayIconPicker getVariable "fn_createFrame");
    }];

    if (_x == _defaultIcon) then
    {
        [_ctrlTile] call (_displayIconPicker getVariable "fn_createFrame");
    };

    _currentRowCount = _currentRowCount + 1;

    if (_currentRowCount == _tileRowCount) then
    {
        _currentRowCount = 0;
        _currentColumnCount = _currentColumnCount + 1;
    };
} forEach _icons;

true
