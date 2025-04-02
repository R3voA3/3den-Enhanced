class ENH_AmbientFlyby
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_AMBIENTFLYBY_DISPLAYNAME";
    class Attributes
    {
        class ENH_AmbientFlyby_Subcategory
        {
            description = "$STR_ENH_MAIN_AMBIENTFLYBY_DESCRIPTION";
            property = "ENH_AmbientFlyby_Subcategory";
            control = "ENH_SubCategoryNoHeader3_Fixed";
        };
        class ENH_AmbientFlyby
        {
            displayName = "$STR_ENH_MAIN_AMBIENTFLYBY_DISPLAYNAME";
            property = "ENH_ambientFlyby";
            control = "ENH_AmbientFlyby";
            expression ="\
            if (isServer && !is3DEN && ((_value # 0) isNotEqualTo [])) then\
            {\
                ENH_AmbientFlyby_Enabled = true;\
                _value spawn\
                {\
                    scriptName 'ENH_Attribute_AmbientFlyby';\
                    diag_log _this;\
                    params ['_classes', '_startPos', '_endPos', '_alt', '_speed', '_side', ['_delay', [300, 300, 300], [[], 0]], ['_rndStartOffset', 0], ['_rndEndOffset', 0]];\
                    if (_delay isEqualType 0) then {_delay = [_delay, _delay, _delay]};\
                    \
                    while {ENH_AmbientFlyby_Enabled} do\
                    {\
                        sleep random _delay;\
                        [
                            _startPos vectorAdd [random _rndStartOffset - random _rndStartOffset, random _rndStartOffset - random _rndStartOffset],
                            _endPos vectorAdd [random _rndEndOffset - random _rndEndOffset, random _rndEndOffset - random _rndEndOffset],
                            _alt,
                            _speed,
                            selectRandom _classes,
                            _side
                        ] call BIS_fnc_ambientFlyby;\
                    };\
                };\
            }";
            defaultValue = "[[], [0, 0, 0], [0, 0, 0], 500, 'normal', west, [300, 300, 300], 0, 0]";
        };
    };
};
