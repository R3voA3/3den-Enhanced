class ENH_removeFromRemainsCollector: ENH_SetCaptive
{
	displayName = $STR_ENH_removeFromRemainsCollector_displayName;
	tooltip = $STR_ENH_removeFromRemainsCollector_tooltip;
	property = "ENH_removeFromRemainsCollector";
	expression = "if (_value) then {removeFromRemainsCollector [this]}";
};