class ENH_AdvancedDamage: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_advancedDamage_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_advancedDamage_onAttributeSave";
    class Controls: Controls {};// Is filled dynamically on attributeLoad
};
