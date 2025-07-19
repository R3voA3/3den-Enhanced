#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-07-19

    Description:
    This is an awesome description.

    Parameter(s):
    0: ARRAY - Some description, optional, default false

    Return Value:
    ARRAY - True on success, false if failed

    Examples(s):
    [] call ENH_fnc_missionDisplay;
*/

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

    systemChat format ["Command Hash %1", _commandHash];
    systemChat format ["Value %1", _y];

    private _action = _commandHash getOrDefault ["action", ""];

    // TODO: This should be unified in one function 2025-07-19 R3vo
    if (_action != "") then
    {
        private _priorityMap = profileNamespace getVariable ["ENH_3DENCommandPalette_PriorityMap", createHashMap];
        private _actionHash = hashValue _action;
        private _text = _commandHash getOrDefault ["text", ""];

        if (_commandHash getOrDefault ["opensNewWindow", 0] == 1) then
        {
            _text = _text + "...";
        };

        _commands pushBack
        [
            _commandHash getOrDefault ["action", ""],
            _commandHash getOrDefault ["picture", ""],
            "", // Shortcuts, not used
            _commandHash getOrDefault ["text", ""],
            _commandHash getOrDefault ["description", "Custom Command"],
            _actionHash,
            _priorityMap getOrDefault [_actionHash, 0],
            _commandHash getOrDefault ["copyToClipboard", 0]
        ];
    };
} forEach _JSONHash;

_commands
