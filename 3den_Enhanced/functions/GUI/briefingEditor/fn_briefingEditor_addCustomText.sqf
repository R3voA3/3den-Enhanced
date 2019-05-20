/*
   Author: Revo

   Description:
   Adds coloured text to the briefing.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

#define GET_CONTROL(IDD,IDC) ((findDisplay IDD) displayCtrl IDC)

private _text = ctrlText GET_CONTROL(50000,110);
private _colour = GET_CONTROL(50000,100) lbData (lbCurSel GET_CONTROL(50000,100));
private _expression = ctrlText GET_CONTROL(50000,120);
private _briefingText = ctrlText GET_CONTROL(50000,10);

if (_colour isEqualTo "") then {_colour = "#F5F5F5"};

if (_expression isEqualTo "") then
{
	_text = format ["<font color='%1'>%2</font color>",_colour,_text];
}
else
{
	_text = format ["<font color='%1'><execute expression='%2'>%3</execute></font color>",_colour,_expression,_text];
};

GET_CONTROL(50000,10) ctrlSetText _briefingText + _text;

true
