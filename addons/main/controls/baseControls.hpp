// These controls are directly used inside attribute controls
class ENH_3DEN_Attribute_Control_TitleX: ctrlStatic
{
    text = "$STR_3DEN_AXIS_X";
    style = 2;
    shadow = 0;
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    w = QUOTE(ATTRIBUTE_CONTENT_H * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    colorBackground[] = {COLOR_POSX_RGBA};
};
class ENH_3DEN_Attribute_Control_TitleY: ENH_3DEN_Attribute_Control_TitleX
{
    text = "$STR_3DEN_AXIS_Y";
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W * (1 / 3)) * GRID_W);
    colorBackground[] = {COLOR_POSY_RGBA};
};
class ENH_3DEN_Attribute_Control_TitleZ: ENH_3DEN_Attribute_Control_TitleX
{
    text = "$STR_3DEN_AXIS_Z";
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W * (2 / 3)) * GRID_W);
    colorBackground[] = {COLOR_POSZ_RGBA};
};
class ENH_3DEN_Attribute_Control_ValueX: ctrlEdit
{
    idc = 101;
    text = "0";
    x = QUOTE((ATTRIBUTE_TITLE_W + 5) * GRID_W);
    w = QUOTE((ATTRIBUTE_CONTENT_W / 3 - 5) * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    font = FONT_MONO;
    sizeEx = QUOTE(3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5);
};
class ENH_3DEN_Attribute_Control_ValueY: ENH_3DEN_Attribute_Control_ValueX
{
    idc = 102;
    x = QUOTE((ATTRIBUTE_TITLE_W +ATTRIBUTE_CONTENT_W * (1 / 3) +ATTRIBUTE_CONTENT_H) * GRID_W);
};
class ENH_3DEN_Attribute_Control_ValueZ: ENH_3DEN_Attribute_Control_ValueX
{
    idc = 103;
    x = QUOTE((ATTRIBUTE_TITLE_W +ATTRIBUTE_CONTENT_W * (2 / 3) +ATTRIBUTE_CONTENT_H) * GRID_W);
};
class ENH_3DEN_Attribute_Control_TitleA: ctrlStatic
{
    text = "$STR_3DEN_AXIS_A";
    style = 2;
    shadow = 0;
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    w = QUOTE(ATTRIBUTE_CONTENT_H * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    colorText[] = {COLOR_TEXT_RGBA};
    colorBackground[] = {COLOR_POSX_RGBA};
};
class ENH_3DEN_Attribute_Control_TitleB: ENH_3DEN_Attribute_Control_TitleA
{
    text = "$STR_3DEN_AXIS_B";
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W * (1 / 3)) * GRID_W);
    colorBackground[] = {COLOR_POSY_RGBA};
};
class ENH_3DEN_Attribute_Control_ValueA: ctrlEdit
{
    idc = 101;
    text = "0";
    x = QUOTE((ATTRIBUTE_TITLE_W + 5) * GRID_W);
    w = QUOTE((ATTRIBUTE_CONTENT_W / 3 -5) * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    font = FONT_MONO;
    sizeEx = QUOTE(3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5);
};
class ENH_3DEN_Attribute_Control_ValueB: ENH_3DEN_Attribute_Control_ValueA
{
    idc = 102;
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W * (1 / 3) +ATTRIBUTE_CONTENT_H) * GRID_W);
};
class ENH_3DEN_Attribute_Control_TitleZ_Front: ENH_3DEN_Attribute_Control_TitleZ
{
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
};
class ENH_3DEN_Attribute_Control_ValueZ_Front: ENH_3DEN_Attribute_Control_ValueZ
{
    x = QUOTE((ATTRIBUTE_TITLE_W + 5) * GRID_W);
};
class ENH_3DEN_Attribute_Control_TitleMin: ctrlStatic
{
    text = "$STR_3DEN_ATTRIBUTES_TIMEOUT_TITLEMIN_TEXT";
    style = 1;
    shadow = 0;
    x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
    w = QUOTE(ATTRIBUTE_CONTENT_H * 2 * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    colorText[] = {COLOR_TEXT_RGBA};
    colorBackground[] = {COLOR_TEXT_RGB, 0};
};
class ENH_3DEN_Attribute_Control_TitleMid: ENH_3DEN_Attribute_Control_TitleMin
{
    text = "$STR_3DEN_ATTRIBUTES_TIMEOUT_TITLEMID_TEXT";
    x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W * (1 / 3)) * GRID_W);
};
class ENH_3DEN_Attribute_Control_TitleMax: ENH_3DEN_Attribute_Control_TitleMin
{
    text = "$STR_3DEN_ATTRIBUTES_TIMEOUT_TITLEMAX_TEXT";
    x = QUOTE((ATTRIBUTE_TITLE_W +ATTRIBUTE_CONTENT_W * (2 / 3)) * GRID_W);
};
class ENH_3DEN_Attribute_Control_ValueMin: ctrlEdit
{
    idc = 101;
    x = QUOTE((ATTRIBUTE_TITLE_W +(5 * 2)) * GRID_W);
    w = QUOTE((ATTRIBUTE_CONTENT_W / 3 - 2 * ATTRIBUTE_CONTENT_H) * GRID_W);
    h = QUOTE(CTRL_DEFAULT_H);
    font = FONT_MONO;
    sizeEx = QUOTE(3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5);
};
class ENH_3DEN_Attribute_Control_ValueMid: ENH_3DEN_Attribute_Control_ValueMin
{
    idc = 102;
    x = QUOTE((ATTRIBUTE_TITLE_W +ATTRIBUTE_CONTENT_W * (1 / 3) +(ATTRIBUTE_CONTENT_H * 2)) * GRID_W);
};
class ENH_3DEN_Attribute_Control_ValueMax: ENH_3DEN_Attribute_Control_ValueMin
{
    idc = 103;
    x = QUOTE((ATTRIBUTE_TITLE_W +ATTRIBUTE_CONTENT_W * (2 / 3) +(ATTRIBUTE_CONTENT_H * 2)) * GRID_W);
};
