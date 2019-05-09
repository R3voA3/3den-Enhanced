/*
   Author: Revo

   Description:
   Inits the Colour Picker GUI (Enh_colourPicker.hpp)

   Parameter(s):
   -
   Returns:
   BOOLEAN - true
*/

disableSerialization;

private _display = findDisplay 110000;
//Setup sliders
{
	_x sliderSetRange [0,1];
	_x sliderSetSpeed [0.1,0.1];
	_x sliderSetPosition 0.5;
} forEach [_display displayCtrl 1900,_display displayCtrl 1901,_display displayCtrl 1902,_display displayCtrl 1903];

//Setup edit boxes
{
	_x ctrlSetText "0.5";
} forEach [_display displayCtrl 1400,_display displayCtrl 1401,_display displayCtrl 1402,_display displayCtrl 1403];

true