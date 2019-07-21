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
						params ['_delay','_line1','_line2','_line3','_type'];\
						waitUntil {time > _delay};\
						switch (_type) do\
						{\
							case 0:\
							{\
								private _text = parseText format\
								[\
									""<t align='right' size='1.6'><t font='PuristaBold' size='1.8'>%1<br/></t>%2<br/>%3</t>"",\
									_line1,\
									_line2,\
									_line3\
								];\
								[_text,true] spawn BIS_fnc_textTiles;\
							};\
							case 1:\
							{\
								[_line1,_line2,_line3] spawn BIS_fnc_infoText;\
							};\
							case 2:\
							{\
								[_line1,_line2,_line3] spawn BIS_fnc_EXP_camp_SITREP;\
							};\
						};\
					};\
				}";
			defaultValue = "[0,briefingName,'by ' + profileName,[daytime,'HH:MM'] call BIS_fnc_TimeToString,0]";
		};
	};
};