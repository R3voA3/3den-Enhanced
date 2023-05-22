/*
	Author: linkion and R3vo

	Description:
	Apply the Virtual Arsenal Manager selection to an 3DEN object.

	Parameter(s):
	0: Object - 3DEN Object to apply attribute(s) to
	1: true - whether to apply ace arsenal attribute

	Returns:
	-

	Usage:
	[_box, true, true] call ENH_fnc_VAM_applyAttribute;
*/

params["_object", "_aceBool", "_biBool"];

private _selectHashMap = uiNamespace getVariable ["ENH_VAM_selectHashMap", createHashMap];


if (_aceBool && isClass(configFile >> "CfgPatches" >> "ace_arsenal")) then {
  _object set3DENAttribute ["ace_arsenal_attribute", [keys _selectHashMap, 0]];
};

if (_biBool) then {
  [_object, keys(_selectHashMap)] call BIS_fnc_addVirtualWeaponCargo;
};