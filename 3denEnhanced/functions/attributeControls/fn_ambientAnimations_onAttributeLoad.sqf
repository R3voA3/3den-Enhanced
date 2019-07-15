/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the ambient animation attribute. Called when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute value

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];
_value params ["_animationName","_gear"];

_attCtrl = getText (_config >> "control");
_animCtrl = _ctrlGroup controlsGroupCtrl 100;
_ctrlGear = _ctrlGroup controlsGroupCtrl 101;
_staticItemsCfgAnim = configFile >> "Cfg3DEN" >> "Attributes" >> _attCtrl >> "Controls" >> "Anim" >> "items";
_staticItemsCfgGear = configFile >> "Cfg3DEN" >> "Attributes" >> _attCtrl >> "Controls" >> "Gear" >> "items";

{
	if (_animationName == getText (_x >> "data")) then
	{
		_animCtrl lbSetCurSel _forEachIndex;
	};
} forEach configProperties [_staticItemsCfgAnim,"isclass _x"];

{
	if (_gear == getText (_x >> "data")) then
	{
		_ctrlGear lbSetCurSel _forEachIndex;
	};
} forEach configProperties [_staticItemsCfgGear,"isclass _x"];

if (is3DENMultiplayer) then
{
	(_ctrlGroup controlsGroupCtrl 100) ctrlEnable false;
	(_ctrlGroup controlsGroupCtrl 101) ctrlEnable false;
	(_ctrlGroup controlsGroupCtrl 102) ctrlEnable false;
};

true