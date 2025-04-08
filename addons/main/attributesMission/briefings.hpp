class ENH_Briefing
{
    collapsed = 1;
    displayName = "$STR_A3_CFGDIARY_FIXEDPAGES_DIARY";
    class Attributes
    {
        class ENH_Briefing_BLUFOR_Subcategory
        {
            description = "$STR_WEST";
            data = "AttributeSystemSubcategory";
            control = "ENH_SubCategoryNoHeader1_Fixed";
        };
        // BLUFOR
        class ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_SITUATION_TITLE";
            tooltip = "$STR_ENH_MAIN_BRIEFING_TOOLTIP";
            property = "ENH_Briefing_BLUFOR_Situation";
            control = "EditMulti5";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_BLUFOR_Situation'; waitUntil {!isNull player}; if (side player == west) then {sleep 0.1; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SITUATION_TITLE', _this call BIS_fnc_localize]]}}};";
            defaultValue = "''";
        };
        class ENH_Briefing_BLUFOR_Mission: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_MISSION_TITLE";
            property = "ENH_Briefing_BLUFOR_Mission";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_BLUFOR_Mission'; waitUntil {!isNull player}; if (side player == west) then {sleep 0.2; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_MISSION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_BLUFOR_Execution: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_EXECUTION_TITLE";
            property = "ENH_Briefing_BLUFOR_Execution";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_BLUFOR_Execution'; waitUntil {!isNull player}; if (side player == west) then {sleep 0.3; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_EXECUTION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_BLUFOR_Signal: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_SIGNAL_TITLE";
            property = "ENH_Briefing_BLUFOR_Signal";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_BLUFOR_Signal'; waitUntil {!isNull player}; if (side player == west) then {sleep 0.4; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SIGNAL_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        // EAST
        class ENH_Briefing_OPFOR_Subcategory: ENH_Briefing_BLUFOR_Subcategory
        {
            description = "$STR_EAST";
        };
        class ENH_Briefing_OPFOR_Situation: ENH_Briefing_BLUFOR_Situation
        {
            property = "ENH_Briefing_OPFOR_Situation";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_OPFOR_Situation'; waitUntil {!isNull player}; if (side player == east) then {sleep 0.1; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SITUATION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_OPFOR_Mission: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_MISSION_TITLE";
            property = "ENH_Briefing_OPFOR_Mission";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_OPFOR_Mission'; waitUntil {!isNull player}; if (side player == east) then {sleep 0.2; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_MISSION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_OPFOR_Execution: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_EXECUTION_TITLE";
            property = "ENH_Briefing_OPFOR_Execution";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_OPFOR_Execution'; waitUntil {!isNull player}; if (side player == east) then {sleep 0.3; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_EXECUTION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_OPFOR_Signal: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_SIGNAL_TITLE";
            property = "ENH_Briefing_OPFOR_Signal";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_OPFOR_Signal'; waitUntil {!isNull player}; if (side player == east) then {sleep 0.4; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SIGNAL_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        // INDEPENDENT
        class ENH_Briefing_Independent_Subcategory: ENH_Briefing_BLUFOR_Subcategory
        {
            description = "$STR_GUERRILA";
        };
        class ENH_Briefing_Independent_Situation: ENH_Briefing_BLUFOR_Situation
        {
            property = "ENH_Briefing_Independent_Situation";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Independent_Situation'; waitUntil {!isNull player}; if (side player == independent) then {sleep 0.1; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SITUATION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_Independent_Mission: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_MISSION_TITLE";
            property = "ENH_Briefing_Independent_Mission";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Independent_Mission'; waitUntil {!isNull player}; if (side player == independent) then {sleep 0.2; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_MISSION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_Independent_Execution: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_EXECUTION_TITLE";
            property = "ENH_Briefing_Independent_Execution";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Independent_Execution'; waitUntil {!isNull player}; if (side player == independent) then {sleep 0.3; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_EXECUTION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_Independent_Signal: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_SIGNAL_TITLE";
            property = "ENH_Briefing_Independent_Signal";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Independent_Signal'; waitUntil {!isNull player}; if (side player == independent) then {sleep 0.4; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SIGNAL_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        // CIVILIAN
        class ENH_Briefing_Civilian_Subcategory: ENH_Briefing_BLUFOR_Subcategory
        {
            description = "$STR_CIVILIAN";
        };
        class ENH_Briefing_Civilian_Situation: ENH_Briefing_BLUFOR_Situation
        {
            property = "ENH_Briefing_Civilian_Situation";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Civilian_Situation'; waitUntil {!isNull player}; if (side player == civilian) then {sleep 0.1; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SITUATION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_Civilian_Mission: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_MISSION_TITLE";
            property = "ENH_Briefing_Civilian_Mission";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Civilian_Mission'; waitUntil {!isNull player}; if (side player == civilian) then {sleep 0.2; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_MISSION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_Civilian_Execution: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_EXECUTION_TITLE";
            property = "ENH_Briefing_Civilian_Execution";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Civilian_Execution'; waitUntil {!isNull player}; if (side player == civilian) then {sleep 0.3; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_EXECUTION_TITLE', _this call BIS_fnc_localize]]}}};";
        };
        class ENH_Briefing_Civilian_Signal: ENH_Briefing_BLUFOR_Situation
        {
            displayName = "$STR_A3_DIARY_SIGNAL_TITLE";
            property = "ENH_Briefing_Civilian_Signal";
            expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Civilian_Signal'; waitUntil {!isNull player}; if (side player == civilian) then {sleep 0.4; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SIGNAL_TITLE', _this call BIS_fnc_localize]]}}};";
        };
    };
};
