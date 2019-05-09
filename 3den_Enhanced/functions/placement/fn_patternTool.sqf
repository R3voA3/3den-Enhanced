/*
   Author: Revo

   Description:
   Executes one of three pattern tools. Works only together with the Enh_patternTool display (IDD 10000)

   Parameter(s):
   _this: STRING - "line","circular" or "fillArea"

   Returns:
   BOOLEAN - true / false
*/

private _objects  = get3DENSelected "Object";
private _markers  = get3DENSelected "Marker";
private _triggers = get3DENSelected "Trigger";
private _logics   = get3DENSelected "Logic";
private _entities = _objects + _markers + _triggers + _logics;

if (count _entities == 0) exitWith {false};

//Pattern type is defined by the action selected in the menu strip
private _patternType = missionNamespace getVariable ["Enh_pattern_type","line"];

disableSerialization;
private _display = findDisplay 100000;
private _ctrlRad = _display displayCtrl 1404;
private _ctrlSpace = _display displayCtrl 1403;
private _ctrlA = _display displayCtrl 1400;
private _ctrlB = _display displayCtrl 1401;
private _ctrlNum = _display displayCtrl 1402;

//Retrieve all values from the dialogue
private _radius = ctrlText _ctrlRad;
private _spacing = ctrlText _ctrlSpace;
private _a = ctrlText _ctrlA;
private _b = ctrlText _ctrlB;
private _count = ctrlText _ctrlNum;

//Save settings to profileNamespace to restore them later
profileNamespace setVariable ["Enh_patternTool_radius",_radius];
profileNamespace setVariable ["Enh_patternTool_spacing",_spacing];
profileNamespace setVariable ["Enh_patternTool_a",_a];
profileNamespace setVariable ["Enh_patternTool_b",_b];
profileNamespace setVariable ["Enh_patternTool_count",_count];
//Line Pattern
private _fnc_linePattern =
{
	private _start = (_entities # 0 get3DENAttribute "Position") # 0;
	if (_spacing isEqualType "") then {_spacing = parseNumber _spacing};
	_newPos = _start;
	collect3DENHistory
	{
		{
			if (_forEachIndex == 0) then
			{
				_x set3DENAttribute ["Position",_start] ;
			}
			else
			{
				_x set3DENAttribute ["Position",_newPos];
			};
			_newPos = (_x get3DENAttribute "Position") # 0;
			_newPos = [(_newPos # 0) + _spacing,_newPos # 1,0];
		} forEach _entities;
	};
};
//Circular Pattern
private _fnc_circularPattern =
{
	private _center = screenToWorld [0.5,0.5];
	private _angle = 0;
	private _angleStep = 360 / (count _entities);
	collect3DENHistory
	{
	   {
	   	private _pos = _center getPos [parseNumber _radius,_angle];
	   	_x set3DENAttribute ["Position",_pos];
	   	_x set3DENAttribute ["Rotation",[0,0,_angle]];
	   	_angle = _angle + _angleStep;
	   } forEach _entities;
	};
};
//Fill Area
private _fnc_fillArea =
{
	private _center = screenToWorld [0.5,0.5];
	_a = parseNumber _a;
	_b = parseNumber _b;

	collect3DENHistory
	{
		for "_i" from 1 to parseNumber _count do
		{

			private _randomPos = [_center # 0 + random _a - random _a,_center # 1 + random _b - random _b ,0];
			create3DENEntity
			[
				"Object",
				typeOf (selectRandom _entities),
				_randomPos
			];
		};
	};
};

switch (_patternType) do
{
	case "line": {call _fnc_linePattern};
	case "circular": {call _fnc_circularPattern};
	case "fillArea": {call _fnc_fillArea};
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true