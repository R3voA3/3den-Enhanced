class ENH_Garrison2
{
    collapsed = 1;
    displayName = "Garrison";
    class Attributes
    {
        class ENH_Garrison2_GroupTogether
        {
            displayName = "Group Entities";
            property = "ENH_CoENH_Garrison2_GroupTogetherllapseAssetBrowser";
            control = "Checkbox";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison_GroupTogether', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison_GroupTogether', false]";
        };
        class ENH_Garrison2_RandomRotation: ENH_Garrison2_GroupTogether
        {
            displayName = "Random Roation";
            property = "ENH_Garrison2_RandomRotation";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison_RandomRotation', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison_RandomRotation', true]";
        };
        class ENH_Garrison2_DisablePath: ENH_Garrison2_GroupTogether
        {
            displayName = "Random Rotation";
            property = "ENH_Garrison2_DisablePath";
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison_DisablePath', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison_DisablePath', true]";
        };
        class ENH_Garrison2_AutoSelectRemainingEntities: ENH_Garrison2_GroupTogether
        {
            displayName = "Auto-Select";
            tooltip = "If enabled, remaining units that couldn't be put into positions will be auto selected.";
            property = "ENH_Garrison2_AutoSelectRemainingEntities";
            expression = "profileNamespace setVariable ['AutoSelectRemainingEntities', _value]";
            defaultValue = "profileNamespace getVariable ['AutoSelectRemainingEntities', true]";
        };
        class ENH_Garrison2_UnitPos
        {
            displayName = "Unit Pos Behaviour ";
            property = "ENH_Garrison2_UnitPos";
            control = "Combo";
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
            expression = "profileNamespace setVariable ['ENH_EditorPreferences_Garrison_UnitPos', _value]";
            defaultValue = "profileNamespace getVariable ['ENH_EditorPreferences_Garrison_UnitPos', 4]";
        };
    };
};
