class ENH_BlacklistedAssets
{
	displayName = "Asset Blacklist"
	tooltip = "Enter the classnames of factions you want to remove from Eden Editor by default.\nFor available faction classnames see: https://community.bistudio.com/wiki/faction\nTo reset this options, remove all entries and restart Eden Editor.\nInput must look as follows: Classname_1 Classname_2 Classname_3 Classname_n.";
	property = "ENH_BlacklistedAssets";
	control = "EditArray";
	expression = "profileNamespace setVariable ['%s',_value]";
	defaultValue = "profileNamespace getVariable ['ENH_BlacklistedAssets',[]]";
};