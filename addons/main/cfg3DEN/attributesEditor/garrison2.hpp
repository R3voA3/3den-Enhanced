class ENH_Garrison2
{
    collapsed = 1;
    displayName = "Garrison";
    class Attributes
    {
        class ENH_Garrison2_CreateLayer
        {
            displayName = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_CREATE_LAYER_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_CREATE_LAYER_TOOLTIP";
            property = "ENH_Garrison2_CreateLayer";
            control = "Checkbox";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_CreateLayer', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_CreateLayer', false]";
        };
        // TODO: Broken. See https://feedback.bistudio.com/T191578 2025-05-03 R3vo
        class ENH_Garrison2_GroupTogether: ENH_Garrison2_CreateLayer
        {
            displayName = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_GROUP_TOGETHER_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_GROUP_TOGETHER_TOOLTIP";
            property = "ENH_Garrison2_GroupTogether";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_GroupTogether', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_GroupTogether', false]";
        };
        class ENH_Garrison2_RandomRotation: ENH_Garrison2_CreateLayer
        {
            displayName = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_RANDOM_ROTATION_DISPLAYNAME";
            property = "ENH_Garrison2_RandomRotation";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_RandomRotation', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_RandomRotation', true]";
        };
        class ENH_Garrison2_DisablePathfinding: ENH_Garrison2_CreateLayer
        {
            displayName = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_DISABLE_PATHFINDING_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_DISABLE_PATHFINDING_TOOLTIP";
            property = "ENH_Garrison2_DisablePathfinding";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_DisablePathfinding', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_DisablePathfinding', false]";
        };
        class ENH_Garrison2_AutoSelectRemainingEntities: ENH_Garrison2_CreateLayer
        {
            displayName = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_AUTO_SELECT_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_AUTO_SELECT_TOOLTIP";
            property = "ENH_Garrison2_AutoSelectRemainingEntities";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_AutoSelectRemainingEntities', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_AutoSelectRemainingEntities', true]";
        };
        class ENH_Garrison2_CheckForTakenPositions: ENH_Garrison2_CreateLayer
        {
            displayName = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_CHECK_FOR_TAKEN_POSITIONS_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_CHECK_FOR_TAKEN_POSITIONS_TOOLTIP";
            property = "ENH_Garrison2_CheckForTakenPositions";
            expression = "profileNamespace setVariable ['ENH_Garrison2_CheckForTakenPositions', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_Garrison2_CheckForTakenPositions', true]";
        };
        class ENH_Garrison2_Stance
        {
            displayName = "$STR_3DEN_OBJECT_ATTRIBUTE_STANCE_DISPLAYNAME";
            property = "ENH_Garrison2_Stance";
            control = "Combo";
            typeName = "NUMBER";
            class Values
            {
                class Stand
                {
                    name = "$STR_3DEN_ATTRIBUTES_STANCE_UP";
                    value = STANCE_STAND;
                };
                class Kneel
                {
                    name = "$STR_3DEN_ATTRIBUTES_STANCE_MIDDLE";
                    value = STANCE_KNEEL;
                };
                class Prone
                {
                    name = "$STR_3DEN_ATTRIBUTES_STANCE_DOWN";
                    value = STANCE_PRONE;
                };
                class Large
                {
                    name = "$STR_3DEN_ATTRIBUTES_STANCE_DEFAULT";
                    value = STANCE_DEFAULT;
                };
                class Random
                {
                    name = "$STR_3DEN_OBJECT_ATTRIBUTE_COMBO_DISPLAYNAME_RANDOM";
                    value = STANCE_RANDOM;
                };
                class RandomNoProne
                {
                    name = "$STR_ENH_MAIN_PREFERENCES_GARRISON2_STANCE_RANDOM_NO_PRONE_DISPLAYNAME";
                    value = STANCE_NO_PRONE;
                };
            };
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_Stance', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_Stance', 4]";
        };
    };
};
