#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2023-09-19

    Description:
    Initializes ENH_BriefingEditor GUI.

    Parameter(s):
    Internal use only.

    Returns:
    -
*/

disableSerialization;

params
[
    ["_display", uiNamespace getVariable ['ENH_BriefingEditor_Display', displayNull]],
    ["_mode", "onLoad"],
    ["_param", "", [""]]
];

switch _mode do
{
    case "onLoad":
    {
        uiNamespace setVariable ["ENH_BriefingEditor_Display", _display];

        private _colorsHTML =
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
            // Author: k0ss (github.com/k0ss)
            private _nums = toArray "0123456789ABCDEF";
            private _hex = toArray (_this # 0);
            _hex = _hex - [(_hex # 0)];
            private _r = (_nums find (_hex # 0)) * 16 + (_nums find (_hex # 1));
            private _g = (_nums find (_hex # 2)) * 16 + (_nums find (_hex # 3));
            private _b = (_nums find (_hex # 4)) * 16 + (_nums find (_hex # 5));

            [(_r/255), (_g/255), (_b/255), 1];
        };

        private _ctrlLBColors = CTRL(IDC_BRIEFINGEDITOR_COLORS);
        private _ctrlLBMarkers = CTRL(IDC_BRIEFINGEDITOR_MARKERS);
        private _ctrlLBFonts = CTRL(IDC_BRIEFINGEDITOR_FONTS);

        // Update syntax highlighting
        CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlAddEventHandler ["EditChanged", {[ctrlParent (_this#0), 'htmlHighlight'] call ENH_fnc_briefingEditor}];

        // Get history if available
        (profileNamespace getVariable ["ENH_briefingEditor_history", ["", "Diary", ""]]) params ["_title", "_subject", "_text"];

        CTRL(IDC_BRIEFINGEDITOR_TITLE) ctrlSetText _title;
        CTRL(IDC_BRIEFINGEDITOR_SUBJECT) ctrlSetText _subject;
        CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText _text;

        // Load templates
        [nil, "handleTemplates", "fillTemplatesList"] call ENH_fnc_briefingEditor;

        {
            _ctrlLBColors lbAdd format ["%1 %2", localize "STR_ENH_MAIN_BRIEFINGEDITOR_COLOR", _forEachIndex];
            _ctrlLBColors lbSetData [_forEachIndex, _x];
            _ctrlLBColors lbSetColor [_forEachIndex, [_x] call _getColorFromHex];
            _ctrlLBColors lbSetTooltip [_forEachIndex, _x];
        } forEach _colorsHTML;

        // Fill marker list
        {
            // If marker has no name, use variable name instead
            private _name = (_x get3DENAttribute "text") # 0;
            private _varName = (_x get3DENAttribute "markerName") # 0;
            if (_name isEqualTo "") then {_name = _varName};

            _ctrlLBMarkers lbAdd _name;
            _ctrlLBMarkers lbSetData [_forEachIndex, _varName];

            // Get icon
            private _markerType = (_x get3DENAttribute "itemClass") # 0;
            private _icon = getText (configFile >> "CfgMarkers" >> _markerType >> "icon");

            // Get color
            private _markerColor = (_x get3DENAttribute "baseColor") # 0;
            private _color = getArray (configFile >> "CfgMarkerColors" >> _markerColor >> "color");
            _color = _color call BIS_fnc_colorConfigToRGBA;

            if (_markerColor isEqualTo "Default") then
            {
                _color = getArray (configFile >> "CfgMarkers" >> _markerType >> "color");
                if (count _color == 4) then {_color = _color call BIS_fnc_colorConfigToRGBA} else {_color = [1, 1, 1, 1]};
                if (_color isEqualTo [0, 0, 0, 1]) then {_color = [1, 1, 1, 1]};
            };

            _ctrlLBMarkers lbSetPictureRight [_forEachIndex, _icon];
            _ctrlLBMarkers lbSetPictureRightColor [_forEachIndex, _color];
        } forEach (all3DENEntities # 5);

        // Add fonts
        {
            _ctrlLBFonts lbAdd configName _x;
            _ctrlLBFonts lbSetTooltip [_forEachIndex, configName _x];
        } forEach ("true" configClasses (configFile >> "CfgFontFamilies"));

        lbSort _ctrlLBFonts;
        lbSort _ctrlLBMarkers;

        [nil, 'switchTAG', 'Linebreak'] call ENH_fnc_briefingEditor;
    };
    case "onUnload":
    {
        // Create history of last input when closing the display
        profileNamespace setVariable
        [
            "ENH_briefingEditor_history",
            [
                ctrlText CTRL(IDC_BRIEFINGEDITOR_TITLE),
                ctrlText CTRL(IDC_BRIEFINGEDITOR_SUBJECT),
                ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT)
            ]
        ];
    };
    case "htmlHighlight":
    {
        private _text = ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) splitString "";
        private _stringFinal = [];
        private _highlight = false;
        private _h = (ctrlTextHeight CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT)) + 5 * GRID_H max (WINDOW_HAbs - 10 * CTRL_DEFAULT_H - 3 * GRID_H);

        {
            if (_x == "<") then {_highlight = true};

            if _highlight then
            {
                _text = text _x setAttributes ["color", "#2A8DFF"];
                _stringFinal pushBack _text;
            }
            else
            {
                _stringFinal pushBack _x;
            };
            if (_x == ">") then {_highlight = false};
        } forEach _text;

        CTRL(IDC_BRIEFINGEDITOR_HIGHLIGHT) ctrlSetStructuredText composeText _stringFinal;
        CTRL(IDC_BRIEFINGEDITOR_HIGHLIGHT) ctrlSetPositionH _h;
        CTRL(IDC_BRIEFINGEDITOR_HIGHLIGHT) ctrlCommit 0;

        CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetPositionH _h;
        CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlCommit 0;
    };
    case "export":
    {
        private _text = ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT);
        private _subject = ctrlText CTRL(IDC_BRIEFINGEDITOR_SUBJECT);
        private _title = ctrlText CTRL(IDC_BRIEFINGEDITOR_TITLE);
        private _showTitle = [true, false] select (lbCurSel CTRL(IDC_BRIEFINGEDITOR_SHOWTITLE));

        private _createBriefing = format
        [
            "player createDiaryRecord [""%1"", [""%2"", ""%3""], %4, ""%5"", %6];",
            _subject,
            _title,
            _text,
            "taskNull",
            "",
            _showTitle
        ];

        if (_subject != "Diary") then // If user uses a non default subject, create it and export the code for it
        {
            private _createSubject = format ["player createDiarySubject [""%1"", ""%1""];", _subject];
            _createBriefing = _createSubject + endl + _createBriefing;
        };

        _createBriefing = "// Code (SQF)" + endl + endl + _createBriefing + endl + endl + "// Raw Text (Briefing Attribute, Task Description)" + endl + endl + (_text trim ["""", 0]);

        uiNamespace setVariable ["display3DENCopy_data", [localize "ENH_BRIEFINGEDITOR_EXPORT", _createBriefing]];
        _display createDisplay "display3denCopy";
    };
    case "switchTAG":
    {
        private _ctrlFirstParam = CTRL(IDC_BRIEFINGEDITOR_FIRSTPARAM);
        private _ctrlFirstParamValue = CTRL(IDC_BRIEFINGEDITOR_FIRSTPARAMVALUE);
        private _ctrlSecondParam = CTRL(IDC_BRIEFINGEDITOR_SECONDPARAM);
        private _ctrlSecondParamValue = CTRL(IDC_BRIEFINGEDITOR_SECONDPARAMVALUE);
        private _ctrlThirdParam = CTRL(IDC_BRIEFINGEDITOR_THIRDPARAM);
        private _ctrlThirdParamValue = CTRL(IDC_BRIEFINGEDITOR_THIRDPARAMVALUE);
        private _ctrlLBColors = CTRL(IDC_BRIEFINGEDITOR_COLORS);
        private _ctrlLBFonts = CTRL(IDC_BRIEFINGEDITOR_FONTS);
        private _ctrlLBMarkers = CTRL(IDC_BRIEFINGEDITOR_MARKERS);

        uiNamespace setVariable ["ENH_BriefingEditor_SelectedTAG", _param];

        private _fnc_setupCtrls =
        {
            params [["_states", [true, true, true]], ["_texts", ["", "", ""]], ["_lbStates", [false, false, false]], ["_defaults", ["", "", ""]]];
            {
                _x ctrlShow (_states # _forEachIndex);
                _x ctrlSetText (_defaults # _forEachIndex);
            } forEach [_ctrlFirstParamValue, _ctrlSecondParamValue, _ctrlThirdParamValue];
            {
                _x ctrlSetText localize (_texts # _forEachIndex);
            } forEach [_ctrlFirstParam, _ctrlSecondParam, _ctrlThirdParam];
            {
                _x ctrlShow (_lbStates # _forEachIndex);
            } forEach [_ctrlLBMarkers, _ctrlLBColors, _ctrlLBFonts];
        };

        switch _param do
        {
            case "Linebreak":
            {
                [[false, false, false], ["", "", ""], [false, false, false]] call _fnc_setupCtrls;
            };
            case "Marker":
            {
                [[false, false, false], ["Marker", "", ""], [true, false, false]] call _fnc_setupCtrls;
            };
            case "Image":
            {
                [[true, true, true], ["STR_ENH_MAIN_BRIEFINGEDITOR_PATH", "STR_ENH_MAIN_BRIEFINGEDITOR_WIDTH", "STR_ENH_MAIN_BRIEFINGEDITOR_HEIGHT"], [false, false, false], ["", "300", "150"]] call _fnc_setupCtrls;
            };
            case "Font":
            {
                [[true, false, false], ["STR_ENH_MAIN_BRIEFINGEDITOR_SIZE", "", ""], [false, true, true]] call _fnc_setupCtrls;
            };
            case "Execute";
            case "ExecuteClose":
            {
                [[true, false, false], ["STR_ENH_MAIN_BRIEFINGEDITOR_EXPRESSION", "", ""]] call _fnc_setupCtrls;
            };
        };
    };
    case "addTAG":
    {
        private _TAG = uiNamespace getVariable ["ENH_BriefingEditor_SelectedTAG", "Linebreak"];

        #define BRIEFINGTEXT ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT)
        #define VALUE1 ctrlText CTRL(IDC_BRIEFINGEDITOR_FIRSTPARAMVALUE)
        #define VALUE2 ctrlText CTRL(IDC_BRIEFINGEDITOR_SECONDPARAMVALUE)
        #define VALUE3 ctrlText CTRL(IDC_BRIEFINGEDITOR_THIRDPARAMVALUE)
        #define COLORHTML CTRL(IDC_BRIEFINGEDITOR_COLORS) lbData lbCurSel CTRL(IDC_BRIEFINGEDITOR_COLORS)
        #define FONT CTRL(IDC_BRIEFINGEDITOR_FONTS) lbText lbCurSel CTRL(IDC_BRIEFINGEDITOR_FONTS)
        #define MARKER CTRL(IDC_BRIEFINGEDITOR_MARKERS) lbData lbCurSel CTRL(IDC_BRIEFINGEDITOR_MARKERS)

        private _chars = BRIEFINGTEXT splitString "";
        ctrlTextSelection CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) params ["_start", "_length", "_text"];

        // Exit if text is empty and tag is not image
        if (_text == "" && _TAG != "Linebreak") exitWith {};

        private _textNew = switch _TAG do
        {
            case "Linebreak":
            {
                "<br/>";
            };
            case "Marker":
            {
                format ["<marker name='%1'>%2</marker>", MARKER, _text];
            };
            case "Image":
            {
                format ["<img image='%1' width='%2' height='%3'/>", VALUE1, parseNumber VALUE2, parseNumber VALUE3];
            };
            case "Font":
            {
                format ["<font color='%1' size='%2' face='%3'>%4</font>", COLORHTML, VALUE1, FONT, _text];
            };
            case "Execute":
            {
                format ["<execute expression='%1'>%2</execute>", VALUE1, _text];
            };
            case "executeClose":
            {
                format ["<executeClose expression='%1'>%2</executeClose>", VALUE1, _text];
            };
        };

        // Handle the case when selection was made from right to left
        if (_length < 0) then
        {
            _start = _start - abs _length;
        };

        private _end = _start + abs _length - 1;

        // Insert new text right behind selection
        _chars insert [_end + 1, [_textNew]];

        // Delete selected text
        _chars deleteRange [_start, count _text];

        CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText (_chars joinString "");
        CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetTextSelection [_start, count _textNew];
        ctrlSetFocus CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT);
    };
    case "handleTemplates":
    {
        private _title = ctrlText CTRL(IDC_BRIEFINGEDITOR_TITLE);
        private _subject = ctrlText CTRL(IDC_BRIEFINGEDITOR_SUBJECT);
        private _text = ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT);
        private _templates = profileNamespace getVariable ["ENH_BriefingEditor_Templates", []];
        private _ctrlTemplateList = CTRL(IDC_BRIEFINGEDITOR_TEMPLATES);

        switch _param do
        {
            case "create":
            {
                private _templateData =
                [
                    _title,
                    _text,
                    _subject,
                    systemTime
                ];
                profileNamespace setVariable ["ENH_BriefingEditor_Templates", _templates + [_templateData]];
                saveProfileNamespace;
                [nil, "handleTemplates", "fillTemplatesList"] call ENH_fnc_briefingEditor;
            };
            case "delete":
            {
                private _selectedIndex = lbCurSel _ctrlTemplateList;
                if (_selectedIndex == -1) exitWith {};
                _templates deleteAt _selectedIndex;
                profileNamespace setVariable ["ENH_BriefingEditor_Templates", _templates];
                saveProfileNamespace;
                [nil, "handleTemplates", "fillTemplatesList"] call ENH_fnc_briefingEditor;
            };
            case "apply":
            {
                private _selectedIndex = lbCurSel _ctrlTemplateList;
                if (_selectedIndex == -1) exitWith {};

                private _templateData = _templates select _selectedIndex;
                _templateData params [["_title", ""], ["_text", ""], ["_subject", "Diary"]];
                CTRL(IDC_BRIEFINGEDITOR_TITLE) ctrlSetText _title;
                CTRL(IDC_BRIEFINGEDITOR_SUBJECT) ctrlSetText _subject;
                CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText _text;
            };
            case "fillTemplatesList":
            {
                // Clear list and refill it with updated templates from profileNamespace
                lbClear _ctrlTemplateList;

                {
                    _x params [["_title", ""], ["_text", ""], ["_subject", "Diary"], ["_t", systemTime]];
                    _t = [_t] call ENH_fnc_systemTimeFormatted;
                    _ctrlTemplateList lbAdd _title;
                    _ctrlTemplateList lbSetTextRight [_forEachIndex, _t];
                    _ctrlTemplateList lbSetTooltip [_forEachIndex, format ["Date Created: %1\nSubject: %2\nTitle: %3\nText: %4", _t, _subject, _title, _text]];
                } forEach (profileNamespace getVariable ["ENH_BriefingEditor_Templates", []]);
            };
        };
    };
};
