/*
   Author: Revo

   Description:
   Adds an image to the briefing.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/
#define GET_CONTROL(IDD,IDC) ((findDisplay IDD) displayCtrl IDC)

private _path = ctrlText GET_CONTROL(50000,40);
private _briefingText = ctrlText GET_CONTROL(50000,10);
private _width = ctrlText GET_CONTROL(50000,50);
private _height = ctrlText GET_CONTROL(50000,90);

if (_path isEqualTo "") exitWith {};

GET_CONTROL(50000,10) ctrlSetText (_briefingText + format ["<img image='%1' width='%2' height='%3'/>",_path,_width,_height]);

ctrlSetFocus GET_CONTROL(50000,10);

true
