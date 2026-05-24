class ENH_MarkerDrawPriority
{
    displayName = "$STR_ENH_MAIN_MARKERDRAWPRIORITY_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_MARKERDRAWPRIORITY_TOOLTIP";
    property = "ENH_markerDrawPriority";
    control = "EditShort";
    expression = "if (_value != 0 && isServer) then {[_this, _value] remoteExec ['setMarkerDrawPriority', 0, true]}";
    defaultValue = 0;
    typeName = "NUMBER";
    validate = "NUMBER";
};
