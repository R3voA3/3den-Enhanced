class ENH_AllowSprint
{
  displayName = "$STR_ENH_ALLOWSPRINTING_DISPLAYNAME";
  tooltip = "$STR_ENH_ALLOWSPRINTING_TOOLTIP";
  control = "Checkbox";
  property = "ENH_allowSprint";
  expression = "_this allowSprint _value";
  defaultValue = "true";
  condition = "objectBrain";
};