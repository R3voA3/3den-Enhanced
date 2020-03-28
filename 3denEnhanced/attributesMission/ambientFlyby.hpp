class ENH_AmbientFlyby
{
	collapsed = 1;
	displayName = $STR_ENH_AMBIENTFLYBY_DISPLAYNAME;
	class Attributes
	{
		class ENH_AmbientFlyby
		{
			displayName = $STR_ENH_AMBIENTFLYBY_DISPLAYNAME;
			property = "ENH_ambientFlyby";
			control = "ENH_AmbientFlyby";
			expression ="\
			if (isServer && {!is3DEN && {!((_value # 0) isEqualTo [])}}) then\
			{\
				ENH_AmbientFlyby_Enabled = true;\
				_value spawn\
				{\
					params ['_classes','_startPos','_endPos','_alt','_speed','_side','_delay'];\
					while {ENH_AmbientFlyby_Enabled} do\
					{\
						sleep _delay;\
						[_startPos,_endPos,_alt,_speed,selectRandom _classes,_side] call BIS_fnc_ambientFlyby;\
					};\
				};\
			}";
			defaultValue = "[[],[0,0,0],[0,0,0],500,'normal',west,300]";
		};
	};
};