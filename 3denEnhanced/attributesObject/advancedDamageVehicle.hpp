class ENH_AdvancedDamageVehicle
{
	displayName = $STR_ENH_attributeCategory_advancedDamage;
	collapsed = 1;
	class Attributes
	{
		class ENH_AdvancedDamageVehicle_VariousVehicles//All Vehicles
		{
			control = "SubCategoryDesc2";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_advancedDamageVeh_categories_allVehicles_title;
			description = $STR_ENH_advancedDamageVeh_categories_allVehicles_description;
		};
		class ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_engine1;
			tooltip = "";
			property = "ENH_damageEngine";
			control = "Slider";
			expression = "_this setHitPointDamage ['hitEngine',_value]";
			defaultValue = "0";
			condition = "objectVehicle";
		};
		class ENH_Gun: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_gun;
			property = "ENH_damageGun";
			expression = "_this setHitPointDamage ['hitGun',_value]";
		};
		class ENH_FuelTank: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_fuelTank1;
			property = "ENH_damageFuelTank";
			expression = "_this setHitPointDamage ['hitFuel',_value]";
		};
		class ENH_Turret: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_turret;
			property = "ENH_damageTurret";
			expression = "_this setHitPointDamage ['hitTurret',_value]";
		};
		class ENH_Hull: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_hull;
			property = "ENH_hull";
			expression = "_this setHitPointDamage ['hitHull',_value]";
		};
		class ENH_Window: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows1;
			property = "ENH_damageWindows";
			expression = "_this setHitPointDamage ['HitRGlass',_value]";
		};
		class ENH_Window1: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows2;
			property = "ENH_damageWindows1";
			expression = "_this setHitPointDamage ['HitGlass1',_value]";
		};
		class ENH_Window2: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows3;
			property = "ENH_damageWindows2";
			expression = "_this setHitPointDamage ['HitGlass2',_value]";
		};
		class ENH_Window3: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows4;
			property = "ENH_damageWindows3";
			expression = "_this setHitPointDamage ['HitGlass3',_value]";
		};
		class ENH_Window4: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows5;
			property = "ENH_damageWindows4";
			expression = "_this setHitPointDamage ['HitGlass4',_value]";
		};
		class ENH_Window5: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows6;
			property = "ENH_damageWindows5";
			expression = "_this setHitPointDamage ['HitGlass5',_value]";
		};
		class ENH_Window6: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows7;
			property = "ENH_damageWindows6";
			expression = "_this setHitPointDamage ['HitGlass6',_value]";
		};
		class ENH_AdvancedDamageVehicle_LandVehicles
		{
			control = "SubCategoryDesc2";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_advancedDamageVeh_categories_landVehicles_title;
			description = $STR_ENH_advancedDamageVeh_categories_landVehicles_description;
		};
		class ENH_LFWheel: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_LFWheel;
			property = "ENH_damageLFWheel";
			expression = "_this setHitPointDamage ['hitLFWheel',_value]";
		};
		class ENH_RFWheel: ENH_Engine
		{
			displayName =$STR_ENH_advancedDamageVeh_RFWheel;
			property = "ENH_damageRFWheel";
			expression = "_this setHitPointDamage ['hitRFWheel',_value]";
		};
		class ENH_LF2Wheel: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_LF2Wheel;
			property = "ENH_damageLF2Wheel";
			expression = "_this setHitPointDamage ['HitLF2Wheel',_value]";
		};
		class ENH_RF2Wheel: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_RF2Wheel;
			property = "ENH_damageRF2Wheel";
			expression = "_this setHitPointDamage ['HitRF2Wheel',_value]";
		};
		class ENH_LMWheel: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_LMWheel;
			property = "ENH_damageLMWheel";
			expression = "_this setHitPointDamage ['HitLMWheel',_value]";
		};
		class ENH_RMWheel: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_RMWheel;
			property = "ENH_damageRMWheel";
			expression = "_this setHitPointDamage ['HitRMWheel',_value]";
		};
		class ENH_LBWheel: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_LBWheel;
			property = "ENH_damageLBWheel";
			expression = "_this setHitPointDamage ['HitLBWheel',_value]";
		};
		class ENH_RBWheel: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_RBWheel;
			property = "ENH_damageRBWheel";
			expression = "_this setHitPointDamage ['HitRBWheel',_value]";
		};
		class ENH_vehBody: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_body;
			property = "ENH_damageVehBody";
			expression = "_this setHitPointDamage ['hitBody',_value]";
		};
		class ENH_LTrack: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_LTrack;
			property = "ENH_damageLTrack";
			expression = "_this setHitPointDamage ['hitLTrack',_value]";
		};
		class ENH_RTrack: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_RTrack;
			property = "ENH_damageRTrack";
			expression = "_this setHitPointDamage ['hitRTrack',_value]";
		};
		class ENH_AdvancedDamageVehicle_Aeronautical
		{
			control = "SubCategoryDesc2";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_advancedDamageVeh_categories_aeronauticalVehicles_title;
			description = $STR_ENH_advancedDamageVeh_categories_aeronauticalVehicles_description;
		};
		class ENH_Avionics: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_avionics;
			property = "ENH_damageAvionics";
			expression = "_this setHitPointDamage ['hitAvionics',_value]";
		};
		class ENH_MainRotor: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_mainRotor;
			property = "ENH_damageMainRotor";
			expression = "_this setHitPointDamage ['hitRRotor',_value]";
		};
		class ENH_TailRotor: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_tailRotor;
			property = "ENH_damageTailRotor";
			expression = "_this setHitPointDamage ['hitVRotor',_value]";
		};
		class ENH_Engine2: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_engine2;
			property = "ENH_engine2";
			expression = "_this setHitPointDamage ['hitengine2',_value]";
		};
		class ENH_Fuel2: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_fuelTank2;
			property = "ENH_fuel2";
			expression = "_this setHitPointDamage ['hitfuel2',_value]";
		};
		class ENH_RAileron: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_leftAileron;
			property = "ENH_hitlaileron";
			expression = "_this setHitPointDamage ['hitlaileron',_value]";
		};
		class ENH_LAileron: ENH_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_rightAileron;
			property = "ENH_hitraileron";
			expression = "_this setHitPointDamage ['hitraileron',_value]";
		};
		class ENH_LRudder: ENH_Engine//Linkes Ruder
		{
			displayName = $STR_ENH_advancedDamageVeh_leftRudder;
			property = "ENH_hitlcrudder";
			expression = "_this setHitPointDamage ['hitlcrudder',_value]";
		};
		class ENH_RRudder: ENH_Engine//Querruder
		{
			displayName = $STR_ENH_advancedDamageVeh_RightRudder;
			property = "ENH_hitrrudder";
			expression = "_this setHitPointDamage ['hitrrudder',_value]";
		};
		class ENH_LCElevator: ENH_Engine//Linkes Höhenruder
		{
			displayName = $STR_ENH_advancedDamageVeh_leftElevator;
			property = "ENH_hitlcelevator";
			expression = "_this setHitPointDamage ['hitlcelevator',_value]";
		};
		class ENH_RCElevator: ENH_Engine//Querruder
		{
			displayName = $STR_ENH_advancedDamageVeh_rightElevator;
			property = "ENH_hitrelevator";
			expression = "_this setHitPointDamage ['hitrelevator',_value]";
		};
		class ENH_GearLights: ENH_Engine//Querruder
		{
			displayName = $STR_ENH_advancedDamageVeh_gearLights;
			property = "ENH_gear_f_lights";
			expression = "_this setHitPointDamage ['#gear_f_lights',_value]";
		};
	};
};