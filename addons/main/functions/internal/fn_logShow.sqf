#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-01-01
    File: addons\main\functions\internal\fn_logShow.sqf

    Description:
    Shows logs created with ENH_fnc_log.

    Parameter(s):
    -

    Return Value:
    BOOLEAN - True, false if no data to show
*/

disableSerialization;

private _data = uiNamespace getVariable ["ENH_Log_Data", []];

if (_data isEqualTo []) exitWith {false};

private _display = (if (is3DEN) then {findDisplay 313} else {[] call BIS_fnc_displayMission}) createDisplay "RscDisplayEmpty";



private _ctrlEdit = _display ctrlCreate ["ctrlEdit", 645];
_ctrlEdit ctrlSetPosition [0, 0, 1, 0.04];
_ctrlEdit ctrlSetBackgroundColor [0, 0, 0, 1];
_ctrlEdit ctrlCommit 0;

private _ctrlTV = _display ctrlCreate ["ctrlTree", -1];
_ctrlTV ctrlSetFont "EtelkaMonospacePro";
_ctrlTV ctrlSetFontHeight 0.03;
_ctrlTV ctrlSetPosition [0, 0.06, 1, 0.94];
_ctrlTV ctrlSetBackgroundColor [0, 0, 0, 1];
_ctrlTV ctrlCommit 0;

{
    _x params [["_tickTime", -1], ["_message", ""]];

    private _path = _ctrlTV tvAdd
    [
        [],
        format
        [
            "%1 - %2 - %3",
            (_forEachIndex + 1) call ENH_fnc_formatInteger,
            _tickTime toFixed 3,
            _message
        ]
    ];

    _ctrlTV tvSetData [[_path], _message];
} forEach _data;

_ctrlTV ctrlAddEventHandler ["TreeDblClick",
{
    params ["_ctrlTV", "_selectionPath"];

    uiNamespace setVariable
    [
        "display3DENCopy_data",
        [
            "Message",
            _ctrlTV tvData _selectionPath
        ]
    ];

    ctrlParent _ctrlTV createDisplay "Display3denCopy";
}];

true
