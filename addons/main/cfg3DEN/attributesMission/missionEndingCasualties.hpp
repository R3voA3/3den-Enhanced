class ENH_MissionEnding_Casualties
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_DISPLAYNAME";
    class Attributes
    {
        class ENH_MissionEnding_Subcategory
        {
            description = "$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_DESCRIPTION";
            property = "ENH_MissionEnding_Subcategory";
            control = "ENH_SubCategoryNoHeader3_Fixed";
        };
        class ENH_MissionEnding_Casualties
        {
            displayName = "$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_DESCRIPTION";
            property = "ENH_missionEnding_casualties";
            control = "ENH_MissionEnding_Casualties";
            expression =
            "\
                if (!is3DEN && isServer && (_value # 1) != 'enddefault') then\
                {\
                    ENH_Casualties_Counter = 0;\
                    \
                    addMissionEventHandler ['EntityKilled',\
                    {\
                        params ['_killed'];\
                        _thisArgs params ['_threshold', '_debriefing', '_isWin', '_side', '_threshold'];\
                        \
                        if (side group _killed isEqualTo _side) then\
                        {\
                            ENH_Casualties_Counter = ENH_Casualties_Counter + 1;\
                        };\
                        if (ENH_Casualties_Counter >= _threshold) exitWith\
                        {\
                            removeMissionEventHandler [_thisEvent, _thisEventHandler];\
                            [_debriefing, _isWin] remoteExecCall ['BIS_fnc_endMission', 0];\
                        };\
                    }, _value];\
                };";
            defaultValue = "[5, 'enddefault', false, civilian]";
        };
    };
};
