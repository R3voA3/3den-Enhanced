#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Names all selected entities. Name is taken from the ENH_nameObjects dialog.

    Parameter(s):
    -

    Returns:
    -
*/

if !is3DEN exitWith {};

private _toName = [["Object", "Logic", "Trigger", "Marker", "Layer"]] call ENH_fnc_all3DENSelected;

if (_toName isEqualTo []) exitWith
{
    ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
};

disableSerialization;

private _display = findDisplay IDD_DISPLAY3DEN createDisplay "ENH_NameObjects";
_display setVariable ["SelectedEntities", _toName];

CTRL(IDC_NAMEOBJECTS_VARIABLENAME) ctrlSetText (profileNamespace getVariable ["ENH_NameObjects_LastVarName", profileName]);
CTRL(IDC_NAMEOBJECTS_INDEXSTART) ctrlSetText (profileNamespace getVariable ["ENH_NameObjects_LastIndexStart", "0"]);

CTRL(IDC_NAMEOBJECTS_REMOVE_NAME) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];

    private _display = ctrlParent _ctrlButton;

    [localize "STR_ENH_MAIN_NAMEOBJECTS"] collect3DENHistory
    {
        {
            _x set3DENAttribute ["Name", ""];
        } forEach (_display getVariable ["SelectedEntities", []]);
    };
    _display closeDisplay 0;
    ["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
}];

CTRL(IDC_NAMEOBJECTS_SET_NAME) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];

    private _display = ctrlParent _ctrlButton;
    private _varName = ctrlText CTRL(IDC_NAMEOBJECTS_VARIABLENAME);
    private _index = parseNumber ctrlText CTRL(IDC_NAMEOBJECTS_INDEXSTART);

    [localize "STR_ENH_MAIN_NAMEOBJECTS"] collect3DENHistory
    {
        {  // Set name attribute for object. For marker set markerName attribute
            _x set3DENAttribute ["Name", format ["%1_%2", _varName, _index]];
            _x set3DENAttribute ["markerName", format ["%1_%2", _varName, _index]];
            _index = _index + 1;
        } forEach (_display getVariable ["SelectedEntities", []]);
    };

    profileNamespace setVariable ["ENH_NameObjects_LastVarName", _varName];
    profileNamespace setVariable ["ENH_NameObjects_LastIndexStart", str _index];
    saveProfileNamespace;

    _display closeDisplay 0;
    ["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
}];
