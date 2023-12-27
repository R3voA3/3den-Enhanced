params [["_mode", "toggle"]];

#define LAYERNAME "ENH_l_Temp_Triggers (do not modify!)"

switch _mode do
{
  case "toggle":
  {
    collect3DENHistory
    {
      private _areaMarkers = all3DENEntities # 5 select {_x get3DENAttribute "markerType" param [0, -1] > -1};

      if (_areaMarkers isEqualTo []) exitWith {};

      private _deleted = "delete" call ENH_fnc_highLightAreaMarkers;

      //If layer was found then exit to allow for toggling
      if _deleted exitWith {};

      private _tempLayer = -1 add3DENLayer LAYERNAME;

      {
        private _markerIsRectangular = _x get3DENAttribute "markerType" select 0 == 0;
        private _tempTrigger = create3DENEntity ["Trigger", "EmptyDetectorArea10x10", [0, 0, 0]];

        _tempTrigger set3DENLayer _tempLayer;

        private _pos = _x get3DENAttribute "position" select 0;
        _pos set [2, 0];

        private _size = _x get3DENAttribute "size2" select 0;
        _size set [2, -1];

        _tempTrigger set3DENAttribute ["position", _pos];
        _tempTrigger set3DENAttribute ["isRectangle", _markerIsRectangular];
        _tempTrigger set3DENAttribute ["size3", _size];
        _tempTrigger set3DENAttribute ["rotation", _x get3DENAttribute "rotation" select 0];
        _tempTrigger set3DENAttribute ["text", _x get3DENAttribute "markerName" select 0];
      } forEach _areaMarkers;
    };
  };
  case "delete":
  {
    private _deleted = false;
    collect3DENHistory
    {
      private _allLayers = all3DENEntities#6;

      {
        if (_x get3DENAttribute "name" isEqualTo [LAYERNAME]) exitWith
        {
          delete3DENEntities [_x];
          _deleted = true;
        };
      } forEach _allLayers;
    };
    _deleted
  };
};