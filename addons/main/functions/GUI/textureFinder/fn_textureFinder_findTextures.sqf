#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Used by the ENH_TexturFinder GUI. Searches the config file for useable textures.

    Parameter(s):
    -

    Returns:
    -
*/

startLoadingScreen [""];

disableSerialization;
private _display = findDisplay IDD_TEXTUREFINDER;

CTRL(IDC_TEXTUREFINDER_SEARCH) ctrlEnable false;
CTRL(IDC_TEXTUREFINDER_TEXTURELIST) ctrlEnable false;
CTRL(IDC_TEXTUREFINDER_COLLAPSEALL) ctrlEnable false;
CTRL(IDC_TEXTUREFINDER_EXPANDALL) ctrlEnable false;

// Focus Search CTRL + F
_display displayAddEventHandler ["KeyDown",
{
    params ["_display", "_key", "_shift", "_ctrl"];
    if (_key isEqualTo 33 && _ctrl && !_shift) then
    {
        ctrlSetFocus CTRL(IDC_TEXTUREFINDER_SEARCH);
    };
}];

// Update preview
CTRL(IDC_TEXTUREFINDER_TEXTURELIST) ctrlAddEventHandler ["TreeMouseMove",
{
    call ENH_fnc_textureFinder_updatePreview;
}];

CTRL(IDC_TEXTUREFINDER_TEXTURELIST) ctrlAddEventHandler ["TreeMouseHold",
{
    call ENH_fnc_textureFinder_updatePreview;
}];

// Collapse
CTRL(IDC_TEXTUREFINDER_COLLAPSEALL) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];
    tvCollapseAll (ctrlParent _ctrlButton displayCtrl IDC_TEXTUREFINDER_TEXTURELIST)
}];

// Expand
CTRL(IDC_TEXTUREFINDER_EXPANDALL) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];
    tvExpandAll (ctrlParent _ctrlButton displayCtrl IDC_TEXTUREFINDER_TEXTURELIST)
}];

// Copy path
CTRL(IDC_TEXTUREFINDER_TEXTURELIST) ctrlAddEventHandler ["KeyDown",
{
    params ["_ctrlTV", "_key", "", "_ctrl"];

    if (_key isEqualTo 46 && _ctrl) then
    {
        private _path = _ctrlTV tvData (tvCurSel _ctrlTV);
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
