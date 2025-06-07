class ENH_HoldActionIcons
{
    displayName = "Hold Action Icons";
    tooltip = "Define additional icons here that can be used for the hold action attribute.";
    property = "ENH_HoldActionIcons";
    control = "ENH_InputList";
    expression = "profileNamespace setVariable ['ENH_EditorPreferences_HoldActionIcons', _value]";
    defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_HoldActionIcons', []]";
};
