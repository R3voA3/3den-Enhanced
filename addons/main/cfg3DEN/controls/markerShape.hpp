class ENH_MarkerShape: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_markerShape_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_markerShape_onAttributeSave";
    h = QUOTE(8 * CTRL_DEFAULT_H + 5 * pixelH);
    class Controls: Controls
    {
        class Title: Title
        {
            h = QUOTE(8 * CTRL_DEFAULT_H);
        };
        class Value: ctrlToolbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(8 * CTRL_DEFAULT_H);
            columns = 2;
            rows = 4;
            strings[] =
            {
                "a3\3den\data\attributes\default_ca.paa",
                "\x\enh\addons\main\data\triangle_ca.paa",
                "\x\enh\addons\main\data\pentagon_ca.paa",
                "\x\enh\addons\main\data\hexagon_ca.paa",
                "\x\enh\addons\main\data\heptagon_ca.paa",
                "\x\enh\addons\main\data\octagon_ca.paa",
                "\x\enh\addons\main\data\nonagon_ca.paa",
                "\x\enh\addons\main\data\decagon_ca.paa"
            };
            tooltips[] =
            {
                "$STR_A3_OPTIONS_DEFAULT",
                "$STR_ENH_MAIN_MARKER_SHAPE_TRIANGLE",
                "$STR_ENH_MAIN_MARKER_SHAPE_PENTAGON",
                "$STR_ENH_MAIN_MARKER_SHAPE_HEXAGON",
                "$STR_ENH_MAIN_MARKER_SHAPE_HEPTAGON",
                "$STR_ENH_MAIN_MARKER_SHAPE_OCTAGON",
                "$STR_ENH_MAIN_MARKER_SHAPE_NONAGON",
                "$STR_ENH_MAIN_MARKER_SHAPE_DECAGON"
            };
            style = QUOTE(ST_CENTER + ST_PICTURE + ST_KEEP_ASPECT_RATIO);
            onLoad = "_this call ENH_fnc_markerShape_onAttributeLoad";
        };
    };
};
