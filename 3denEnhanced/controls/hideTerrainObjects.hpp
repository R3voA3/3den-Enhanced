class ENH_HideTerrainObjects: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_hideTerrainObjects_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_hideTerrainObjects_onAttributeSave";
	h = 12.5 * SIZE_M * GRID_H + 20 * pixelH;
	class Controls: Controls
	{
		ATTRIBUTE_DESCRIPTION($STR_ENH_HIDETERRAINOBJECTS_DESCRIPTION,3);
    class EffectsTitle: Title
		{
			text = $STR_A3_RSCATTRIBUTEPOSTPROCESS_TITLE;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class Effect: ctrlToolbox
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 4.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			rows = 1;
      columns = 2;
      strings[] =
      {
        $STR_CA_HIDE,
        $STR_CFG_MARKERS_DESTROY
      };
      values[] = {0,1};
		};
		class TypesTitle: Title
		{
			text = $STR_A3_TO_HIDETERRAINOBJECTS4;
			y = 5.5 * SIZE_M * GRID_H + 10 * pixelH;
		};
		class Types: ctrlListbox
		{
			idc = 110;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 5.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = 6 * SIZE_M * GRID_H;
			onLBSelChanged = "_this call ENH_fnc_hideTerrainObjects_onLBSelChanged";
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 11.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call ENH_fnc_hideTerrainObjects_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};