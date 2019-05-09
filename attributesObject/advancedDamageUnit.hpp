class Enh_AdvancedDamageUnit
{
	displayName = $STR_ENH_attributeCategory_advancedDamage;
	collapsed = 1;
	class Attributes
	{
		class Enh_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_head;
			tooltip = "";
			property = "Enh_damageHead";
			control = "Slider";
			expression = "_this setHitPointDamage ['hitHead',_value];";
			defaultValue = "0";
			condition = "objectBrain";
		};
		class Enh_Face: Enh_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_face;
			property = "Enh_damageFace";
			expression = "_this setHitPointDamage ['hitFace',_value];";
		};
		class Enh_Neck: Enh_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_neck;
			property = "Enh_damageNeck";
			expression = "_this setHitPointDamage ['hitNeck',_value];";
		};
		class Enh_Chest: Enh_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_chest;
			property = "Enh_damageChest";
			expression = "_this setHitPointDamage ['hitChest',_value];";
		};
		class Enh_Arms: Enh_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_arms;
			property = "Enh_damageArms";
			expression = "_this setHitPointDamage ['hitArms',_value];";
		};
		class Enh_Hands: Enh_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_hands;
			property = "Enh_damageHands";
			expression = "_this setHitPointDamage ['hitHands',_value];";
		};
		class Enh_Abdomen: Enh_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_abdomen;
			property = "Enh_damageAbdomen";
			expression = "_this setHitPointDamage ['hitAbdomen',_value];";
		};
		class Enh_Pelvis: Enh_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_pelvis;
			property = "Enh_damagePelvis";
			expression = "_this setHitPointDamage ['hitPelvis',_value];";
		};
		class Enh_Diaphragm: Enh_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_diaphragm;
			property = "Enh_damageDiaphragm";
			expression = "_this setHitPointDamage ['hitDiaphragm',_value];";
		};
		class Enh_Legs: Enh_Head
		{
			displayName = $STR_ENH_advancedDamageUnit_legs;
			property = "Enh_damageLegs";
			expression = "_this setHitPointDamage ['hitLegs',_value];";
		};
	};
};
