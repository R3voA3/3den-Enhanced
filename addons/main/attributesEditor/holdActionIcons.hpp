class ENH_HoldActionIcons
{
    displayName = "Hold Action Icons"; // TODO: localize 2025-06-07 R3vo
    tooltip = "Define additional icons here that can be used for the hold action attribute."; // TODO: localize 2025-06-07 R3vo
    property = "ENH_HoldActionIcons";
    control = "ENH_InputList";
    expression = "profileNamespace setVariable ['ENH_EditorPreferences_HoldActionIcons', _value]";
    defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_HoldActionIcons', []]";
};
