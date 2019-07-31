/*
   Author: R3vo

   Date: 2019-07-30

   Description:
   Gets current profile color.

   Parameter(s):
   0: BOOLEAN - If true, alpha value will be set to one, ignoring profile setting. Default: true

   Returns:
   ARRAY - Array in format [r,g,b,a]
*/

params [["_alphaTo1",true]];

private _return = [
	profilenamespace getVariable ['GUI_BCG_RGB_R',0.77],
	profilenamespace getVariable ['GUI_BCG_RGB_G',0.51],
	profilenamespace getVariable ['GUI_BCG_RGB_B',0.08],
	profilenamespace getVariable ['GUI_BCG_RGB_A',0.08]
];

if (_alphaTo1) then {_return set [3,1]};

_return
