/*
	Author: linkion

	Description:
	Select compatible items based on current selection and selects them.

	Parameter(s):
	-

	Returns:
	-

	Usage:
	[] call ENH_fnc_VAM_selectCompatibleItems;
*/

private _selectHashMap = uiNamespace getVariable ["ENH_VAM_selectHashMap", createHashMap];
private _newItems = [];

{
	// Current result is saved in variable _x
	_newItems pushBackUnique [_x] call ENH_fnc_compatibleItems;
} forEach _selectHashMap;

{
	// Current result is saved in variable _x
	private _itemVal = (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap]) get toLower _x;
	_selectHashMap set [toLower _x, _itemVal];
} forEach _newItems;