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
'ONLOAD' call ENH_fnc_3denRadio_toggleRadio;

//Enable session timer
[] spawn ENH_fnc_sessionTimer;

//Initialize ambient animations
call ENH_fnc_initAmbientAnimationsInEditor;

true