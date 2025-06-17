class ENH_MarkerShape
{
    displayName = "Custom Shape";
    tooltip = "";
    property = "ENH_markerShape";
    control = "ENH_MarkerShape";
    expression = "if (_value != 'NONE' && isServer) then {_this setMarkerShape _value}";
    defaultValue = "NONE";
    typeName = "STRING";
    validate = "STRING";
};
