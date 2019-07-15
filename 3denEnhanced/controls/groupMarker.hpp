class Enh_GroupMarker: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_groupMarker_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_groupMarker_onAttributeSave";
	h = 4 * SIZE_M * GRID_H + 15 * pixelH;
	class Controls: Controls
	{
		class TypeTitle: Title 
		{
			text = "Marker Type";
		};
		class Type: ctrlCombo
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class ColourTitle: Title
		{
			text = "Marker Colour";
			y = SIZE_M * GRID_H + 5 * pixelH;
		};
		class Colour: ctrlCombo
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			y = SIZE_M * GRID_H + 5 * pixelH;
		};		
		class TextTitle: Title
		{
			text = "Marker Text";
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class Text: ctrlEdit
		{
			idc = 102;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class ShowGroupSizeTitle: Title 
		{
			text = "Show Group Size";
			y = 3 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class ShowGroupSize: ctrlCheckbox
		{
			idc = 103;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
			y = 3 * SIZE_M * GRID_H + 15 * pixelH;
		};
	};
};