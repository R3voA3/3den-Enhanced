/*
   Author: R3vo

   Date: 2019-06-05

   Description:
   Is called by Eden event handler onMissionPreviewEnd.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

//Enable 3den Radio
'ONLOAD' call ENH_fnc_3DENRadio_toggleRadio;

//Enable session timer
[] spawn ENH_fnc_sessionTimer;

true