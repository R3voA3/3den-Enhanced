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
                [_this, _value] spawn {\
                    scriptName 'ENH_Attribute_GroupMarker';\
                    params ['_group', '_parameters'];\
                    _parameters params [['_type', ''], ['_color', 'Default'], ['_text', groupID _group], ['_showGroupSize', true], ['_showVehicle', true]];\
                    private _marker = createMarkerLocal [\
                        'ENH_GroupMarker_' + str _group,\
                        [0, 0]\
                    ];\
                    _marker setMarkerTypeLocal _type;\
                    _marker setMarkerColorLocal _color;\
                    _marker setMarkerTextLocal (_text call BIS_fnc_localize);\
                    private _groupString = _text call BIS_fnc_localize;\
                    while {true} do\
                    {\
                        sleep 1;\
                        if (isNull _group) exitWith {deleteMarker _marker};\
                        if (_group getVariable ['ENH_GroupMarker_Update', true]) then\
                        {\
                            private _leader = leader _group;\
                            _marker setMarkerPos _leader;\
                            private _sizeString = (' (' + str count units _group + ')');\
                            if (_showGroupSize && {vehicle _leader != _leader}) then\
                            {\
                                private _vehicleName = getText (configOf vehicle _leader >> 'displayName');\
                                private _vehicleString = (' [' + _vehicleName + ']');\
                                if _showGroupSize then\
                                {\
                                    _marker setMarkerTextLocal (_groupString + _vehicleString + _sizeString);\
                                }\
                                else\
                                {\
                                    _marker setMarkerTextLocal (_groupString + _vehicleString);\
                                };\
                            }\
                            else\
                            {\
                                if _showGroupSize then\
                                {\
                                    _marker setMarkerTextLocal (_groupString + _sizeString);\
                                };\
                            };\
                        };\
                    };\
                };\
            };";
            defaultValue = "['', 'Default', '', true, true]";
        };
    };
};
