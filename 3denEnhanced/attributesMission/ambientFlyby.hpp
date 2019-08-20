class Enh_AmbientFlyby
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_ambientFlyby;
	class Attributes
	{
		class Enh_AmbientFlyby
		{
			displayName = $STR_ENH_attributeCategory_ambientFlyby;
			property = "Enh_ambientFlyby";
			control = "Enh_AmbientFlyby";
			expression ="\
			if (isServer && !is3DEN && !((_value # 0) isEqualTo '')) then\
			{\
				Enh_AmbientFlyby_Enabled = true;\
				_value spawn\
				{\
					params ['_classes','_startPos','_endPos','_alt','_speed','_side','_delay'];\
					while {Enh_AmbientFlyby_Enabled} do\
					{\
						sleep _delay;\
						[_startPos,_endPos,_alt,_speed,selectRandom _classes,_side] call BIS_fnc_ambientFlyby;\
					};\
				};\
			}";
			defaultValue = "['',[0,0,0],[0,0,0],500,'normal',west,300]";
		};
	};
};