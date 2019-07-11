class Enh_AllowCrewInImmobile: Enh_SetCaptive
{
	displayName = $STR_ENH_allowCrewImmobile_displayName;
	tooltip = $STR_ENH_allowCrewImmobile_tooltip;
	property = "Enh_allowCrewInImmobile";
	expression =
	"\
		_this allowCrewInImmobile _value;\
		{\
			_x disableAI 'FSM';\
			_x setBehaviour 'CARELESS';\
		} forEach crew _this;\
	";
	condition = "objectVehicle";
};