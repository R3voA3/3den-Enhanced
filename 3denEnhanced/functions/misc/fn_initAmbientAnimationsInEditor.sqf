/*
   Author: R3vo

   Date: 2019-08-18

   Description:
   Is called onTerrainNew Eden attribute. Used to activate ambient animation in the editor for proper visualisation.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

#define ATTRIBUTE (_x get3DENAttribute "ENH_AmbientAnimations")
#define EXIT if (_units isEqualTo []) exitWith {false};

//Select only soldiers from all objects
private _units = (all3DENEntities # 0) select
{
	_x isKindOf "CAManBase"
};

EXIT

//Only select soldiers which have the ENH_AmbientAnimation attribute set
_units = _units select 
{
	!((ATTRIBUTE # 0 # 0) isEqualTo "")
};

EXIT

//Select random animation and play it
{
	private _animations = ATTRIBUTE # 0 # 1;
	_x switchMove selectRandom _animations;
} forEach _units;

true