class ENH_AddGunLight
{
    displayName = "$STR_ENH_MAIN_ADDGUNLIGHT_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_ADDGUNLIGHT_TOOLTIP";
    property = "ENH_addGunLight";
    control = "Checkbox";
    expression =
    "\
        if (!is3DEN && _value) then\
        {\
            if (primaryWeaponItems _this select 1 isEqualTo '') then\
            {\
                [_this, 'acc_flashlight'] remoteExec ['addPrimaryWeaponItem', _this];\
            };\
            [_this, 'forceOn'] remoteExec ['enableGunLights', _this];\
        }";
    condition = "objectBrain";
    defaultValue = "false";
};
