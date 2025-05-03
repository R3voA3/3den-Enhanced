class ENH_Garrison2
{
    collapsed = 1;
    displayName = "Garrison";
    class Attributes
    {
        class ENH_Garrison2_GroupTogether
        {
            displayName = "Group Entities";// TODO: translation 2025-05-02 R3vo
            tooltip = "If enabled, all entities moved into a building will be grouped together.";
            property = "ENH_Garrison2_GroupTogether";
            control = "Checkbox";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_GroupTogether', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_GroupTogether', false]";
        };
        class ENH_Garrison2_RandomRotation: ENH_Garrison2_GroupTogether
        {
            displayName = "Random Rotation";
            property = "ENH_Garrison2_RandomRotation";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_RandomRotation', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_RandomRotation', true]";
        };
        class ENH_Garrison2_DisablePath: ENH_Garrison2_GroupTogether
        {
            displayName = "Disable Path";
            tooltip = "If enabled, pathing gets disabled for AI units so that they cannot leave their position.";
            property = "ENH_Garrison2_DisablePath";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_DisablePath', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_DisablePath', false]";
        };
        class ENH_Garrison2_AutoSelectRemainingEntities: ENH_Garrison2_GroupTogether
        {
            displayName = "Auto-Select";
            tooltip = "If enabled, remaining units that couldn't be put into positions will be auto selected.";
            property = "ENH_Garrison2_AutoSelectRemainingEntities";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_AutoSelectRemainingEntities', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_AutoSelectRemainingEntities', true]";
        };
        class ENH_Garrison2_CheckForTakenPositions: ENH_Garrison2_GroupTogether
        {
            displayName = "Empty Positions Only";
            tooltip = "If enabled, every building position will first be checked if it has already been taken.";
            property = "ENH_Garrison2_CheckForTakenPositions";
            expression = "profileNamespace setVariable ['ENH_Garrison2_CheckForTakenPositions', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_Garrison2_CheckForTakenPositions', true]";
        };
        class ENH_Garrison2_UnitPos
        {
            displayName = "Stance";
            property = "ENH_Garrison2_UnitPos";
            control = "Combo";
            typeName = "NUMBER";
            class Values
            {
                class Stand
                {
                    name = "Stand";
                    value = 0;
                };
                class Kneel
                {
                    name = "Kneel";
                    value = 1;
                };
                class Prone
                {
                    name = "Prone";
                    value = 2;
                };
                class Large
                {
                    name = "Default Stance";
                    value = 3;
                };
                class Random
                {
                    name = "Random";
                    value = 4;
                };
            };
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_UnitPos', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_UnitPos', 4]";
        };
    };
};
