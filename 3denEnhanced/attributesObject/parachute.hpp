class ENH_Parachute: ENH_SetCaptive
{
	displayName = $STR_ENH_PARACHUTE_DISPLAYNAME;
	tooltip = $STR_ENH_PARACHUTE_TOOLTIP;
	property = "ENH_parachute";
	expression = "if (_value && !is3DEN) then\
	{\
	 	_this moveInDriver (createVehicle ['Steerable_Parachute_F',getPos _this,[],0,'FLY']);\
	}";
	condition = "objectBrain";
};