#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2026-11-21

    Description:
    Returns the scenario seed from mission.sqm.

    Parameter(s):
    -

    Returns:
    STRING - Scenario seed, or an empty string if mission.sqm or the seed is unavailable
*/

if (!fileExists "mission.sqm") exitWith {""};

private _result = flatten (loadFile "mission.sqm" regexFind ["randomseed=[0-9]{7}"]);

if !(_result isEqualTypeArray ["", 0]) exitWith {""};

_result select 0 splitString "=" select 1;
