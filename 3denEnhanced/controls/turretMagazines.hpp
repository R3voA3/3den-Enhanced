class ENH_TurretMagazines: TitleWide
{
	attributeLoad = "[_this,_value] call ENH_fnc_magazineTurrets_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_magazineTurrets_onAttributeSave";
	h = 8.5 * SIZE_M * GRID_H + 20 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION("Shows all available magazines from all turrets. Use the slider to set a custom magazine count.",1);
		class TypeTitle: Title
		{
			text = "Magazines";
			y = 2.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class Type: ctrlListbox
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 2.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 4 * SIZE_M * GRID_H;
		};
		class MagCountTitle: Title
		{
			text = "Count";
			y = 6.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class MagCount: ctrlXSliderH
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			sliderRange[] = {0,50};
			sliderStep = 1;
			lineSize = 1;
		};		
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 7.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		  onButtonDown  = "_this call ENH_fnc_magazineTurrets_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};