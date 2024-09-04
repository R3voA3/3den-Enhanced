class ENH_VirtualArsenal
{
    displayName = "$STR_ENH_MAIN_ARSENAL_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_ARSENAL_TOOLTIP";
    property = "ENH_virtualArsenal";
    control = "Checkbox";
    expression = "if (!is3DEN && _value) then {['AmmoboxInit', [_this, true]] spawn BIS_fnc_arsenal}";
    condition = "1";
    defaultValue = "false";
};
