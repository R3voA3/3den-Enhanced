class Enh_MapIndicators: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_mapIndicators_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_mapIndicators_onAttributeSave";
	h = 8.5 * SIZE_M * GRID_H + 20 * pixelH;
	class Controls: Controls
	{
		class DescriptionGroup: ctrlControlsGroup
		{
			x = 5 * GRID_W;
			y = 0.5 * SIZE_M * GRID_H;
			h = 4 * SIZE_M * GRID_H;
			w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W) * GRID_W;
			class Controls
			{
				class DescriptionDeco: ctrlStatic
				{
					w = 5 * pixelW;
					h = SIZE_M * GRID_H;
					colorBackground[] = {1,1,1,0.05};
				};
				class DescriptionHeader: ctrlStatic
				{
					text = $STR_ENH_description;
					x = 7 * pixelW;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = SIZE_M * GRID_H;
					colorText[] = {1,1,1,0.4};
					colorBackground[] = {1,1,1,0.05};
					colorShadow[] = {0,0,0,0};
				};
				class Description: ctrlStructuredText
				{
					text = $STR_ENH_mapIndicators_description;
					x = 7 * pixelW;
					y = SIZE_M * GRID_H;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = 3 * SIZE_M * GRID_H;
					colorText[] = {1,1,1,0.4};
					colorBackground[] = {1,1,1,0};
					shadow = 0;
					class Attributes
					{
						align = "left";
						color = "#999999";
						colorLink = "";
						font = "RobotoCondensedLight";
						size = 1;
					};
				};
			};
		};
		class FriendlyText: Title
		{
			text = $STR_ENH_mapIndicators_friendlyText;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class FriendlyValue: ctrlCheckbox
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = SIZE_M * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class EnemyText: FriendlyText
		{
			y = 5.5 * SIZE_M * GRID_H + 10 * pixelH;
			text = $STR_ENH_mapIndicators_enemyText;
		};
		class EnemyValue: FriendlyValue
		{
			idc = 101;
			y = 5.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class MinesText: FriendlyText
		{
			y = 6.5 * SIZE_M * GRID_H + 15 * pixelH;
			text = $STR_ENH_mapIndicators_minesText;
		};
		class MinesValue: FriendlyValue
		{
			idc = 102;
			y = 6.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class PingText: FriendlyText
		{
			y = 7.5 * SIZE_M * GRID_H + 20 * pixelH;
			text = $STR_ENH_mapIndicators_pingText;
		};
		class PingValue: FriendlyValue
		{
			idc = 103;
			y = 7.5 * SIZE_M * GRID_H + 20 * pixelH;
		};
	};
};