/*
   Author: R3vo

   Date: 2019-06-11

   Description:
   Used by the Enh_PlacementTools GUI. Places selected units in a rectangle.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

private _newPos = Enh_PlacementTools_Center;
private _numX = (Enh_PlacementTools_RectangleA / Enh_PlacementTools_RectangleSpacing) - 1;
private _numY = (Enh_PlacementTools_RectangleB / Enh_PlacementTools_RectangleSpacing) - 1;
private _c1 = _numX;
private _c2 = _c1 + _numY;
private _c3 =  _c1 + _c2;
private _c4 = _numY + _c3;
private _counter = 1;
private _toSelect = [];
private _rotation = [0,0,0];

/*
_c3-------------------_c2
-						-
-						-
-						-
-						-
_c4-------------------_c1 
*/
{
	_x set3DENAttribute ["Position",_newPos];
	_x set3DENAttribute ["Rotation",_rotation];

	if (_counter < (_c1)) then {_newPos = _newPos vectorAdd [Enh_PlacementTools_RectangleSpacing,0,0]; _rotation = [0,0,0];};
	if (_counter >= (_c1) && _counter < _c2) then {_newPos = _newPos vectorAdd [0,Enh_PlacementTools_RectangleSpacing,0]; _rotation = [0,0,90]; };
	if (_counter >= (_c2) && _counter < _c3) then {_newPos = _newPos vectorAdd [-Enh_PlacementTools_RectangleSpacing,0,0]; _rotation = [0,0,0]; };
	if (_counter >= (_c3) && _counter < _c4) then {_newPos = _newPos vectorAdd [0,-Enh_PlacementTools_RectangleSpacing,0];  _rotation = [0,0,90]; };
	//_toSelect pushBack _x;
	if (_counter >= _c4) exitWith {};
	
	_counter = _counter + 1;
} forEach call Enh_fnc_all3DENSelected;

//set3DENSelected _toSelect;

#define OUTPUT format ["%1 m / %2 m / %3 m",Enh_PlacementTools_RectangleA,Enh_PlacementTools_RectangleB,Enh_PlacementTools_RectangleSpacing]
(uiNamespace getVariable "Enh_PlacementTools_Display") displayCtrl 120 ctrlSetText OUTPUT;

true