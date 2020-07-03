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

   Returns:
   BOOLEAN: true
*/

params ["_ctrlLb","_lbText","_lbData","_pictureLeft","_pictureRight"];
private _indexItem = _ctrlLb lbAdd _lbText;
_ctrlLb lbSetData [_indexItem,_lbData];
_ctrlLb lbSetPicture [_indexItem,_pictureLeft];
_ctrlLb lbSetPictureRight [_indexItem,_pictureRight];

true