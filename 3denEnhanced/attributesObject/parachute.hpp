class Enh_Parachute: Enh_SetCaptive
{
	displayName = $STR_ENH_parachute_displayName;
	tooltip = $STR_ENH_parachute_tooltip;
	property = "Enh_parachute";
	expression = "if (_value && !is3DEN) then\
	{\
	 	_this moveInDriver (createVehicle ['Steerable_Parachute_F',getPos _this,[],0,'FLY']);\
	}";
	condition = "objectBrain";
};