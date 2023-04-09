class ENH_MarkerDrawPriority
{
  displayName = "STR_ENH_MARKERDRAWPRIORITY_DISPLAYNAME";
  tooltip = "$STR_ENH_MARKERDRAWPRIORITY_TOOLTIP";
  property = "ENH_markerDrawPriority";
  control = "EditShort";
  expression = "if (_value != 0) then {_this setMarkerDrawPriority _value}";
  condition = "1";
  defaultValue = "0";
  typeName = "NUMBER";
  validate = "NUMBER";
};