/*
  Author: R3vo

  Date: 2019-06-05

  Description:
  Is called by Eden event handler onMissionPreviewEnd.

  Parameter(s):
  -

  Returns:
  -
*/

//Enable 3DEN Radio
call ENH_fnc_3DENRadio_toggleRadio;

//Enable Minimap
"init" call ENH_fnc_3DENMinimap;