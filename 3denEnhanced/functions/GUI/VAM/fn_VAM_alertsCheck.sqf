/*
	Author: linkion and R3vo

	Description:
	Check for common mistakes and add them to alerts

	Parameter(s):
	-

	Returns:
	-

	Usage:
	[] call ENH_fnc_VAM_alertsCheck;
*/

// values ["errorText", ["mouseOverText", "linkedItemClass"]]
private _alertsHashMap = uiNamespace getVariable ["ENH_VAM_alertsHashMap", createHashMap];
private _selectHashMap = uiNamespace getVariable ["ENH_VAM_selectHashMap", createHashMap];


// check if selected items have any magazines selected
{
	_y params ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort", "_class"];

	private _compatibleItems = [_x] call ENH_fnc_compatibleItems;
	_compatibleItems = _compatibleItems apply {toLower(_x)};

	{ // remove compatible item if not magazine

		if (not(isClass(configFile >> "CFGMagazines" >> _x))) then {
			_compatibleItems deleteAt _forEachIndex;
		}
	} forEach _compatibleItems;

	private _compatibleItemsSelected = _compatibleItems arrayIntersect (keys _selectHashMap);

	if ((count _compatibleItemsSelected) == 0) then {
		private _errorText = format["No magazines selected for %1", _displayName];
		private _mouseOverText = format["You have not selected any magazines for %1, click to show location of weapon.", _class];
		_alertsHashMap set [_errorText, [_mouseOverText, _x]];
	}

} forEach _selectHashMap;