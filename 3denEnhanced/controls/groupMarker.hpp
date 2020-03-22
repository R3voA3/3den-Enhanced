class ENH_GroupMarker: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_groupMarker_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_groupMarker_onAttributeSave";
	h = 23.5 * SIZE_M * GRID_H + 30 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_GROUPMARKER_DESCRIPTION,3);
		class TypeTitle: Title 
		{
			text = $STR_ENH_GROUPMARKER_TYPE;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class Type: ctrlListbox
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 8 * SIZE_M * GRID_H;
		};
		class ColourTitle: Title
		{
			text = $STR_ENH_GROUPMARKER_COLOUR;
			y = 12.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class Colour: ctrlListbox	
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 12.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 8 * SIZE_M * GRID_H;
		};		
		class TextTitle: Title
		{
			text = $STR_ENH_GROUPMARKER_TEXT;
			y = 20.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class Text: ctrlEdit
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 20.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class ShowGroupSizeTitle: Title 
		{
			text = $STR_ENH_GROUPMARKER_SHOWGROUPSIZE;
			y = 21.5 * SIZE_M * GRID_H + 20 * pixelH;
		};
		class ShowGroupSize: ctrlCheckbox
		{
			idc = 103;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 21.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 22.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call ENH_fnc_groupMarker_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};