class ENH_DynamicSkill
{
	collapsed = 1;
	displayName = $STR_ENH_ATTRIBUTECATEGORY_DYNAMICSKILL;
	class Attributes
	{
		class ENH_Enable
		{
			displayName = $STR_ENH_ATTRIBUTECATEGORY_DYNAMICSKILL;
			property = "ENH_dynamicSkill";
			control = "ENH_DynamicSkill";
			expression = "if (!is3DEN && {_value # 0 && {isServer}}) then\
			{\
				_value params\
				[\
					'_enable',\
					'_skillMinBLUFOR',\
					'_skillAimMinBLUFOR',\
					'_skillMaxBLUFOR',\
					'_skillAimMaxBlUFOR',\
					'_skillMinOPFOR',\
					'_skillAimMinOPFOR',\
					'_skillMaxOPFOR',\
					'_skillAimMaxOPFOR',\
					'_skillMinINDFOR',\
					'_skillAimMinINDFOR',\
					'_skillMaxINDFOR',\
					'_skillAimMaxINDFOR'\
				];\
				[\
					true,\
					[\
						[WEST,_skillMinBLUFOR,_skillAimMinBLUFOR,_skillMaxBLUFOR,_skillAimMaxBlUFOR],\
						[EAST,_skillMinOPFOR,_skillAimMinOPFOR,_skillMaxOPFOR,_skillAimMaxOPFOR],\
						[INDEPENDENT,_skillMinINDFOR,_skillAimMinINDFOR,_skillMaxINDFOR,_skillAimMaxINDFOR]\
					]\
				] call BIS_fnc_EXP_camp_dynamicAISkill;\
			}";
			defaultValue = "[false,0.5,0.8,0.3,0.5,0.5,0.8,0.3,0.5,0.5,0.8,0.3,0.5,0.5,0.8,0.3,0.5]";
		};
	};
};