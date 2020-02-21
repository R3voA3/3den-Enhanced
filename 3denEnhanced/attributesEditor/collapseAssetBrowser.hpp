class ENH_CollapseAssetBrowser
{
	displayName = $STR_ENH_COLLAPSEASSETBROWSER;
	property = "ENH_CollapseAssetBrowser";
	control = "Checkbox";
	expression = "profileNamespace setVariable ['%s',_value]";
	defaultValue = "profileNamespace getVariable ['ENH_CollapseAssetBrowser',false]";
};