class ENH_MissionEnding_Casualties
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_DISPLAYNAME";
    class Attributes
    {
        class ENH_MissionEnding_Subcategory
        {
            description = "$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_DESCRIPTION";
            data = "AttributeSystemSubcategory";
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
                    ENH_Casualties_Threshold = _value param [0, 5];\
                    ENH_Casualties_Debriefing = _value param [1, 'enddefault'];\
                    ENH_Casualties_IsWin = _value param [2, false];\
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
                            [ENH_Casualties_Debriefing, ENH_Casualties_IsWin] remoteExecCall ['BIS_fnc_endMission', 0];\
                        };\
                    }];\
                };";
            defaultValue = "[5, 'enddefault', false, civilian]";
        };
    };
};
