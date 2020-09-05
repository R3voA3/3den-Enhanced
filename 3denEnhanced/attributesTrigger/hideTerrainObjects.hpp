class ENH_HideTerrainObjects
{
	collapsed = 0;
	displayName = "Hide or Destroy Terrain Objects";
	class Attributes
	{
		class ENH_HideTerrainObjects
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
            if (_effect == 0) then\
            {\
              {\
                  hideObjectGlobal _x;\
                  sleep 0.001;\
              } forEach nearestTerrainObjects [_trigger,[],(triggerArea _trigger) # 0,false];\
            }\
            else\
            {\
              {\
                _x setDamage [1,false];\
                sleep 0.001;\
              } forEach nearestTerrainObjects [_trigger,[],(triggerArea _trigger) # 0,false];\
            };\
          };\
      };";
			defaultValue = "[0,[]]";
		};
	};
};