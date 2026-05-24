class ENH_DynamicViewDistance
{
    displayName = "$STR_ENH_MAIN_DYNAMICVIEWDISTANCE_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_DYNAMICVIEWDISTANCE_TOOLTIP";
    property = "ENH_DynamicViewDistance";
    control = "Checkbox";
    expression = "profileNamespace setVariable ['ENH_EditorPreferences_DynamicViewDistance', _value]";
    defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_DynamicViewDistance', false]";
};
