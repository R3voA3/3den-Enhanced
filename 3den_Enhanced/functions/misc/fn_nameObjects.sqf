/*
   Author: Revo

   Description:
   Names all selected entities. Name is taken from the Enh_nameObjects dialog.

   Parameter(s):
   -

   Returns:
   BOOLEAN - true / false
*/

#define DISPLAY (findDisplay 80000)
#define GET_CTRL(IDC) (DISPLAY displayCtrl IDC)

if !(is3DEN) exitWith {false};

private _input    = param [0,"UNNAME",[""]];
private _objects  = get3DENSelected "Object";
private _markers  = get3DENSelected "Marker";
private _triggers = get3DENSelected "Trigger";
private _logics   = get3DENSelected "Logic";
private _toName = _objects + _markers + _triggers + _logics;

if (count _toName == 0) exitWith {false; DISPLAY closeDisplay 0};

if (_input == "UNNAME") then
{
   collect3DENHistory
   {
      {
         _x set3DENAttribute ["Name",""];
      } forEach _toName;
   };
}
else
{
   private _index = parseNumber (ctrlText  GET_CTRL(1100));
   profileNamespace setVariable ["Enh_nameObjects_lastIndex",str _index];

   private _varName  = ctrlText GET_CTRL(1000);
   profileNamespace setVariable ["Enh_nameObjects_lastVarName",_varName];
   _varName = _varName + "_";

   collect3DENHistory
   {
      {
         _x set3DENAttribute ["Name",_varName + (str _index)];
         _index = _index + 1;
      } forEach _toName;
   };
};

DISPLAY closeDisplay 0;
["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true