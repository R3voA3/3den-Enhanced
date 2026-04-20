#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-03-21

    Description:
    Fills given combo box with all debriefings from CfgDebriefing both from missionConfigFile and configFile.

    Parameter(s):
    0: CONTROL - Control comboBox
    1: STRING - Debriefing config name

    Returns:
    -
*/

params ["_ctrlCombo", "_debriefing"];

{
    private _title = getText (_x >> "title");
    private _subtitle = getText (_x >> "subtitle");
    private _description = getText (_x >> "description");
    private _configName = toLower configName _x;// We make everything lower case, just to be sure (Is BIS_fnc_endMission case sensitiv?)

    _ctrlCombo lbAdd _configName;
    _ctrlCombo lbSetTooltip
    [
        _forEachIndex,
         format ["Title: %1\nSubtitle: %2\nDescription: %3", _title, _subtitle, _description]
    ];
    if (_configName isEqualTo _debriefing) then
    {
        _ctrlCombo lbSetCurSel _forEachIndex;
    };
} forEach ("true" configClasses (configFile >> "CfgDebriefing")) + ("true" configClasses (missionConfigFile >> "CfgDebriefing"));
