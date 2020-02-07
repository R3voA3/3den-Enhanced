class ENH_AddGunLight
{
	displayName = $STR_ENH_addGunLight_displayName;
	tooltip = $STR_ENH_addGunLight_tooltip;
	property = "ENH_addGunLight";
	control = "Checkbox";
	expression =
	"if (!is3DEN && _value) then\
	{\
		_this addPrimaryWeaponItem 'acc_flashlight';\
		_this enableGunLights 'forceOn';\
	}";
	condition = "objectBrain";
	defaultValue = "false";
};