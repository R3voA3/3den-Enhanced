class ENH_AmbientAnimations: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_ambientAnimations_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_ambientAnimations_onAttributeSave";
    h = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
    class Controls: Controls
    {
        class AnimTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTANIMATIONS_ANIMATION_DISPLAYNAME";
        };
        class Animation: ctrlCombo
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class CanExitTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTANIMATIONS_CANEXIT_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AMBIENTANIMATIONS_CANEXIT_TOOLTIP";
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
        };
        class CanExit: ctrlCheckbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class AttachTitle: Title
        {
            text = "$STR_ENH_MAIN_AMBIENTANIMATIONS_ATTACH_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_AMBIENTANIMATIONS_ATTACH_TOOLTIP";
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class Attach: CanExit
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
    };
};
