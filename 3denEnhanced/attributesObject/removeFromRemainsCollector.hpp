class ENH_removeFromRemainsCollector: ENH_SetCaptive
{
	displayName = $STR_ENH_REMOVEFROMREMAINSCOLLECTOR_DISPLAYNAME;
	tooltip = $STR_ENH_REMOVEFROMREMAINSCOLLECTOR_TOOLTIP;
	property = "ENH_removeFromRemainsCollector";
	expression = "if (_value) then {removeFromRemainsCollector [this]}";
};