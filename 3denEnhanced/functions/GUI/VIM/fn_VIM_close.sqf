/*
  Author: R3vo

  Date: 2021-06-28

  Description:
  Prevents the vehicle inventory manager from being accidentally closed and shows a warning.

  Parameter(s):
  -

  Returns:
  -
*/

#define DISPLAY_VIM (uiNamespace getVariable "ENH_Display_VIM")

private _currentValue = true call ENH_fnc_VIM_applyAttribute;
private _setValue = (ENH_VIM_target get3DENAttribute "ammoBox") # 0;

//Check if saved attribute value is equal to the content of the inventory list
if (_currentValue isNotEqualTo _setValue) then
{
  [
    localize "STR_ENH_VIM_EXIT_TEXT",
    localize "STR_CFG_MARKERS_WARNING",
    [
      nil,
      {
        [] spawn
        {
          waitUntil {!isNull DISPLAY_VIM};
          DISPLAY_VIM closeDisplay 1
        }
      }
    ],
    nil,
    "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\save_ca.paa",
    DISPLAY_VIM
  ] call BIS_fnc_3DENShowMessage;
}
else
{
  DISPLAY_VIM closeDisplay 1;
};