class ENH_removeFromRemainsCollector
{
	displayName = $STR_ENH_REMOVEFROMREMAINSCOLLECTOR_DISPLAYNAME;
	tooltip = $STR_ENH_REMOVEFROMREMAINSCOLLECTOR_TOOLTIP;
  control = "Checkbox";
	property = "ENH_removeFromRemainsCollector";
	expression = "if (!is3DEN && {_value}) then {removeFromRemainsCollector [this]}";
  defaultValue = "false";
};