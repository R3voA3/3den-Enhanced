/*
  Author: R3vo

  Date: 2020-01-16

  Description:
  Sets 3DEN camera parameters according to selected list Box entry.

  Parameter(s):
  0: CONTROL - List Box
  1: NUMBER - Selected index

  Returns:
  -
*/

params ["_ctrlLnB","_row"];

private _data = call compile (_ctrlLnB lnbData [_row,0]);

_data params ["_world","_camPosition","_camVectorDir","_camVectorUp"];

move3DENCamera [_camPosition,true];
get3DENCamera setVectorDirAndUp [_camVectorDir,_camVectorUp];