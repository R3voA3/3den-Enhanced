/*
   Author: R3vo

   Date: 2020-02-03

   Description:
   Toggles all disable AI attribute on/off.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

private _entities = [["Object"]] call ENH_fnc_all3DENSelected;

if (_entities isEqualTo []) exitWith
{
	["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
	false
};

if (isNil "ENH_attribute_disableAI_state") then
{ 
  ENH_attribute_disableAI_state = false;
}
else
{
  ENH_attribute_disableAI_state = !ENH_attribute_disableAI_state;
};

collect3DENHistory
{
  { 
    private _entity = _x; 
    { 
      private _attributeName = "ENH_disableAI_" + _x;
      _entity set3DENAttribute [_attributeName,ENH_attribute_disableAI_state]; 
    } forEach ["move","target","cover","autotarget","anim","FSM","aimingError","teamswitch","suppression","checkVisible","autocombat","path","mineDetection","weaponAim","NVG","lights","radioProtocol"]; 
  } forEach _entities;
};

[
	format
	[
		localize "STR_ENH_TOGGLEAIFEATURES_NOTIFICATION",
		[localize "STR_ENH_DISABLED",localize "STR_ENH_ENABLED"] select ENH_attribute_disableAI_state
	]
] call BIS_fnc_3DENNotification;

true