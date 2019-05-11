/*
   Author: Revo

   Description:
   Closes the briefing editor and creates a history.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true
*/

#define GET_CONTROL(IDD,IDC) ((findDisplay IDD) displayCtrl IDC)
private _savedTemplates = [];
//Create history of last input when closing the display
profileNamespace setVariable
[
	"Enh_briefingEditor_history",
	[
      ctrlText GET_CONTROL(50000,30),//Briefing Title
      ctrlText GET_CONTROL(50000,20),//Subject Text
		ctrlText GET_CONTROL(50000,10)//Briefing Text
	]
];

//Update template list
for "_index" from 0 to (lbSize GET_CONTROL(50000,80) - 1) do
{
   private _briefingTitle = GET_CONTROL(50000,80) lbText _index;
   private _briefingText = GET_CONTROL(50000,80) lbData _index;
   _savedTemplates pushBack [_briefingTitle,_briefingText];
};

profileNamespace setVariable ["Enh_briefingEditor_templates",_savedTemplates];

(findDisplay 50000) closeDisplay 1;

['ShowPanelLeft',true] call BIS_fnc_3DENInterface;
['ShowPanelRight',true] call BIS_fnc_3DENInterface;

true