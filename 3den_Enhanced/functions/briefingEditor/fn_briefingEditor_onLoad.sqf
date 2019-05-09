/*
   Author: Revo

   Description:
   Fills the briefing editor with the last saved input (History) and hides left & right 3DEN panel.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true
*/

#define GET_CONTROL(IDD,IDC) ((findDisplay IDD) displayCtrl IDC)

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

sleep 0.005;
//Close display by pressing ESC and save
(findDisplay 50000) displayAddEventHandler
[
   "keyDown",
   {
      if (_this # 1 isEqualTo 1) then
      {
         call Enh_fnc_briefingEditor_onClose;
      }
   }
];

//Hide left & right tab to prevent interference
["ShowPanelLeft",false] call BIS_fnc_3DENInterface;
["ShowPanelRight",false] call BIS_fnc_3DENInterface;
//Get history if available
private _historyLatest = profileNamespace getVariable ["Enh_briefingEditor_history",["","Diary",""]];

GET_CONTROL(50000,30) ctrlSetText (_historyLatest # 0);//Briefing Title
GET_CONTROL(50000,20) ctrlSetText (_historyLatest # 1);//Subject Text
GET_CONTROL(50000,10) ctrlSetText (_historyLatest # 2);//Briefing Text

{
   GET_CONTROL(50000,100) lbAdd format ["%1 %2",localize "STR_ENH_briefingEditor_colour",_forEachIndex];
   GET_CONTROL(50000,100) lbSetData [_forEachIndex,_x];

   GET_CONTROL(50000,100) lbSetColor [_forEachIndex,[_x] call _getColorFromHex];
} forEach _coloursHTML;
//Load saved templates
private _templates = profileNamespace getVariable "Enh_briefingEditor_templates";
//Exit in case the template list is empty
if (isNil "_templates") exitWith {};

private _ctrlTemplateList =  GET_CONTROL(50000,80);

{
   private _briefingTitle = _x # 0;
   private _briefingText = _x # 1;
   //private _briefingSubject = (_templates select _forEachIndex) select 2; Currently not used

   _ctrlTemplateList lbAdd _briefingTitle;
   _ctrlTemplateList lbSetData [_forEachIndex,_briefingText];
   _ctrlTemplateList lbSetTooltip [_forEachIndex,localize "STR_ENH_briefingEditor_loadTemplate_tooltip"];

} forEach _templates;

private _allMarkers = all3DENEntities # 5;
private _ctrlMarkerList = GET_CONTROL(50000,60);
//Fill marker list
{
   _ctrlMarkerList lbAdd ((_x get3DENAttribute "text") # 0);
   _ctrlMarkerList lbSetData [_forEachIndex,(_x get3DENAttribute "markerName") # 0];
   _ctrlMarkerList lbSetTooltip [_forEachIndex,localize "STR_ENH_briefingEditor_addMarker_tooltip"];
   //Get icon
   private _markerType = (_x get3DENAttribute "itemClass") # 0;
   private _icon = getText (configfile >> "CfgMarkers" >> _markerType >> "icon");
   _ctrlMarkerList lbSetPictureRight [_forEachIndex,_icon];
   //Get colour
   _ctrlMarkerList lbSetPictureRightColor 
   [
      _forEachIndex,
      getArray (configfile >> "CfgMarkerColors" >> (_x get3DENAttribute "baseColor") # 0 >> "color") call BIS_fnc_colorConfigToRGBA //Function is need to because some colours are defined as string
   ];
} forEach _allMarkers;

ctrlSetFocus GET_CONTROL(50000,10);

true