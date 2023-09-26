/*
  Author: linkion and R3vo

  Description:
  Select/deselect of currently selected item in table view.
  also change selection state of parents (if not all items selected, parent(s) is partially selected)

  Parameter(s):
  0: tvControl - controlgroup for table view
  1: INT - 1 for selecting, 0 for deselecting

  Returns:
  -
*/


params ["_ctrlTV","_add", ["_selectedPath", []]];

if (count _selectedPath == 0) then {
  _selectedPath = tvCurSel _ctrlTV;
};
private _picture = ["\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa", "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa"] select _add;

_ctrlTV tvSetPicture [_selectedPath, _picture];
_ctrlTV tvSetValue [_selectedPath, _add];

private _selectHashMap = uiNamespace getVariable ["ENH_VAM_selectHashMap", createHashMap];
private _itemClass = toLower(_ctrlTV tvData _selectedPath);

if (_add == 1 && (_ctrlTV tvCount _selectedPath) == 0) then {
  private _itemValues = (uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap]) get _itemClass;
  _selectHashMap insert [[_itemClass, _itemValues]];
} else {
  _selectHashMap deleteAt _itemClass;
};

private _fnc_traverseChildren =
{
  params ["_path"];

  for "_i" from (_ctrlTV tvCount _path) to 0 step -1 do
  {
    private _newPath = _path + [_i];

    _ctrlTV tvSetPicture [_newPath, _picture];
    _ctrlTV tvSetValue [_newPath, _add];

    private _selectHashMap = uiNamespace getVariable ["ENH_VAM_selectHashMap", createHashMap];
    private _itemClass = toLower(_ctrlTV tvData _newPath);

    if (_add == 1 && (_ctrlTV tvCount _newPath) == 0) then {
      private _itemValues = (uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap]) get _itemClass;
      _selectHashMap insert [[_itemClass, _itemValues]];
    } else {
      _selectHashMap deleteAt _itemClass;
    };

    if (_ctrlTV tvCount _newPath > 0) then
    {
      [_newPath] call _fnc_traverseChildren;
    };
  };
};

private _fnc_traverseParents =
{
  params ["_path"];

  // traversing backwards from farthest child to first parent
  // to make sure to check uncheck when all children are checked
  for "_i" from 1 to (count _path - 1) step 1 do {
    private _partialCheckedPic = "\a3\ui_f\data\gui\rsccommon\rsccheckbox\checkbox_checked_ca.paa";
    private _newPath = +_path;
    _newPath deleteRange [count _path - _i, count _path];

    _ctrlTV tvSetPicture [_newPath, _partialCheckedPic];
    _ctrlTV tvSetValue [_newPath, 2];

    // check if all children are checked
    private _tempBool = true;
    for "_i" from (_ctrlTV tvCount _newPath) to 0 step -1 do
    {
      private _newPath = _newPath + [_i];
      if (_ctrlTV tvValue _newPath == 0 || _ctrlTV tvValue _newPath == 2) exitWith {
        _tempBool = false;
      };
    };
    // make parent checked
    if (_tempBool) then {
      private _checkedPic = "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa";

      _ctrlTV tvSetPicture [_newPath, _checkedPic];
      _ctrlTV tvSetValue [_newPath, 1];
    };

    // check if all children are unchecked
    private _tempBool = true;
    for "_i" from (_ctrlTV tvCount _newPath) to 0 step -1 do
    {
      private _newPath = _newPath + [_i];
      if (_ctrlTV tvValue _newPath == 1 || _ctrlTV tvValue _newPath == 2) exitWith {
        _tempBool = false;
      };
    };
    // make parent unchecked
    if (_tempBool) then {
      private _uncheckedPic = "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa";

      _ctrlTV tvSetPicture [_newPath, _uncheckedPic];
      _ctrlTV tvSetValue [_newPath, 0];
    };
  };
};

[_selectedPath] call _fnc_traverseChildren;
[_selectedPath] call _fnc_traverseParents;