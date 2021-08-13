/*
  Author: R3vo

  Date: 2021-04-13

  Description:
  Fills the list of the 3DENShorcuts GUI. Is also used to filter the list.

  Parameter(s):
  0: CONTROL - ListNBox
  1: STRING - Filter

  Returns:
  -
*/

params ["_ctrlContent", "_filter"];

lnbClear _ctrlContent;
{
  _x params ["_text", "_sc", "_picture"];
  private _index = _ctrlContent lnbAddRow ["", _text, _sc];
  _ctrlContent lnbSetPicture [[_index, 0], _picture];
} forEach ((uiNamespace getVariable ["ENH_3DENShortcuts_Cache", []]) select {toLower _filter in toLower (_x select 0)});