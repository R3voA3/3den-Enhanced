/*
   Author: Revo

   Description:
   Initialises the GUI "Enh_GridPattern";

   Parameter(s):
   -

   Returns:
   BOOLEAN - true
*/


#define GET_CTRL(IDC) (_disp displayCtrl IDC)

private ["_disp","_numRows","_numColumns","_spacingX","_spacingY","_save"];

disableSerialization;
_disp = findDisplay 160000;

_numRows = parseNumber ctrlText GET_CTRL(1400);
_numColumns = parseNumber ctrlText GET_CTRL(1401);
_spacingX = parseNumber ctrlText GET_CTRL(1402);
_spacingY = parseNumber ctrlText GET_CTRL(1403);

_save = profileNamespace getVariable ["Enh_gridPattern_values",["0","0","0","0"]];//rows,colums,x,y

GET_CTRL(1400) ctrlSetText (_save # 0);
GET_CTRL(1401) ctrlSetText (_save # 1);
GET_CTRL(1402) ctrlSetText (_save # 2);
GET_CTRL(1403) ctrlSetText (_save # 3);

true