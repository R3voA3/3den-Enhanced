class Enh_WeaponRecoil
{
	displayName = $STR_ENH_weaponRecoil_displayName;
	tooltip = $STR_ENH_weaponRecoil_tooltip;
	control = "Slider";
	property = "Enh_weaponRecoil";
	expression =
	"\
	_this setVariable ['Enh_weaponRecoil',_value];\
	_this setUnitRecoilCoefficient _value;\
	_this addEventHandler\
	[\
		'Respawn',\
		{\
			(_this # 0) setUnitRecoilCoefficient ((_this # 0) getVariable 'Enh_weaponRecoil')\
		}\
	]";
	defaultValue = "1";
	conditioin = "objectBrain";
};