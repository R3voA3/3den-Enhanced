class ENH_BriefingEditor
{
    idd = IDD_BRIEFINGEDITOR;
    onLoad = "[_this#0, 'onLoad'] call ENH_fnc_BriefingEditor";
    onUnload = "[_this#0, 'onUnload'] call ENH_fnc_BriefingEditor";
    class ControlsBackground
    {
        DISABLE_BACKGROUND
        class Header: ctrlStaticTitle
        {
            text = "$STR_ENH_MAIN_BRIEFINGEDITOR";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Background: ctrlStaticBackground
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(WINDOW_HAbs - 4 * CTRL_DEFAULT_H);
        };
        class FirstParamText: ctrlStatic
        {
            idc = IDC_BRIEFINGEDITOR_FIRSTPARAM;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (25 + 40 + 1) * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H + 2 * GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class SecondParamText: FirstParamText
        {
            idc = IDC_BRIEFINGEDITOR_SECONDPARAM;
            y = QUOTE(WINDOW_TOPAbs + 4 * CTRL_DEFAULT_H + 3 * GRID_H);
        };
        class ThirdParamText: FirstParamText
        {
            idc = IDC_BRIEFINGEDITOR_THIRDPARAM;
            y = QUOTE(WINDOW_TOPAbs + 5 * CTRL_DEFAULT_H + 4 * GRID_H);
        };
        class Subject: ctrlStatic
        {
            text = "$STR_ENH_MAIN_BRIEFINGEDITOR_SUBJECT";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + 1 * GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class Title: Subject
        {
            text = "$STR_ENH_MAIN_BRIEFINGEDITOR_BRIEFINGTITLE";
            y = QUOTE(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H + 2 * GRID_H);
        };
        class Templates: Subject
        {
            text = "$STR_ENH_MAIN_BRIEFINGEDITOR_TEMPLATES";
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (25 + 40 + 1) * GRID_W);
        };
        class ShowTitle: Subject
        {
            text = "$STR_ENH_MAIN_BRIEFINGEDITOR_SHOWTITLE";
            y = QUOTE(WINDOW_TOPAbs + 4 * CTRL_DEFAULT_H + 3 * GRID_H);
        };
        class BriefingText: Subject
        {
            text = "$STR_ENH_MAIN_BRIEFINGEDITOR_TEXT";
            tooltip = "$STR_ENH_MAIN_BRIEFINGEDITOR_TEXT_TOOLTIP";
            y = QUOTE(WINDOW_TOPAbs + 5 * CTRL_DEFAULT_H + 4 * GRID_H);
        };
        class Footer: ctrlStaticFooter
        {
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - 2 * GRID_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H + 2 * GRID_H);
        };
    };
    class Controls
    {
        class MenuStrip: ctrlMenuStrip
        {
            idc = -1;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H);
            w = QUOTE(WINDOW_W_ATTRIBUTES * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            class Items
            {
                items[] =
                {
                    "FolderExport",
                    "FolderFormatting",
                    "FolderTemplates",
                    "FolderHelp"
                };
                class FolderExport
                {
                    text = "Export";
                    items[] = {"Export"};
                };
                class FolderFormatting
                {
                    text = "Formatting";
                    items[] =
                    {
                        "Linebreak",
                        "Marker",
                        "Image",
                        "Font",
                        "Separator",
                        "Execute",
                        "ExecuteClose",
                        "Separator",
                        "AddTAG"
                    };
                };
                class FolderTemplates
                {
                    text = "$STR_ENH_MAIN_BRIEFINGEDITOR_TEMPLATES";
                    items[] = {"CreateTemplate", "Separator", "ApplyTemplate", "DeleteTemplate"};
                };
                class FolderHelp
                {
                    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELP_TEXT";
                    items[] = {"3denEnhancedDocumentation", "BikiDocumentation"};
                };
                //Export
                class Export
                {
                    text = "$STR_ENH_MAIN_BRIEFINGEDITOR_EXPORT";
                    action = "[nil, 'export'] call ENH_fnc_BriefingEditor";
                    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_E};
                    opensNewWindow = 1;
                };
                //Formatting
                class Linebreak
                {
                    text = "Linebreak";
                    action = "[nil, 'switchTAG', 'Linebreak'] call ENH_fnc_BriefingEditor";
                    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_1};
                };
                class Marker
                {
                    text = "Marker";
                    action = "[nil, 'switchTAG', 'Marker'] call ENH_fnc_BriefingEditor";
                    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_2};
                };
                class Image
                {
                    text = "Image";
                    action = "[nil, 'switchTAG', 'Image'] call ENH_fnc_BriefingEditor";
                    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_3};
                };
                class Font
                {
                    text = "Font";
                    action = "[nil, 'switchTAG', 'Font'] call ENH_fnc_BriefingEditor";
                    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_4};
                };
                class Execute
                {
                    text = "Execute";
                    action = "[nil, 'switchTAG', 'Execute'] call ENH_fnc_BriefingEditor";
                    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_5};
                };
                class ExecuteClose
                {
                    text = "Execute Close";
                    action = "[nil, 'switchTAG', 'ExecuteClose'] call ENH_fnc_BriefingEditor";
                    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_6};
                };
                class AddTAG
                {
                    text = "$STR_ENH_MAIN_BRIEFINGEDITOR_ADDTAG";
                    action = "[nil, 'addTAG'] call ENH_fnc_BriefingEditor";
                    shortcuts[] = {INPUT_CTRL_OFFSET + DIK_RETURN};
                };
                //Templates
                class ApplyTemplate
                {
                    text = "$STR_ENH_MAIN_BRIEFINGEDITOR_APPLYTEMPLATE";
                    action = "[nil, 'handleTemplates', 'apply'] call ENH_fnc_BriefingEditor";
                };
                class CreateTemplate
                {
                    text = "$STR_ENH_MAIN_BRIEFINGEDITOR_CREATETEMPLATE";
                    action = "[nil, 'handleTemplates', 'create'] call ENH_fnc_BriefingEditor";
                };
                class DeleteTemplate
                {
                    text = "$STR_ENH_MAIN_BRIEFINGEDITOR_DELETETEMPLATE";
                    action = "[nil, 'handleTemplates', 'delete'] call ENH_fnc_BriefingEditor";
                };
                //Help
                class 3denEnhancedDocumentation
                {
                    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
                    picture = "\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
                    weblink = "https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#briefing-editor";
                    opensNewWindow = 1;
                };
                class BikiDocumentation: 3denEnhancedDocumentation
                {
                    text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPBIKI_TEXT";
                    weblink = "https://community.bistudio.com/wiki/Arma_3:_Briefing";
                };
                class Default;
                class Separator;
            };
        };
        class SubjectValue: ctrlEdit
        {
            idc = IDC_BRIEFINGEDITOR_SUBJECT;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 25 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + CTRL_DEFAULT_H + 6 * GRID_H);
            w = QUOTE(40 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class TitleValue: SubjectValue
        {
            idc = IDC_BRIEFINGEDITOR_TITLE;
            y = QUOTE(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H + 2 * GRID_H);
        };
        class ShowTitleValue: ctrlToolbox
        {
            idc = IDC_BRIEFINGEDITOR_SHOWTITLE;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + 25 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 4 * CTRL_DEFAULT_H + 3 * GRID_H);
            w = QUOTE(40 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            rows = 1;
            columns = 2;
            strings[] =
            {
                "$STR_ENH_MAIN_YES",
                "$STR_ENH_MAIN_NO"
            };
            values[] = {0, 1};
        };
        class Group: ctrlControlsGroup
        {
            x = QUOTE(CENTER_X - 0.5 * (WINDOW_W_ATTRIBUTES - 2) * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 6 * CTRL_DEFAULT_H + 5 * GRID_H);
            w = QUOTE((WINDOW_W_ATTRIBUTES - 2) * GRID_W);
            h = QUOTE(WINDOW_HAbs - 10 * CTRL_DEFAULT_H - 3 * GRID_H);
            class Controls
            {
                class BriefingTextValue: ctrlEditMulti
                {
                    idc = IDC_BRIEFINGEDITOR_BRIEFINGTEXT;
                    w = QUOTE((WINDOW_W_ATTRIBUTES - 2) * GRID_W);
                    h = QUOTE(WINDOW_HAbs - 10 * CTRL_DEFAULT_H - 3 * GRID_H);
                    font = "ENH_BlankFont";
                    colorBackground[] = {0, 0, 0, 0};
                    colorText[] = {1, 1, 1, 1};
                    forceDrawCaret = 1;
                    colorSelection[] =
                    {
                        "profilenamespace getvariable ['GUI_BCG_RGB_R', 0.13]",
                        "profilenamespace getvariable ['GUI_BCG_RGB_G', 0.54]",
                        "profilenamespace getvariable ['GUI_BCG_RGB_B', 0.21]",
                        0.3
                    };
                };
                class BriefingTextSyntaxHighligthingValue: ctrlStructuredText
                {
                    idc = IDC_BRIEFINGEDITOR_HIGHLIGHT;
                    w = QUOTE((WINDOW_W_ATTRIBUTES - 2) * GRID_W);
                    h = QUOTE(WINDOW_HAbs - 10 * CTRL_DEFAULT_H - 3 * GRID_H);
                    colorBackground[] = {COLOR_TAB_RGBA};
                    class Attributes
                    {
                        font = "EtelkaMonospacePro";
                        align = "left";
                    };
                };
            };
        };
        class FirstParamValue: ctrlEdit
        {
            idc = IDC_BRIEFINGEDITOR_FIRSTPARAMVALUE;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (25 + 40 + 1 + 25 + 1) * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H + 2 * GRID_H);
            w = QUOTE(47 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
        class SecondParamValue: FirstParamValue
        {
            idc = IDC_BRIEFINGEDITOR_SECONDPARAMVALUE;
            y = QUOTE(WINDOW_TOPAbs + 4 * CTRL_DEFAULT_H + 3 * GRID_H);
        };
        class ThirdParamValue: FirstParamValue
        {
            idc = IDC_BRIEFINGEDITOR_THIRDPARAMVALUE;
            y = QUOTE(WINDOW_TOPAbs + 5 * CTRL_DEFAULT_H + 4 * GRID_H);
        };
        class MarkerList: ctrlCombo
        {
            idc = IDC_BRIEFINGEDITOR_MARKERS;
            x = QUOTE(CENTER_X - 0.5 * WINDOW_W_ATTRIBUTES * GRID_W + (25 + 40 + 1 + 25 + 1) * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + 3 * CTRL_DEFAULT_H + 2 * GRID_H);
            w = QUOTE(47 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
         class ColourList: MarkerList
        {
            idc = IDC_BRIEFINGEDITOR_COLOURS;
            y = QUOTE(WINDOW_TOPAbs + 4 * CTRL_DEFAULT_H + 3 * GRID_H);
        };
        class FontsList: MarkerList
        {
            idc = IDC_BRIEFINGEDITOR_FONTS;
            y = QUOTE(WINDOW_TOPAbs + 5 * CTRL_DEFAULT_H + 4 * GRID_H);
        };
        class TemplateList: MarkerList
        {
            idc = IDC_BRIEFINGEDITOR_TEMPLATES;
            y = QUOTE(WINDOW_TOPAbs + 2 * CTRL_DEFAULT_H + 1 * GRID_H);
        };
        class Close: ctrlButtonClose
        {
            x = QUOTE(CENTER_X + 0.5 * WINDOW_W_ATTRIBUTES * GRID_W - 26 * GRID_W);
            y = QUOTE(WINDOW_TOPAbs + WINDOW_HAbs - 3 * CTRL_DEFAULT_H - GRID_H);
            w = QUOTE(25 * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};