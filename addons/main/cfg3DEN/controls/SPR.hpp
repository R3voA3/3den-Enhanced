class ENH_SPR: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_SPR_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_SPR_onAttributeSave";
    h = QUOTE(10 * CTRL_DEFAULT_H + 35 * pixelH);
    class Controls: Controls
    {
        class RulesetTitle: Title
        {
            text = "$STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNTEMPLATES_DISPLAYNAME";
        };
        class Ruleset: ctrlCombo
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class RespawnTimeTitle: Title
        {
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            text = "$STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNDELAY_DISPLAYNAME";
            tooltip = "$STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNDELAY_TOOLTIP";
        };
        class RespawnTimeValue: ctrlXSliderH
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            sliderPosition = 20;
            sliderRange[] = {2, 360};
            sliderStep = 1;
            lineSize = 1;
        };
        class RespawnTimeEdit: ctrlEdit
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W);
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
            w = QUOTE(EDIT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class CanDieTitle: Title
        {
            text = "$STR_ENH_MAIN_SPR_CANDIE_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_SPR_CANDIE_TOOLTIP";
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class CanDie: ctrlCheckbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            y = QUOTE(2* CTRL_DEFAULT_H + 10 * pixelH);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class RestoreLoadoutTitle: Title
        {
            text = "$STR_ENH_MAIN_SAVELOADOUT_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_SAVELOADOUT_TOOLTIP";
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class RestoreLoadout: CanDie
        {
            idc = IDC_ATTRIBUTE_CONTROL_04;
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class CodeGroup: ENH_3DEN_Attribute_Control_EditMultiCode5_Group
        {
            idc = IDC_ATTRIBUTE_CONTROL_05;
            y = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
        };
        class Reset: ENH_3DEN_Attribute_Control_ResetButton
        {
            y = QUOTE(9 * CTRL_DEFAULT_H + 25 * pixelH);
        };
    };
};
