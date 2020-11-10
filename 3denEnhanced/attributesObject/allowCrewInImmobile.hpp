class ENH_AllowCrewInImmobile
{
  displayName = $STR_ENH_ALLOWCREWIMMOBILE_DISPLAYNAME;
  tooltip = $STR_ENH_ALLOWCREWIMMOBILE_TOOLTIP;
  property = "ENH_allowCrewInImmobile";
  control = "Checkbox";
  expression =
  "\
  _this allowCrewInImmobile _value;\
  {\
    _x disableAI 'FSM';\
    _x setBehaviour 'CARELESS';\
  } forEach crew _this;\
  ";
  condition = "objectVehicle";
  defaultValue = "false";
};