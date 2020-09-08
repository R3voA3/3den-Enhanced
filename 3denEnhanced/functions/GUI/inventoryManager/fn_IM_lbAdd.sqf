/*
   Author: R3vo

   Date: 2020-06-14

   Description:
   Used by the ENH_InventoryManager GUI. Adds an item to a listbox. Can be used for any listbox.

   Parameter(s):
   0: CONTROL - Control Listbox
   1: STRING - Item Text
   2: STRING - Item Data
   3: STRING - Left Picture
   4: STRING - Right Picture
   5: STRING - Tooltip

   Returns:
   BOOLEAN: true
*/

params
[
   ["_ctrlLb",controlNull],
   ["_lbText",""],
   ["_lbData",""],
   ["_pictureLeft",""],
   ["_pictureRight",""],
   ["_tooltip",""]
];

private _index = _ctrlLb lbAdd _lbText;
_ctrlLb lbSetData [_index,_lbData];
_ctrlLb lbSetPicture [_index,_pictureLeft];
_ctrlLb lbSetPictureRight [_index,_pictureRight];
_ctrlLb lbSetTooltip [_index,_tooltip];

true