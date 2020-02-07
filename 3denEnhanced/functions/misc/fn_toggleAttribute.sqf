/*
	Author: Revo

	Description:
	Toggles given attribute of selected entities of given types. Only attribute which use boolean values can be toggled.

	Parameter(s):
	0: ARRAY - Array of types to select. See ENH_fnc_all3DENSelected for values
	1: STRING - Attribute name

	Returns:
	BOOLEAN: true / false
*/

if !(is3DEN) exitWith {false};

private _types = param [0,["Object"],[[]]];
private _attribute = param [1,"",[""]];
private _selected = [_types] call ENH_fnc_all3DENSelected;

if (_selected isEqualTo []) exitWith
{
	["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
	false
};

#define GET_ATTRIBUTE (_x get3DENAttribute _attribute)

collect3DENHistory
{
	{
		if (GET_ATTRIBUTE isEqualTo [false]) then
		{
		 	_x set3DENAttribute [_attribute,true];
		}
		else
		{
			_x set3DENAttribute [_attribute,false];
		};
	} forEach _selected;
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true