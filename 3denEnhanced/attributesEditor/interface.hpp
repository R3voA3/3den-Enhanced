class ENH_Interface
{
	collapsed = 0;
	displayName = $STR_ENH_INTERFACE;
	class Attributes
	{
		class ENH_CollapseAssetBrowser
		{
			displayName = $STR_ENH_COLLAPSEASSETBROWSER;
			property = "ENH_CollapseAssetBrowser";
			control = "Checkbox";
			expression = "profileNamespace setVariable ['%s',_value]";
			defaultValue = "profileNamespace getVariable ['ENH_CollapseAssetBrowser',false]";
		};
		class ENH_CollapseEntityList
		{
			displayName = $STR_ENH_COLLAPSEENTITYLIST;
			property = "ENH_CollapseEntityList";
			control = "Checkbox";
			expression = "profileNamespace setVariable ['%s',_value]";
			defaultValue = "profileNamespace getVariable ['ENH_CollapseEntityList',false]";
		};
		class ENH_ShowPanelLeft
		{
			displayName = $STR_ENH_SHOWLEFTPANEL;
			property = "ENH_ShowPanelLeft";
			control = "Checkbox";
			defaultValue = "profileNamespace getVariable ['ENH_ShowPanelLeft',true]";
			expression = "profileNamespace setVariable ['ENH_ShowPanelLeft',_value]";
		};
		class ENH_ShowPanelRight
		{
			displayName = $STR_ENH_SHOWRIGHTPANEL;
			property = "ENH_ShowPanelRight";
			control = "Checkbox";
			defaultValue = "profileNamespace getVariable ['ENH_ShowPanelRight',true]";
			expression = "profileNamespace setVariable ['ENH_ShowPanelRight',_value]";
		};
		class ENH_BlacklistedAssets
		{
			displayName = $STR_ENH_ASSETBLACKLIST;
			tooltip = "Enter the classnames of factions you want to remove from Eden Editor by default.\nFor available faction classnames see: https://community.bistudio.com/wiki/faction\nTo reset this options, remove all entries and restart Eden Editor.\nInput must look as follows: Classname_1 Classname_2 Classname_3 Classname_n.";
			property = "ENH_BlacklistedAssets";
			control = "EditArray";
			expression = "profileNamespace setVariable ['%s',_value]";
			defaultValue = "profileNamespace getVariable ['ENH_BlacklistedAssets',[]]";
		};
		class ENH_Statusbar_EntityCounter
		{
			displayName = $STR_ENH_STATUSBAR_ENTITYCOUNTER_DISPLAYNAME;
			property = "ENH_Statusbar_EntityCounter";
			control = "Checkbox";
			expression = "profileNamespace setVariable ['%s',_value]; 'init' call ENH_fnc_statusbar_entityCounter";
			defaultValue = "profileNamespace getVariable ['ENH_Statusbar_EntityCounter',true]";
		};
	};
};