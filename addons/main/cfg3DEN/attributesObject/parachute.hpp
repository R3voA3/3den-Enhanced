class ENH_Parachute
{
    displayName = "$STR_ENH_MAIN_PARACHUTE_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_PARACHUTE_TOOLTIP";
    property = "ENH_parachute";
    control = "Checkbox";
    expression = "\
    if (!is3DEN && _value) then\
    {\
        if (local _this) then\
        {\
            private _parachute = createVehicle ['Steerable_Parachute_F', getPosATL _this, [], 0, 'FLY'];\
            _this moveInDriver _parachute;\
        };\
    }";
    condition = "objectBrain";
    defaultValue = "false";
};
