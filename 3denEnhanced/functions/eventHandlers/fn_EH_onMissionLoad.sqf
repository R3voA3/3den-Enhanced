/*
   Author: R3vo

   Date: 2019-06-05

   Description:
   Is called by Eden event handler onMissionLoad.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

//Enable 3den Radio
'ONLOAD' call ENH_fnc_3DENRadio_toggleRadio;

//Enable session timer
[] spawn ENH_fnc_sessionTimer;

//Initialize ambient animations
call ENH_fnc_initAmbientAnimationsInEditor;

//Collapse left tree view (entity list). A small delay is needed to let the list fully load first
if (profileNamespace getVariable ['ENH_CollapseEntityList',false]) then
{
   [] spawn
   {
      sleep 0.1;
      ["collapseEntityList"] call bis_fnc_3DENInterface;
   };
};

true