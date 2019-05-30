class Enh_ColourPicker
{
	idd = ENH_COLORPICKER;
	movingEnable = true;
	onLoad = "[] spawn Enh_fnc_colourPicker_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = 0.335938 * safezoneW + safezoneX;
			y = 0.262 * safezoneH + safezoneY;
			w = 0.275625 * safezoneW;
			h = 0.434 * safezoneH;
		};
	};
	class Controls
	{
		class Header: Enh_Text
		{
			text = $STR_ENH_colourPicker_header;
			x = 0.335936 * safezoneW + safezoneX;
			y = 0.234 * safezoneH + safezoneY;
			w = 0.275625 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class TextRed: Enh_Text
		{
			text = $STR_ENH_colourPicker_red;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.318 * safezoneH + safezoneY;
			w = 0.0525 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TextGreen: Enh_Text
		{
			text = $STR_ENH_colourPicker_green;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.374 * safezoneH + safezoneY;
			w = 0.0525 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TextBlue: Enh_Text
		{
			text = $STR_ENH_colourPicker_blue;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.0525 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TextAlpha: Enh_Text
		{
			text = $STR_ENH_colourPicker_alpha;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.486 * safezoneH + safezoneY;
			w = 0.0525 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class SliderRed: ctrlXSliderH
		{
			idc = 1900;
			x = 0.42125 * safezoneW + safezoneX;
			y = 0.318 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.028 * safezoneH;
			onSliderPosChanged = "((findDisplay 110000) displayCtrl 1400) ctrlSetText ((_this select 1) toFixed 3); ((findDisplay 110000) displayCtrl 1201) ctrlSetText (format ['#(argb,8,8,3)color(%1,0,0,1)',((_this select 1) toFixed 3)]); 0 = '' call Enh_fnc_colourPicker";
		};
		class SliderGreen: ctrlXSliderH
		{
			idc = 1901;
			x = 0.42125 * safezoneW + safezoneX;
			y = 0.374 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.028 * safezoneH;
			onSliderPosChanged = "((findDisplay 110000) displayCtrl 1401) ctrlSetText ((_this select 1) toFixed 3); ((findDisplay 110000) displayCtrl 1202) ctrlSetText (format ['#(argb,8,8,3)color(0,%1,0,1)',((_this select 1) toFixed 3)]); 0 = '' call Enh_fnc_colourPicker";
		};
		class SliderBlue: ctrlXSliderH
		{
			idc = 1902;
			x = 0.42125 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.028 * safezoneH;
			onSliderPosChanged = "((findDisplay 110000) displayCtrl 1402) ctrlSetText ((_this select 1) toFixed 3); ((findDisplay 110000) displayCtrl 1203) ctrlSetText (format ['#(argb,8,8,3)color(0,0,%1,1)',((_this select 1) toFixed 3)]); 0 = '' call Enh_fnc_colourPicker";
		};
		class SliderAlpha: ctrlXSliderH
		{
			idc = 1903;
			x = 0.42125 * safezoneW + safezoneX;
			y = 0.486 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.028 * safezoneH;
			onSliderPosChanged = "((findDisplay 110000) displayCtrl 1403) ctrlSetText ((_this select 1) toFixed 3); ((findDisplay 110000) displayCtrl 1204) ctrlSetText (format ['#(argb,8,8,3)color(0,0,0,%1)',((_this select 1) toFixed 3)]); 0 = '' call Enh_fnc_colourPicker";
		};
		class ValueRed: ctrlEdit
		{
			idc = 1400;
			x = 0.565625 * safezoneW + safezoneX;
			y = 0.318 * safezoneH + safezoneY;
			w = 0.039375 * safezoneW;
			h = 0.028 * safezoneH;
			onKillFocus = "((findDisplay 110000) displayCtrl 1900) sliderSetPosition (parseNumber (ctrlText (_this select 0))); ((findDisplay 110000) displayCtrl 1201) ctrlSetText (format ['#(argb,8,8,3)color(%1,0,0,0)',(parseNumber (ctrlText (_this select 0)) toFixed 3)]); 0 = '' call Enh_fnc_colourPicker";
		};
		class ValueGreen: ctrlEdit
		{
			idc = 1401;
			x = 0.565625 * safezoneW + safezoneX;
			y = 0.374 * safezoneH + safezoneY;
			w = 0.039375 * safezoneW;
			h = 0.028 * safezoneH;
			onKillFocus = "((findDisplay 110000) displayCtrl 1901) sliderSetPosition (parseNumber (ctrlText (_this select 0))); ((findDisplay 110000) displayCtrl 1202) ctrlSetText (format ['#(argb,8,8,3)color(0,%1,0,0)',(parseNumber (ctrlText (_this select 0)) toFixed 3)]); 0 = '' call Enh_fnc_colourPicker";
		};
		class ValueBlue: ctrlEdit
		{
			idc = 1402;
			x = 0.565625 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.039375 * safezoneW;
			h = 0.028 * safezoneH;
			onKillFocus = "((findDisplay 110000) displayCtrl 1902) sliderSetPosition (parseNumber (ctrlText (_this select 0))); ((findDisplay 110000) displayCtrl 1203) ctrlSetText (format ['#(argb,8,8,3)color(0,0,%1,0)',(parseNumber (ctrlText (_this select 0)) toFixed 3)]); 0 = '' call Enh_fnc_colourPicker";
		};
		class ValueAlpha: ctrlEdit
		{
			idc = 1403;
			x = 0.565625 * safezoneW + safezoneX;
			y = 0.486 * safezoneH + safezoneY;
			w = 0.039375 * safezoneW;
			h = 0.028 * safezoneH;
			onKillFocus = "((findDisplay 110000) displayCtrl 1903) sliderSetPosition (parseNumber (ctrlText (_this select 0))); ((findDisplay 110000) displayCtrl 1204) ctrlSetText (format ['#(argb,8,8,3)color(0,0,0,%1)',(parseNumber (ctrlText (_this select 0)) toFixed 3)]); 0 = '' call Enh_fnc_colourPicker";
		};
		class FinalColourPreview: Enh_Picture
		{
			idc = 1200;
			text = "#(argb,8,8,3)color(0,1,1,1)";
			x = 0.421249 * safezoneW + safezoneX;
			y = 0.57 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.07 * safezoneH;
		};
		class TextFinalColour: Enh_Text
		{
			text = $STR_ENH_colourPicker_finalColour;
			x = 0.42125 * safezoneW + safezoneX;
			y = 0.542 * safezoneH + safezoneY;
			w = 0.105 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Close: Enh_Button
		{
			text = $STR_ENH_garrison_close;
			x = 0.3425 * safezoneW + safezoneX;
			y = 0.654 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			action = "(findDisplay 110000) closeDisplay 0";
		};
		class Export: Enh_Button
		{
			text = $STR_ENH_3denRadio_exportPlaylist_text;
			x = 0.539374 * safezoneW + safezoneX;
			y = 0.654 * safezoneH + safezoneY;
			w = 0.065625 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'export' call Enh_fnc_colourPicker";
		};
		class PreviewRed: Enh_Picture
		{
			idc = 1201;
			text = "#(argb,8,8,3)color(1,0,0,1)";
			x = 0.539374 * safezoneW + safezoneX;
			y = 0.318 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class PreviewGreen: Enh_Picture
		{
			idc = 1202;
			text = "#(argb,8,8,3)color(0,1,0,1)";
			x = 0.539375 * safezoneW + safezoneX;
			y = 0.374 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class PreviewBlue: Enh_Picture
		{
			idc = 1203;
			text = "#(argb,8,8,3)color(0,0,1,1)";
			x = 0.539375 * safezoneW + safezoneX;
			y = 0.43 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class PreviewAlpha: Enh_Picture
		{
			idc = 1204;
			text = "#(argb,8,8,3)color(1,1,1,0.3)";
			x = 0.539375 * safezoneW + safezoneX;
			y = 0.486 * safezoneH + safezoneY;
			w = 0.013125 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
};

/* #Tizeky
$[
	1.063,
	["ColourPicker",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[2200,"Background",[1,"",["0.335938 * safezoneW + safezoneX","0.262 * safezoneH + safezoneY","0.275625 * safezoneW","0.434 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"Header",[1,"Colour Picker",["0.335936 * safezoneW + safezoneX","0.234 * safezoneH + safezoneY","0.275625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"TextRed",[1,"Red",["0.3425 * safezoneW + safezoneX","0.318 * safezoneH + safezoneY","0.0525 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1002,"TextGreen",[1,"Green",["0.3425 * safezoneW + safezoneX","0.374 * safezoneH + safezoneY","0.0525 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1003,"TextBlue",[1,"Blue",["0.3425 * safezoneW + safezoneX","0.43 * safezoneH + safezoneY","0.0525 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1004,"TextAlpha",[1,"Alpha",["0.3425 * safezoneW + safezoneX","0.486 * safezoneH + safezoneY","0.0525 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1900,"SliderRed",[1,"",["0.42125 * safezoneW + safezoneX","0.318 * safezoneH + safezoneY","0.105 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1901,"Slider",[1,"Green",["0.42125 * safezoneW + safezoneX","0.374 * safezoneH + safezoneY","0.105 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1902,"SliderBlue",[1,"",["0.42125 * safezoneW + safezoneX","0.43 * safezoneH + safezoneY","0.105 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1903,"SliderAlpha",[1,"",["0.42125 * safezoneW + safezoneX","0.486 * safezoneH + safezoneY","0.105 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1400,"ValueRed",[1,"",["0.565625 * safezoneW + safezoneX","0.318 * safezoneH + safezoneY","0.039375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1401,"ValueGreen",[1,"",["0.565625 * safezoneW + safezoneX","0.374 * safezoneH + safezoneY","0.039375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1402,"ValueBlue",[1,"",["0.565625 * safezoneW + safezoneX","0.43 * safezoneH + safezoneY","0.039375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1403,"ValueAlpha",[1,"",["0.565625 * safezoneW + safezoneX","0.486 * safezoneH + safezoneY","0.039375 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1200,"FinalColourPreview",[1,"#(argb,8,8,3)color(0,1,1,1)",["0.421249 * safezoneW + safezoneX","0.57 * safezoneH + safezoneY","0.105 * safezoneW","0.07 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1005,"TextFinalColour",[1,"Final Colour",["0.42125 * safezoneW + safezoneX","0.542 * safezoneH + safezoneY","0.105 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"Close",[1,"Close",["0.3425 * safezoneW + safezoneX","0.654 * safezoneH + safezoneY","0.065625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1601,"Export",[1,"Export",["0.440937 * safezoneW + safezoneX","0.654 * safezoneH + safezoneY","0.065625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1602,"Convert",[1,"Convert",["0.539374 * safezoneW + safezoneX","0.654 * safezoneH + safezoneY","0.065625 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1201,"PreviewRed",[1,"#(argb,8,8,3)color(1,0,0,1)",["0.539374 * safezoneW + safezoneX","0.318 * safezoneH + safezoneY","0.013125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1202,"PreviewGreen",[1,"#(argb,8,8,3)color(0,1,0,1)",["0.539375 * safezoneW + safezoneX","0.374 * safezoneH + safezoneY","0.013125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1203,"PreviewBlue",[1,"#(argb,8,8,3)color(0,0,1,1)",["0.539375 * safezoneW + safezoneX","0.43 * safezoneH + safezoneY","0.013125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1204,"PreviewAlpha",[1,"#(argb,8,8,3)color(1,1,1,0.3)",["0.539375 * safezoneW + safezoneX","0.486 * safezoneH + safezoneY","0.013125 * safezoneW","0.028 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/
