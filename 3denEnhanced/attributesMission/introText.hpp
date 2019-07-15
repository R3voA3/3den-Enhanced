class Enh_IntroText_Category
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_introText;
	class Attributes
	{
		class Enh_IntroText
		{
			property = "Enh_introText";
			control = "Enh_IntroText";
			expression =
			"\
				if (!is3DEN && (_value # 0) > 0 && hasInterface) then\
				{\
					_value spawn\
					{\
						waitUntil {time > (_this # 0)};\
						if !(_this # 4) then\
						{\
							private _text = parseText format\
							[\
								""<t align='right' size='1.6'><t font='PuristaBold' size='1.8'>%1<br/></t>%2<br/>%3</t>"",\
								_this # 1,\
								_this # 2,\
								_this # 3\
							];\
							[_text,true] spawn BIS_fnc_textTiles;\
						}\
						else\
						{\
							[_this # 1,_this # 2,_this # 3] spawn BIS_fnc_EXP_camp_SITREP;\
						};\
					};\
				}";
			defaultValue = "[5,missionName,'by ' + profileName,[daytime,'HH:MM'] call BIS_fnc_TimeToString,false]";
		};
	};
};