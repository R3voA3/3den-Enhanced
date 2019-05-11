class Enh_FeatureType
{
	displayName = $STR_ENH_featureType_displayName;
	tooltip = $STR_ENH_featureType_displayName;
	property = "Enh_featureType";
	control = "Enh_FeatureType";
	expression = "if (_value isEqualType 0) then {_this setFeatureType _value}; if (_value isEqualType 'STRING') then {_this setFeatureType parseNumber _value}";//Type check to prevent issues
	condition = "1";
	defaultValue = "0";
	typeName = "NUMBER";
};