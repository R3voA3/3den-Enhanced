class Enh_OnEventCode
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_onEventCode;
	class Attributes
	{
		class Enh_OnRespawnEvent
		{
			displayName = $STR_ENH_onRespawnEvent_displayName;
			tooltip = $STR_ENH_onRespawnEvent_tooltip;
			property = "Enh_onRespawnEvent";
			control = "EditCodeMulti5";
			expression = "if (_value != 'false') then {_this addEventHandler ['respawn',_value]}";
			condition = "objectControllable + objectVehicle";
			typeName = "STRING";
			defaultValue = "'false'";
		};
		class Enh_OnKilledEvent: Enh_OnRespawnEvent
		{
			displayName = $STR_ENH_onKilledEvent_displayName;
			tooltip = $STR_ENH_onKilledEvent_tooltip;
			property = "Enh_onKilledEvent";
			expression = "if (_value != 'false') then {_this addEventHandler ['killed',_value]}";
		};
		class Enh_OnDamagedEvent: Enh_OnRespawnEvent
		{
			displayName = $STR_ENH_onDamagedEvent_displayName;
			tooltip = $STR_ENH_onDamagedEvent_tooltip;
			property = "Enh_onDamagedEvent";
			expression = "if (_value != 'false') then {_this addEventHandler ['dammaged',_value]}";
		};
	};
};