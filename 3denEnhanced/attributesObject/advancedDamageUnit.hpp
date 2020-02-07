class ENH_AdvancedDamageUnit
{
	displayName = $STR_ENH_attributeCategory_advancedDamage;
	collapsed = 1;
	class Attributes
	{
		class ENH_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_head;
			tooltip = "";
			property = "ENH_damageHead";
			control = "Slider";
			expression = "_this setHitPointDamage ['hitHead',_value];";
			defaultValue = "0";
			condition = "objectBrain";
		};
		class ENH_Face: ENH_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_face;
			property = "ENH_damageFace";
			expression = "_this setHitPointDamage ['hitFace',_value];";
		};
		class ENH_Neck: ENH_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_neck;
			property = "ENH_damageNeck";
			expression = "_this setHitPointDamage ['hitNeck',_value];";
		};
		class ENH_Chest: ENH_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_chest;
			property = "ENH_damageChest";
			expression = "_this setHitPointDamage ['hitChest',_value];";
		};
		class ENH_Arms: ENH_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_arms;
			property = "ENH_damageArms";
			expression = "_this setHitPointDamage ['hitArms',_value];";
		};
		class ENH_Hands: ENH_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_hands;
			property = "ENH_damageHands";
			expression = "_this setHitPointDamage ['hitHands',_value];";
		};
		class ENH_Abdomen: ENH_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_abdomen;
			property = "ENH_damageAbdomen";
			expression = "_this setHitPointDamage ['hitAbdomen',_value];";
		};
		class ENH_Pelvis: ENH_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_pelvis;
			property = "ENH_damagePelvis";
			expression = "_this setHitPointDamage ['hitPelvis',_value];";
		};
		class ENH_Diaphragm: ENH_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_diaphragm;
			property = "ENH_damageDiaphragm";
			expression = "_this setHitPointDamage ['hitDiaphragm',_value];";
		};
		class ENH_Legs: ENH_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_legs;
			property = "ENH_damageLegs";
			expression = "_this setHitPointDamage ['hitLegs',_value];";
		};
	};
};
