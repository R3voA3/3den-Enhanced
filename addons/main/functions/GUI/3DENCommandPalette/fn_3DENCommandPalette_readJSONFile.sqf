#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-07-19

    Description:
    Reads the JSON file containing the command palette commands.

    Parameter(s):
    -

    Return Value:
    ARRAY - With all commands or empty array if the file could not be read.
*/

if !(isClass (configFile >> "CfgPatches" >> "PY3_Pythia")) exitWith {[]};

private _path = profileNamespace getVariable ['ENH_EditorPreferences_Interface_3DENCommandPalette_Path', ''];

if (_path == "") exitWith {[]};

private _json =
[
    "ENH_Pythia.CommandPalette_Read_File",
    ["C:\Users\rober\OneDrive\Dokumente\Arma 3 - Other Profiles\R3vo\ENH_Command_Palette_Commands.json"]
] call (uiNamespace getVariable "py3_fnc_callExtension");

if (_json == "") exitWith {[]};

private _JSONHash = fromJSON _json;
private _commands = [];

{
    private _commandHash = _JSONHash get _x;
    private _action = _commandHash getOrDefault ["action", ""];

    // TODO: This should be unified in one function 2025-07-19 R3vo
    if (_action != "") then
    {
        private _priorityMap = profileNamespace getVariable ["ENH_3DENCommandPalette_PriorityMap", createHashMap];
        private _actionHash = hashValue _action;
        private _text = _commandHash getOrDefault ["text", ""];
        private _description = _commandHash getOrDefault ["description", "Custom Command"];

        if (_commandHash getOrDefault ["opensNewWindow", 0] == 1) then
        {
            _text = _text + "...";
        };

        if (_description == "") then
        {
            _description = "JSON Command";
        };

        _commands pushBack
        [
            _action,
            _commandHash getOrDefault ["picture", ""],
            "", // Shortcuts, not used
            _text,
            _description,
            _actionHash,
            _priorityMap getOrDefault [_actionHash, 0],
            (_commandHash getOrDefault ["copyToClipboard", 0]) == 1
        ];
    };
} forEach _JSONHash;

_commands
