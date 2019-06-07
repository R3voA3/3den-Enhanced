private _space =6;
private _distanceX = 2000;
private _distanceY = 2000;
private _newPos = Enh_PlacementTools_Center;
private _numX = (_distanceX / _space) - 1;
private _numY = (_distanceY / _space) - 1;
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

	if (_counter < (_c1)) then {_newPos = _newPos vectorAdd [_space,0,0]; _rotation = [0,0,0];};
	if (_counter >= (_c1) && _counter < _c2) then {_newPos = _newPos vectorAdd [0,_space,0]; _rotation = [0,0,90]; };
	if (_counter >= (_c2) && _counter < _c3) then {_newPos = _newPos vectorAdd [-_space,0,0]; _rotation = [0,0,0]; };
	if (_counter >= (_c3) && _counter < _c4) then {_newPos = _newPos vectorAdd [0,-_space,0];  _rotation = [0,0,90]; };
	_toSelect pushBack _x;
	if (_counter >= _c4) exitWith {};
	
	_counter = _counter + 1;
} forEach call Enh_fnc_all3DENSelected;

set3DENSelected _toSelect;


























/* {
	if (_counterXbottom < _numX) then 
	{
		_x set3DENAttribute ["Position",_newPos];
		_newPos = _newPos vectorAdd [_space,0,0];
		_counterXbottom = _counterXbottom + 1;
	};
	if (_counterXTop < _numX) then 
	{
		_x set3DENAttribute ["Position",_newPos];
		_newPos = _newPos vectorAdd [_space,0,0];
		_counterXbottom = _counterXbottom + 1;
	};
} forEach _selected;
 */


/*
//X
for "_i" from 0 to _numX - 1 do
{
	_selected # _i set3DENAttribute ["Position",_newPos];
	_selected = _selected - [_selected # _i];
	_newPos = _newPos vectorAdd [_space,0,0];
};

_newPos = _center vectorAdd [0,_distanceY,0];

for "_i" from 0 to _numX - 1 do
{
	
	_selected # _i set3DENAttribute ["Position",_newPos];
_selected = _selected - [_selected # _i];
	_newPos = _newPos vectorAdd [_space,0,0];
};

_newPos = _center vectorAdd [0,_space,0];

//Y
for "_i" from 0 to _numX - 1 do
{
	_selected # _i set3DENAttribute ["Position",_newPos];
	_selected = _selected - [_selected # _i];
	_newPos = _newPos vectorAdd [0,_space,0];
};
/*
_newPos = _center vectorAdd [0,_distanceX + _space,0];

for "_i" from 0 to _numX - 1 do
{
	
	_selected # _i set3DENAttribute ["Position",_newPos];

	_newPos = _newPos vectorAdd [0,_space,0];
};