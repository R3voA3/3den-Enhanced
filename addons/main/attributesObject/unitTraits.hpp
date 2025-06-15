class ENH_UnitTraits
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_ATTRIBUTECATEGORY_UNITTRAITS";
    class Attributes
    {
        class ENH_UnitTraits_Subcategory
        {
            description = "$STR_ENH_MAIN_UNITTRAITS_SUBCATEGORY";
            data = "AttributeSystemSubcategory";
            control = "ENH_SubCategoryNoHeader1_Fixed";
        };
        class ENH_Medic // Disabled when ACE is loaded
        {
            displayName = "$STR_ENH_MAIN_UNITTRAITS_MEDIC_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_UNITTRAITS_MEDIC_TOOLTIP";
            property = "ENH_unitTraits_medic";
            control = "Checkbox";
            expression = "if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['Medic', _value]] remoteExec ['setUnitTrait', _this]}";
            condition = "objectBrain";
            defaultValue = "_this getUnitTrait 'Medic'";
        };
        class ENH_Engineer: ENH_Medic // Disabled when ACE is loaded
        {
            displayName = "$STR_ENH_MAIN_UNITTRAITS_ENGINEER_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_UNITTRAITS_ENGINEER_TOOLTIP";
            property = "ENH_unitTraits_engineer";
            expression = "if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['Engineer', _value]] remoteExec ['setUnitTrait', _this]}";
            defaultValue = "_this getUnitTrait 'Engineer'";
        };
        class ENH_ExplosiveSpecialist: ENH_Medic // Disabled when ACE is loaded
        {
            displayName = "$STR_ENH_MAIN_UNITTRAITS_EXPLOSIVESPECIALIST_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_UNITTRAITS_EXPLOSIVESPECIALIST_TOOLTIP";
            property = "ENH_unitTrait_explosiveSpecialist";
            expression = "if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['ExplosiveSpecialist', _value]] remoteExec ['setUnitTrait', _this]}";
            defaultValue = "_this getUnitTrait 'ExplosiveSpecialist'";
        };
        class ENH_UAVHacker: ENH_Medic
        {
            displayName = "$STR_ENH_MAIN_UNITTRAITS_UAVHACKER_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_UNITTRAITS_UAVHACKER_TOOLTIP";
            property = "ENH_unitTrait_UAVHacker";
            expression = "[_this, ['UAVHacker', _value]] remoteExec ['setUnitTrait', _this]";
            defaultValue = "_this getUnitTrait 'UAVHacker'";
        };
        class ENH_Camouflage: ENH_Medic // Disabled when ACE is loaded
        {
            displayName = "$STR_ENH_MAIN_CAMOUFLAGECOEF_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_CAMOUFLAGECOEF_TOOLTIP";
            property = "ENH_unitTraits_camouflage";
            control = "ENH_SliderMultiZero";
            expression = "if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['CamouflageCoef', _value]] remoteExec ['setUnitTrait', _this]}";
            defaultValue = 1;
        };
        class ENH_AudibleCoef: ENH_Camouflage // Disabled when ACE is loaded
        {
            displayName = "$STR_ENH_MAIN_AUDIBLECOEF_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AUDIBLECOEF_TOOLTIP";
            property = "ENH_unitTraits_audibleCoef";
            expression = "if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['AudibleCoef', _value]] remoteExec ['setUnitTrait', _this]}";
        };
        class ENH_LoadCoef: ENH_Camouflage // Disabled when ACE is loaded
        {
            displayName = "$STR_ENH_MAIN_LOADCOEF_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_LOADCOEF_TOOLTIP";
            property = "ENH_unitTraits_loadCoef";
            expression = "if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['LoadCoef', _value]] remoteExec ['setUnitTrait', _this]}";
        };
    };
};
