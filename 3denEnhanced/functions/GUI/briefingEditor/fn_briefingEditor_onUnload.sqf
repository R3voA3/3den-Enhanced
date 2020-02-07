/*
   Author: R3vo

   Date: 2019-06-21

   Description:
   Closes the briefing editor and creates a history.

   Parameter(s):
   0: DISPLAy - ENH_BriefingEditor

   Returns:
   BOOLEAN: true
*/

disableSerialization;

params ["_display"];

#define CTRL(IDC) (_display displayCtrl IDC)

//Create history of last input when closing the display
profileNamespace setVariable
[
	"ENH_briefingEditor_history",
	[
      ctrlText CTRL(30),//Briefing Title
      ctrlText CTRL(20),//Subject Text
		ctrlText CTRL(10)//Briefing Text
	]
];

//Save templates to profileNamespace
private _ctrlLBTemplates = CTRL(80);
private _savedTemplates = [];

for "_index" from 0 to (lbSize _ctrlLBTemplates - 1) do
{
   private _briefingTitle =_ctrlLBTemplates lbText _index;
   private _briefingText = _ctrlLBTemplates lbData _index;
   _savedTemplates pushBack [_briefingTitle,_briefingText];
};

profileNamespace setVariable ["ENH_briefingEditor_templates",_savedTemplates];

['ShowPanelLeft',true] call BIS_fnc_3DENInterface;
['ShowPanelRight',true] call BIS_fnc_3DENInterface;

true