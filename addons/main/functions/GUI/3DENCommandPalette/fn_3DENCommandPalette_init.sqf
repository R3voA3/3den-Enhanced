#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-21

    Description:
    This is an awesome description.

    Parameter(s):
    0: ARRAY - Some description, optional, default false

    Return Value:
    ARRAY - True on success, false if failed

    Examples(s):
    [] call ENH_fnc_missionDisplay;
*/

disableSerialization;

#define GROUP_H 51
#define UI_W 120
#define UI_Y (WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H)

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

ctrlDelete (_display3DEN getVariable ["ENH_3DENCommandPalette_ControlsGroup", controlNull]); // TODO: remove later 2025-06-22 R3vo

private _ctrlGroup = _display3DEN ctrlCreate ["ctrlControlsGroupNoScrollbars", 1001];
private _ctrlImgLeft = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", 1002, _ctrlGroup];
private _ctrlImgRight = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", 1003, _ctrlGroup];
private _ctrlBackground = _display3DEN ctrlCreate ["ctrlStaticBackground", 1004, _ctrlGroup];
private _ctrlEdit = _display3DEN ctrlCreate ["ctrlEdit", 645, _ctrlGroup];
private _ctrlListNBox = _display3DEN ctrlCreate ["ctrlListNBox", 1005, _ctrlGroup];
private _ctrlFooter = _display3DEN ctrlCreate ["ctrlStaticFooter", 1006, _ctrlGroup];

_ctrlGroup ctrlSetPosition
[
    0.5 - UI_W * 0.5 * GRID_W - 4 * GRID_W,
    UI_Y,
    UI_W * GRID_W,
    GROUP_H * GRID_H
];

_ctrlImgLeft ctrlSetText "\x\enh\addons\main\data\left_ca.paa";

_ctrlImgLeft ctrlSetPosition
[
    0,
    0,
    5 * GRID_W,
    7 * GRID_H
];

_ctrlImgRight ctrlSetText "\x\enh\addons\main\data\right_ca.paa";

_ctrlImgRight ctrlSetPosition
[
    UI_W * GRID_W - 5 * GRID_W,
    0,
    5 * GRID_W,
    7 * GRID_H
];

_ctrlBackground ctrlSetPosition
[
    4 * GRID_W,
    0,
    (UI_W - 8) * GRID_W,
    GROUP_H * GRID_H
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

_ctrlFooter ctrlSetText "HOLD CTRL TO PREVENT SCROLLING THE BACKGROUND";

_ctrlListNBox lnbAddColumn 8 * GRID_W;
_ctrlListNBox lnbAddColumn 110 * GRID_W;

_ctrlListNBox ctrlSetPosition
[
    4 * GRID_W,
    7 * GRID_H,
    (UI_W - 8) * GRID_W,
    39 * GRID_H
];

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
    params ["_ctrlGroup", "", "", "_mouseOver"];

    _ctrlGroup ctrlSetPositionH ([7 * GRID_H, GROUP_H * GRID_H] select _mouseOver);
    _ctrlGroup ctrlSetFade ([0.5, 0] select _mouseOver);
    _ctrlGroup ctrlCommit 0;

    if (ctrlPosition _ctrlGroup select 3 < GROUP_H * GRID_H) then
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
};

_ctrlGroup ctrlAddEventHandler ["MouseMoving", _fnc_mouseHandler];
_ctrlEdit ctrlAddEventHandler ["EditChanged", _fnc_search];
_ctrlListNBox ctrlAddEventHandler ["LBDblClick", _fnc_execCommand];

private _controls = [_ctrlListNBox, _ctrlEdit, _ctrlBackground, _ctrlImgLeft, _ctrlImgRight, _ctrlGroup];

_ctrlGroup ctrlCommit 0;
allControls _ctrlGroup apply {_x ctrlCommit 0};

_display3DEN setVariable ["ENH_3DENCommandPalette_ControlsGroup", _ctrlGroup]; // TODO: remove later 2025-06-22 R3vo
_display3DEN setVariable ["ENH_3DENCommandPalette_ListNBox", _ctrlListNBox];
_display3DEN setVariable ["ENH_3DENCommandPalette_Edit", _ctrlEdit];
