#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-08-18

    Description:
    Is called onTerrainNew and onMissionLoad. Used to activate ambient animation in the editor for proper visualisation.

    Parameter(s):
    -

    Returns:
    -
*/

#define ATTRIBUTE (_x get3DENAttribute "ENH_AmbientAnimations")
#define EXIT if (_units isEqualTo []) exitWith {false};

// Select only soldiers from all objects
// Only select soldiers which have the ENH_AmbientAnimation attribute set
private _units = (all3DENEntities # 0) select
{
    (_x isKindOf "CAManBase") && (((ATTRIBUTE # 0 # 0) isNotEqualTo ""))
};

EXIT

// Select random animation and play it
{
    private _animations = ATTRIBUTE # 0 # 1;
    _x switchMove selectRandom _animations;
} forEach _units;
