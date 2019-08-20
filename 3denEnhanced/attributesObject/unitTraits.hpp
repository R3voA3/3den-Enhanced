class Enh_UnitTraits
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_unitTraits;
	class Attributes
	{
		class Enh_Medic
		{
			displayName = $STR_ENH_unitTraits_medic_displayName;
			tooltip = $STR_ENH_unitTraits_medic_tooltip;
			property = "Enh_unitTraits_medic";
			control = "Checkbox";
			expression = "_this setUnitTrait ['Medic',_value]";
			condition = "objectBrain";
			defaultValue = "_this getUnitTrait 'Medic'";
			typeName = "BOOL";
		};
		class Enh_Engineer: Enh_Medic
		{
			displayName = $STR_ENH_unitTraits_engineer_displayName;
			tooltip = $STR_ENH_unitTraits_engineer_tooltip;
			property = "Enh_unitTraits_engineer";
			expression = "_this setUnitTrait ['Engineer',_value]";
			defaultValue = "_this getUnitTrait 'Engineer'";
		};
		class Enh_ExplosiveSpecialist: Enh_Medic
		{
			displayName = $STR_ENH_unitTraits_explosiveSpecialist_displayName;
			tooltip = $STR_ENH_unitTraits_explosiveSpecialist_tooltip;
			property = "Enh_unitTrait_explosiveSpecialist";
			expression = "_this setUnitTrait ['ExplosiveSpecialist',_value]";
			defaultValue = "_this getUnitTrait 'ExplosiveSpecialist'";
		};
		class Enh_UAVHacker: Enh_Medic
		{
			displayName = $STR_ENH_unitTraits_UAVHacker_displayName;
			tooltip = $STR_ENH_unitTraits_UAVHacker_tooltip;
			property = "Enh_unitTrait_UAVHacker";
			expression = "_this setUnitTrait ['UAVHacker',_value]";
			defaultValue = "_this getUnitTrait 'UAVHacker'";
		};
		class Enh_Camouflage: Enh_Medic
		{
			displayName = $STR_ENH_camouflageCoef_displayName;
			tooltip = $STR_ENH_camouflageCoef_tooltip;
			property = "Enh_unitTraits_camouflage";
			control = "SliderCameraSpeedMult";
			expression = "_this setUnitTrait ['CamouflageCoef',_value]";
			defaultValue = "1";
			typeName = "NUMBER";
		};
		class Enh_AudibleCoef: Enh_Camouflage
		{
			displayName = $STR_ENH_audibleCoef_displayName;
         	tooltip = $STR_ENH_audibleCoef_tooltip;
			property = "Enh_unitTraits_audibleCoef";
			expression = "_this setUnitTrait ['AudibleCoef',_value]";
		};
      	class Enh_LoadCoef: Enh_Camouflage
      	{
         	displayName = $STR_ENH_loadCoef_displayName;
         	tooltip = $STR_ENH_loadCoef_tooltip;
         	property = "Enh_unitTraits_loadCoef";
         	expression = "_this setUnitTrait ['LoadCoef',_value]";
      	};
	};
};