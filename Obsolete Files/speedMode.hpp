class Enh_SpeedMode: Title
{
	attributeLoad = "[_this controlsGroupCtrl 100,_config] call Enh_fnc_attributeLoadCombo";
	attributeSave = "[_this controlsGroupCtrl 100,_config] call Enh_fnc_attributeSaveCombo";

	class Controls: Controls
	{
		class Title: Title {};
		class Value: ctrlCombo
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;

			class Items
			{
				class Limited
				{
					text = $STR_3den_attributes_speedmode_limited;
					data = "LIMITED";
					picture = "\a3\3DEN\Data\Attributes\SpeedMode\limited_ca.paa";
					default = 1;
				};
				class Normal
				{
					text = $STR_3den_attributes_speedmode_normal;
					data = "NORMAL";
					picture = "\a3\3DEN\Data\Attributes\SpeedMode\normal_ca.paa";
				};
				class Full
				{
					text = $STR_3den_attributes_speedmode_full;
					data = "FULL";
					picture = "\a3\3DEN\Data\Attributes\SpeedMode\full_ca.paa";
				};
			};
		};
	};
};