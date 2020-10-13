class ENH_HideTerrainObjects
{
	collapsed = 0;
	displayName = $STR_HIDETERRAINOBJECTS;// Hide or Destroy Terrain Objects
	class Attributes
	{
		class ENH_HideTerrainObjects // Doesn't work yet. To be implemented later...maybe
		{
			displayName = "Object Types";
			property = "ENH_HideTerrainObjects";
			control = "ENH_HideTerrainObjects";
			expression = "\
      if (!is3DEN && {isServer}) then\
      {\
          [_this,_value] spawn\
          {\
            _this params ['_trigger','_value'];\
            _value params ['_effect','_types'];\
            private _area = triggerArea _trigger;\
            private _objects = nearestTerrainObjects [_trigger,_types,_area # 0 max _area # 1 * 1.42,false] inAreaArray _trigger;\
            if (_effect == 0) then\
            {\
              {\
                  hideObjectGlobal _x;\
                  _x setDamage [1,false];\
              } forEach _objects;\
            }\
            else\
            {\
              {\
                _x setDamage [1,false];\
              } forEach _objects;\
            };\
          };\
      };";
			defaultValue = "[0,[]]";
		};
	};
};