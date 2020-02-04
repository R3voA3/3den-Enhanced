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

if (isNil "Enh_attribute_disableAI_state") then 
{ 
  Enh_attribute_disableAI_state = false; 
}
else
{
  Enh_attribute_disableAI_state = !Enh_attribute_disableAI_state;
};

collect3DENHistory
{
  { 
    private _entity = _x; 
    { 
      private _attributeName = "Enh_disableAI_" + _x;
      _entity set3DENAttribute [_attributeName,Enh_attribute_disableAI_state]; 
    } forEach ["move","target","cover","autotarget","anim","FSM","aimingError","teamswitch","suppression","checkVisible","autocombat","path","mineDetection","weaponAim","NVG","lights","radioProtocol"]; 
  } forEach get3DENSelected "Object"; 
};

[
	format
	[
		"AI features %1.",
		["disabled","enabled"] select Enh_attribute_disableAI_state
	]
] call BIS_fnc_3DENNotification;

true