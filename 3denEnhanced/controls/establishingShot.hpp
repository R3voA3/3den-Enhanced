class Enh_EstablishingShot: Title
{
	attributeLoad = "[_this,_value] call Enh_fnc_establishingShot_onAttributeLoad";
	attributeSave = "_this call Enh_fnc_establishingShot_onAttributeLoad";
	h = 5 * SIZE_M * GRID_H + 20 * pixelH;
	class Controls: Controls
	{
		class CenterTitle: Title
		{
			text = $STR_ENH_establishingShot_centerPos_displayName;
			tooltip = $STR_ENH_establishingShot_centerPos_tooltip;
		};
		class TextTitle: Title
		{
			y = SIZE_M * GRID_H + 5 * pixelH;
			text = $STR_ENH_establishingShot_displayedText;
		};
		class AltitudeTitle: Title
		{
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
			text = $STR_ENH_establishingShot_altitude_displayName;
		};
		class RadiusTitle: Title
		{
			y = 3 * SIZE_M * GRID_H + 15 * pixelH;
			text = $STR_ENH_establishingShot_radius_displayName;
		};
		class AngleTitle: Title
		{
			y = 4 * SIZE_M * GRID_H + 20 * pixelH;
			text = $STR_ENH_establishingShot_viewingAngle_displayName;
		};
		class CenterValue: ctrlEdit
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class TextValue: CenterValue
		{
			idc = 101;
			y = SIZE_M * GRID_H + 5 * pixelH;
		};
		class AltitudeValue: CenterValue
		{
			idc = 102;
			y = 2 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class RadiusValue: CenterValue
		{
			idc = 103;
			y = 3 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class AngleValue: CenterValue
		{
			idc = 104;
			y = 4 * SIZE_M * GRID_H + 20 * pixelH;
		};
	};
};