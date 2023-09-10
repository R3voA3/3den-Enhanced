/*
  Author: R3vo

  Description:
  Used by the ENH_TexturFinder GUI. Searches the config file for useable textures.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

startLoadingScreen [""];

disableSerialization;
private _display = findDisplay IDD_TEXTUREFINDER;

CTRL(IDC_TEXTUREFINDER_SEARCH) ctrlEnable false;
CTRL(IDC_TEXTUREFINDER_TEXTURELIST) ctrlEnable false;
CTRL(IDC_TEXTUREFINDER_COLLAPSEALL) ctrlEnable false;
CTRL(IDC_TEXTUREFINDER_EXPANDALL) ctrlEnable false;

//Focus Search CTRL + F
_display displayAddEventHandler ["keyDown",
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 33 && _ctrl && !_shift) then
  {
    ctrlSetFocus (_display displayCtrl IDC_TEXTUREFINDER_SEARCH);
  };
}];

//Update preview
_display displayCtrl IDC_TEXTUREFINDER_TEXTURELIST ctrlAddEventHandler ["treeMouseMove",
{
  _this call ENH_fnc_textureFinder_updatePreview;
}];

_display displayCtrl IDC_TEXTUREFINDER_TEXTURELIST ctrlAddEventHandler ["treeMouseHold",
{
  _this call ENH_fnc_textureFinder_updatePreview;
}];

//Collapse
_display displayCtrl IDC_TEXTUREFINDER_COLLAPSEALL ctrlAddEventHandler ["buttonClick",
{
  params ["_ctrlButton"];
  tvCollapseAll (ctrlParent _ctrlButton displayCtrl IDC_TEXTUREFINDER_TEXTURELIST)
}];

//Expand
_display displayCtrl IDC_TEXTUREFINDER_EXPANDALL ctrlAddEventHandler ["buttonClick",
{
  params ["_ctrlButton"];
  tvExpandAll (ctrlParent _ctrlButton displayCtrl IDC_TEXTUREFINDER_TEXTURELIST)
}];

//Copy path
_display displayCtrl IDC_TEXTUREFINDER_TEXTURELIST ctrlAddEventHandler ["keyDown",
{
  params ["_ctrlTV", "_key", "", "_ctrl"];

  if (_key isEqualTo 46 && _ctrl) then
  {
    private _path = _ctrlTV tvdata (tvCurSel _ctrlTV);
    if (_path isEqualTo "") exitWith {};
    copyToClipboard str _path;
    ["ENH_DataCopied"] call BIS_fnc_3DENNotification;
  };
}];

if (uiNamespace getVariable ["ENH_TextureFinder_Textures", []] isEqualTo []) then
{
  private _textureData = [];
  allAddonsInfo apply
  {
    _textureData append addonFiles [_x#0, ".jpg"];
    _textureData append addonFiles [_x#0, ".paa"];
  };
  uiNamespace setVariable ["ENH_TextureFinder_Textures", _textureData];
};

[] call ENH_fnc_textureFinder_fillList;