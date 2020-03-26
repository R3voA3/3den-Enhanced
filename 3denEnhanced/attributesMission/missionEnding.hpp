class ENH_MissionEnding
{
	collapsed = 1;
	displayName = $STR_ENH_MISSIONENDING_CATEGORY_DISPLAYNNAME;
	class Attributes
	{
		class ENH_MissionEnding_Casualties
		{
			displayName = $STR_ENH_MISSIONENDING_CASUALTIES_DISPLAYNAME;
			property = "ENH_missionEnding_casualties";
			control = "ENH_MissionEnding_Casualties";
			expression =
			"\
				if (!is3DEN && {isServer && {(_value # 1) != 'enddefault'}}) then\
				{\
					ENH_Casualties_Threshold = _value param [0,5];\
					ENH_Casualties_Debriefing = _value param [1,'enddefault'];\
					ENH_Casualties_IsWin = _value param [2,false];\
					ENH_Casualties_Side = _value param [3];\
					ENH_Casualties_Counter = 0;\
					\
					addMissionEventHandler ['EntityKilled',\
					{\
						params ['_killed', '_killer'];\
						if (side group _killed isEqualTo ENH_Casualties_side) then\
						{\
							ENH_Casualties_Counter = ENH_Casualties_Counter + 1;\
						};\
						if (ENH_Casualties_Counter >= ENH_Casualties_Threshold) exitWith\
						{\
							[ENH_Casualties_Debriefing,ENH_Casualties_IsWin] remoteExecCall ['BIS_fnc_endMission',0];\
						};\
					}];\
				};";
			defaultValue = "[5,'enddefault',false,civilian]";
		};
 		/* class ENH_MissionEnding_1
		{
			displayName = "Mission Ending";
			property = "ENH_MissionEnding_1";
			control = "ENH_MissionEnding";
			expression =
			"\
				if (!is3DEN && {isServer && {(_value # 1) != 'enddefault'}}) then\
				{\
					_value spawn\
					{\
						params ['_condition','_debriefing','_isWin','_playMusic'];\
						_condition = compile _condition;\
						waitUntil {sleep 10; call _condition};\
						[_debriefing,_isWin,true,_playMusic] remoteExecCall ['BIS_fnc_endMission',0];\
					};\
				};";
			defaultValue = "['','enddefault',false,false]";
		};
		class ENH_MissionEnding_2: ENH_MissionEnding_1
		{
			property = "ENH_MissionEnding_2";
		};
		class ENH_MissionEnding_3: ENH_MissionEnding_1
		{
			property = "ENH_MissionEnding_3";
		};*/
	};
};