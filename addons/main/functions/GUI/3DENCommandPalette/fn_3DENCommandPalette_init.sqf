#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-21

    Description:
    Initializes the 3DEN Command Palette.

    Parameter(s):
    1:
    2:

    Return Value:
    NUMBER - State
*/

disableSerialization;

params [["_display3DEN", findDisplay IDD_DISPLAY3DEN], ["_state", 0]];

#define GROUP_H 51
#define UI_W 120
#define UI_Y (WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H)

ctrlDelete (_display3DEN getVariable ["ENH_3DENCommandPalette_ControlsGroup", controlNull]);

if (_state == -1) exitWith {_state};

if (_state == 0) then
{
    // Top position

};

if (_state == 1) then
{

};

private _fnc_addCommand =
{
    params ["_action", "_picture", "_shortcuts", "_text"];

    private _row = _ctrlListNBox lnbAddRow ["", _text, _shortcuts];

    _ctrlListNBox lnbSetPicture [[_row, 0], _picture];
    _ctrlListNBox lnbSetData [[_row, 0], _action];

    private _commands = findDisplay IDD_DISPLAY3DEN getVariable ["ENH_3DENCommandPalette_Commands", []];

    _commands pushBack
    [
        _action,
        _picture,
        _shortcuts,
        _text
    ];

    findDisplay IDD_DISPLAY3DEN setVariable ["ENH_3DENCommandPalette_Commands", _commands];
};

private _3DENActions =
[
    // "AddCustomConnection",
    // "AddUnitToSel",
    // "AddWaypoint",
    // "CenterCameraOnPlayer",
    // "ChangeSeat",
    // "ClearSelections",
    // "CopyUnit",
    // "CreateAndChangeComment",
    // "CreateComment",
    // "CreateCustomComposition",
    // "CutUnit",
    // "DeleteCustomComposition",
    // "DeleteUnits",
    // "EditCustomComposition",
    // "Exit3DEN",
    // "ForceToFormation",
    // "GroupWith",
    // "LevelOutObjects",
    // "LevelWithSurface",
    // "MissionExportMP",
    // "MissionExportSP",
    // "MissionLoad",
    // "MissionMerge",
    // "MissionNew",
    // "MissionPartIntro",
    // "MissionPartMission",
    // "MissionPartOutroLoose",
    // "MissionPartOutroWin",
    // "MissionPreview",
    // "MissionPreviewBriefing",
    // "MissionPreviewMP",
    // "MissionSave",
    // "MissionSaveAs",
    // "MoveGridDecrease",
    // "MoveGridIncrease",
    // "MoveGridToggle",
    // "OpenAttributes",
    // "OpenIntelDisplay",
    // "OpenRequiredAddons",
    // "OpenSteamPublishDialog",
    // "OptionsAudio",
    // "OptionsControls",
    // "OptionsGame",
    // "OptionsVideo",
    // "PasteUnit",
    // "PasteUnitOrig",
    // "PublishCustomComposition",
    // "Redo",
    // "RestoreEditTreeExpansion",
    // "RotateGridDecrease",
    // "RotateGridIncrease",
    // "RotateGridToggle",
    // "ScaleGridToggle",
    // "SearchCreate",
    // "SearchEdit",
    // "SelectAllOnScreen",
    // "SelectGroupMode",
    // "SelectLayerAllDescendants",
    // "SelectLayerChildren",
    // "SelectMarkerMode",
    // "SelectModuleMode",
    // "SelectObjectMode",
    // "SelectSubmode1",
    // "SelectSubmode2",
    // "SelectSubmode3",
    // "SelectSubmode4",
    // "SelectSubmode5",
    // "SelectSubmode6",
    // "SelectTriggerMode",
    // "SelectUnit",
    // "SelectWaypointMode",
    // "SetFlyingHeight",
    // "SetTriggerOwner",
    // "SetWaypointActivation",
    // "SubmodeToggle",
    // "SurfaceSnapDisable",
    // "SurfaceSnapEnable",
    // "SurfaceSnapToggle",
    // "SyncWith",
    // "ToggleMap",
    // "ToggleMapIDs",
    // "ToggleMapTextures",
    // "TogglePlaceEmptyVehicle",
    // "ToggleUnitSel",
    // "ToggleVegetation",
    // "Undo",
    // "Unknown",
    // "VerticalASL",
    // "VerticalATL",
    // "VerticalToggle",
    // "WidgetArea",
    // "WidgetCoord",
    // "WidgetNone",
    // "WidgetRotation",
    // "WidgetScale",
    // "WidgetSpaceLocal",
    // "WidgetSpaceWorld",
    // "WidgetToggle",
    // "WidgetTranslation"
    "addcustomconnection",
    "addunittosel",
    "addwaypoint",
    "centercameraonplayer",
    "changeseat",
    "clearselections",
    "copyunit",
    "createandchangecomment",
    "createcomment",
    "createcustomcomposition",
    "cutunit",
    "deletecustomcomposition",
    "deleteunits",
    "editcustomcomposition",
    "exit3den",
    "forcetoformation",
    "groupwith",
    "leveloutobjects",
    "levelwithsurface",
    "missionexportmp",
    "missionexportsp",
    "missionload",
    "missionmerge",
    "missionnew",
    "missionpartintro",
    "missionpartmission",
    "missionpartoutroloose",
    "missionpartoutrowin",
    "missionpreview",
    "missionpreviewbriefing",
    "missionpreviewmp",
    "missionsave",
    "missionsaveas",
    "movegriddecrease",
    "movegridincrease",
    "movegridtoggle",
    "openattributes",
    "openinteldisplay",
    "openrequiredaddons",
    "opensteampublishdialog",
    "optionsaudio",
    "optionscontrols",
    "optionsgame",
    "optionsvideo",
    "pasteunit",
    "pasteunitorig",
    "publishcustomcomposition",
    "redo",
    "restoreedittreeexpansion",
    "rotategriddecrease",
    "rotategridincrease",
    "rotategridtoggle",
    "scalegridtoggle",
    "searchcreate",
    "searchedit",
    "selectallonscreen",
    "selectgroupmode",
    "selectlayeralldescendants",
    "selectlayerchildren",
    "selectmarkermode",
    "selectmodulemode",
    "selectobjectmode",
    "selectsubmode1",
    "selectsubmode2",
    "selectsubmode3",
    "selectsubmode4",
    "selectsubmode5",
    "selectsubmode6",
    "selecttriggermode",
    "selectunit",
    "selectwaypointmode",
    "setflyingheight",
    "settriggerowner",
    "setwaypointactivation",
    "submodetoggle",
    "surfacesnapdisable",
    "surfacesnapenable",
    "surfacesnaptoggle",
    "syncwith",
    "togglemap",
    "togglemapids",
    "togglemaptextures",
    "toggleplaceemptyvehicle",
    "toggleunitsel",
    "togglevegetation",
    "undo",
    "unknown",
    "verticalasl",
    "verticalatl",
    "verticaltoggle",
    "widgetarea",
    "widgetcoord",
    "widgetnone",
    "widgetrotation",
    "widgetscale",
    "widgetspacelocal",
    "widgetspaceworld",
    "widgettoggle",
    "widgettranslation"
];

private _fnc_search =
{
    params ["_ctrlEdit", "_searchText"];

    private _ctrlListNBox = findDisplay IDD_DISPLAY3DEN getVariable ["ENH_3DENCommandPalette_ListNBox", controlNull];
    private _commands = findDisplay IDD_DISPLAY3DEN getVariable ["ENH_3DENCommandPalette_Commands", []];

    lnbClear _ctrlListNBox;

    _commands apply
    {
        _x params ["_action", "_picture", "_shortcuts", "_text"];

        if (_searchText == "" || {toLower _searchText in toLower _text}) then
        {
            private _row = _ctrlListNBox lnbAddRow ["", _text, _shortcuts];

            _ctrlListNBox lnbSetPicture [[_row, 0], _picture];
            _ctrlListNBox lnbSetData [[_row, 0], _action];
        };
    };
};

private _fnc_mouseHandler =
{
    params ["_display3DEN", "", "", ["_mouseOver", -1, [true, 0]]];


    getMousePosition params ["_mouseX", "_mouseY"];

    private _ctrlGroup = _display3DEN getVariable ["ENH_3DENCommandPalette_ControlsGroup", controlNull];
    private _ctrlEdit = _display3DEN getVariable ["ENH_3DENCommandPalette_Edut", controlNull];
    private _ctrlScrollBlock = _display3DEN getVariable ["ENH_3DENCommandPalette_ScrollBlock", controlNull];

    // That way we can overwrite mouseOver from other scripts
    if (_mouseOver isEqualType 0) then
    {
        _mouseOver = _display3DEN ctrlAt [_mouseX, _mouseY] == _ctrlGroup
    };

    _ctrlScrollBlock ctrlSetPositionH ([7 * GRID_H, GROUP_H * GRID_H] select _mouseOver);

    _ctrlGroup ctrlSetPositionH ([7 * GRID_H, GROUP_H * GRID_H] select _mouseOver);
    _ctrlGroup ctrlSetFade ([0.5, 0] select _mouseOver);

    _ctrlScrollBlock ctrlCommit 0;
    _ctrlGroup ctrlCommit 0;



    if (focusedCtrl _display3DEN == _ctrlEdit && {ctrlPosition _ctrlGroup select 3 < GROUP_H * GRID_H}) then
    {
        findDisplay IDD_DISPLAY3DEN getVariable "ENH_3DENCommandPalette_Edit" ctrlSetText "";
        ctrlSetFocus (findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_MOUSEAREA);
    };
};

private _fnc_execCommand =
{
    params ["_ctrlListNBox", "_row"];

    private _code = _ctrlListNBox lnbData [_row, 0];

    if (_code != "") then
    {
        call compile _code;
    };

    ctrlDelete ctrlParentControlsGroup _ctrlListNBox;
};

// private _ctrlGroup = _display3DEN ctrlCreate ["ctrlControlsGroupNoScrollbars", 1001];
// private _ctrlImgLeft = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", 1002, _ctrlGroup];
// private _ctrlImgRight = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", 1003, _ctrlGroup];
// private _ctrlBackgroundEdit = _display3DEN ctrlCreate ["ctrlStaticBackground", 1004, _ctrlGroup];
// private _ctrlBackgroundList = _display3DEN ctrlCreate ["ctrlStaticBackground", 1005, _ctrlGroup];
// private _ctrlEdit = _display3DEN ctrlCreate ["ctrlEdit", 645, _ctrlGroup];
// private _ctrlListNBox = _display3DEN ctrlCreate ["ctrlListNBox", 1006, _ctrlGroup];
// private _ctrlFooter = _display3DEN ctrlCreate ["ctrlStaticFooter", 1007, _ctrlGroup];

private _ctrlGroup = _display3DEN displayCtrl 80001;
private _ctrlImgLeft = _display3DEN displayCtrl 80002;
private _ctrlImgRight = _display3DEN displayCtrl 80003;
private _ctrlBackgroundEdit = _display3DEN displayCtrl 80004;
private _ctrlBackgroundList = _display3DEN displayCtrl 80005;
private _ctrlEdit = _display3DEN displayCtrl 80006;
private _ctrlListNBox = _display3DEN displayCtrl 80007;
private _ctrlFooter = _display3DEN displayCtrl 80008;

private _ctrlScrollBlock = _display3DEN displayCtrl 80009;

private _groupPos =
[
    0.5 - UI_W * 0.5 * GRID_W - 4 * GRID_W,
    [(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H), safeZoneY + safeZoneH - (7 + 4 + 1 + GROUP_H) * GRID_H] select _state,
    UI_W * GRID_W,
    GROUP_H * GRID_H
];

_ctrlScrollBlock ctrlSetPosition _groupPos;
_ctrlGroup ctrlSetPosition _groupPos;

_ctrlImgLeft ctrlSetText "\x\enh\addons\main\data\left_ca.paa";

_ctrlImgLeft ctrlSetPosition
[
    0,
    [0, (GROUP_H - 7) * GRID_H] select _state,
    7 * GRID_W,
    7 * GRID_H
];

_ctrlImgRight ctrlSetText "\x\enh\addons\main\data\right_ca.paa";

_ctrlImgRight ctrlSetPosition
[
    UI_W * GRID_W - 7 * GRID_W,
    0,
    7 * GRID_W,
    7 * GRID_H
];

_ctrlBackgroundEdit ctrlSetPosition
[
    7 * GRID_W,
    0,
    (UI_W - 14) * GRID_W,
    7 * GRID_H
];

_ctrlBackgroundList ctrlSetPosition
[
    4 * GRID_W,
    7 * GRID_H,
    (UI_W - 8) * GRID_W,
    (GROUP_H - 7) * GRID_H
];

_ctrlEdit ctrlSetPosition
[
    4 * GRID_W,
    GRID_H,
    (UI_W - 8) * GRID_W,
    5 * GRID_H
];

_ctrlFooter ctrlSetPosition
[
    4 * GRID_W,
    GROUP_H * GRID_H - CTRL_DEFAULT_H,
    (UI_W - 8) * GRID_W,
    CTRL_DEFAULT_H
];

_ctrlFooter ctrlSetText "HOLD CTRL TO PREVENT SCROLLING THE BACKGROUND";// TODO: Localize 2025-06-23 R3vo

_ctrlListNBox lnbAddColumn 8 * GRID_W;
_ctrlListNBox lnbAddColumn 110 * GRID_W;

_ctrlListNBox ctrlSetPosition
[
    4 * GRID_W,
    7 * GRID_H,
    (UI_W - 8) * GRID_W,
    39 * GRID_H
];

private _menuStripItems = "true" configClasses (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items");
private _cfg3DENCommands = "true" configClasses (configFile >> "Cfg3DEN" >> "ENH_Command_Pallet_Commands");

(_menuStripItems + _cfg3DENCommands) apply
{
    private _action = getText (_x >> "action");
    private _text = getText (_x >> "text");
    private _data = getText (_x >> "data");

    if (_text == "") then {continue};

    if (getText (_x >> "weblink") != "") then {continue};

    // Entries that have no action nor data are folders or separators
    if (_action == "" && {_data == ""}) then {continue};

    // Let's check if an action was added in _cfg3DENCommands
    if (_action == "" && {_data != ""}) then
    {
        // Check if the data entry is a valid 3den action
        if (toLower _data in _3DENActions) then
        {
            _action = format ["do3DENAction %1", str _data];
        };

        // If still empty we ignore it entirely
        if (_action == "") then {continue};
    };

    if (getNumber (_x >> "opensNewWindow") == 1) then
    {
        _text = _text + "...";
    };

    private _picture = getText (_x >> "picture");
    private _shortcuts = [[getArray (_x >> "shortcuts")]] call ENH_fnc_3DENShortcuts_parseShortcut;

    [_action, _picture, _shortcuts, _text] call _fnc_addCommand;
};

// Read JSON files
(getArray (configFile >> "Cfg3DEN" >> "ENH_3DENCommandPalette" >> "JSONFilePaths")) apply
{
    private _filePath = _x;

    if !(fileExists _filePath) then
    {
        diag_log format ["3DEN Enhanced: Failed to load file (%1) into Command Palette", _filePath];
        continue;
    };

    private _data = fromJSON loadFile _filePath;

    _data apply
    {
        [
             _y get "action",
             _y get "picture",
             [[_y get "shortcuts"]] call ENH_fnc_3DENShortcuts_parseShortcut,
             _y get "text"
        ] call _fnc_addCommand;
    };
};

_ctrlListNBox lnbSort [1, false];

_display3DEN displayAddEventHandler ["MouseMoving", _fnc_mouseHandler];
_ctrlEdit ctrlAddEventHandler ["EditChanged", _fnc_search];
_ctrlListNBox ctrlAddEventHandler ["LBDblClick", _fnc_execCommand];

private _controls = [_ctrlListNBox, _ctrlEdit, _ctrlBackgroundEdit, _ctrlBackgroundEdit, _ctrlImgLeft, _ctrlImgRight, _ctrlGroup, _ctrlScrollBlock];

_ctrlGroup ctrlCommit 0;
allControls _ctrlGroup apply {_x ctrlCommit 0};

// _display3DEN displayAddEventHandler ["KeyDown",
// {
//     params ["_display3DEN", "_key", "", "_ctrl"];

//     if (_key == DIK_P && {_ctrl}) then
//     {
//         private _ctrlEdit = _display3DEN getVariable ["ENH_3DENCommandPalette_Edit", controlNull];
//         ctrlSetFocus _ctrlEdit;
//         [_display3DEN, nil, nil, true] call (_display3DEN getVariable ["ENH_3DENCommandPalette_MouseHandler", {}])
//     };
// }];

_display3DEN setVariable ["ENH_3DENCommandPalette_ControlsGroup", _ctrlGroup];
_display3DEN setVariable ["ENH_3DENCommandPalette_ListNBox", _ctrlListNBox];
_display3DEN setVariable ["ENH_3DENCommandPalette_Edit", _ctrlEdit];
_display3DEN setVariable ["ENH_3DENCommandPalette_ScrollBlock", _ctrlScrollBlock];
_display3DEN setVariable ["ENH_3DENCommandPalette_MouseHandler", _fnc_mouseHandler];

// TODO: Move control toolbar 2025-06-23 R3vo

true
