/*
  Author: R3vo

  Date: 2021-07-18

  Description:
  Updates the list according to the filter.

  Parameter(s):
  0: CONTROL
  1: NUMBER - Selected index

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

params ["_ctrlToolbox", "_index"];

private _display = ctrlParent _ctrlToolbox;
private _ctrlListbox = _display displayCtrl IDC_CREATEOBJECT_LIST;

private _nameProperty = ["displayName", "name"] select _index;
private _pictureProperty = ["editorPreview", "icon"] select _index;
private _confgName = ["CfgVehicles", "CfgMarkers"] select _index;
private _condition = ["getNumber (_x >> 'scope') == 1", "getNumber (_x >> 'scope') == 0"] select _index;

lbClear _ctrlListbox;

_classes = _condition configClasses (configFile >> _confgName);
{
  private _row = _ctrlListbox lbAdd configName _x;
  _ctrlListbox lbSetTooltip [_row, getText (_x >> _nameProperty)];
  private _picture = getText (_x >> _pictureProperty);
  if (fileExists _picture) then
  {
    _ctrlListbox lbSetPictureRight [_row, _picture];
  };
} forEach _classes;