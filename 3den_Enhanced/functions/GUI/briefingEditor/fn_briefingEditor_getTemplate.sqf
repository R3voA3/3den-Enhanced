/*  Author: Revo

   Description:
   Retrieves the template information and fills the editor with its data.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true
*/

#define GET_CONTROL(IDD,IDC) ((findDisplay IDD) displayCtrl IDC)

private _ctrl = param [0,controlNull,[controlNull]];
private _index = param [1,0,[0]];

private _briefingTitle = _ctrl lbText _index;
private _briefingText = _ctrl lbData _index;

GET_CONTROL(50000,30) ctrlSetText _briefingTitle;
GET_CONTROL(50000,20) ctrlSetText "Diary";//Set it to diary by default
GET_CONTROL(50000,10) ctrlSetText _briefingText;

true