class ENH_AllowCrewInImmobile
{
    displayName = "$STR_ENH_MAIN_ALLOWCREWIMMOBILE_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_ALLOWCREWIMMOBILE_TOOLTIP";
    property = "ENH_allowCrewInImmobile";
    control = "Checkbox";
    expression =
    "\
    [_this, _value] remoteExec ['allowCrewInImmobile', _this];\
    {\
        [_x, 'FSM'] remoteExec ['disableAI', _x];\
        [_x, 'CARELESS'] remoteExec ['setBehaviour', _x];\
    } forEach crew _this;\
    ";
    condition = "objectVehicle";
    defaultValue = "false";
};
