/*
   Author: R3vo

   Date: 2019-05-25

   Description:
   Used by the ENH_ENH_ScenarioAttributesManager GUI.
   Applies selected template to current mission.

   Parameter(s):
   0: CONTROL - Control button

   Returns:
   BOOLEAN: true / false
*/

params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _ctrlLB	= _display displayCtrl 1501;
private _selectedTemplate = lbCurSel _ctrlLB;

if (_selectedTemplate isEqualTo -1) exitWith {false};

//Data is string but needs to be array
_data = call compile (_ctrlLB lbData _selectedTemplate);

//We don't need the title and description of the template, only the attributes
_data = _data # 2;

collect3DENHistory 
{
   set3DENMissionAttributes _data;
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true
   