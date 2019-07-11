class Enh_EstablishingShot
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_establishingShot;
	class Attributes
	{
		class Enh_EstablishingShot
		{
			property = "Enh_establisingShot";
			control = "Enh_EstablishingShot";
			expression = "if (!(_value # 0 isEqualTo [0,0,0]) && hasInterface && !is3DEN) then {_value spawn BIS_fnc_establishingShot}";
			defaultValue = "[[0,0,0],getText (configfile >> 'CfgWorlds' >> worldName >> 'description'),150,300,45]";
		};
	};
};
