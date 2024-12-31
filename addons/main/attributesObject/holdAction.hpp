class ENH_HoldAction
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_HOLDACTION_DISPLAYNAME";
    class Attributes
    {
        class ENH_HoldAction_Subcategory
        {
            description = "$STR_ENH_MAIN_HOLDACTION_DESCRIPTION";
            data = "AttributeSystemSubcategory";
            control = "ENH_SubCategoryNoHeader1_Fixed";
        };
        class ENH_HoldAction
        {
            displayName = "$STR_ENH_MAIN_HOLDACTION_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_HOLDACTION_DESCRIPTION";
            property = "ENH_HoldAction";
            control = "ENH_HoldAction";
            expression = "\
            _value params ['_name', '_iconIdle', '_iconProgress', '_conditionShow', '_conditionProgress', '_codeStart', '_codeProgress', '_codeCompletion', '_codeInterrupt', '_duration', '_priority', '_showUnconscious', '_showWindow', '_removeAfterUse'];\
            if (!is3DEN && (_name != '')) then\
            {\
                if _removeAfterUse then\
                {\
                    _codeCompletion = format ['%1 %2', '[_this select 0, _this select 2] remoteExecCall [''removeAction'', 0]; remoteExecCall ['''', _this select 0];', _codeCompletion];\
                };\
                [\
                    _this,\
                    _name,\
                    _iconIdle,\
                    _iconProgress,\
                    _conditionShow,\
                    _conditionProgress,\
                    compile _codeStart,\
                    compile _codeProgress,\
                    compile _codeCompletion,\
                    compile _codeInterrupt,\
                    nil,\
                    _duration,\
                    _priority,\
                    _removeAfterUse,\
                    _showUnconscious,\
                    _showWindow\
                ] remoteExecCall ['BIS_fnc_holdActionAdd', 0, _this];\
            };";
            condition = "1 - logicModule";
            defaultValue = "['', '\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa', '\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa', 'true', 'true', '', '', '', '', 10, 1000, false, true, true]";
        };
    };
};
