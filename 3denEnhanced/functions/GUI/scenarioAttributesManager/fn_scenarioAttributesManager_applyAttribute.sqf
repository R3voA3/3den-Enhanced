/*
   Author: R3vo

   Date: 2019-05-24

   Description:
   Used by the ENH_ENH_ScenarioAttributesManager_TemplateData GUI.
   Applies attribute selected in tree view controls via button.

   Parameter(s):
   0: CONTROL - Button

   Returns:
   BOOLEAN: true / false
*/

//params ["_ctrlTV", "_tvPath"];
params ["_ctrlButton"];

private _ctrlTV = ctrlParent _ctrlButton displayCtrl 1500;
private _tvPath = tvCurSel _ctrlTV;

if (_tvPath isEqualTypeArray [0] || _tvPath isEqualTo []) exitWith {false};

//Data is string, we need an array, so compiling it is
_attributeData = call compile (_ctrlTV tvData _tvPath);//["Section","PropertyName",value];

set3DENMissionAttributes [_attributeData];

[format ["Attribute %1 was set to %2",_attributeData # 1, _attributeData # 2]] call BIS_fnc_3DENNotification;

true