/*
   Author: R3vo

   Date: 2019-06-21

   Description:
   Initializes ENH_BriefingEditor GUI.

   Parameter(s):
   0: DISPLAY - ENH_BriefingEditor

   Returns:
   BOOLEAN: true
*/

disableSerialization;

//Hide left & right tab to prevent interference
["ShowPanelLeft",false] call BIS_fnc_3DENInterface;
["ShowPanelRight",false] call BIS_fnc_3DENInterface;

params ["_display"];
#define CTRL(IDC) (_display displayCtrl IDC)

private _coloursHTML =
[
   "#0000FF",
   "#8A2BE2",
   "#A52A2A",
   "#DEB887",
   "#5F9EA0",
   "#7FFF00",
   "#D2691E",
   "#FF7F50",
   "#6495ED",
   "#FFF8DC",
   "#DC143C",
   "#00FFFF",
   "#00008B",
   "#008B8B",
   "#B8860B",
   "#A9A9A9",
   "#A9A9A9",
   "#006400",
   "#BDB76B",
   "#8B008B",
   "#556B2F",
   "#FF8C00",
   "#9932CC",
   "#8B0000",
   "#E9967A",
   "#8FBC8F",
   "#483D8B",
   "#2F4F4F",
   "#2F4F4F",
   "#00CED1",
   "#9400D3",
   "#FF1493",
   "#00BFFF",
   "#696969",
   "#696969",
   "#1E90FF",
   "#B22222",
   "#FFFAF0",
   "#228B22",
   "#FF00FF",
   "#DCDCDC",
   "#F8F8FF",
   "#FFD700",
   "#DAA520",
   "#808080",
   "#808080",
   "#008000",
   "#ADFF2F",
   "#F0FFF0",
   "#FF69B4",
   "#CD5C5C",
   "#4B0082",
   "#FFFFF0",
   "#F0E68C",
   "#E6E6FA",
   "#FFF0F5",
   "#7CFC00",
   "#FFFACD",
   "#ADD8E6",
   "#F08080",
   "#E0FFFF",
   "#FAFAD2",
   "#D3D3D3",
   "#90EE90",
   "#FFB6C1",
   "#FFA07A",
   "#20B2AA",
   "#87CEFA",
   "#778899",
   "#778899",
   "#B0C4DE",
   "#FFFFE0",
   "#00FF00",
   "#32CD32",
   "#FAF0E6",
   "#FF00FF",
   "#800000",
   "#66CDAA",
   "#0000CD",
   "#BA55D3",
   "#9370DB",
   "#3CB371",
   "#7B68EE",
   "#00FA9A",
   "#48D1CC",
   "#C71585",
   "#191970",
   "#F5FFFA",
   "#FFE4E1",
   "#FFE4B5",
   "#FFDEAD",
   "#000080",
   "#FDF5E6",
   "#808000",
   "#6B8E23",
   "#FFA500",
   "#FF4500",
   "#DA70D6",
   "#EEE8AA",
   "#98FB98",
   "#AFEEEE",
   "#DB7093",
   "#FFEFD5",
   "#FFDAB9",
   "#CD853F",
   "#FFC0CB",
   "#DDA0DD",
   "#B0E0E6",
   "#800080",
   "#FF0000",
   "#BC8F8F",
   "#4169E1",
   "#8B4513",
   "#FA8072",
   "#F4A460",
   "#2E8B57",
   "#FFF5EE",
   "#A0522D",
   "#C0C0C0",
   "#87CEEB",
   "#6A5ACD",
   "#708090",
   "#708090",
   "#FFFAFA",
   "#00FF7F",
   "#4682B4",
   "#D2B48C",
   "#008080",
   "#D8BFD8",
   "#FF6347",
   "#40E0D0",
   "#EE82EE",
   "#F5DEB3",
   "#FFFFFF",
   "#F5F5F5",
   "#FFFF00"
];

private _getColorFromHex =
{
    //Author: k0ss (github.com/k0ss)
    private _nums = toArray "0123456789ABCDEF";
    private _hex = toArray (_this # 0);
    private _hex = _hex - [(_hex # 0)];
    private _r = (_nums find (_hex # 0)) * 16 + (_nums find (_hex # 1));
    private _g = (_nums find (_hex # 2)) * 16 + (_nums find (_hex # 3));
    private _b = (_nums find (_hex # 4)) * 16 + (_nums find (_hex # 5));

   [(_r/255),(_g/255),(_b/255),1];
};

//Get history if available
private _historyLatest = profileNamespace getVariable ["ENH_briefingEditor_history",["","Diary",""]];

CTRL(30) ctrlSetText (_historyLatest # 0);//Briefing Title
CTRL(20) ctrlSetText (_historyLatest # 1);//Subject Text
CTRL(10) ctrlSetText (_historyLatest # 2);//Briefing Text

//Load saved templates
private _templates = profileNamespace getVariable "ENH_briefingEditor_templates";

//Exit in case the template list is empty
if !(isNil "_templates") then 
{
   private _ctrlTemplateList = CTRL(80);

   {
      _x params ["_briefingTitle","_briefingText"];
   
      _ctrlTemplateList lbAdd _briefingTitle;
      _ctrlTemplateList lbSetData [_forEachIndex,_briefingText];
      _ctrlTemplateList lbSetTooltip [_forEachIndex,localize "STR_ENH_BRIEFINGEDITOR_LOADTEMPLATE_TOOLTIP"];
   } forEach _templates;
};

 private _ctrlLBColours = _display displayCtrl 100;
{
   _ctrlLBColours lbAdd format ["%1 %2",localize "STR_ENH_BRIEFINGEDITOR_COLOUR",_forEachIndex];
   _ctrlLBColours lbSetData [_forEachIndex,_x];
   _ctrlLBColours lbSetColor [_forEachIndex,[_x] call _getColorFromHex];
   _ctrlLBColours lbSetTooltip [_forEachIndex,_x];
} forEach _coloursHTML;

//Fill marker list
private _ctrlLBMarkers = CTRL(60);
{
   //If marker has no name, use variable name instead
   private _name = (_x get3DENAttribute "text") # 0;
   private _varName = (_x get3DENAttribute "markerName") # 0;
   if (_name isEqualTo "") then {_name = _varName};

   _ctrlLBMarkers lbAdd _name;
   _ctrlLBMarkers lbSetData [_forEachIndex,_varName];
   _ctrlLBMarkers lbSetTooltip [_forEachIndex,localize "STR_ENH_BRIEFINGEDITOR_ADDMARKER_TOOLTIP"];

   //Get icon
   private _markerType = (_x get3DENAttribute "itemClass") # 0;
   private _icon = getText (configfile >> "CfgMarkers" >> _markerType >> "icon");
   _ctrlLBMarkers lbSetPictureRight [_forEachIndex,_icon];

   //Get colour
   _ctrlLBMarkers lbSetPictureRightColor
   [
      _forEachIndex,
      getArray (configfile >> "CfgMarkerColors" >> (_x get3DENAttribute "baseColor") # 0 >> "color") call BIS_fnc_colorConfigToRGBA //Function is needed to because some colours are defined as string
   ];
} forEach (all3DENEntities # 5);

//Add tags to combo
private _ctrlComboTags = CTRL(90);

{
   _ctrlComboTags lbAdd _x;
} forEach ["Linebreak","Marker","Image","Font","Execute","ExecuteClose"];//Do not localize. Biki description is English

_ctrlComboTags lbSetCurSel 0;

//Add fonts
private _ctrlLBFonts = CTRL(70);
{
   _ctrlLBFonts lbAdd configName _x; 
   _ctrlLBFonts lbSetTooltip [_forEachIndex,configName _x];
} forEach ('true' configClasses (configFile >> 'CfgFontFamilies'));

true