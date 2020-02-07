/*
   Author: R3vo

   Date: 2019-05-24

   Description:
   Used by the ENH_ENH_ScenarioAttributesManager_TemplateData GUI. 
   Removes currently selected item from template listbox.
   
   Parameter(s):
   0: CONTROL - Control button

   Returns:
   BOOLEAN: true
*/
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _ctrlLB = _display displayCtrl 1501;

_ctrlLB lbDelete (lbCurSel _ctrlLB);

true