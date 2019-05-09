/*
   Author: Revo

   Description:
   Adds an interactive marker to the briefing.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true
*/

#define GET_CONTROL(IDD,IDC) ((findDisplay IDD) displayCtrl IDC)
params ["_ctrl", "_selectedIndex"];

private _briefingText = ctrlText GET_CONTROL(50000,10);  
private _markerVarName = _ctrl lbData _selectedIndex;
private _markerText = _ctrl lbText _selectedIndex;

GET_CONTROL(50000,10) ctrlSetText (_briefingText + format ["<marker name='%1'>%2</marker>",_markerVarName,_markerText]);

ctrlSetFocus GET_CONTROL(50000,10);

true