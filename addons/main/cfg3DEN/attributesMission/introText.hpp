class ENH_IntroText
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_INTROTEXT_DISPLAYNAME";
    class Attributes
    {
        class ENH_IntroText_Subcategory
        {
            description = "$STR_ENH_MAIN_INTROTEXT_DESCRIPTION";
            data = "AttributeSystemSubcategory";
            control = "ENH_SubCategoryNoHeader1_Fixed";
        };
        class ENH_IntroText
        {
            displayName = "$STR_ENH_MAIN_INTROTEXT_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_INTROTEXT_DESCRIPTION";
            property = "ENH_introText";
            control = "ENH_IntroText";
            expression =
            "\
                if (!is3DEN && (_value # 0) > 0 && hasInterface) then\
                {\
                    _value spawn\
                    {\
                        scriptName 'ENH_Attribute_IntroText';\
                        params ['_delay', '_l1', '_l2', '_l3', '_type'];\
                        _l1 = _l1 call BIS_fnc_localize;\
                        _l2 = _l2 call BIS_fnc_localize;\
                        _l3 = _l3 call BIS_fnc_localize;\
                        uiSleep _delay;\
                        switch _type do\
                        {\
                            case 0:\
                            {\
                                private _text = parseText format\
                                [\
                                    ""<t align='right' size='1.6'><t font='PuristaBold' size='1.8'>%1<br/></t>%2<br/>%3</t>"",\
                                    _l1,\
                                    _l2,\
                                    _l3\
                                ];\
                                [_text, true] spawn BIS_fnc_textTiles;\
                            };\
                            case 1:\
                            {\
                                [_l1, _l2, _l3] spawn BIS_fnc_infoText;\
                            };\
                            case 2:\
                            {\
                                [_l1, _l2, _l3] spawn BIS_fnc_EXP_camp_SITREP;\
                            };\
                        };\
                    };\
                }";
            defaultValue = "[0, briefingName, 'by ' + profileName, [daytime, 'HH:MM'] call BIS_fnc_TimeToString, 0]";
        };
    };
};
