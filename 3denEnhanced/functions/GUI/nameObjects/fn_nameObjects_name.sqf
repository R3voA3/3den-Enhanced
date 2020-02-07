/*
   Author: Revo

   Description:
   Names all selected entities. Name is taken from the ENH_nameObjects dialog.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

private _display = findDisplay 80000;
private _input    = param [0,"UNNAME",[""]];
private _toName = [["Object","Logic","Trigger","Marker"]] call ENH_fnc_all3DENSelected;

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
   private _varName  = ctrlText (_display displayCtrl 1000);
   private _index = parseNumber ctrlText (_display displayCtrl 1100);
   profileNamespace setVariable ["ENH_NameObjects_LastVarName",_varName];
   _varName = _varName + "_";

   collect3DENHistory
   {
      {
         _x set3DENAttribute ["Name",_varName + (str _index)];
         _index = _index + 1;
      } forEach _toName;
   };
};

_display closeDisplay 0;
["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true