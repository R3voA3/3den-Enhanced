class ENH_GroupMarker
{
    displayName = "$STR_ENH_MAIN_GROUPMARKER_DISPLAYNAME";
    collapsed = 1;
    class Attributes
    {
        class ENH_GroupMarker_Subcategory
        {
            description = "$STR_ENH_MAIN_GROUPMARKER_DESCRIPTION";
            property = "ENH_GroupMarker_Subcategory";
            control = "ENH_SubCategoryNoHeader3_Fixed";
        };
        class ENH_GroupMarker
        {
            displayName = "$STR_ENH_MAIN_GROUPMARKER_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_GROUPMARKER_DESCRIPTION";
            property = "ENH_groupMarker";
            control = "ENH_GroupMarker";
            expression = "\
            if (!is3DEN && (_value # 0 != '')) then\
            {\
                [_this, _value] spawn\
                {\
                    scriptName 'ENH_Attribute_GroupMarker';\
                    params ['_group', '_parameters'];\
                    _parameters params\
                    [\
                        ['_type', ''],\
                        ['_color', 'Default'],\
                        ['_text', groupID _group],\
                        ['_showGroupSize', true],\
                        ['_showVehicle', true]\
                    ];\
                    private _marker = createMarkerLocal\
                    [\
                        'ENH_GroupMarker_' + str _group,\
                        [0, 0]\
                    ];\
                    private _markerText = _text call BIS_fnc_localize;\
                    _marker setMarkerTypeLocal _type;\
                    _marker setMarkerColorLocal _color;\
                    while {true} do\
                    {\
                        sleep 1;\
                        if (isNull _group) exitWith {deleteMarker _marker};\
                        if (markerShape _marker == '') exitWith {_group setVariable ['ENH_GroupMarker_Update', false]};\
                        if (_group getVariable ['ENH_GroupMarker_Update', true]) then\
                        {\
                            private _leader = leader _group;\
                            private _textExt = '';\
                            if (_showVehicle && {!isNull objectParent _leader}) then\
                            {\
                                _textExt = format ['[%1]', getText (configOf objectParent _leader >> 'displayName')];\
                            };\
                            if (_showGroupSize) then\
                            {\
                                _textExt = format ['%1 [%2]',_textExt, count units _group];\
                            };\
                            _marker setMarkerTextLocal format ['%1 %2', _markerText, _textExt];\
                            _marker setMarkerPos _leader;\
                        };\
                    };\
                };\
            }";
            defaultValue = "['', 'Default', '', true, true]";
        };
    };
};
