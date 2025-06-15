#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2022-04-11

    Description:
    Fills the listbox with existing layers, except system layers.

    Parameter(s):
    0: CONTROL - Listbox control

    Returns:
    -
*/

disableSerialization;

params ["_display"];

private _ctrlTV = CTRL(IDC_MOVETOLAYER_TREE);

{
    private _layerID = _x;
    private _index = _ctrlTV tvAdd [[], _layerID get3DENAttribute "name" select 0];
    _ctrlTV tvSetValue [[_index], _layerID]; // 3DEN ID

    // Define icon
    private _visible = (_layerID get3DENAttribute "Visibility" select 0);
    private _canTransform = (_layerID get3DENAttribute "Transformation" select 0);

    private _icon = "\a3\3den\data\cfg3den\layer\icon_ca.paa";

    if (!_visible && _canTransform) then {_icon = "\a3\3den\data\cfg3den\layer\iconhidden_ca.paa"};
    if (_visible && !_canTransform) then {_icon = "\a3\3den\data\cfg3den\layer\icondisabled_ca.paa"};
    if (!_visible && !_canTransform) then {_icon = "\a3\3den\data\cfg3den\layer\iconhiddendisabled_ca.paa"};

    _ctrlTV tvSetPictureRight [[_index], _icon];
} forEach (all3DENEntities # 6);

_ctrlTV tvSortAll [[], false];

// Focus search box
ctrlSetFocus (ctrlParent _ctrlTV displayCtrl IDC_MOVETOLAYER_SEARCH);

[CTRL(IDC_MOVETOLAYER_SEARCH), CTRL(IDC_MOVETOLAYER_BUTTONSEARCH)] call ENH_fnc_initSearchControls;
