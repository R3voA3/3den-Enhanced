class ENH_MarkerShape
{
    displayName = "$STR_ENH_MAIN_MARKER_SHAPE_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_ATTRIBUTES_MARKER_SHAPE_DISABLED";
    property = "ENH_markerShape";
    control = "ENH_MarkerShape";
    expression = "if (_value != 'NONE' && isServer) then {_this setMarkerShape _value}";
    defaultValue = "NONE";
    typeName = "STRING";
    validate = "STRING";
};
