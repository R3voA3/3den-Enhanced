class Enh_AmbientAnimation: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_ambientAnimations_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_ambientAnimations_onAttributeSave";
	h = 3 * SIZE_M * GRID_H + 10 * pixelH;
	class Controls: Controls
	{
		class AnimText: Title
		{
			text = $STR_ENH_ambAnimations_animText_text;
			tooltip = $STR_ENH_ambAnimations_animText_tooltip;
		};

		class GearText: Title
		{
			y = SIZE_M * GRID_H + 5 * pixelH;
			text = $STR_ENH_ambAnimations_gearText_text;
			tooltip = $STR_ENH_ambAnimations_gearText_tooltip;
		};
		class Anim: ctrlCombo
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;

			class Items
			{
				class NoChange
				{
					text = $STR_3den_attributes_default_unchanged_text;
					tooltip = $STR_3den_attributes_default_unchanged_tooltip;
					data = "";
					default = 1;
				};
				class STAND1
				{
					text = $STR_ENH_ambAnimCombo_stand;
					data = "STAND1";
				};
				class STAND2
				{
					text = $STR_ENH_ambAnimCombo_stand;
					data = "STAND2";
				};
				class STAND_IA
				{
					text = $STR_ENH_ambAnimCombo_standIA;
					data = "STAND_IA";
				};
				class STAND_U1
				{
					text = $STR_ENH_ambAnimCombo_standU1;
					data = "STAND_U1";
				};
				class STAND_U2
				{
					text = $STR_ENH_ambAnimCombo_standU2;
					data = "STAND_U2";
				};
				class STAND_U3
				{
					text = $STR_ENH_ambAnimCombo_standU3;
					data = "STAND_U3";
				};
				class WATCH
				{
					text = $STR_ENH_ambAnimCombo_watch1;
					data = "WATCH";
				};
				class WATCH2
				{
					text = $STR_ENH_ambAnimCombo_watch2;
					data = "WATCH2";
				};
				class GUARD
				{
					text = $STR_ENH_ambAnimCombo_guard;
					data = "GUARD";
				};
				class LISTEN_BRIEFING
				{
					text = $STR_ENH_ambAnimCombo_listenBriefing;
					data = "LISTEN_BRIEFING";
				};
				class LEAN_ON_TABLE
				{
					text = $STR_ENH_ambAnimCombo_leanOnTable;
					data = "LEAN_ON_TABLE";
				};
				class LEAN
				{
					text = $STR_ENH_ambAnimCombo_lean;
					data = "LEAN";
				};
				class BRIEFING
				{
					text = $STR_ENH_ambAnimCombo_briefing;
					data = "BRIEFING";
				};
				class BRIEFING_POINT_LEFT
				{
					text = $STR_ENH_ambAnimCombo_briefingPointLeft;
					data = "BRIEFING_POINT_LEFT";
				};
				class BRIEFING_POINT_RIGHT
				{
					text = $STR_ENH_ambAnimCombo_briefingPointRight;
					data = "BRIEFING_POINT_right";
				};
				class BRIEFING_POINT_TABLE
				{
					text = $STR_ENH_ambAnimCombo_briefingPointTable;
					data = "BRIEFING_POINT_TABLE";
				};
				class KNEEL
				{
					text = $STR_ENH_ambAnimCombo_kneel;
					data = "KNEEL";
				};
				class PRONE_INJURED_U1
				{
					text = $STR_ENH_ambAnimCombo_proneInjured2;
					data = "PRONE_INJURED_U1";
				};
				class PRONE_INJURED_U2
				{
					text = $STR_ENH_ambAnimCombo_proneInjured1;
					data = "PRONE_INJURED_U2";
				};
				class PRONE_INJURED
				{
					text = $STR_ENH_ambAnimCombo_proneInjured;
					data = "PRONE_INJURED";
				};
				class REPAIR_VEH_STAND
				{
					text = $STR_ENH_ambAnimCombo_repairVehStand;
					data = "REPAIR_VEH_STAND";
				};
				class REPAIR_VEH_KNEEL
				{
					text = $STR_ENH_ambAnimCombo_repairVehKneel;
					data = "REPAIR_VEH_KNEEL";
				};
				class REPAIR_VEH_PRONE
				{
					text = $STR_ENH_ambAnimCombo_repairVehProne;
					data = "REPAIR_VEH_PRONE";
				};
				class KNEEL_TREAT
				{
					text = $STR_ENH_ambAnimCombo_kneelTreat;
					data = "KNEEL_TREAT";
				};
				class SIT_HIGH1
				{
					text = $STR_ENH_ambAnimCombo_sitHigh_1;
					data = "SIT_HIGH1";
				};
				class SIT_HIGH2
				{
					text = $STR_ENH_ambAnimCombo_sitHigh_2;
					data = "SIT_HIGH2";
				};
				class SIT_SAD1
				{
					text = $STR_ENH_ambAnimCombo_sitSad_1;
					data = "SIT_SAD1";
				};
				class SIT_SAD2
				{
					text = $STR_ENH_ambAnimCombo_sitSad_2;
					data = "SIT_SAD2";
				};
				class SIT_U1
				{
					text = $STR_ENH_ambAnimCombo_sitU1;
					data = "SIT_U1";
				};
				class SIT_U2
				{
					text = $STR_ENH_ambAnimCombo_sitU2;
					data = "SIT_U2";
				};
				class SIT_U3
				{
					text = $STR_ENH_ambAnimCombo_sitU3;
					data = "SIT_U3";
				};
				class SIT1
				{
					text = $STR_ENH_ambAnimCombo_sit1;
					data = "SIT1";
				};
				class SIT2
				{
					text = $STR_ENH_ambAnimCombo_sit2;
					data = "SIT2";
				};
				class SIT3
				{
					text = $STR_ENH_ambAnimCombo_sit3;
					data = "SIT3";
				};
				class SIT_AT_TABLE
				{
					text = $STR_ENH_ambAnimCombo_sitAtTable;
					data = "SIT_AT_TABLE";
				};
				class SIT_LOW
				{
					text = $STR_ENH_ambAnimCombo_sitLow;
					data = "SIT_LOW";
				};
				class SIT_LOW_U
				{
					text = $STR_ENH_ambAnimCombo_sitLowU;
					data = "SIT_LOW_U";
				};
			};
		};

		class Gear: Anim
		{
			idc = 101;
			y = SIZE_M * GRID_H + 5 * pixelH;

			class Items
			{
				class ASIS
				{
					text = $STR_3den_attributes_default_unchanged_text;
					tooltip = $STR_3den_attributes_default_unchanged_tooltip;
					data = "ASIS";
					default = 1;
				};
				class NONE
				{
					text = $STR_ENH_ambAnimEquipCombo_none;
					data = "NONE";
				};
				class RANDOM
				{
					text = $STR_ENH_ambAnimEquipCombo_random;
					data = "RANDOM";
				};
				class LIGHT
				{
					text = $STR_ENH_ambAnimEquipCombo_light;
					data = "LIGHT";
				};
				class MEDIUM
				{
					text = $STR_ENH_ambAnimEquipCombo_medium;
					data = "MEDIUM";
				};
				class FULL
				{
					text = $STR_ENH_ambAnimEquipCombo_full;
					data = "FULL";
				};
			};
		};
		class Reset: ctrlButton
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W / 3;
			h = SIZE_M * GRID_H;
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
			onButtonDown  = "_this call Enh_fnc_ambientAnimations_onButtonDown";
			text = $STR_ENH_ambAnimations_reset_text;
		};
	};
};
