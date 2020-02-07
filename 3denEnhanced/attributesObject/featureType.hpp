class ENH_FeatureType
{
	displayName = $STR_ENH_featureType_displayName;
	tooltip = $STR_ENH_featureType_displayName;
	property = "ENH_featureTypeNew";//Before ENH_featureType, was changed to fix data type issue once and for all
	control = "ENH_FeatureType";
	expression = "_this setFeatureType _value";
	defaultValue = "0";
	typeName = "NUMBER";
};