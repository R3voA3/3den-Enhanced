#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-05-02

    Description:
    Checks if  position is in bounding box of object.

    Parameter(s):
    0: OBJECT - The object
    1: ARRAY - Cursor position
    2: NUMBER - Bounding box type see boundingBoxReal on biki

    Return Value:
    BOOLEAN - True if in BB, false if not
*/

params [["_object", objNull], ["_position", [0, 0, 0]], ["_bbType", 0]];

// Disable garrison for objects in layers that are hidden or for which transformation is disabled
private _layer = get3DENLayer _object;

if (_layer > -1 && {_layer get3DENAttribute "Transformation" isEqualTo [false] ||
    {_layer get3DENAttribute "Visibility" isEqualTo [false]}}) exitWith {false};

private _bb = _bbType boundingBoxReal _object;
private _p1 = _bb select 0;
private _p2 = _bb select 1;
private _maxWidth = abs ((_p2 select 0) - (_p1 select 0));
private _maxLength = abs ((_p2 select 1) - (_p1 select 1));
private _maxHeight = abs ((_p2 select 2) - (_p1 select 2));

private _isInBoundingBox = ASLToAGL _position inArea
[
    ASLToAGL getPosASL _object,
    _maxWidth * 0.5,
    _maxLength  * 0.5,
    getDir _object,
    true,
    _maxHeight * 0.5
];

// We use both as get3DENMouseOver adds more precision but on the other hand
// does not detect terrain objects
_isInBoundingBox || {_object in get3DENMouseOver}
