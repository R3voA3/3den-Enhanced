class Enh_DynamikSkill
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_dynamicSkill;
	class Attributes
	{
		class Enh_Enable
		{
			displayName = $STR_ENH_dynamicSkill_enable_displayName;
			tooltip = $STR_ENH_dynamicSkill_enable_tooltip;
			property = "Enh_toggleDynamicSkill";
			control = "CheckboxState";
			expression = "if (_value && !is3DEN && isServer) then\
			{\
				[] spawn\
				{\
					waitUntil {time > 0.2};\
					[\
						true,\
						[\
							[\
								WEST,\
								missionNamespace getVariable ['Enh_skillMinWest',0.5],\
								missionNamespace getVariable ['Enh_skillAimMinWest',0.3],\
								missionNamespace getVariable ['Enh_skillMaxWest',0.8],\
								missionNamespace getVariable ['Enh_skillAimMaxWest',0.5]\
							],\
							[\
								EAST,\
								missionNamespace getVariable ['Enh_skillMinEast',0.5],\
								missionNamespace getVariable ['Enh_skillAimMinEast',0.3],\
								missionNamespace getVariable ['Enh_skillMaxEast',0.8],\
								missionNamespace getVariable ['Enh_skillAimMaxEast',0.5]\
							],\
							[\
								INDEPENDENT,\
								missionNamespace getVariable ['Enh_skillMinIndep',0.5],\
								missionNamespace getVariable ['Enh_skillAimMinIndep',0.3],\
								missionNamespace getVariable ['Enh_skillMaxIndep',0.8],\
								missionNamespace getVariable ['Enh_skillAimMaxIndep',0.5]\
							]\
						]\
					] call BIS_fnc_EXP_camp_dynamicAISkill;\
				};\
			}";
			defaultValue = "false";
		};
		class Enh_BLUFORSkill
		{
			control = "SubCategory";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_dynamicSkill_BLUFORSkill_displayname;
		};
		class Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillMin_displayname;
			property = "Enh_skillMinWest";
			control = "Skill";
			expression = "if (isServer) then {missionNamespace setVariable ['%s',_value]}";
			defaultValue = "0.5";
			typeName = "NUMBER";
		};
		class Enh_SkillAimMinWest: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillMin_displayName;
			property = "Enh_skillAimMinWest";
			defaultValue = "0.3";
		};
		class Enh_SkillMaxWest: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillMax_displayName;
			property = "Enh_skillMaxWest";
			defaultValue = "0.8";
		};
		class Enh_SkillAimMaxWest: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillAimMax_displayName;
			property = "Enh_skillAimMaxWest";
		};
		class Enh_OPFORSkill
		{
			control = "SubCategory";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_dynamicSkill_OPFORSkill_displayName;
		};
		class Enh_SkillMinEast: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillMin_displayName;
			property = "Enh_skillMinEast";
		};
		class Enh_SkillAimMinEast: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillAimMin_displayName;
			property = "Enh_skillAimMinEast";
			defaultValue = "0.3";
		};
		class Enh_SkillMaxEast: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillMax_displayName;
			property = "Enh_skillMaxEast";
			defaultValue = "0.8";
		};
		class Enh_SkillAimMaxEast: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillAimMax_displayName;
			property = "Enh_skillAimMaxEast";
		};
		class Enh_INDFORSkill
		{
			control = "SubCategory";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_dynamicSkill_INDFORSkill_displayName;
		};
		class Enh_SkillMinIndep: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillMin_displayName;
			property = "Enh_skillMinIndep";
		};
		class Enh_SkillAimMinIndep: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillAimMin_displayName;
			property = "Enh_skillAimMinIndep";
			defaultValue = "0.3";
		};
		class Enh_SkillMaxIndep: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillMax_displayName;
			property = "Enh_skillMaxIndep";
			defaultValue = "0.8";
		};
		class Enh_SkillAimMaxIndep: Enh_SkillMinWest
		{
			displayName = $STR_ENH_dynamicSkill_skillAimMax_displayName;
			property = "Enh_skillAimMaxIndep";
		};
	};
};
