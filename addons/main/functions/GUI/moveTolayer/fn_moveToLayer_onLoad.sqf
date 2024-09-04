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

#include "\x\enh\addons\main\script_component.hpp"

disableSerialization;

params ["_display"];

private _ctrlTV = CTRL(IDC_MOVETOLAYER_TREE);

{
    private _layerID = _x;
    private _index = _ctrlTV tvAdd [[], _layerID get3DENAttribute "name" select 0];
    _ctrlTV tvSetValue [[_index], _layerID]; //3DEN ID

    //Define icon
    private _visible = (_layerID get3DENAttribute "Visibility" select 0);
    private _canTransform = (_layerID get3DENAttribute "Transformation" select 0);

    private _icon = "\a3\3den\data\cfg3den\layer\icon_ca.paa";

    if (!_visible && _canTransform) then {_icon = "\a3\3den\data\cfg3den\layer\iconhidden_ca.paa"};
    if (_visible && !_canTransform) then {_icon = "\a3\3den\data\cfg3den\layer\icondisabled_ca.paa"};
    if (!_visible && !_canTransform) then {_icon = "\a3\3den\data\cfg3den\layer\iconhiddendisabled_ca.paa"};

    _ctrlTV tvSetPictureRight [[_index], _icon];
} forEach (all3DENEntities # 6);

_ctrlTV tvSortAll [[], false];

//Focus search box
ctrlSetFocus (ctrlParent _ctrlTV displayCtrl IDC_MOVETOLAYER_SEARCH);

//Handle search button
CTRL(IDC_MOVETOLAYER_SEARCH) ctrlAddEventHandler ["EditChanged",
{
    params ["_ctrlEdit", "_newText"];

    private _image = [TEXTURE_SEARCH_END, TEXTURE_SEARCH_START] select (_newText == "");

    ctrlParent _ctrlEdit displayCtrl IDC_MOVETOLAYER_BUTTONSEARCH ctrlSetText _image;
}];

//Handle search button
CTRL(IDC_MOVETOLAYER_BUTTONSEARCH) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];

    //Change search button icon and clear edit control to reset tree view filter
    ctrlParent _ctrlButton displayCtrl IDC_MOVETOLAYER_SEARCH ctrlSetText "";
    _ctrlButton ctrlSetText TEXTURE_SEARCH_START;
}];
