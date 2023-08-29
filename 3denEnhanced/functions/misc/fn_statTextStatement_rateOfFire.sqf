//#include "script_component.hpp"
/*
 * Author: Alganthe
 * Rate of fire text statement.
 *
 * Arguments:
 * 0: item config path (CONFIG)
 * 1: Args for configExtreme
 *  1.1: Stat limits (ARRAY of BOOL)
 *  1.2: Evaluate as a logarithmic number (BOOL)
 *
 * Return Value:
 * String
 *
 * Public: No
*/

params ["_config", "_args"];
_args params ["_statMinMax", "_configExtremeBool"];

private _fireModes = getArray (_config >> "modes");
private _fireRate = [];

{
    _fireRate pushBackUnique (getNumber (_config >> _x >> "reloadTime"));
} foreach _fireModes;

_fireRate sort true;
_fireRate = _fireRate param [0, 0];

if (_fireRate == 0) exitWith {"PEWPEWPEW"};
format ["%1 rpm", round (60 / _fireRate)]
