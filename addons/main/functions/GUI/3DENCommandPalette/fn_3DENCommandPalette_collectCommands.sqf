#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-07-13

    Description:
    Collects all commands for the command palette

    Parameter(s):
    -

    Return Value:
    ARRAY: A list of all commands
*/

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

private _menuStripItems = "true" configClasses (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items") apply {[_x, "configFile"]};
private _descriptionExtItems = "true" configClasses (missionConfigFile >> "ENH_3DENCommandPalette_Commands") apply {[_x, "missionConfigFile"]};
private _cfg3DENItems = "true" configClasses (configFile >> "Cfg3DEN" >> "ENH_3DENCommandPalette_Commands") apply {[_x, "Cfg3DEN"]};
private _commands = [];

(_menuStripItems + _descriptionExtItems + _cfg3DENItems) apply
{
    _x params ["_config", "_rootConfig"];

    private _action = getText (_config >> "action");
    private _text = getText (_config >> "text");
    private _data = getText (_config >> "data");

    if (_text == "") then {continue};

    if (getText (_config >> "weblink") != "") then {continue};

    // Entries that have no action nor data are folders or separators
    if (_action == "" && {_data == ""}) then {continue};

    // Entries that have no action but data might be 3DENActions
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

    if (getNumber (_config >> "opensNewWindow") == 1) then
    {
        _text = _text + "...";
    };

    private _picture = getText (_config >> "picture");
    private _shortcuts = [[getArray (_config >> "shortcuts")]] call ENH_fnc_parseShortcut;
    private _description = getText (_config >> "description"); // 3den Enhanced specific property

    if (_description == "") then
    {
        call
        {
            private _configString = toLower str _x;
            if (_rootConfig == "missionConfigFile" || {_rootConfig == "Cfg3DEN"}) exitWith
            {
                _description = localize "$STR_ENH_MAIN_3DEN_COMMAND_PALETTE_CUSTOM_COMMAND";
            };
            if (_rootConfig == "configFile") exitWith
            {
                _description = localize "$STR_ENH_MAIN_3DEN_COMMAND_PALETTE_MENU_STRIP_COMMAND";
            };
        };
    };

    private _actionHash = hashValue _action;
    private _priorityMap = profileNamespace getVariable ["ENH_3DENCommandPalette_PriorityMap", createHashMap];
    private _copyToClipboard = getNumber (_config >> "copyToClipboard") == 1;

    _commands pushBack [_action, _picture, _shortcuts, _text, _description, _actionHash, _priorityMap getOrDefault [_actionHash, 0], _copyToClipboard];
};

private _JSONUserCommands = call ENH_fnc_3DENCommandPalette_readJSONFile;
if (_JSONUserCommands isNotEqualTo []) then
{
    _commands = _commands + _JSONUserCommands;
};

// Sort first by name, then by _priority (how often it was used)
[[_commands, [], {_x#3}] call BIS_fnc_sortBy, [], {_x#6}] call BIS_fnc_sortBy;
