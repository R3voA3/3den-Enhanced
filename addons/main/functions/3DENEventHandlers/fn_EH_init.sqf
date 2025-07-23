#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-05-07

    Description:
    -

    Parameter(s):
    -

    Returns:
    -
*/

params ["_display3DEN"];

private _code =
{
    if !is3DEN exitWith {};

    params ["_display3DEN"];

    // Direction
    private _dir = round getDir get3DENCamera;
    private _dir = switch (count str _dir) do
    {
        case 1: {format ["00%1 °", _dir]};
        case 2: {format ["0%1 °", _dir]};
        default {format ["%1 °", _dir]};
    };

    _display3DEN displayCtrl IDC_STATUSBAR_CAMDIR ctrlSetText _dir;

    // Session timer
    _display3DEN displayCtrl IDC_STATUSBAR_SESSIONTIMER ctrlSetTooltip format
    [
        "%1: %2",
        localize "STR_ENH_MAIN_STATUSBAR_SESSIONTIMER_TOOLTIP",
        [diag_tickTime / 3600] call BIS_fnc_timeToString
    ];

    // Dynamic view distance
    if (profileNamespace getVariable ["ENH_EditorPreferences_DynamicViewDistance", false]) then
    {
        private _vd = linearConversion [0, 2000, getPosASL get3DENCamera # 2, 200, 12000, true];
        setViewDistance _vd;
        setObjectViewDistance (0.5 * _vd);
    };

    // Entity counter
    private _conditionHide =  !(profileNamespace getVariable ["ENH_EditorPreferences_Interface_EntityCounter", true]) ||
    {
        private _ctrlCamDir = _display3DEN displayCtrl IDC_DISPLAY3DEN_STATUSBAR controlsGroupCtrl IDC_STATUSBAR_CAMDIR;
        private _ctrlIconObjects = _display3DEN displayCtrl IDC_DISPLAY3DEN_STATUSBAR controlsGroupCtrl IDC_STATUSBAR_ICONOBJECTS;
        ctrlPosition _ctrlIconObjects # 0 < ctrlPosition _ctrlCamDir # 0 + ctrlPosition _ctrlCamDir # 2;
    };

    for "_i" from IDC_STATUSBAR_NUMMARKERS to IDC_STATUSBAR_ICONOBJECTS do
    {
        _display3DEN displayCtrl _i ctrlShow !_conditionHide;
    };

    if !_conditionHide then
    {
        [
            [IDC_STATUSBAR_NUMMARKERS, "Marker"],
            [IDC_STATUSBAR_NUMSYSTEMS, "Logic"],
            [IDC_STATUSBAR_NUMWAYPOINTS, "Waypoint"],
            [IDC_STATUSBAR_NUMTRIGGERS, "Trigger"],
            [IDC_STATUSBAR_NUMGROUPS, "Group"],
            [IDC_STATUSBAR_NUMOBJECTS, "Object"]
        ] apply
        {
            _x params ["_idc", "_type"];
            _display3DEN displayCtrl _idc ctrlShow true;
            _display3DEN displayCtrl _idc ctrlSetText str count get3DENSelected _type;
        };
    };

    // Draw dlc icons
    if (profileNamespace getVariable ["ENH_EditorPreferences_Interface_DrawDLCIcons", false]) then
    {
        (entities [[], [], true, false] select {get3DENCamera distance _x <= 100}) apply
        {
            // Stupid workaround because modParams spams .rpt file otherwise
            private _mod = configSourceMod configOf _x;
            if (_mod != "") then
            {
                drawIcon3D
                [
                    (modParams [_mod, ["logoSmall"]]) # 0,
                    [1, 1, 1, 0.8],
                    _x modelToWorldVisual [0, 0, 0.5],
                    0.5,
                    0.5,
                    0
                ];
            }
        };
    };

    // Draw building positions
    if (profileNamespace getVariable ["ENH_EditorPreferences_Interface_DrawBuildingPositions", false]) then
    {
        (get3DENCamera nearObjects ["House", 100]) apply
        {
            for "_i" from 0 to (count (_x buildingPos -1) - 1) do
            {
                drawIcon3D
                [
                    TEXTURE_BUILDING_POS,
                    [COLOR_BUILDING_POS],
                    _x buildingPos _i,
                    0.5,
                    0.5,
                    0,
                    str _i
                ];
            };
        };
    };

    // Show custom marker color and shape on hover
    call ENH_fnc_3DENShowCustomMarkerColorAndShape;

    // We return nil here, otherwise we break other mods (CBA, ACE)
    nil
};

_display3DEN displayAddEventHandler ["MouseHolding", _code];
_display3DEN displayAddEventHandler ["MouseMoving", _code];

// Add tooltips to entity list
_display3DEN displayCtrl IDC_DISPLAY3DEN_EDIT ctrlAddEventHandler ["MouseEnter", ENH_fnc_entityList_addTooltips];

// Init minimap
_display3DEN call ENH_fnc_3DENMinimap;

// Remove mods without units or weapons from Asset Browser mod filter
[_display3DEN displayCtrl 4242] call ENH_fnc_assetBrowser_modFilter;

// Add alternativ keybind to open 3DEN Command Palette
_display3DEN displayAddEventHandler ["KeyDown",
{
    params ["", "_key", "", "_ctrl", "_alt"];

    if (_ctrl && {_alt && {_key == DIK_SPACE}}) then
    {
        call ENH_fnc_3DENCommandPalette_init;
    };
}];
