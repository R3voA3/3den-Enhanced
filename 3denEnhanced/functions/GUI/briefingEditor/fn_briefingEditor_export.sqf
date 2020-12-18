/*
  Author: R3vo

  Description:
  Retrieves all information from the Briefing Editor and copies it to player's clipboard in an useable format.

  Parameter(s):
  0: CONTROL - Button control

  Returns:
  BOOLEAN: true
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;

params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _text = ctrlText CTRL(IDC_BRIEFINGEDITOR_BRIEFINGTEXT);
private _subject = ctrlText CTRL(IDC_BRIEFINGEDITOR_SUBJECT);
private _title = ctrlText CTRL(IDC_BRIEFINGEDITOR_TITLE);
private _showTitle = [true,false] select (lbCurSel CTRL(IDC_BRIEFINGEDITOR_SHOWTITLE));

if (([_text,_subject,_title] find "") > -1) exitWith {false};

private _createBriefing = format
[
  "0 = player createDiaryRecord [""%1"",[""%2"",""%3""],%4,""%5"",%6];",
  _subject,
  _title,
  _text,
  "taskNull",
  "",
  _showTitle
];

if !(_subject isEqualTo "Diary") then//If user uses a non default subject, create it and export the code for it
{
  private _createSubject = format ["0 = player createDiarySubject [""%1"",""%1""];",_subject];
  copyToClipboard (_createSubject + endl + _createBriefing);
}
else
{
  copyToClipboard _createBriefing;
};

["ENH_DataCopied"] call BIS_fnc_3DENNotification;

true