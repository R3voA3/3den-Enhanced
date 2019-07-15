class Enh_MapIndicators: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_mapIndicators_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_mapIndicators_onAttributeSave";
	h = 4 * SIZE_M * GRID_H + 15 * pixelH;
	class Controls: Controls
	{
		class FriendlyText: Title
		{
			text = $STR_ENH_mapIndicators_friendlyText;
		};
		class EnemyText: FriendlyText
		{
			y = SIZE_M * GRID_H + 5 * pixelH;
			text = $STR_ENH_mapIndicators_enemyText;
		};
		class MinesText: FriendlyText
		{
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
			text = $STR_ENH_mapIndicators_minesText;
		};
		class PingText: FriendlyText
		{
			y = 3 * SIZE_M * GRID_H + 15 * pixelH;
			text = $STR_ENH_mapIndicators_pingText;
		};
		class FriendlyValue: ctrlCheckbox
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = SIZE_M * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class EnemyValue: FriendlyValue
		{
			idc = 101;
			y = SIZE_M * GRID_H + 5 * pixelH;
		};
		class MinesValue: FriendlyValue
		{
			idc = 102;
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class PingValue: FriendlyValue
		{
			idc = 103;
			y = 3 * SIZE_M * GRID_H + 15 * pixelH;
		};
	};
};
