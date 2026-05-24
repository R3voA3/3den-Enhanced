class ENH_MapIndicators: Title
{
    attributeLoad = "[_this, _value] call ENH_fnc_mapIndicators_onAttributeLoad";
    attributeSave = "_this call ENH_fnc_mapIndicators_onAttributeSave";
    h = QUOTE(4 * CTRL_DEFAULT_H + 20 * pixelH);
    class Controls: Controls
    {
        class FriendlyText: Title
        {
            text = "$STR_ENH_MAIN_MAPINDICATORS_FRIENDLY";
            tooltip = "$STR_ENH_MAIN_MAPINDICATORS_FRIENDLY_TOOLTIP";
        };
        class FriendlyValue: ctrlCheckbox
        {
            idc = IDC_ATTRIBUTE_CONTROL_00;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE(SIZE_M * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class EnemyText: FriendlyText
        {
            text = "$STR_ENH_MAIN_MAPINDICATORS_ENEMY";
            tooltip = "$STR_ENH_MAIN_MAPINDICATORS_ENEMY_TOOLTIP";
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
        };
        class EnemyValue: FriendlyValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_01;
            y = QUOTE(CTRL_DEFAULT_H + 5 * pixelH);
        };
        class MinesText: FriendlyText
        {
            text = "$STR_ENH_MAIN_MAPINDICATORS_MINES";
            tooltip = "$STR_ENH_MAIN_MAPINDICATORS_MINES_TOOLTIP";
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class MinesValue: FriendlyValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_02;
            y = QUOTE(2 * CTRL_DEFAULT_H + 10 * pixelH);
        };
        class PingText: FriendlyText
        {
            text = "$STR_ENH_MAIN_MAPINDICATORS_PING";
            tooltip = "$STR_ENH_MAIN_MAPINDICATORS_PING_TOOLTIP";
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
        class PingValue: FriendlyValue
        {
            idc = IDC_ATTRIBUTE_CONTROL_03;
            y = QUOTE(3 * CTRL_DEFAULT_H + 15 * pixelH);
        };
    };
};
