class Enh_BriefingEditor
{
	idd = ENH_IDD_BRIEFINGEDITOR;
	movingEnable = true;
	onLoad = "[] spawn Enh_fnc_briefingEditor_onLoad";
	onUnload = "call Enh_fnc_briefingEditor_onUnload";
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
			text = $STR_ENH_briefingEditor_headline_displayName;
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
			action = "call Enh_fnc_briefingEditor_addCustomText";
		};
		class MarkerHeader: ctrlStaticTitle
		{
			text = $STR_ENH_briefingEditor_marker_displayName;
			x = 0.650937 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.028 * safezoneH;
   			colorBackground[] = COLOUR_USER_PRESET;
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
			action = "call Enh_fnc_briefingEditor_addLinebreak";
		};
		class Export: ctrlButton
		{
			text = $STR_ENH_briefingEditor_export_displayName;
			x = 0.4475 * safezoneW + safezoneX;
			y = 0.528 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call Enh_fnc_briefingEditor_export";
		};
		class CreateTemplate: ctrlButton
		{
			text = $STR_ENH_briefingEditor_createTemplate_displayName;
			x = 0.545937 * safezoneW + safezoneX;
			y = 0.528 * safezoneH + safezoneY;
			w = 0.0853125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "call Enh_fnc_briefingEditor_createTemplate";
		};
		class Image_Headline: ctrlStatic
		{
			text = $STR_ENH_briefingEditor_picture_displayName;
			x = 0.0996875 * safezoneW + safezoneX;
			y = 0.122 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.028 * safezoneH;
   			colorBackground[] = COLOUR_USER_PRESET;
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
			action = "call Enh_fnc_briefingEditor_addPicture";
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
			onLBDblClick = "call Enh_fnc_briefingEditor_addMarker";
		};
		class TemplateList: ctrlListbox
		{
			idc = 80;
			x = 0.217813 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.111562 * safezoneW;
			h = 0.42 * safezoneH;
			onKeyDown = "if ((_this # 1) == 211 ) then {(_this #  0) lbDelete (lbCurSel (_this # 0))}";
			onLBDblClick = "[_this # 0,_this # 1] call Enh_fnc_briefingEditor_getTemplate";
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
	};
};