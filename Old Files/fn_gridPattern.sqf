/*
   Author: Revo

   Description:
   Places objects in pattern defined by number of rows, number of columns and spacing in meters. Works only with GUI "Enh_GridPattern"

   Parameter(s):
   -
   Returns:
   BOOLEAN - true / false
*/

#define GET_CTRL(IDC) (_disp displayCtrl IDC)

_objects = get3DENSelected "Object";

if(_objects isEqualTo [] || !is3DEN) exitWith {false};

disableSerialization;
_disp = findDisplay 160000;

_numRows = parseNumber ctrlText GET_CTRL(1400);
_numColumns = parseNumber ctrlText GET_CTRL(1401);
_spacingX = parseNumber ctrlText GET_CTRL(1402);
_spacingY = parseNumber ctrlText GET_CTRL(1403);

profileNamespace setVariable ["Enh_gridPattern_values",[str _numRows,str _numColumns,str _spacingX,str _spacingY]];

_startPos = screenToWorld [0.5,0.5];
_offSet = [0,0,0];
_counterColumns = 0;
_counterRows = 0;
_objectsToSelect = [];

collect3DENHistory
{
	{
		if (_counterColumns == _numColumns) then//Check if column is full, if yes, manipulate start position
		{
			_startPos = _startPos vectorAdd [0,_spacingY,0];
			_offset = [0,0,0];
			_counterColumns = 0;
			_counterRows = _counterRows + 1;
		};

		if (_counterRows == _numRows) exitWith {set3DENSelected _objectsToSelect};//Exit if rows are full

		_x set3DENAttribute ["Position",_startPos vectorAdd _offset];
		_offSet = _offSet vectorAdd [_spacingX,0,0];
		_counterColumns = _counterColumns + 1;
		_objectsToSelect pushBack _x;
	} forEach _objects;
};

set3DENSelected _objectsToSelect;

true