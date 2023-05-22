//#include "script_component.hpp"
/*
 * Author: Alganthe
 * Impact bar statement.
 *
 * Arguments:
 * 0: item config path (CONFIG)
 * 1: Args for configExtreme
 *  1.1: Stat limits (ARRAY of SCALAR)
 *  1.2: Bar limits (ARRAY of SCALAR)
 *  1.3: is item Launcher (BOOL)
 *
 * Return Value:
 * Number
 *
 * Public: No
*/

params ["_config", "_args"];
_args params ["_hitMinMax", "_initSpeedMinMax"];

private _statValues = [
    [_config],
    ["hit", "initSpeed"],
    [true, false],
    [_hitMinMax select 0, _initSpeedMinMax select 0]
] call BIS_fnc_configExtremes;
(_statValues select 1) params ["_hit", "_initSpeed"];

_hit = linearConversion [_hitMinMax select 0, _hitMinMax select 1, _hit, 0.01, 1];
_initSpeed = linearConversion [_initSpeedMinMax select 0, _initSpeedMinMax select 1, _initSpeed, 0.01, 1];

([configName _config] call BIS_fnc_itemType) params["_itemCat", "_itemType"];
private _isLauncher = (_itemCat isEqualTo "Weapon" && (_itemType isEqualTo "RocketLauncher" || _itemType isEqualTo "MissileLauncher"));

[sqrt(_hit^2 * _initSpeed), _hit] select (_isLauncher)
