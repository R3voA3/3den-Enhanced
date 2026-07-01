class ENH_TurretStabilization // TODO: localize 2026-05-05 R3vo
{
    displayName = "$STR_ENH_MAIN_TURRETSTABILIZATION_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_TURRETSTABILIZATION_TOOLTIP";
    property = "ENH_TurretStabilization";
    control = "Combo";
    expression = "\
    if (!is3DEN && {_value > -1}) then\
    {\
        if (isNil 'ENH_fnc_applyTurretStabilization') then\
        {\
            ENH_fnc_applyTurretStabilization = compileFinal\
            {\
                params ['_vehicle', '_value'];\
                allTurrets _vehicle apply\
                {\
                    _vehicle enableGunStabilization [_value, _x];\
                };\
            };\
        };\
        [_this, _value] remoteExec ['ENH_fnc_applyTurretStabilization', _this];\
    }";
    condition = "objectVehicle * script";
    conditionScript = "allTurrets _this isNotEqualTo []";
    defaultValue = -1;
    typeName = "NUMBER";
    class Values
    {
        class Unchanged
        {
            name = "$STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TEXT";
            tooltip = "$STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TOOLTIP";
            value = -1;
        };
        class NoStabilization
        {
            name = "$STR_ENH_MAIN_TURRETSTABILIZATION_NONE_TEXT";
            value = 0;
        };
        class ElevationStabilisation
        {
            name = "$STR_ENH_MAIN_TURRETSTABILIZATION_VERTICAL_TEXT";
            value = 1;
        };
        class TraverseStabilisation
        {
            name = "$STR_ENH_MAIN_TURRETSTABILIZATION_HORIZONTAL_TEXT";
            value = 2;
        };
        class FullStabilization
        {
            name = "$STR_ENH_MAIN_TURRETSTABILIZATION_FULL_TEXT";
            value = 3;
        };
    };
};
