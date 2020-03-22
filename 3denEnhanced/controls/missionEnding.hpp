class ENH_MissionEnding: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_missionEnding_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_missionEnding_onAttributeSave";
	h = 13.5 * SIZE_M * GRID_H + 30 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_MISSIONENDING_DESCRIPTION,3);
		class ConditionTitle: Title
		{
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
			text = $STR_ENH_CONDITION;
			tooltip = $STR_ENH_MISSIONENDING_CONDITION_TOOLTIP;
		};
		class ConditionValue: ctrlEditMulti
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 5 * SIZE_M * GRID_H;
		};
		class EndingTitle: Title
		{
			text = $STR_ENH_MISSIONENDING_ENDING_DISPLAYNAME;
			tooltip = $STR_ENH_MISSIONENDING_ENDING_TOOLTIP;
			y = 9.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class Ending: ctrlCombo
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 9.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			wholeHeight = 5 * SIZE_M * GRID_H;
		};
		class IsWinTitle: Title
		{
			text = $STR_ENH_MISSIONENDING_WIN_DISPLAYNAME;
			y = 10.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class IsWin: ctrlCheckbox
		{
			idc = 103;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 10.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class PlayMusicTitle: Title
		{
			text = $STR_ENH_MISSIONENDING_PLAYMUSIC;
			y = 11.5 * SIZE_M * GRID_H + 20 * pixelH;
		};
		class PlayMusic: ctrlCheckbox
		{
			idc = 104;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 11.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 12.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call ENH_fnc_missionEnding_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};