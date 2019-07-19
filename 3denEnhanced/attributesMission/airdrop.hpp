class Enh_Airdrop
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_airdrop;
	class Attributes
	{
		class Enh_Airdrop_Classes
		{
			displayName = $STR_ENH_airdrop_classes_displayName;
			tooltip = $STR_ENH_airdrop_classes_tooltip;
			property = "Enh_Airdrop_Classes";
			control = "Enh_Airdrop";
			expression =
			"\
				if (!is3DEN && !((_value # 0) isEqualTo '') && isServer) then\
				{\
					_value spawn\
					{\
						params ['_classes','_center','_condition','_alt','_r','_side'];\
						_condition = compile _condition;\
						waitUntil {sleep 1; call _condition};\
						private _group = createGroup _side;\
						playSound3D ['A3\Data_F_Warlords\sfx\flyby.wss',objNull,false,_center vectorAdd [0,0,100],2.5];\
						Enh_Airdrop_Units = [];\
						{\
							private _unit = _group createUnit [_x,[0,0,0],[],0,'NONE'];\
							_center set [2,_center # 2 + random [-20,0,20]];\
							private _para = createVehicle ['Steerable_Parachute_F',_center getPos [_r * sqrt random 1,random 360],[],0,'FLY'];\
							Enh_Airdrop_Units pushBack _unit;\
							_unit moveInDriver _para;\
						} forEach _classes;\
					};\
				}";
			defaultValue = "['',[0,0,0],false,500,200,west]";
		};
	};
};