class ENH_HoldActionIcons
{
    displayName = "$STR_ENH_MAIN_PREFERENCES_HOLD_ACTION_ICONS_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_PREFERENCES_HOLD_ACTION_ICONS_TOOLTIP";
    property = "ENH_HoldActionIcons";
    control = "ENH_InputList";
    expression = "profileNamespace setVariable ['ENH_EditorPreferences_HoldActionIcons', _value]";
    defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_HoldActionIcons', []]";
};
