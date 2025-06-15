class RscControlsGroupNoScrollbars;
class RscButtonMenu;
class RscDebugConsole: RscControlsGroupNoScrollbars
{
    class Controls
    {
        class ButtonFunctions: RscButtonMenu
        {
            idc = IDC_NONE;
           // Dynamically reposition it if Connor's functions viewer is available as well.
            onLoad = "_this # 0 ctrlSetText ('ENH_' + localize 'STR_A3_RSCDEBUGCONSOLE_BUTTONFUNCTIONS'); if (isClass (configFile >> 'RscDisplayDebugPublic' >> 'Controls' >> 'DebugConsole' >> 'controls' >> 'CAU_xFuncViewer')) then {_this # 0 ctrlSetPosition [7.5 * (((safeZoneW / safeZoneH) min 1.2) / 40), 21.6 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)]; _this # 0 ctrlCommit 0;}";
            x = QUOTE(7.5 * GUI_GRID_W);
            y = QUOTE(19.4 * GUI_GRID_H);
            w = QUOTE(7.4 * GUI_GRID_W);
            h = QUOTE(1 * GUI_GRID_H);
            onButtonClick = "ctrlParent (_this # 0) createDisplay 'ENH_FunctionsViewer'";
        };
    };
};
