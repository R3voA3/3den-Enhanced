class ENH_MapIndicators: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_mapIndicators_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_mapIndicators_onAttributeSave";
	h = 7.5 * SIZE_M * GRID_H + 25 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_MAPINDICATORS_DESCRIPTION,2);
		class FriendlyText: Title
		{
			text = $STR_ENH_MAPINDICATORS_FRIENDLYTEXT;
			y = 3.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class FriendlyValue: ctrlCheckbox
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 3.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = SIZE_M * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class EnemyText: FriendlyText
		{
			y = 4.5 * SIZE_M * GRID_H + 10 * pixelH;
			text = $STR_ENH_MAPINDICATORS_ENEMYTEXT;
		};
		class EnemyValue: FriendlyValue
		{
			idc = 101;
			y = 4.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class MinesText: FriendlyText
		{
			y = 5.5 * SIZE_M * GRID_H + 15 * pixelH;
			text = $STR_ENH_MAPINDICATORS_MINESTEXT;
		};
		class MinesValue: FriendlyValue
		{
			idc = 102;
			y = 5.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class PingText: FriendlyText
		{
			y = 6.5 * SIZE_M * GRID_H + 20 * pixelH;
			text = $STR_ENH_MAPINDICATORS_PINGTEXT;
		};
		class PingValue: FriendlyValue
		{
			idc = 103;
			y = 6.5 * SIZE_M * GRID_H + 20 * pixelH;
		};
	};
};