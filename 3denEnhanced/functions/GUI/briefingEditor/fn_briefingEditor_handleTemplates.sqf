/*
  Author: R3vo

  Date: 2019-06-21

  Description:
  Handles template operations.

  Parameter(s):
  0: STRING - Mode
  1: CONTROL - Any control

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;

params [["_mode", ""], "_ctrl"];

private _display = ctrlParent _ctrl;
private _title = ctrlText CTRL(IDC_BRIEFINGEDITOR_TITLE);
private _subject = ctrlText CTRL(IDC_BRIEFINGEDITOR_SUBJECT);
private _text = ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT);
private _templates = profileNamespace getVariable ["ENH_briefingEditor_templates", []];
private _ctrlTemplateList = CTRL(IDC_BRIEFINGEDITOR_TEMPLATES);

switch (_mode) do
{
  case "add":
  {
    private _templateData =
    [
      _title,
      _text,
      _subject,
      systemTime
    ];
    profileNamespace setVariable ["ENH_briefingEditor_templates", _templates + [_templateData]];
  };
  case "remove":
  {
    private _selectedIndex = lbCurSel _ctrlTemplateList;
    if (_selectedIndex == -1) exitWith {};
    _templates deleteAt _selectedIndex;
    profileNamespace setVariable ["ENH_briefingEditor_templates", _templates];
  };
  case "load":
  {
    private _selectedIndex = lbCurSel _ctrlTemplateList;
    if (_selectedIndex == -1) exitWith {};

    private _templateData = _templates select _selectedIndex;
    _templateData params [["_title", ""], ["_text", ""], ["_subject", "Diary"]];
    CTRL(IDC_BRIEFINGEDITOR_TITLE) ctrlSetText _title;
    CTRL(IDC_BRIEFINGEDITOR_SUBJECT) ctrlSetText _subject;
    CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) ctrlSetText _text;
    CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT) call ENH_fnc_briefingEditor_htmlHighlight;
  };
};

//Clear list and refill it with updated templates from profileNamespace
lbClear _ctrlTemplateList;

{
  _x params [["_title", ""], ["_text", ""], ["_subject", "Diary"], ["_t", systemTime]];
  _t = [_t] call ENH_fnc_systemTimeFormatted;
  _ctrlTemplateList lbAdd _title;
  _ctrlTemplateList lbSetTextRight [_forEachIndex, _t];
  _ctrlTemplateList lbSetTooltip [_forEachIndex, format ["Date Created: %1\nSubject: %2\nTitle: %3\nText: %4", _t, _subject, _title, _text]];
} forEach (profileNamespace getVariable ["ENH_briefingEditor_templates", []]);