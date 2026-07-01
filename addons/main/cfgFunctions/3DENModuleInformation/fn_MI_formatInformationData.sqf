#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-09-27

    Description:
    Returns formatted module or sync entity information.

    Parameter(s):
    0: HASHMAP - Information data returned by ENH_fnc_MI_getInformationData.

    Return Value:
    STRUCTURED TEXT - Formatted information
*/

params [["_data", createHashMap]];

private _displayName = "";

// Display Name
private _displayName = _data get "displayName";
private _optional = _data get "optional";
private _area = _data get "area";

if (_optional != "" && _area != "") then
{
    _displayName = format ["%1 %2 (%3)", _displayName, _area, _optional];
};

if (_optional == "" && _area != "") then
{
    _displayName = format ["%1 %2", _displayName, _area];
};

if (_optional != "" && _area == "") then
{
    _displayName = format ["%1 (%2)", _displayName, _optional];
};

_displayName = format ["<t font='RobotoCondensedBold' size='1.5'>%1</t>", _displayName];

// Config name
private _configName = format ["<t font='RobotoCondensed' size='0.75'>%1</t>", _data get "configName"];

// Description
private _description = _data get "description";

// Position
private _position = format ["<t font='RobotoCondensedBold'>%1 </t>%2", localize "STR_ENH_MAIN_MODULEINFORMATION_POSITION", _data get "position"];

// Duplicate
private _duplicate = format ["<t font='RobotoCondensedBold'>%1 </t>%2", localize "STR_ENH_MAIN_MODULEINFORMATION_DUPLICATE", _data get "duplicate"];

// Direction
private _direction = format ["<t font='RobotoCondensedBold'>%1 </t>%2", localize "STR_ENH_MAIN_MODULEINFORMATION_DIRECTION", _data get "direction"];

parseText ([_displayName, _configName, _description, _position, _duplicate, _direction] joinString LB_HTML);
