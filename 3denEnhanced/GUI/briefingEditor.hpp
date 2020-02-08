class ENH_BriefingEditor
{
	idd = -1;
	movingEnable = true;
	onLoad = "_this spawn ENH_fnc_briefingEditor_onLoad";
	onUnload = "_this call ENH_fnc_briefingEditor_onUnload";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(160);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = 160 * GRID_W;
			h = 110 * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_BRIEFINGEDITOR;
			x = CENTERED_X(160);
			y = DIALOG_TOP;
			w = 160 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Templates: ctrlStatic
		{	
			text = $STR_ENH_BRIEFINGEDITOR_TEMPLATES;
			x = CENTERED_X(160);
			y = DIALOG_TOP + CTRL_DEFAULT_H + 1 * GRID_H;
			w = 33 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class TemplateList: ctrlListbox
		{
			idc = 80;
			x = CENTERED_X(160) + 1 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 7 * GRID_H;
			w = 33 * GRID_W;
			h = 90 * GRID_H;
			onKeyDown = "if ((_this # 1) == 211 ) then {(_this #  0) lbDelete (lbCurSel (_this # 0))}";
			onLBDblClick = "_this call ENH_fnc_briefingEditor_getTemplate";
		};
		class Marker: ctrlStatic
		{
			text = $STR_ENH_BRIEFINGEDITOR_MARKER;
			x = CENTER_X + 45 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 1 * GRID_H;
			w = 35 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class MarkerList: ctrlListbox
		{
			idc = 60;
			x = CENTER_X + 46 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 7 * GRID_H;
			w = 33 * GRID_W;
			h = 25 * GRID_H;
		};
		class Colours: ctrlStatic
		{
			text = $STR_ENH_BRIEFINGEDITOR_COLOUR;
			x = CENTER_X + 45 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 33 * GRID_H;
			w = 35 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
 		class ColourList: ctrlListbox
		{
			idc = 100;
			x = CENTER_X + 46 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 39 * GRID_H;
			w = 33 * GRID_W;
			h = 30 * GRID_H;
		};
		class Fonts: ctrlStatic
		{
			text = $STR_ENH_BRIEFINGEDITOR_FONT;
			x = CENTER_X + 45 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 70 * GRID_H;
			w = 35 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class FontsList: ctrlListbox
		{
			idc = 70;
			x = CENTER_X + 46 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 76 * GRID_H;
			w = 33 * GRID_W;
			h = 21 * GRID_H;
		};
		class Subject: ctrlStatic
		{
			text = $STR_ENH_BRIEFINGEDITOR_SUBJECT;
			x = CENTER_X - 46 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 1 * GRID_H;
			w = 45 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SubjectValue: ctrlEdit
		{
			idc = 20;
			x = CENTER_X - 45 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 7 * GRID_H;
			w = 45 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Title: ctrlStatic
		{
			text = $STR_ENH_BRIEFINGEDITOR_BRIEFINGTITLE;
			x = CENTER_X;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 1 * GRID_H;
			w = 44 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class TitleValue: ctrlEdit
		{
			idc = 30;
			x = CENTER_X + 1 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 7 * GRID_H;
			w = 44 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class BriefingText: ctrlStatic
		{
			text = $STR_ENH_BRIEFINGEDITOR_TEXT;
			tooltip = $STR_ENH_BRIEFINGEDITOR_TEXT_TOOLTIP;
			x = CENTERED_X(90);
			y = DIALOG_TOP + CTRL_DEFAULT_H + 13 * GRID_H;
			w = 90 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class BriefingTextValue: ctrlEditMulti
		{
			idc = 10;
			x = CENTERED_X(90);
			y = DIALOG_TOP + CTRL_DEFAULT_H + 19 * GRID_H;
			w = 90 * GRID_W;
			h = 60 * GRID_H;
		};
		class ShowTitle: ctrlToolbox
		{
			idc = 40;
			x = CENTERED_X(90);
			y = DIALOG_TOP + CTRL_DEFAULT_H + 80 * GRID_H;
			w = 90 * GRID_W;
			h = CTRL_DEFAULT_H;
            rows = 1;
            columns = 2;
            strings[] = 
            {
                $STR_ENH_BRIEFINGEDITOR_SHOWTITLE,
                $STR_ENH_BRIEFINGEDITOR_HIDETITLE
            };
            values[] = {0,1};
        };
		class TAGs: ctrlStatic
		{
			text = $STR_ENH_BRIEFINGEDITOR_TAGS;
			x = CENTERED_X(90);
			y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
			w = 85 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Help: ctrlButton
		{
			text = "?";
			url = "https://community.bistudio.com/wiki/createDiaryRecord";
			x = CENTER_X + 40 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 86 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
 		class TAGsValue: ctrlCombo
		{
			idc = 90;
			x = CENTERED_X(90);
			y = DIALOG_TOP + CTRL_DEFAULT_H + 92 * GRID_H;
			w = 90 * GRID_W;
			h = CTRL_DEFAULT_H;
			onLBSelChanged = "_this call ENH_fnc_briefingEditor_onLBSelChanged";
        };
		class FirstParam: ctrlStatic
		{
			idc = 200;
			x = CENTER_X - 46 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 98 * GRID_H;
			w = 29 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class FirstParamValue: ctrlEdit
		{
			idc = 210;
			x = CENTER_X - 45 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
			w = 29 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SecondParam: ctrlStatic
		{
			idc = 220;
			x = CENTER_X - 16 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 98 * GRID_H;
			w = 29 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SecondParamValue: ctrlEdit
		{
			idc = 230;
			x = CENTER_X - 15 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
			w = 29 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class ThirdParam: ctrlStatic
		{
			idc = 240;
			x = CENTER_X + 14 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 98 * GRID_H;
			w = 31 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class ThirdParamValue: ctrlEdit
		{
			idc = 250;
			x = CENTER_X + 15 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class CreateTemplate: ctrlButton
		{
			text = $STR_ENH_BRIEFINGEDITOR_CREATETEMPLATE;
			x = CENTERED_X(160) + 1 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 98 * GRID_H;
			w = 33 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_briefingEditor_createTemplate";
		};
		class AddTAG: ctrlButton
		{
			text = $STR_ENH_BRIEFINGEDITOR_ADDTAG;
			x = CENTERED_X(160) + 1 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
			w = 33 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_briefingEditor_addTAG";
		};
		class Export: ctrlButton
		{
			text = $STR_ENH_BRIEFINGEDITOR_EXPORT;
			x = CENTER_X + 46 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 98 * GRID_H;
			w = 33 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call ENH_fnc_briefingEditor_export";
		};
		class Close: ctrlButtonClose
		{
			x = CENTER_X + 46 * GRID_W;
			y = DIALOG_TOP + CTRL_DEFAULT_H + 104 * GRID_H;
			w = 33 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};

/*class ENH_BriefingEditor
{
	idd = ENH_IDD_BRIEFINGEDITOR;
	movingEnable = true;
	onLoad = "[] spawn ENH_fnc_briefingEditor_onLoad";
	onUnload = "call ENH_fnc_briefingEditor_onUnload";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class BackgroundRight: ctrlStaticBackground
		{
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.308437 * safezoneW;
			h = 0.42 * safezoneH;
		};
		class BackgroundCenter: ctrlStaticBackground
		{
			x = 0.769063 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.308 * safezoneH;
		};
		class BackgroundLeft: ctrlStaticBackground
		{
			x = 0.0996875 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.42 * safezoneH;
		};
	};
	class Controls
	{
		class Text_Text: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_briefingText_displayName;
			x = 0.782188 * safezoneW + safezoneX;
			y = 0.276 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Expression_Text: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_expression_displayName;
			x = 0.782188 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class BriefingEditorHeader: ctrlStaticTitle
		{
			text = $STR_ENH_briefingEditor;
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.308437 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TemplatesHeader: ctrlStaticTitle
		{	text = $STR_ENH_briefingEditor_templates_displayName;
			x = 0.217813 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ColouredTextHeader: ctrlStaticTitle
		{
			text = $STR_ENH_briefingEditor_colourAndExpression_displayName;
			x = 0.769063 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class AddText: ctrlButton
		{
			text = $STR_ENH_briefingEditor_addText_displayName;
			x = 0.782188 * safezoneW + safezoneX;
			y = 0.528 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call ENH_fnc_briefingEditor_addCustomText";
		};
		class MarkerHeader: ctrlStaticTitle
		{
			text = $STR_ENH_briefingEditor_marker_displayName;
			x = 0.650937 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.028 * safezoneH;
   			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class Subject_Text: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_subject_displayName;
			x = 0.349063 * safezoneW + safezoneX;
			y = 0.164 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Title_Text: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_briefingTitle_displayName;
			x = 0.349063 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Briefing_Text: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_briefingText_displayName;
			x = 0.349063 * safezoneW + safezoneX;
			y = 0.276 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Linebreak: ctrlButton
		{
			text = $STR_ENH_briefingEditor_addLinebreak_displayName;
			x = 0.349063 * safezoneW + safezoneX;
			y = 0.528 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call ENH_fnc_briefingEditor_addLinebreak";
		};
		class Export: ctrlButton
		{
			text = $STR_ENH_briefingEditor_export_displayName;
			x = 0.4475 * safezoneW + safezoneX;
			y = 0.528 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call ENH_fnc_briefingEditor_export";
		};
		class CreateTemplate: ctrlButton
		{
			text = $STR_ENH_briefingEditor_createTemplate_displayName;
			x = 0.545937 * safezoneW + safezoneX;
			y = 0.528 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call ENH_fnc_briefingEditor_createTemplate";
		};
		class Image_Headline: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_picture_displayName;
			x = 0.0996875 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.028 * safezoneH;
   			colorBackground[] = {COLOUR_USER_PRESET};
		};
		class Path_Text: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_path_displayName;
			x = 0.112813 * safezoneW + safezoneX;
			y = 0.164 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class AddPicture: ctrlButton
		{
			text = $STR_ENH_briefingEditor_addPicture_displayName;
			x = 0.112813 * safezoneW + safezoneX;
			y = 0.528 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call ENH_fnc_briefingEditor_addPicture";
		};
		class Width_Text: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_width_displayName;
			x = 0.112813 * safezoneW + safezoneX;
			y = 0.276 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Height_Text: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_height_displayName;
			x = 0.112813 * safezoneW + safezoneX;
			y = 0.388 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class BriefingText_Value: ctrlEditMulti
		{
			idc = 10;
			x = 0.349063 * safezoneW + safezoneX;
			y = 0.332 * safezoneH + safezoneY;
			w = 0.282187 * safezoneW;
			h = 0.182 * safezoneH;
		};
		class Subject_Value: ctrlEdit
		{
			idc = 20;
			x = 0.440937 * safezoneW + safezoneX;
			y = 0.164 * safezoneH + safezoneY;
			w = 0.190312 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Title_Value: ctrlEdit
		{
			idc = 30;
			x = 0.440937 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.190312 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Path_Value: ctrlEdit
		{
			idc = 40;
			x = 0.112813 * safezoneW + safezoneX;
			y = 0.22 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Width_Value: ctrlEdit
		{
			idc = 50;
			x = 0.112813 * safezoneW + safezoneX;
			y = 0.332 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class MarkerList: ctrlListbox
		{
			idc = 60;
			x = 0.650937 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.42 * safezoneH;
			onLBDblClick = "call ENH_fnc_briefingEditor_addMarker";
		};
		class TemplateList: ctrlListbox
		{
			idc = 80;
			x = 0.217813 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.42 * safezoneH;
			onKeyDown = "if ((_this # 1) == 211 ) then {(_this #  0) lbDelete (lbCurSel (_this # 0))}";
			onLBDblClick = "[_this # 0,_this # 1] call ENH_fnc_briefingEditor_getTemplate";
		};
		class Height_Value: ctrlEdit
		{
			idc = 90;
			x = 0.112813 * safezoneW + safezoneX;
			y = 0.444 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class ColourList: ctrlListbox
		{
			idc = 100;
			x = 0.769063 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.098 * safezoneH;
			onSetFocus = "params ['_ctrl']; ENH_BriefingEditor_ColourListH = (ctrlPosition _ctrl) # 3; _ctrl ctrlSetPositionH (ENH_BriefingEditor_ColourListH * 5); _ctrl ctrlCommit 0.2";
			onKillFocus = "params ['_ctrl']; _ctrl ctrlSetPositionH ENH_BriefingEditor_ColourListH; _ctrl ctrlCommit 0.2";
		};
		class CustomText_Value: ctrlEditMulti
		{
			idc = 110;
			x = 0.782188 * safezoneW + safezoneX;
			y = 0.332 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.042 * safezoneH;
		};
		class Expression_Value: ctrlEditMulti
		{
			idc = 120;
			x = 0.782188 * safezoneW + safezoneX;
			y = 0.444 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.07 * safezoneH;
		};
		class Filter: ctrlToolbox
		{
			x = 0.440937 * safezoneW + safezoneX;
			y = 0.29 * safezoneH + safezoneY;
			w = 0.190312 * safezoneW;
			h = 0.028 * safezoneH;
            rows = 1;
            columns = 2;
            strings[] = 
            {
                $STR_ENH_briefingEditor_showTitle,
                $STR_ENH_briefingEditor_hideTitle
            };
            values[] = {0,1};
        };
	};
};*/