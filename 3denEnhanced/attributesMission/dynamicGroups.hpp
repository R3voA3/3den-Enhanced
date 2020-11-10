class ENH_DynamicGroups
{
  collapsed = 1;
  displayName = $STR_ENH_DYNAMICGROUPS_DISPLAYNAME;
  class Attributes
  {
    class ENH_EnableDynamicGroups
    {
      displayName = $STR_ENH_ENABLE;
      tooltip = $STR_ENH_DYNAMICGROUPS_TOOLTIP;
      property = "ENH_dynamicGroups";
      control = "Checkbox";
      expression =
      "\
        if (!is3DEN && isMultiplayer && _value) then\
        {\
          if (isServer) then {['Initialize'] call BIS_fnc_dynamicGroups};\
          if (hasInterface) then\
          {\
            [] spawn\
            {\
              scriptName 'ENH_Attribute_DynamicGroups';\
              waitUntil {!isNull player};\
              ['InitializePlayer',[player]] call BIS_fnc_dynamicGroups;\
            };\
          };\
        };\
      ";
      defaultValue = "false";
    };
  };
};

class ENH_Briefing
{
  collapsed = 1;
  displayName = "Briefings";
  class Attributes
  {
    class ENH_Briefing_BLUFOR_Subcategory
    {
      description = "Briefing (BLUFOR)";
      data = "AttributeSystemSubcategory";
      control = "ENH_SubCategoryNoHeader1_Fixed";
    };
    class ENH_Briefing_BLUFOR_Situation
    {
      displayName = "Situation";
      tooltip = "Briefing is added to all players of given side. It is JIP compatible.";
      property = "ENH_Briefing_BLUFOR_Situation";
      control = "EditMulti5";
      expression = "if hasInterface then {player createDiaryRecord ['Situation',_value]}";
      defaultValue = "";
    };
    class ENH_Briefing_BLUFOR_Mission: ENH_Briefing_BLUFOR_Situation
    {
      displayName = "Mission";
      property = "ENH_Briefing_BLUFOR_Mission";
    };
    class ENH_Briefing_BLUFOR_Execution: ENH_Briefing_BLUFOR_Situation
    {
      displayName = "Execution";
      property = "ENH_Briefing_BLUFOR_Execution";
    };
    class ENH_Briefing_BLUFOR_Signal: ENH_Briefing_BLUFOR_Situation
    {
      displayName = "Signal";
      property = "ENH_Briefing_BLUFOR_Signal";
    };
    class ENH_Briefing_OPFOR_Subcategory
    {
      description = "Briefing (OPFOR)";
      data = "AttributeSystemSubcategory";
      control = "ENH_SubCategoryNoHeader1_Fixed";
    };
    class ENH_Briefing_OPFOR_Situtation: ENH_Briefing_BLUFOR_Situation
    {
      displayName = "Signal";
      property = "ENH_Briefing_OPFOR_Signal";
    };
  };
};