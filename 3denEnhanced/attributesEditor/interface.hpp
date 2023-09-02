class ENH_Interface
{
  collapsed = 1;
  displayName = "$STR_ENH_INTERFACE";
  class Attributes
  {
    class ENH_CollapseAssetBrowser
    {
      displayName = "$STR_ENH_COLLAPSEASSETBROWSER";
      property = "ENH_CollapseAssetBrowser";
      control = "Checkbox";
      expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_CollapseAssetBrowser', _value]";
      defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_CollapseAssetBrowser', false]";
    };
    class ENH_CollapseEntityList: ENH_CollapseAssetBrowser
    {
      displayName = "$STR_ENH_COLLAPSEENTITYLIST";
      property = "ENH_CollapseEntityList";
      expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_CollapseEntityList', _value]";
      defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_CollapseEntityList', false]";
    };
    class ENH_ShowPanelLeft: ENH_CollapseAssetBrowser
    {
      displayName = "$STR_ENH_SHOWLEFTPANEL";
      property = "ENH_ShowPanelLeft";
      expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_ShowPanelLeft', _value]";
      defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_ShowPanelLeft', true]";
    };
    class ENH_ShowPanelRight: ENH_ShowPanelLeft
    {
      displayName = "$STR_ENH_SHOWRIGHTPANEL";
      property = "ENH_ShowPanelRight";
      expression = "profileNamespace setVariable ['ENH_EditorPreferences_Interface_ShowPanelRight', _value]";
      defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Interface_ShowPanelRight', true]";
    };
    class ENH_EntityCounter: ENH_ShowPanelLeft
    {
      displayName = "$STR_ENH_STATUSBAR_ENTITYCOUNTER_DISPLAYNAME";
      property = "ENH_Statusbar_EntityCounter";
      expression = "'init' call ENH_fnc_statusbar_entityCounter";
    };
    class ENH_Blacklist: ENH_ShowPanelLeft
    {
      displayName = "$STR_ENH_MENUSTRIPENTRIES";
      tooltip = "$STR_ENH_MENUSTRIPENTRIES_TOOLTIP";
      property = "ENH_MenuStrip_Blacklist";
      control = "ENH_MenuStripBlacklist";
    };
  };
};