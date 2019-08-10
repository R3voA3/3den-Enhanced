class Enh_MissionEnding
{
	collapsed = 1;
	displayName = "Mission Ending";
	class Attributes
	{
		class Enh_MissionEnding_Casualties
		{
			displayName = "Mission Ending";
			property = "Enh_missionEnding_casualties";
			control = "Enh_MissionEnding_Casualties";
			expression =
			"\
				diag_log _value;\
				if (!is3DEN && isServer && !((_value # 1) isEqualTo 'enddefault')) then\
				{\
					Enh_Casualties_Threshold = _value param [0,5];\
					Enh_Casualties_Debriefing = _value param [1,'enddefault'];\
					Enh_Casualties_IsWin = _value param [2,false];\
					Enh_Casualties_Side = _value param [3];\
					Enh_Casualties_Counter = 0;\
					\
					addMissionEventHandler ['EntityKilled',\
					{\
						params ['_killed', '_killer'];\
						if (side group _killed isEqualTo Enh_Casualties_side && isPlayer _killer) then\
						{\
							Enh_Casualties_Counter = Enh_Casualties_Counter + 1;\
						};\
						if (Enh_Casualties_Counter >= Enh_Casualties_Threshold) exitWith\
						{\
							[Enh_Casualties_Debriefing,Enh_Casualties_IsWin] remoteExecCall ['BIS_fnc_endMission',0];\
						};\
					}];\
				};";
			defaultValue = "[5,'enddefault',false,civilian]";
		};
	};
};