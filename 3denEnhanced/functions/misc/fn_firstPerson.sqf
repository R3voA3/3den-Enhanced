/*
   Author: R3vo

   Date: 2020-01-18

   Description:
   Moves 3DEN camera to eye position of selected object.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

(uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") params ["","_selectedEntity"];

move3DENCamera [eyePos _selectedEntity,false]; 

get3DENCamera setDir getDir _selectedEntity;

true