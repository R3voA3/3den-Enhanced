/*
   Author: Revo

   Description:
   Retrieves all information from the Briefing Editor and copies it to player's clipboard in an useable format.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

#define GET_CONTROL(IDD,IDC) ((findDisplay IDD) displayCtrl IDC)

private _briefingText = ctrlText GET_CONTROL(50000,10);
private _subject = ctrlText GET_CONTROL(50000,20);
private _title = ctrlText GET_CONTROL(50000,30);



private _innerArray = format ["%1",[_title,_briefingText]];
private _outerArray = format ["%1,%2",str _subject,_innerArray];

if !(_subject isEqualTo "Diary") then//If user uses a non default subject, create it and export the code for it
{
   private _subjectCreate = format ["0 = player createDiarySubject [""%1"",""%1""]",_subject];
   private _briefingCreate = format ["0 = player createDiaryRecord [%1];",_outerArray];
   copyToClipboard (_subjectCreate + endl + _briefingCreate);
}
else
{
   copyToClipboard format ["0 = player createDiaryRecord [%1];",_outerArray];
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true