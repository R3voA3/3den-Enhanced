/*
   Author: R3vo

   Date: 2019-05-24

   Description:
   Used by the ENH_ENH_ScenarioAttributesManager_TemplateData GUI. 
   Used to set the title and description of the template.

   Parameter(s):
   0: CONTROL - Control button

   Returns:
   BOOLEAN: true
*/

params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;

ENH_ScenarioAttributesManager_TemplateTitle = ctrlText (_display displayCtrl 1400);
ENH_ScenarioAttributesManager_TemplateDescription = ctrlText (_display displayCtrl 1401);

//Close display ENH_ENH_ScenarioAttributesManager_TemplateData and wait for the parent display to be available again
_display closeDisplay 1;

[] spawn 
{
	waitUntil {!(isNull findDisplay 160000)};

	private _display = findDisplay 160000;
	private _ctrlLB = _display displayCtrl 1501;
	
	private _attributeValues = call ENH_fnc_scenarioAttributesManager_getScenarioAttributes;


	private _index = _ctrlLB lbAdd ENH_ScenarioAttributesManager_TemplateTitle;
	_ctrlLB lbSetTooltip [_index,ENH_ScenarioAttributesManager_TemplateDescription];

	//Save Title, Description and actual scenario attributes
	_ctrlLB lbSetData [_index,str [ENH_ScenarioAttributesManager_TemplateTitle,ENH_ScenarioAttributesManager_TemplateDescription,_attributeValues]];
	lbSort [_ctrlLB,"DESC"];
};

true