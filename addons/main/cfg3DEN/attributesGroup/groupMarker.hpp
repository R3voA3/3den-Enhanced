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
            if (!is3DEN && isServer && (_value#0 != '')) then\
            {\
                _value params\
                [\
                    ['_type', ''],\
                    ['_color', 'Default'],\
                    ['_markerText', groupID _this],\
                    ['_showGroupSize', true],\
                    ['_showVehicle', true]\
                ];\
                private _marker = createMarkerLocal\
                [\
                    format ['ENH_Group_Marker_%1', hashValue _this],\
                    [0, 0]\
                ];\
                _markerText = _markerText call BIS_fnc_localize;\
                _marker setMarkerTypeLocal _type;\
                _marker setMarkerColorLocal _color;\
                if (isNil 'ENH_GroupMarker_Initialized') then\
                {\
                    ENH_GroupMarker_Initialized = true;\
                    ENH_GroupMarker_Markers = createHashMap;\
                    ENH_GroupMarker_LastFrame = 0;\
                    ENH_GroupMarker_FrameInterval = 5;\
                    addMissionEventHandler\
                    [\
                        'EachFrame',\
                        {\
                            if (ENH_GroupMarker_LastFrame + ENH_GroupMarker_FrameInterval <= diag_frameNo) then\
                            {\
                                ENH_GroupMarker_LastFrame = diag_frameNo;\
                                ENH_GroupMarker_Markers apply\
                                {\
                                    values _y params keys _y;\
                                    if (_group getVariable ['ENH_GroupMarker_Update', false]) then {continue};\
                                    if (markerShape _x == '' || {isNull _group}) then\
                                    {\
                                        ENH_GroupMarker_Markers deleteAt _x;\
                                    }\
                                    else\
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
                                        _x setMarkerTextLocal format ['%1 %2', _markerText, _textExt];\
                                        _x setMarkerPos _leader;\
                                    };\
                                };\
                            };\
                        }\
                    ];\
                };\
                ENH_GroupMarker_Markers set\
                [\
                    _marker,\
                    createHashMapFromArray\
                    [
                        ['_group', _this],\
                        ['_markerText', _markerText],\
                        ['_showGroupSize', _showGroupSize],\
                        ['_showVehicle', _showVehicle]\
                    ]\
                ];\
            }";
            defaultValue = "['', 'Default', '', true, true]";
        };
    };
};
