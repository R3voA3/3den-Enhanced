#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-10-20

    Description:
    Used by the CfgSentences Browser GUI. Returns all data relevant for a sentence.

    Parameter(s):
    0: STRING - Config path as string. Saved in tvData

    Returns:
    ARRAY: [<configLedgible>,<bikbPath>,<topic>,<sentence>,<soundPath>]
*/

params ["_configStr"];

private _config = [_configStr, configNull] call BIS_fnc_configPath;
private _configArray = _configStr call BIS_fnc_configPath;
private _topic = _configArray select 3;
private _sentence = _configArray select 5;

private _configTopic = _configArray select [0, 4];
private _bikbPath = getText (([_configTopic, configNull] call BIS_fnc_configPath) >> "file");

private _soundPath = (getArray (_config >> "speech") select 0) select [1]; // Trim leadeing / to make it work with playSound3D
private _configLedgible = _configArray joinString " >> ";

[_configLedgible, _bikbPath, _topic, _sentence, _soundPath]
