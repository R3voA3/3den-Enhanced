/*
   Author: R3vo

   Date: 2019-06-20

   Description:
   Used by ENH_BriefingEditor GUI. Triggers when "Add TAG" button is clicked.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

disableSerialization;

params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;

private _ctrlFirstParamValue = _display displayCtrl 210;
private _ctrlSecondParamValue = _display displayCtrl 230;
private _ctrlThirdParamValue = _display displayCtrl 250;
private _ctrlBriefingValue = _display displayCtrl 10;

#define SELECTEDINDEX lbCurSel (_display displayCtrl 90)

#define BRIEFINGTEXT ctrlText _ctrlBriefingValue
#define VALUE1 ctrlText _ctrlFirstparamValue
#define VALUE2 ctrlText _ctrlSecondparamValue
#define VALUE3 ctrlText _ctrlThirdparamValue

switch (SELECTEDINDEX) do
{
	case 0:
	{
		_ctrlBriefingValue ctrlSetText BRIEFINGTEXT + "<br></br>";
	};
	case 1:
	{
		#define MARKER (_display displayCtrl 60) lbData lbCurSel (_display displayCtrl 60)
		_ctrlBriefingValue ctrlSetText BRIEFINGTEXT + format ["<marker name='%1'>%2</marker>",MARKER,VALUE1];
	};
	case 2:
	{
		_ctrlBriefingValue ctrlSetText BRIEFINGTEXT + format ["<img image='%1' width='%2' height='%3'/>",VALUE1,parseNumber VALUE2,parseNumber VALUE3];
	};
	case 3:
	{
		#define COLOURHTML (_display displayCtrl 100) lbData lbCurSel (_display displayCtrl 100)
		#define FONT (_display displayCtrl 70) lbText lbCurSel (_display displayCtrl 70)
		_ctrlBriefingValue ctrlSetText BRIEFINGTEXT + format ["<font color='%1' size='%2' face='%3'>%4</font>",COLOURHTML,VALUE1,FONT,VALUE2];
	};
	case 4:
	{
		_ctrlBriefingValue ctrlSetText BRIEFINGTEXT + format ["<execute expression='%1'>%2</execute>",VALUE1,VALUE2];
		
	};
	case 5:
	{
		_ctrlBriefingValue ctrlSetText BRIEFINGTEXT + format ["<executeClose expression='%1'>%2</executeClose>",VALUE1,VALUE2];
		
	};
};

true