/*
   Author: R3vo

   Date:  2019-05-24

   Description:
   Used by the Enh_Enh_ScenarioAttributesManager_TemplateData GUI.
   Applies the selection attribute when tvTree is double clicked.

   Parameter(s):
   0: CONTROL - Tree view

   Returns:
   BOOLEAN: true
*/

params ["_ctrlTV", "_selectionPath"];

if (_selectionPath isEqualTypeArray [0]) exitWith {false};

//Data is string, we need an array, so compiling it is
_attributeData = call compile (_ctrlTV tvData _selectionPath);//["Section","PropertyName",value];

set3DENMissionAttributes [_attributeData];

[format ["Attribute %1 was set to %2",_attributeData # 1, _attributeData # 2]] call BIS_fnc_3DENNotification;

true