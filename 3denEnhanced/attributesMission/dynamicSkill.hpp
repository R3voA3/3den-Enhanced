class ENH_DynamicSkill
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_dynamicSkill;
	class Attributes
	{
		class ENH_Enable
		{
			displayName = $STR_ENH_attributeCategory_dynamicSkill;
			property = "ENH_dynamicSkill";
			control = "ENH_DynamicSkill";
			expression = "if (_value # 0 && !is3DEN && isServer) then\
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