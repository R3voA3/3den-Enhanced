class ENH_AddGunLight
{
	displayName = $STR_ENH_ADDGUNLIGHT_DISPLAYNAME;
	tooltip = $STR_ENH_ADDGUNLIGHT_TOOLTIP;
	property = "ENH_addGunLight";
	control = "Checkbox";
	expression = "if (!is3DEN) then {_this addPrimaryWeaponItem 'acc_flashlight'; _this enableGunLights 'forceOn'}";
	condition = "objectBrain";
	defaultValue = "false";
};