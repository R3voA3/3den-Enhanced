class Enh_removeFromRemainsCollector: Enh_SetCaptive
{
	displayName = $STR_ENH_removeFromRemainsCollector_displayName;
	tooltip = $STR_ENH_removeFromRemainsCollector_tooltip;
	property = "Enh_removeFromRemainsCollector";
	expression = "if (_value) then {removeFromRemainsCollector [this]}";
};