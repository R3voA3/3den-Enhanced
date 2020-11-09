class ENH_EstablishingShot: Title
{
    attributeLoad = "[_this,_value] call ENH_fnc_establishingShot_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_establishingShot_onAttributeSave";
    h = 7 * SIZE_M * GRID_H + 35 * pixelH;
    class Controls: Controls
    {
        class CenterTitle: Title
        {
            text = $STR_ENH_ESTABLISHINGSHOT_CENTERPOS_DISPLAYNAME;
        };
        class CenterValue: ctrlEdit
        {
            idc = 100;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            w = ATTRIBUTE_CONTENT_W * GRID_W;
            h = SIZE_M * GRID_H;
        };
        class TextTitle: Title
        {
            y = 1 * SIZE_M * GRID_H + 5 * pixelH;
            text = $STR_ENH_ESTABLISHINGSHOT_DISPLAYEDTEXT;
        };
        class TextValue: CenterValue
        {
            idc = 101;
            y = 1 * SIZE_M * GRID_H + 5 * pixelH;
        };
        class AltitudeTitle: Title
        {
            y = 2 * SIZE_M * GRID_H + 10 * pixelH;
            text = $STR_ENH_ALTITUDE_DISPLAYNAME;
        };
        class AltitudeValue: ctrlXSliderH
        {
            idc = 102;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            y = 2 * SIZE_M * GRID_H + 10 * pixelH;
            w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
            h = SIZE_M * GRID_H;
             sliderPosition = 500;
            sliderRange[] = {50,2000};
            sliderStep = 50;
            lineSize = 50;
        };
        class AltitudeEdit: ctrlEdit
        {
            idc = 103;
            x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
            y = 2 * SIZE_M * GRID_H + 10 * pixelH;
            w = EDIT_W_WIDE * GRID_W;
            h = SIZE_M * GRID_H;
        };
        class RadiusTitle: Title
        {
            y = 3 * SIZE_M * GRID_H + 15 * pixelH;
            text = $STR_ENH_ESTABLISHINGSHOT_RADIUS_DISPLAYNAME;
        };
        class RadiusValue: ctrlXSliderH
        {
            idc = 104;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            y = 3 * SIZE_M * GRID_H + 15 * pixelH;
            w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
            h = SIZE_M * GRID_H;
             sliderPosition = 200;
            sliderRange[] = {50,2000};
            sliderStep = 50;
            lineSize = 50;
        };
        class RadiusEdit: ctrlEdit
        {
            idc = 105;
            x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
            y = 3 * SIZE_M * GRID_H + 15 * pixelH;
            w = EDIT_W_WIDE * GRID_W;
            h = SIZE_M * GRID_H;
        };
        class AngleTitle: Title
        {
            y = 4 * SIZE_M * GRID_H + 20 * pixelH;
            text = $STR_ENH_ESTABLISHINGSHOT_VIEWINGANGLE_DISPLAYNAME;
        };
        class AngleValue: ctrlXSliderH
        {
            idc = 106;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            y = 4 * SIZE_M * GRID_H + 20 * pixelH;
            w = (ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
            h = SIZE_M * GRID_H;
             sliderPosition = 45;
            sliderRange[] = {0,360};
            sliderStep = 5;
            lineSize = 5;
        };
        class AngleEdit: ctrlEdit
        {
            idc = 107;
            x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W_WIDE) * GRID_W;
            y = 4 * SIZE_M * GRID_H + 20 * pixelH;
            w = EDIT_W_WIDE * GRID_W;
            h = SIZE_M * GRID_H;
        };
        class DirectionTitle: Title
        {
            y = 5 * SIZE_M * GRID_H + 25 * pixelH;
            text = $STR_ENH_ESTABLISHINGSHOT_DIRECTION_DISPLAYNAME;
        };
        class DirectionValue: ctrlToolbox
        {
            idc = 108;
            x = ATTRIBUTE_TITLE_W * GRID_W;
            y = 5 * SIZE_M * GRID_H + 25 * pixelH;
            w = ATTRIBUTE_CONTENT_W * GRID_W;
            h = 2 * SIZE_M * GRID_H;
            rows = 2;
            columns = 1;
            strings[] =
            {
                $STR_ENH_ESTABLISHINGSHOT_ANTICLOCKWISE,
                $STR_ENH_ESTABLISHINGSHOT_CLOCKWISE
            };
            values[] = {0,1};
        };
        class Reset: ENH_ResetButton_Base
        {
            y = 6 * SIZE_M * GRID_H + 30 * pixelH;
            onButtonDown  = "_this call ENH_fnc_establishingShot_onButtonDown";
        };
    };
};