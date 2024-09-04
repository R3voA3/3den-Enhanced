class ENH_AmbientAnimations
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_AMBIENTANIMATIONS_DISPLAYNAME";
    class Attributes
    {
        class ENH_AmbientAnimations_Subcategory
        {
            description = "$STR_ENH_MAIN_AMBIENTANIMATIONS_DESCRIPTION";
            data = "AttributeSystemSubcategory";
            control = "ENH_SubCategoryNoHeader1_Fixed";
        };
        class ENH_AmbientAnimations
        {
            displayName = "$STR_ENH_MAIN_AMBIENTANIMATIONS_DISPLAYNAME";
            control = "ENH_AmbientAnimations";
            property = "ENH_AmbientAnimations";
            expression =
            "\
            if (_value # 0 != '') then\
            {\
                _value params ['_animSet', '_anims', '_canExit', '_attach'];\
                \
                _this setVariable ['ENH_ambientAnimations_anims', _anims];\
                _this disableAI 'ANIM';\
                if (_attach && !is3DEN) then\
                {\
                    private _logic = group _this createUnit ['Logic', getPosATL _this, [], 0, 'NONE'];\
                    _this setVariable ['ENH_ambientAnimations_logic', _logic];\
                    [_this, _logic] call BIS_fnc_attachToRelative;\
                };\
                \
                ENH_fnc_ambientAnimations_play =\
                {\
                    params ['_unit'];\
                    private _anim = selectRandom (_unit getVariable ['ENH_ambientAnimations_anims', []]);\
                    [_unit, _anim] remoteExec ['switchMove', 0];\
                };\
                \
                ENH_fnc_ambientAnimations_exit =\
                {\
                    params ['_unit'];\
                    if !(_unit getVariable ['ENH_ambientAnimations_exit', true]) exitWith {false};\
                    _unit setVariable ['ENH_ambientAnimations_exit', true];\
                    detach _unit;\
                    deleteVehicle (_unit getVariable ['ENH_ambientAnimations_logic', objNull]);\
                    if (alive _unit) then\
                    {\
                        [_unit, ''] remoteExec ['switchMove', 0];\
                        _unit enableAI 'ANIM';\
                    };\
                    _unit removeEventHandler ['Killed', _unit getVariable ['ENH_EHKilled',-1]];\
                    _unit removeEventHandler ['Dammaged', _unit getVariable ['ENH_EHDammaged',-1]];\
                    _unit removeEventHandler ['AnimDone', _unit getVariable ['ENH_EHAnimDone',-1]];\
                };\
                \
                private _EHAnimDone = _this addEventHandler ['AnimDone',\
                    {\
                        params ['_unit'];\
                        if (alive _unit) then\
                        {\
                            _unit call ENH_fnc_ambientAnimations_play;\
                        }\
                        else\
                        {\
                            _unit call ENH_fnc_ambientAnimations_exit;\
                        };\
                    }\
                ];\
                _this setVariable ['ENH_EHAnimDone', _EHAnimDone];\
                \
                if (_canExit && !is3DEN) then\
                {\
                    private _EHKilled = _this addEventHandler ['Killed',\
                    {\
                        (_this select 0) call ENH_fnc_ambientAnimations_exit;\
                    }];\
                    _this setVariable ['ENH_EHKilled', _EHKilled];\
                    private _EHDammaged = _this addEventHandler ['Dammaged',\
                    {\
                        (_this select 0) call ENH_fnc_ambientAnimations_exit;\
                    }];\
                    _this setVariable ['ENH_EHDammaged', _EHDammaged];\
                    _this spawn\
                    {\
                        scriptName 'ENH_Attribute_AmbientAnimations';\
                        params ['_unit'];\
                        waitUntil\
                        {\
                            sleep 1; (_unit getVariable ['ENH_ambientAnimations_exit', false]) || {behaviour _unit == 'COMBAT'}\
                        };\
                        _unit call ENH_fnc_ambientAnimations_exit;\
                    };\
                };\
                _this call ENH_fnc_ambientAnimations_play;\
            };";
            condition = "objectBrain";
            defaultValue = "['', [], false, false]";
        };
    };
};
