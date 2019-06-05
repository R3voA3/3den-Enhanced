/*
   Author: R3vo

   Date:  2019-06-05

   Description:
   Is called by Eden event handler onMissionLoad.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

//Enable 3den Radio
'ONLOAD' call Enh_fnc_3denRadio_toggleRadio;

//Enable session timer
[] spawn Enh_fnc_sessionTimer;

true