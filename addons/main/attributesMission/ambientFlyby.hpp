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
            // TODO: remove diag log from expression 2025-03-29 R3vo
            expression ="\
            if (isServer && !is3DEN && ((_value # 0) isNotEqualTo [])) then\
            {\
                ENH_AmbientFlyby_Enabled = true;\
                _value spawn\
                {\
                    scriptName 'ENH_Attribute_AmbientFlyby';\
                    params ['_classes', '_startPos', '_endPos', '_alt', '_speed', '_side', '_delay', '_rndStartOffset', '_rndEndOffset', '_rndDelayOffset'];\
                    while {ENH_AmbientFlyby_Enabled} do\
                    {\
                        private _finalDelay = ((_delay + random _rndDelayOffset - random _rndDelayOffset) max 1);\
                        private _finalStartPos = _startPos vectorAdd [random _rndStartOffset - random _rndStartOffset, random _rndStartOffset - random _rndStartOffset];\
                        private _finalEndPos = _endPos vectorAdd [random _rndEndOffset - random _rndEndOffset, random _rndEndOffset - random _rndEndOffset];\
                        \
                        sleep _finalDelay;\
                        [
                        _finalStartPos,
                        _finalEndPos,
                        _alt,
                        _speed,
                        selectRandom _classes,
                        _side
                    ] call BIS_fnc_ambientFlyby;\
                    diag_log\
                    [\
                        _finalDelay,\
                        _finalStartPos,\
                        _finalEndPos\
                    ];\
                    };\
                };\
            }";
            defaultValue = "[[], [0, 0, 0], [0, 0, 0], 500, 'normal', west, 300]";
        };
    };
};
