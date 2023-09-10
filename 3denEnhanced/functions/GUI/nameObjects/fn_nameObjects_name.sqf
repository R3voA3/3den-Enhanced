/*
  Author: R3vo

  Description:
  Names all selected entities. Name is taken from the ENH_nameObjects dialog.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

disableSerialization;
private _display = findDisplay IDD_NAMEOBJECTS;
private _input = param [0, "UNNAME", [""]];
private _toName = [["Object", "Logic", "Trigger", "Marker"]] call ENH_fnc_all3DENSelected;

if (_input == "UNNAME") then
{
  [localize "STR_ENH_NAMEOBJECTS"] collect3DENHistory
  {
    {
      _x set3DENAttribute ["Name", ""];
    } forEach _toName;
  };
}
else
{
  private _varName = ctrlText CTRL(IDC_NAMEOBJECTS_VARIABLENAME);
  private _index = parseNumber ctrlText CTRL(IDC_NAMEOBJECTS_INDEXSTART);
  profileNamespace setVariable ["ENH_NameObjects_LastVarName", _varName];
  _varName = _varName + "_";

  [localize "STR_ENH_NAMEOBJECTS"] collect3DENHistory
  {
    {  //Set name attribute for object. For marker set markerName attribute
      _x set3DENAttribute ["Name", _varName + (str _index)];
      _x set3DENAttribute ["markerName", _varName + (str _index)];
      _index = _index + 1;
    } forEach _toName;
  };
};

_display closeDisplay 0;
["ENH_actionPerformed"] call BIS_fnc_3DENNotification;