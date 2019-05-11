/*
   Author: Revo

   Description:
   Places objects in pattern defined by number of columns and spacing (x,y) in meters. Used in the Enh_PatternTools GUI.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true / false
*/

private _startPos = Enh_PlacementTools_Center;
private _offSet = [0,0,0];
private _counterColumns = 0;

collect3DENHistory
{
	{
		if (_counterColumns == Enh_PlacementTools_NumColumns) then//Check if column is full, if yes, manipulate start position and open an new column
		{
			_startPos = _startPos vectorAdd [0,Enh_PlacementTools_SpaceY,0];
			_offset = [0,0,0];
			_counterColumns = 0;
		};

		_x set3DENAttribute ["Position",_startPos vectorAdd _offset];
		_offSet = _offSet vectorAdd [Enh_PlacementTools_SpaceX,0,0];
		_counterColumns = _counterColumns + 1;
	} forEach Enh_PlacementTools_Selected;
};

(uiNamespace getVariable "Enh_PlacementTools_Display") displayCtrl 130 ctrlSetText str [Enh_PlacementTools_NumColumns,Enh_PlacementTools_SpaceX,Enh_PlacementTools_SpaceY];

true