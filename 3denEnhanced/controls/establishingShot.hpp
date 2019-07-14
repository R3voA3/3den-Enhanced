class Enh_EstablishingShot: Title
{
	attributeLoad =
	"\
		_center = _value param [0,[0,0,0],[[]],3];\
		_text = _value param [1,getText (configfile >> 'CfgWorlds' >> worldName >> 'description'),['']];\
		_alt = _value param [2,150,[0]];\
		_r = _value param [3,300,[0]];\
		_angle = _value param [4,45,[0]];\
		\
		(_this controlsGroupCtrl 100) ctrlSetText str _center;\
		(_this controlsGroupCtrl 101) ctrlSetText _text;\
		(_this controlsGroupCtrl 102) ctrlSetText str _alt;\
		(_this controlsGroupCtrl 103) ctrlSetText str _r;\
		(_this controlsGroupCtrl 104) ctrlSetText str _angle";

	attributeSave = "[call compile ctrlText (_this controlsGroupCtrl 100),ctrlText (_this controlsGroupCtrl 101),parseNumber ctrlText (_this controlsGroupCtrl 102),parseNumber ctrlText (_this controlsGroupCtrl 103),parseNumber ctrlText (_this controlsGroupCtrl 104)]";

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