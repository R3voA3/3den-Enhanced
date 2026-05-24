class ENH_MarkerShape
{
    displayName = "$STR_ENH_MAIN_MARKER_SHAPE_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_MARKER_SHAPE_TOOLTIP";
    property = "ENH_markerShape";
    control = "ENH_MarkerShape";
    expression = "if (_value != 'NONE' && isServer) then {_this setMarkerShape _value}";
    defaultValue = "NONE";
    typeName = "STRING";
    validate = "STRING";
};
