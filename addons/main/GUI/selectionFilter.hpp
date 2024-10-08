class ENH_SelectionFilter
{
    idd = -1;
    onLoad = "_this call ENH_fnc_selectionFilter_init";
    class ControlsBackground
    {
    class Header: ctrlStaticTitle
        {
            text = "$STR_ENH_MAIN_SELECTIONFILTER";
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H);
            w = QUOTE(68 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Background: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H);
            w = QUOTE(68 * GRID_W);
            h = QUOTE(7 * GRID_H);
        };
        class Footer: ctrlStaticFooter
        {
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 49 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + 5 * GRID_H);
            w = QUOTE(19 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
        };
    };
    class Controls
    {
        class FilterObjects: ctrlCheckboxToolbar
        {
            idc = 10;
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 1 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + 6 * GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            TEXTURES("\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa")
            checked = 1;
            onCheckedChanged = "_this call ENH_fnc_selectionFilter_onCheckedChanged";
            tooltip = "$STR_3DEN_OBJECT_TEXTPLURAL";
        };
        class FilterGroups: FilterObjects
        {
            idc = 11;
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 7 * GRID_W);
            TEXTURES("\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa")
            tooltip = "$STR_3DEN_GROUP_TEXTPLURAL";
        };
        class FilterTriggers: FilterObjects
        {
            idc = 12;
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 13 * GRID_W);
            TEXTURES("\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa")
            tooltip = "$STR_3DEN_TRIGGER_TEXTPLURAL";
        };
        class FilterSystems: FilterObjects
        {
            idc = 13;
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 19 * GRID_W);
            TEXTURES("\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa")
            tooltip = "$STR_3DEN_LOGIC_TEXTPLURAL";
        };
        class FilterWaypoints: FilterObjects
        {
            idc = 14;
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 25 * GRID_W);
            TEXTURES("\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa")
            tooltip = "$STR_3DEN_WAYPOINT_TEXTPLURAL";
        };
        class FilterMarkers: FilterObjects
        {
            idc = 15;
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 31 * GRID_W);
            TEXTURES("\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa")
            tooltip = "$STR_3DEN_MARKER_TEXTPLURAL";
        };
        class FilterComments: FilterObjects
        {
            idc = 16;
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 37 * GRID_W);
            TEXTURES("\a3\3den\data\cfg3den\comment\texture_ca.paa")
            tooltip = "$STR_3DEN_COMMENT_TEXTPLURAL";
        };
        class FilterLayers: FilterObjects
        {
            idc = 17;
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 43 * GRID_W);
            TEXTURES("\a3\3den\data\cfg3den\layer\icon_ca.paa")
            tooltip = "$STR_3DEN_LAYER_TEXTPLURAL";
        };
        class EditAttribute: ctrlButtonPictureKeepAspect
        {
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 50 * GRID_W);
            text = "\a3\3den\data\displays\display3den\panelright\customcomposition_edit_ca.paa";
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + 6 * GRID_H);
            w = QUOTE(5 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            onButtonClick = "_this spawn ENH_fnc_selectionFilter_editAttributes";
            tooltip = "$STR_3DEN_DISPLAY3DEN_MENUBAR_ATTRIBUTES_TEXT";
        };
        class Ok: EditAttribute
        {
            idc = 1;
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 56 * GRID_W);
            text = "\a3\modules_f\data\iconsavegame_ca.paa";
            colorBackground[] = {0, 0.4, 0, 1};
            onButtonClick = "";
            tooltip = "$STR_ENH_MAIN_SELECTIONFILTER_CONFIRMSELECTION";
        };
        class Cancel: Ok
        {
            idc = -1;
            x = QUOTE(CENTER_X - 0.5 * 68 * GRID_W + 62 * GRID_W);
            text = "\a3\ui_f\data\gui\rsc\rscdisplayarcademap\icon_exit_cross_ca.paa";
            colorBackground[] = {0.7, 0, 0, 1};
            onButtonClick = "_this call ENH_fnc_selectionFilter_cancel";
            tooltip = "$STR_ENH_MAIN_SELECTIONFILTER_RESTORESELECTION";
        };
    };
};
