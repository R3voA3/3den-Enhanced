/*
  Author: R3vo

  Date: 2022-04-11

  Description:
  Fills the listbox with existing layers, except system.

  Parameter(s):
  0: CONTROL - Listbox control

  Returns:
  -
*/

disableSerialization;

params ["_ctrlListBox"];

{
    private _index = _ctrlListBox lbAdd (_x get3DENAttribute "name" select 0);
    _ctrlListBox lbSetValue [_index, _x];
    _ctrlListBox lbSetTextRight [_index, format ["(%1)", count (get3DENLayerEntities _x)]];

    // Define icon
    private _visible = (_x get3DENAttribute "Visibility" select 0);
    private _canTransform =  (_x get3DENAttribute "Transformation" select 0);

    private _icon = "\a3\3den\data\cfg3den\layer\icon_ca.paa";

    if (!_visible && _canTransform) then {_icon = "\a3\3den\data\cfg3den\layer\iconhidden_ca.paa"};
    if (_visible && !_canTransform) then {_icon = "\a3\3den\data\cfg3den\layer\icondisabled_ca.paa"};
    if (!_visible && !_canTransform) then {_icon = "\a3\3den\data\cfg3den\layer\iconhiddendisabled_ca.paa"};

    _ctrlListBox lbSetPicture [_index, _icon];

} forEach (all3DENEntities # 6);

lbSort _ctrlListBox;