class ENH_AdvancedDamageVehicle
{
	displayName = $STR_ENH_ATTRIBUTECATEGORY_ADVANCEDDAMAGE;
	collapsed = 1;
	class Attributes
	{
		class ENH_AdvancedDamageVehicle_VariousVehicles//All Vehicles
		{
			control = "SubCategoryDesc2";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_CATEGORIES_ALLVEHICLES_TITLE;
			description = $STR_ENH_ADVANCEDDAMAGEVEH_CATEGORIES_ALLVEHICLES_DESCRIPTION;
		};
		class ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_ENGINE1;
			tooltip = "";
			property = "ENH_damageEngine";
			control = "Slider";
			expression = "_this setHitPointDamage ['hitEngine',_value]";
			defaultValue = "0";
			condition = "objectVehicle";
		};
		class ENH_Gun: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_GUN;
			property = "ENH_damageGun";
			expression = "_this setHitPointDamage ['hitGun',_value]";
		};
		class ENH_FuelTank: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_FUELTANK1;
			property = "ENH_damageFuelTank";
			expression = "_this setHitPointDamage ['hitFuel',_value]";
		};
		class ENH_Turret: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_TURRET;
			property = "ENH_damageTurret";
			expression = "_this setHitPointDamage ['hitTurret',_value]";
		};
		class ENH_Hull: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_HULL;
			property = "ENH_hull";
			expression = "_this setHitPointDamage ['hitHull',_value]";
		};
		class ENH_Window: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_WINDOWS1;
			property = "ENH_damageWindows";
			expression = "_this setHitPointDamage ['HitRGlass',_value]";
		};
		class ENH_Window1: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_WINDOWS2;
			property = "ENH_damageWindows1";
			expression = "_this setHitPointDamage ['HitGlass1',_value]";
		};
		class ENH_Window2: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_WINDOWS3;
			property = "ENH_damageWindows2";
			expression = "_this setHitPointDamage ['HitGlass2',_value]";
		};
		class ENH_Window3: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_WINDOWS4;
			property = "ENH_damageWindows3";
			expression = "_this setHitPointDamage ['HitGlass3',_value]";
		};
		class ENH_Window4: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_WINDOWS5;
			property = "ENH_damageWindows4";
			expression = "_this setHitPointDamage ['HitGlass4',_value]";
		};
		class ENH_Window5: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_WINDOWS6;
			property = "ENH_damageWindows5";
			expression = "_this setHitPointDamage ['HitGlass5',_value]";
		};
		class ENH_Window6: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_WINDOWS7;
			property = "ENH_damageWindows6";
			expression = "_this setHitPointDamage ['HitGlass6',_value]";
		};
		class ENH_AdvancedDamageVehicle_LandVehicles
		{
			control = "SubCategoryDesc2";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_CATEGORIES_LANDVEHICLES_TITLE;
			description = $STR_ENH_ADVANCEDDAMAGEVEH_CATEGORIES_LANDVEHICLES_DESCRIPTION;
		};
		class ENH_LFWheel: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_LFWHEEL;
			property = "ENH_damageLFWheel";
			expression = "_this setHitPointDamage ['hitLFWheel',_value]";
		};
		class ENH_RFWheel: ENH_Engine
		{
			displayName =$STR_ENH_ADVANCEDDAMAGEVEH_RFWHEEL;
			property = "ENH_damageRFWheel";
			expression = "_this setHitPointDamage ['hitRFWheel',_value]";
		};
		class ENH_LF2Wheel: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_LF2WHEEL;
			property = "ENH_damageLF2Wheel";
			expression = "_this setHitPointDamage ['HitLF2Wheel',_value]";
		};
		class ENH_RF2Wheel: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_RF2WHEEL;
			property = "ENH_damageRF2Wheel";
			expression = "_this setHitPointDamage ['HitRF2Wheel',_value]";
		};
		class ENH_LMWheel: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_LMWHEEL;
			property = "ENH_damageLMWheel";
			expression = "_this setHitPointDamage ['HitLMWheel',_value]";
		};
		class ENH_RMWheel: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_RMWHEEL;
			property = "ENH_damageRMWheel";
			expression = "_this setHitPointDamage ['HitRMWheel',_value]";
		};
		class ENH_LBWheel: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_LBWHEEL;
			property = "ENH_damageLBWheel";
			expression = "_this setHitPointDamage ['HitLBWheel',_value]";
		};
		class ENH_RBWheel: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_RBWHEEL;
			property = "ENH_damageRBWheel";
			expression = "_this setHitPointDamage ['HitRBWheel',_value]";
		};
		class ENH_vehBody: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_BODY;
			property = "ENH_damageVehBody";
			expression = "_this setHitPointDamage ['hitBody',_value]";
		};
		class ENH_LTrack: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_LTRACK;
			property = "ENH_damageLTrack";
			expression = "_this setHitPointDamage ['hitLTrack',_value]";
		};
		class ENH_RTrack: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_RTRACK;
			property = "ENH_damageRTrack";
			expression = "_this setHitPointDamage ['hitRTrack',_value]";
		};
		class ENH_AdvancedDamageVehicle_Aeronautical
		{
			control = "SubCategoryDesc2";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_CATEGORIES_AERONAUTICALVEHICLES_TITLE;
			description = $STR_ENH_ADVANCEDDAMAGEVEH_CATEGORIES_AERONAUTICALVEHICLES_DESCRIPTION;
		};
		class ENH_Avionics: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_AVIONICS;
			property = "ENH_damageAvionics";
			expression = "_this setHitPointDamage ['hitAvionics',_value]";
		};
		class ENH_MainRotor: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_MAINROTOR;
			property = "ENH_damageMainRotor";
			expression = "_this setHitPointDamage ['hitRRotor',_value]";
		};
		class ENH_TailRotor: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_TAILROTOR;
			property = "ENH_damageTailRotor";
			expression = "_this setHitPointDamage ['hitVRotor',_value]";
		};
		class ENH_Engine2: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_ENGINE2;
			property = "ENH_engine2";
			expression = "_this setHitPointDamage ['hitengine2',_value]";
		};
		class ENH_Fuel2: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_FUELTANK2;
			property = "ENH_fuel2";
			expression = "_this setHitPointDamage ['hitfuel2',_value]";
		};
		class ENH_RAileron: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_LEFTAILERON;
			property = "ENH_hitlaileron";
			expression = "_this setHitPointDamage ['hitlaileron',_value]";
		};
		class ENH_LAileron: ENH_Engine
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_RIGHTAILERON;
			property = "ENH_hitraileron";
			expression = "_this setHitPointDamage ['hitraileron',_value]";
		};
		class ENH_LRudder: ENH_Engine//Linkes Ruder
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_LEFTRUDDER;
			property = "ENH_hitlcrudder";
			expression = "_this setHitPointDamage ['hitlcrudder',_value]";
		};
		class ENH_RRudder: ENH_Engine//Querruder
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_RIGHTRUDDER;
			property = "ENH_hitrrudder";
			expression = "_this setHitPointDamage ['hitrrudder',_value]";
		};
		class ENH_LCElevator: ENH_Engine//Linkes Höhenruder
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_LEFTELEVATOR;
			property = "ENH_hitlcelevator";
			expression = "_this setHitPointDamage ['hitlcelevator',_value]";
		};
		class ENH_RCElevator: ENH_Engine//Querruder
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_RIGHTELEVATOR;
			property = "ENH_hitrelevator";
			expression = "_this setHitPointDamage ['hitrelevator',_value]";
		};
		class ENH_GearLights: ENH_Engine//Querruder
		{
			displayName = $STR_ENH_ADVANCEDDAMAGEVEH_GEARLIGHTS;
			property = "ENH_gear_f_lights";
			expression = "_this setHitPointDamage ['#gear_f_lights',_value]";
		};
	};
};