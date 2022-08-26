class ENH_UnitTraits
{
  collapsed = 1;
  displayName = "$STR_ENH_ATTRIBUTECATEGORY_UNITTRAITS";
  class Attributes
  {
  class ENH_Medic
  {
    displayName = "$STR_ENH_UNITTRAITS_MEDIC_DISPLAYNAME";
    tooltip = "$STR_ENH_UNITTRAITS_MEDIC_TOOLTIP";
    property = "ENH_unitTraits_medic";
    control = "Checkbox";
    expression = "[_this, ['Medic', _value]] remoteExec ['setUnitTrait', _this]";
    condition = "objectBrain";
    defaultValue = "_this getUnitTrait 'Medic'";
  };
  class ENH_Engineer: ENH_Medic
  {
    displayName = "$STR_ENH_UNITTRAITS_ENGINEER_DISPLAYNAME";
    tooltip = "$STR_ENH_UNITTRAITS_ENGINEER_TOOLTIP";
    property = "ENH_unitTraits_engineer";
    expression = "[_this, ['Engineer', _value]] remoteExec ['setUnitTrait', _this]";
    defaultValue = "_this getUnitTrait 'Engineer'";
  };
  class ENH_ExplosiveSpecialist: ENH_Medic
  {
    displayName = "$STR_ENH_UNITTRAITS_EXPLOSIVESPECIALIST_DISPLAYNAME";
    tooltip = "$STR_ENH_UNITTRAITS_EXPLOSIVESPECIALIST_TOOLTIP";
    property = "ENH_unitTrait_explosiveSpecialist";
    expression = "[_this, ['ExplosiveSpecialist', _value]] remoteExec ['setUnitTrait', _this]";
    defaultValue = "_this getUnitTrait 'ExplosiveSpecialist'";
  };
  class ENH_UAVHacker: ENH_Medic
  {
    displayName = "$STR_ENH_UNITTRAITS_UAVHACKER_DISPLAYNAME";
    tooltip = "$STR_ENH_UNITTRAITS_UAVHACKER_TOOLTIP";
    property = "ENH_unitTrait_UAVHacker";
    expression = "[_this, ['UAVHacker', _value]] remoteExec ['setUnitTrait', _this]";
    defaultValue = "_this getUnitTrait 'UAVHacker'";
  };
  class ENH_Camouflage: ENH_Medic
  {
    displayName = "$STR_ENH_CAMOUFLAGECOEF_DISPLAYNAME";
    tooltip = "$STR_ENH_CAMOUFLAGECOEF_TOOLTIP";
    property = "ENH_unitTraits_camouflage";
    control = "SliderCameraSpeedMult";
    expression = "[_this, ['CamouflageCoef', _value]] remoteExec ['setUnitTrait', _this]";
    defaultValue = "1";
  };
  class ENH_AudibleCoef: ENH_Camouflage
  {
    displayName = "$STR_ENH_AUDIBLECOEF_DISPLAYNAME";
    tooltip = "$STR_ENH_AUDIBLECOEF_TOOLTIP";
    property = "ENH_unitTraits_audibleCoef";
    expression = "[_this, ['AudibleCoef', _value]] remoteExec ['setUnitTrait', _this]";
  };
  class ENH_LoadCoef: ENH_Camouflage
  {
    displayName = "$STR_ENH_LOADCOEF_DISPLAYNAME";
    tooltip = "$STR_ENH_LOADCOEF_TOOLTIP";
    property = "ENH_unitTraits_loadCoef";
    expression = "[_this, ['LoadCoef', _value]] remoteExec ['setUnitTrait', _this]";
  };
  };
};