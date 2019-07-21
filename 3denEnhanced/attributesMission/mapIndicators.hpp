class Enh_MapIndicators
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_mapIndicators;
	class Attributes
	{
		class Enh_MapIndicators
		{
			property = "Enh_mapIndicators";
			control = "Enh_MapIndicators";
			expression =
			"\
				if (!is3DEN && !(_value isEqualTo [false,false,false,false]) && hasInterface) then\
				{\
					disableMapIndicators _value;\
				};\
			";
			defaultValue = "[false,false,false,false]";
		};
	};
};