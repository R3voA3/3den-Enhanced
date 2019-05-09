/*
   Author: Bohemia Interactive, edited by Revo

   Description:
   Adds all items from a static cfg to the combobox when the attribute is opened and sets the value accordingly

   Parameter(s):
   -
   Returns:
   -
*/

params ["_ctrl","_config"];

_attCtrl = getText (_config >> 'control');
_staticItemsCfg = configFile >> 'Cfg3DEN' >> 'Attributes' >> _attCtrl >> 'Controls' >> 'Value' >> 'items';

_fnc_setValues =
{
   private ['_index'];
   params ['_path',['_apply',true]];
   {
      _cfg = _x;
      if (_apply) then
      {
         _index = _ctrl lbAdd getText (_cfg >> 'text');
         _ctrl lbSetData [_index, getText ( _cfg >> 'data')];
      }
      else
      {
         _index = _foreachindex;
      };
      if !(_value isEqualType '') then
      {
         if (_index isEqualTo _value) then
         {
            _ctrl lbSetCurSel _index;
         };
      }
      else
      {
         if (_value == getText (_cfg >> 'data')) then
         {
            _ctrl lbSetCurSel _index;
         };
      };
   } forEach configProperties [_path,'isclass _x'];
};
if (isClass _staticItemsCfg) then
{
   [_staticItemsCfg,false] call _fnc_setValues;
};