/*
  Author: R3vo

  Date: 2021-05-15

  Description:
  Switches alpha value of markers in Eden Editor between 1 and original value.

  Parameter(s):
  -

  Returns:
  -
*/

private _markers = all3DENEntities # 5;
if (get3DENActionState "ToggleMap" == 0 || _markers isEqualTo []) exitWith {};
if (uiNamespace getVariable ["ENH_MarkerAlpha_NotToggled", true]) then
{
  private _oldValues = _markers apply {[_x get3DENAttribute "markerName" select 0, _x get3DENAttribute "Alpha" select 0]};
  _oldValues apply {_x # 0 set3DENAttribute ["Alpha", 1]};

  uiNamespace setVariable ["ENH_MarkerAlpha_OldValues", _oldValues];
  uiNamespace setVariable ["ENH_MarkerAlpha_NotToggled", false];
}
else
{
  (uiNamespace getVariable ["ENH_MarkerAlpha_OldValues", []]) apply
  {
    _x params ["_marker", "_oldValue"];
    _marker set3DENAttribute ["Alpha", _oldValue]
  };

  uiNamespace setVariable ["ENH_MarkerAlpha_OldValues", []];
  uiNamespace setVariable ["ENH_MarkerAlpha_NotToggled", true];
};