class ENH_Briefing
{
  collapsed = 1;
  displayName = $STR_A3_CFGDIARY_FIXEDPAGES_DIARY;
  class Attributes
  {
    class ENH_Briefing_BLUFOR_Subcategory
    {
      description = $STR_WEST;
      data = "AttributeSystemSubcategory";
      control = "ENH_SubCategoryNoHeader1_Fixed";
    };
    class ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_SITUATION_TITLE;
      tooltip = "These briefings work in singleplayer, multiplayer and for JIP players. You can also insert formatted text created with the Briefing Editor. See 'createDiaryRecord' on the BI Wiki for more information.\n\nIf a stringtable entry is provided, the briefing will be displayed in player's language.";
      property = "ENH_Briefing_BLUFOR_Situation";
      control = "EditMulti5";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == west) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_SITUATION_TITLE',_this call BIS_fnc_localize]]}}};";
      defaultValue = "''";
    };
    class ENH_Briefing_BLUFOR_Mission: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_MISSION_TITLE;
      property = "ENH_Briefing_BLUFOR_Mission";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == west) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_MISSION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_BLUFOR_Execution: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_EXECUTION_TITLE;
      property = "ENH_Briefing_BLUFOR_Execution";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == west) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_EXECUTION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_BLUFOR_Signal: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_SIGNAL_TITLE;
      property = "ENH_Briefing_BLUFOR_Signal";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == west) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_SIGNAL_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    //----------------EAST
    class ENH_Briefing_OPFOR_Subcategory: ENH_Briefing_BLUFOR_Subcategory
    {
      description = $STR_EAST;
    };
    class ENH_Briefing_OPFOR_Situation: ENH_Briefing_BLUFOR_Situation
    {
      property = "ENH_Briefing_OPFOR_Situation";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == east) then {player createDiaryRecord [Diary,[localize 'STR_A3_DIARY_SITUATION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_OPFOR_Mission: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_MISSION_TITLE;
      property = "ENH_Briefing_OPFOR_Mission";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == east) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_MISSION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_OPFOR_Execution: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_EXECUTION_TITLE;
      property = "ENH_Briefing_OPFOR_Execution";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == east) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_EXECUTION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_OPFOR_Signal: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_SIGNAL_TITLE;
      property = "ENH_Briefing_OPFOR_Signal";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == east) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_SIGNAL_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    //----------------INDEPENDENT
    class ENH_Briefing_INDFOR_Subcategory: ENH_Briefing_BLUFOR_Subcategory
    {
      description = $STR_GUERRILA;
    };
    class ENH_Briefing_INDFOR_Situation: ENH_Briefing_BLUFOR_Situation
    {
      property = "ENH_Briefing_INDFOR_Situation";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == independent) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_SITUATION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_INDFOR_Mission: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_MISSION_TITLE;
      property = "ENH_Briefing_INDFOR_Mission";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == independent) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_MISSION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_INDFOR_Execution: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_EXECUTION_TITLE;
      property = "ENH_Briefing_INDFOR_Execution";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == independent) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_EXECUTION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_INDFOR_Signal: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_SIGNAL_TITLE;
      property = "ENH_Briefing_INDFOR_Signal";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == independent) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_SIGNAL_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    //-----------------CIVILIAN
    class ENH_Briefing_CIVFOR_Subcategory: ENH_Briefing_BLUFOR_Subcategory
    {
      description = $STR_CIVILIAN;
    };
    class ENH_Briefing_CIVFOR_Situation: ENH_Briefing_BLUFOR_Situation
    {
      property = "ENH_Briefing_CIVFOR_Situation";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == civilian) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_SITUATION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_CIVFOR_Mission: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_MISSION_TITLE;
      property = "ENH_Briefing_CIVFOR_Mission";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == civilian) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_MISSION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_CIVFOR_Execution: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_EXECUTION_TITLE;
      property = "ENH_Briefing_CIVFOR_Execution";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == civilian) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_EXECUTION_TITLE',_this call BIS_fnc_localize]]}}};";
    };
    class ENH_Briefing_CIVFOR_Signal: ENH_Briefing_BLUFOR_Situation
    {
      displayName = $STR_A3_DIARY_SIGNAL_TITLE;
      property = "ENH_Briefing_CIVFOR_Signal";
      expression = "if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName '%s'; waitUntil {!isNull player}; if (side player == civilian) then {player createDiaryRecord ['Diary',[localize 'STR_A3_DIARY_SIGNAL_TITLE',_this call BIS_fnc_localize]]}}};";
    };
  };
};