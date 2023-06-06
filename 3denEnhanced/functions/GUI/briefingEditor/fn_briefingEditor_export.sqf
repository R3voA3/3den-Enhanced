/*
  Author: R3vo

  Description:
  Retrieves all information from the Briefing Editor and copies it to player's clipboard in an useable format.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

disableSerialization;

private _display = uiNamespace getVariable ["ENH_BriefingEditor_Display", displayNull];
private _text = ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT);
private _subject = ctrlText CTRL(IDC_BRIEFINGEDITOR_SUBJECT);
private _title = ctrlText CTRL(IDC_BRIEFINGEDITOR_TITLE);
private _showTitle = [true, false] select (lbCurSel CTRL(IDC_BRIEFINGEDITOR_SHOWTITLE));

if (([_text, _subject, _title] find "") > -1) exitWith {false};

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

_export = "";
if !(_subject isEqualTo "Diary") then //If user uses a non default subject, create it and export the code for it
{
  private _createSubject = format ["player createDiarySubject [""%1"", ""%1""];", _subject];
  _createBriefing = _createSubject + endl + _createBriefing;
};

_createBriefing = "//Code (SQF)" + endl + endl + _createBriefing + endl + endl + "//Raw Text (Briefing Attribute, Task Description)" + endl + endl + (_text trim ["""", 0]);

uiNamespace setVariable ["display3DENCopy_data", [localize "ENH_BRIEFINGEDITOR_EXPORT", _createBriefing]];
_display createDisplay "display3denCopy";