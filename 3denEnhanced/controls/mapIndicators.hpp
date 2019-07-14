class Enh_MapIndicators: Title
{
	attributeLoad=
	"\
		_ctrlFriendly = _this controlsGroupCtrl 100;\
		_ctrlEnemy = _this controlsGroupCtrl 101;\
		_ctrlMines = _this controlsGroupCtrl 102;\
		_ctrlPing = _this controlsGroupCtrl 103;\
		\
		_ctrlFriendly cbSetChecked (_value param [0,false,[true]]);\
		_ctrlEnemy cbSetChecked (_value param [1,false,[true]]);\
		_ctrlMines cbSetChecked (_value param [2,false,[true]]);\
		_ctrlPing cbSetChecked (_value param [3,false,[true]]);\
	";
	attributeSave = "[cbChecked (_this controlsGroupCtrl 100),cbChecked (_this controlsGroupCtrl 101),cbChecked (_this controlsGroupCtrl 102),cbChecked (_this controlsGroupCtrl 103)]";
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
