class ENH_EstablishingShot: Title
{
	attributeLoad = "[_this, _value] call ENH_fnc_establishingShot_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_establishingShot_onAttributeSave";
	h = QUOTE(8 * CTRL_DEFAULT_H + 35 * pixelH);
	class Controls: Controls
	{
		class CenterTitle: Title
		{
			text = "$STR_ENH_MAIN_ESTABLISHINGSHOT_CENTERPOS_DISPLAYNAME";
			tooltip = "$STR_ENH_MAIN_ESTABLISHINGSHOT_CENTERPOS_TOOLTIP";
		};
		class CenterValue: ctrlEdit
		{
			idc = 100;
			x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
			w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class TextTitle: Title
		{
			y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
			text = "$STR_ENH_MAIN_ESTABLISHINGSHOT_DISPLAYEDTEXT";
		};
		class TextValue: CenterValue
		{
			idc = 101;
			y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
		};
		class AltitudeTitle: Title
		{
			y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
			text = "$STR_ENH_MAIN_ALTITUDE_DISPLAYNAME";
		};
		class AltitudeValue: ctrlXSliderH
		{
			idc = 102;
			x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
			y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
			w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
			sliderPosition = 500;
			sliderRange[] = {50, 2000};
			sliderStep = 50;
			lineSize = 50;
		};
		class AltitudeEdit: ctrlEdit
		{
			idc = 103;
			x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
			y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
			w = QUOTE(EDIT_W_WIDE * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class RadiusTitle: Title
		{
			y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
			text = "$STR_ENH_MAIN_ESTABLISHINGSHOT_RADIUS_DISPLAYNAME";
		};
		class RadiusValue: AltitudeValue
		{
			idc = 104;
			y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
			sliderPosition = 200;
		};
		class RadiusEdit: ctrlEdit
		{
			idc = 105;
			x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
			y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
			w = QUOTE(EDIT_W_WIDE * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class AngleTitle: Title
		{
			y = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
			text = "$STR_ENH_MAIN_ESTABLISHINGSHOT_VIEWINGANGLE_DISPLAYNAME";
		};
		class AngleValue: AltitudeValue
		{
			idc = 106;
			y = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
			sliderPosition = 45;
			sliderRange[] = {0, 360};
			sliderStep = 5;
			lineSize = 5;
		};
		class AngleEdit: ctrlEdit
		{
			idc = 107;
			x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W);
			y = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
			w = QUOTE(EDIT_W_WIDE * GRID_W);
			h = QUOTE(CTRL_DEFAULT_H);
		};
		class DirectionTitle: Title
		{
			y = QUOTE(5 * CTRL_DEFAULT_H + 25 * pixelH);
			text = "$STR_ENH_MAIN_ESTABLISHINGSHOT_DIRECTION_DISPLAYNAME";
		};
		class DirectionValue: ctrlToolbox
		{
			idc = 108;
			x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
			y = QUOTE(5 * CTRL_DEFAULT_H + 25 * pixelH);
			w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
			h = QUOTE(2 * CTRL_DEFAULT_H);
			rows = 2;
			columns = 1;
			strings[] =
			{
				"$STR_ENH_MAIN_ESTABLISHINGSHOT_ANTICLOCKWISE",
				"$STR_ENH_MAIN_ESTABLISHINGSHOT_CLOCKWISE"
			};
			values[] = {0, 1};
		};
		class Reset: ENH_ResetButton_Base
		{
			y = QUOTE(7 * CTRL_DEFAULT_H + 30 * pixelH);
		};
	};
};