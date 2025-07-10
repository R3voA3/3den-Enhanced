#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-21

    Description:
    Opens the 3DEN Command Palette.

    Parameter(s):
    -

    Return Value:
    BOOLEAN: True
*/


#define GROUP_H 51
#define UI_W 80
#define UI_Y (WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H)

disableSerialization;

private _display3DEN = findDisplay IDD_DISPLAY3DEN;
private _rootDisplay = _display3DEN createDisplay "RscDisplayEmpty";

private _ctrlGroup = _rootDisplay ctrlCreate ["ctrlControlsGroupNoScrollbars", -1];
private _ctrlBackground = _rootDisplay ctrlCreate ["ctrlStaticBackground", -1, _ctrlGroup];
private _ctrlEdit = _rootDisplay ctrlCreate ["ctrlEdit", -1, _ctrlGroup];
private _ctrlButtonSearch = _rootDisplay ctrlCreate ["ctrlButtonSearch", -1, _ctrlGroup];
private _ctrlFooter = _rootDisplay ctrlCreate ["ctrlStaticFooter", -1, _ctrlGroup];
private _ctrlGroupCommands = _rootDisplay ctrlCreate ["ctrlControlsGroup", -1, _ctrlGroup];

[_ctrlEdit, _ctrlButtonSearch] call ENH_fnc_initSearchControls;

_rootDisplay setVariable ["ENH_3DENCommandPalette_ControlGroupCommands", _ctrlGroupCommands];
_rootDisplay setVariable ["ENH_3DENCommandPalette_RowIndex", 0];
_display3DEN setVariable ["ENH_3DENCommandPalette_Display", _rootDisplay];

private _fnc_addCommand =
{
    params ["_action", "_picture", "_shortcuts", "_text", ["_description", ""]];

    private _rootDisplay = findDisplay IDD_DISPLAY3DEN getVariable "ENH_3DENCommandPalette_Display";

    private _rowIndex = _rootDisplay getVariable ["ENH_3DENCommandPalette_RowIndex", 0];

    private _ctrlGroupCommands = _rootDisplay getVariable "ENH_3DENCommandPalette_ControlGroupCommands";
    private _ctrlBackground = _rootDisplay ctrlCreate ["ctrlStaticFooter", -1, _ctrlGroupCommands];
    private _ctrlPicture = _rootDisplay ctrlCreate ["ctrlStaticPictureKeepAspect", -1, _ctrlGroupCommands];
    private _ctrlTitle = _rootDisplay ctrlCreate ["ctrlStatic", -1, _ctrlGroupCommands];
    private _ctrlDescription = _rootDisplay ctrlCreate ["ctrlStatic", -1, _ctrlGroupCommands];
    private _ctrlShortcuts = _rootDisplay ctrlCreate ["ctrlStatic", -1, _ctrlGroupCommands];

    private _ctrlFakeButton = _rootDisplay ctrlCreate ["ctrlButton", -1, _ctrlGroupCommands];

    _ctrlBackground ctrlSetPosition
    [
        1 * GRID_W,
        _rowIndex * 8 * GRID_H,
        (UI_W - 1 - 1) * GRID_W,
        7 * GRID_H
    ];

    _ctrlPicture ctrlSetPosition
    [
        2.5 * GRID_W,
        _rowIndex * 8 * GRID_H + 1 * GRID_H,
        5 * GRID_W, 5 * GRID_H
    ];

    _ctrlTitle ctrlSetPosition
    [
        8 * GRID_W, _rowIndex * 8 * GRID_H,
        (UI_W - 8 - 1 - 1) * GRID_W,
        4 * GRID_H
    ];

    _ctrlDescription ctrlSetPosition
    [
        8 * GRID_W,
        _rowIndex * 8 * GRID_H + 4 * GRID_H,
        (UI_W - 8 - 1 - 1) * GRID_W,
        3 * GRID_H
    ];

    _ctrlShortcuts ctrlSetPosition
    [
        (UI_W - 20 - 1) * GRID_W,
        _rowIndex * 8 * GRID_H,
        20 * GRID_W,
        7 * GRID_H
    ];

    _ctrlFakeButton ctrlSetPosition
    [
        1 * GRID_W,
        _rowIndex * 8 * GRID_H,
        (UI_W - 1 - 1) * GRID_W,
        7 * GRID_H
    ];

    _ctrlFakeButton ctrlSetFade 1;

    _ctrlTitle ctrlSetFontHeight (4 * GRID_H);
    _ctrlDescription ctrlSetFontHeight (3 * GRID_H);
    _ctrlShortcuts ctrlSetFontHeight (3 * GRID_H);

    _ctrlDescription ctrlSetTextColor [0.5, 0.5, 0.5, 1];

    _ctrlPicture ctrlSetText _picture;

    _ctrlTitle ctrlSetText _text;
    _ctrlTitle ctrlSetTooltip _text;

    _ctrlDescription ctrlSetText _description;
    _ctrlDescription ctrlSetTooltip _description;

    _ctrlShortcuts ctrlSetText _shortcuts;
    _ctrlShortcuts ctrlSetTooltip _shortcuts;

    _ctrlFakeButton ctrlSetTooltip (_text + endl + _description + endl + _shortcuts); // TODO: Make the font smaller 2025-07-10 R3vo
    _ctrlFakeButton setVariable ["Background", _ctrlBackground];

    _ctrlFakeButton ctrlAddEventHandler ["MouseEnter",
    {
        params ["_ctrlButton"];
        (_ctrlButton getVariable "Background") ctrlSetBackgroundColor
        [
            profileNamespace getVariable ["GUI_BCG_RGB_R", 0.77],
            profileNamespace getVariable ["GUI_BCG_RGB_G", 0.51],
            profileNamespace getVariable ["GUI_BCG_RGB_B", 0.08],
            1
        ];
    }];

    _ctrlFakeButton ctrlAddEventHandler ["MouseExit",
    {
        params ["_ctrlButton"];
        (_ctrlButton getVariable "Background") ctrlSetBackgroundColor [0, 0, 0, 0.3];
    }];

    _ctrlFakeButton setVariable ["Action", _action];

    _ctrlFakeButton ctrlAddEventHandler ["MouseButtonDown",
    {
        params ["_ctrlFakeButton"]
        call compile (_ctrlFakeButton getVariable ["action", "systemChat 'No Action found!'"]);

        ctrlParent _ctrlFakeButton closeDisplay 1;
    }];

    private _controls = [_ctrlBackground, _ctrlPicture, _ctrlTitle, _ctrlDescription, _ctrlShortcuts, _ctrlFakeButton];

    _controls apply {_x ctrlCommit 0};

    _rootDisplay setVariable ["ENH_3DENCommandPalette_RowIndex", _rowIndex + 1];
};

_rootDisplay setVariable ["ENH_3DENCommandPalette_FncAddCommand", _fnc_addCommand];

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

    private _rootDisplay = findDisplay IDD_DISPLAY3DEN getVariable "ENH_3DENCommandPalette_Display";
    private _ctrlGroupCommands = _rootDisplay getVariable ["ENH_3DENCommandPalette_ControlGroupCommands", controlNull];
    private _commands = _rootDisplay getVariable ["ENH_3DENCommandPalette_Commands", []];

    allControls _ctrlGroupCommands apply {ctrlDelete _x};

    _rootDisplay setVariable ["ENH_3DENCommandPalette_RowIndex", 0];

    _commands apply
    {
        _x params ["", "", "", "_text"];

        if (_searchText == "" || {toLower _searchText in toLower _text}) then
        {
            _x call (_rootDisplay getVariable "ENH_3DENCommandPalette_FncAddCommand");
        };
    };
};

_ctrlGroup ctrlSetPosition
[
    0.5 - UI_W * 0.5 * GRID_W - 4 * GRID_W,
    UI_Y,
    UI_W * GRID_W,
    GROUP_H * GRID_H
];

_ctrlBackground ctrlSetPosition
[
    0,
    0,
    UI_W * GRID_W,
    (GROUP_H - 1) * GRID_H
];

_ctrlEdit ctrlSetPosition
[
    GRID_W,
    GRID_H,
    (UI_W - 2 - 5) * GRID_W,
    5 * GRID_H
];

_ctrlButtonSearch ctrlSetPosition
[
    (UI_W - 1 - 5) * GRID_W,
    GRID_H,
    5 * GRID_W,
    5 * GRID_H
];

_ctrlFooter ctrlSetPosition
[
    1 * GRID_W,
    GROUP_H * GRID_H - CTRL_DEFAULT_H,
    (UI_W - 2) * GRID_W,
    3 * GRID_H
];

// _ctrlFooter ctrlSetFontHeight (3 * GRID_H);
// _ctrlFooter ctrlSetText "HOLD CTRL TO PREVENT SCROLLING THE BACKGROUND";// TODO: Localize 2025-06-23 R3vo

_ctrlGroupCommands ctrlSetPosition
[
    0,
    7 * GRID_H,
    UI_W * GRID_W,
    38 * GRID_H
];

private _commands = _rootDisplay getVariable ["ENH_3DENCommandPalette_Commands", []];

if (_commands isEqualTo []) then
{
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

        _commands pushBack [_action, _picture, _shortcuts, _text, "Menu Strip Entry" /*_description*/]; // TODO: LOCALIZE 2025-07-10 R3vo
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

        private _customCommands = fromJSON loadFile _filePath;

        // systemChat str _customCommands;

        {
            private _key = _x;

            _commands pushBack
            [
                _customCommands get _key getOrDefault ["action", ""],
                _customCommands get _key getOrDefault ["picture", ""],
                "", // TODO: Implement 2025-07-10 R3vo
                _customCommands get _key getOrDefault ["text", ""],
                _customCommands get _key getOrDefault ["description", "Custom Command"] // TODO: LOCALIZE 2025-07-10 R3vo
            ];

        } forEach _customCommands
    };

    _rootDisplay setVariable ["ENH_3DENCommandPalette_Commands", _commands];
};

_commands apply {_x call _fnc_addCommand};

_ctrlEdit ctrlAddEventHandler ["EditChanged", _fnc_search];

_ctrlGroup ctrlCommit 0;
allControls _ctrlGroup apply {_x ctrlCommit 0};

ctrlSetFocus _ctrlEdit;

true

// TODO: Add sorting by how often command was used 2025-07-10 R3vo
