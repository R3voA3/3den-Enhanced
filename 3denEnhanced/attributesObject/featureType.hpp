class Enh_FeatureType
{
	displayName = $STR_ENH_featureType_displayName;
	tooltip = $STR_ENH_featureType_displayName;
	property = "Enh_featureTypeNew";//Before Enh_featureType, was changed to fix data type issue once and for all
	control = "Enh_FeatureType";
	expression = "_this setFeatureType _value";
	defaultValue = "0";
	typeName = "NUMBER";
};