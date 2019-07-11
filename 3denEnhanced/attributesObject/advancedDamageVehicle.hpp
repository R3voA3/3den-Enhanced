class Enh_AdvancedDamageVehicle
{
	displayName = $STR_ENH_attributeCategory_advancedDamage;
	collapsed = 1;
	class Attributes
	{
		class Enh_AdvancedDamageVehicle_VariousVehicles//All Vehicles
		{
			control = "SubCategoryDesc2";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_advancedDamageVeh_categories_allVehicles_title;
			description = $STR_ENH_advancedDamageVeh_categories_allVehicles_description;
		};
		class Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_engine1;
			tooltip = "";
			property = "Enh_damageEngine";
			control = "Slider";
			expression = "_this setHitPointDamage ['hitEngine',_value]";
			defaultValue = "0";
			condition = "objectVehicle";
		};
		class Enh_Gun: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_gun;
			property = "Enh_damageGun";
			expression = "_this setHitPointDamage ['hitGun',_value]";
		};
		class Enh_FuelTank: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_fuelTank1;
			property = "Enh_damageFuelTank";
			expression = "_this setHitPointDamage ['hitFuel',_value]";
		};
		class Enh_Turret: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_turret;
			property = "Enh_damageTurret";
			expression = "_this setHitPointDamage ['hitTurret',_value]";
		};
		class Enh_Hull: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_hull;
			property = "Enh_hull";
			expression = "_this setHitPointDamage ['hitHull',_value]";
		};
		class Enh_Window: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows1;
			property = "Enh_damageWindows";
			expression = "_this setHitPointDamage ['HitRGlass',_value]";
		};
		class Enh_Window1: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows2;
			property = "Enh_damageWindows1";
			expression = "_this setHitPointDamage ['HitGlass1',_value]";
		};
		class Enh_Window2: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows3;
			property = "Enh_damageWindows2";
			expression = "_this setHitPointDamage ['HitGlass2',_value]";
		};
		class Enh_Window3: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows4;
			property = "Enh_damageWindows3";
			expression = "_this setHitPointDamage ['HitGlass3',_value]";
		};
		class Enh_Window4: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows5;
			property = "Enh_damageWindows4";
			expression = "_this setHitPointDamage ['HitGlass4',_value]";
		};
		class Enh_Window5: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows6;
			property = "Enh_damageWindows5";
			expression = "_this setHitPointDamage ['HitGlass5',_value]";
		};
		class Enh_Window6: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_windows7;
			property = "Enh_damageWindows6";
			expression = "_this setHitPointDamage ['HitGlass6',_value]";
		};
		class Enh_AdvancedDamageVehicle_LandVehicles
		{
			control = "SubCategoryDesc2";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_advancedDamageVeh_categories_landVehicles_title;
			description = $STR_ENH_advancedDamageVeh_categories_landVehicles_description;
		};
		class Enh_LFWheel: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_LFWheel;
			property = "Enh_damageLFWheel";
			expression = "_this setHitPointDamage ['hitLFWheel',_value]";
		};
		class Enh_RFWheel: Enh_Engine
		{
			displayName =$STR_ENH_advancedDamageVeh_RFWheel;
			property = "Enh_damageRFWheel";
			expression = "_this setHitPointDamage ['hitRFWheel',_value]";
		};
		class Enh_LF2Wheel: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_LF2Wheel;
			property = "Enh_damageLF2Wheel";
			expression = "_this setHitPointDamage ['HitLF2Wheel',_value]";
		};
		class Enh_RF2Wheel: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_RF2Wheel;
			property = "Enh_damageRF2Wheel";
			expression = "_this setHitPointDamage ['HitRF2Wheel',_value]";
		};
		class Enh_LMWheel: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_LMWheel;
			property = "Enh_damageLMWheel";
			expression = "_this setHitPointDamage ['HitLMWheel',_value]";
		};
		class Enh_RMWheel: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_RMWheel;
			property = "Enh_damageRMWheel";
			expression = "_this setHitPointDamage ['HitRMWheel',_value]";
		};
		class Enh_LBWheel: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_LBWheel;
			property = "Enh_damageLBWheel";
			expression = "_this setHitPointDamage ['HitLBWheel',_value]";
		};
		class Enh_RBWheel: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_RBWheel;
			property = "Enh_damageRBWheel";
			expression = "_this setHitPointDamage ['HitRBWheel',_value]";
		};
		class Enh_vehBody: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_body;
			property = "Enh_damageVehBody";
			expression = "_this setHitPointDamage ['hitBody',_value]";
		};
		class Enh_LTrack: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_LTrack;
			property = "Enh_damageLTrack";
			expression = "_this setHitPointDamage ['hitLTrack',_value]";
		};
		class Enh_RTrack: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_RTrack;
			property = "Enh_damageRTrack";
			expression = "_this setHitPointDamage ['hitRTrack',_value]";
		};
		class Enh_AdvancedDamageVehicle_Aeronautical
		{
			control = "SubCategoryDesc2";
			data = "AttributeSystemSubcategory";
			displayName = $STR_ENH_advancedDamageVeh_categories_aeronauticalVehicles_title;
			description = $STR_ENH_advancedDamageVeh_categories_aeronauticalVehicles_description;
		};
		class Enh_Avionics: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_avionics;
			property = "Enh_damageAvionics";
			expression = "_this setHitPointDamage ['hitAvionics',_value]";
		};
		class Enh_MainRotor: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_mainRotor;
			property = "Enh_damageMainRotor";
			expression = "_this setHitPointDamage ['hitRRotor',_value]";
		};
		class Enh_TailRotor: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_tailRotor;
			property = "Enh_damageTailRotor";
			expression = "_this setHitPointDamage ['hitVRotor',_value]";
		};
		class Enh_Engine2: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_engine2;
			property = "Enh_engine2";
			expression = "_this setHitPointDamage ['hitengine2',_value]";
		};
		class Enh_Fuel2: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_fuelTank2;
			property = "Enh_fuel2";
			expression = "_this setHitPointDamage ['hitfuel2',_value]";
		};
		class Enh_RAileron: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_leftAileron;
			property = "Enh_hitlaileron";
			expression = "_this setHitPointDamage ['hitlaileron',_value]";
		};
		class Enh_LAileron: Enh_Engine
		{
			displayName = $STR_ENH_advancedDamageVeh_rightAileron;
			property = "Enh_hitraileron";
			expression = "_this setHitPointDamage ['hitraileron',_value]";
		};
		class Enh_LRudder: Enh_Engine//Linkes Ruder
		{
			displayName = $STR_ENH_advancedDamageVeh_leftRudder;
			property = "Enh_hitlcrudder";
			expression = "_this setHitPointDamage ['hitlcrudder',_value]";
		};
		class Enh_RRudder: Enh_Engine//Querruder
		{
			displayName = $STR_ENH_advancedDamageVeh_RightRudder;
			property = "Enh_hitrrudder";
			expression = "_this setHitPointDamage ['hitrrudder',_value]";
		};
		class Enh_LCElevator: Enh_Engine//Linkes Höhenruder
		{
			displayName = $STR_ENH_advancedDamageVeh_leftElevator;
			property = "Enh_hitlcelevator";
			expression = "_this setHitPointDamage ['hitlcelevator',_value]";
		};
		class Enh_RCElevator: Enh_Engine//Querruder
		{
			displayName = $STR_ENH_advancedDamageVeh_rightElevator;
			property = "Enh_hitrelevator";
			expression = "_this setHitPointDamage ['hitrelevator',_value]";
		};
		class Enh_GearLights: Enh_Engine//Querruder
		{
			displayName = $STR_ENH_advancedDamageVeh_gearLights;
			property = "Enh_gear_f_lights";
			expression = "_this setHitPointDamage ['#gear_f_lights',_value]";
		};
	};
};