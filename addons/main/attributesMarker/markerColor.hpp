class ENH_MarkerColor
{
    displayName = "$STR_ENH_MAIN_CUSTOM_MARKER_COLOR_DISPLAYNAME";
    tooltip = "";
    property = "ENH_markerColor";
    control = "ENH_MarkerColor";
    expression = "if (_value#0 && isServer) then {_this setMarkerColor _value#1}";
    defaultValue = "[false, '#(1,1,1)']";
    typeName = "ARRAY";
    validate = "ARRAY";
};
