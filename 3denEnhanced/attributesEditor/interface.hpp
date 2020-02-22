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