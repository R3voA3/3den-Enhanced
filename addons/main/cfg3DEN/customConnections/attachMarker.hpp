class ENH_AttachMarker
{
    displayName = "$STR_ENH_MAIN_CUSTOM_CONNECTION_ATTACH_MARKER_DISPLAYNAME";
    condition1 = "Marker * script1";
    conditionScript1 = "get3DENConnections _this findIf {_x#0 =='ENH_AttachMarker'} == -1";
    condition2 = "Object";
    property = "ENH_AttachMarker";
    data = "ENH_AttachMarker";
    color[] = {0.12549, 0.505882, 0.313726, 1};
    cursor = "3DENConnectSync";
    // Runs on the server
    expression = "\
    if (isNil 'ENH_AttachMarker_Initialized') then
    {
        ENH_AttachMarker_Initialized = true;\
        ENH_AttachMarker_Markers = createHashMap;\
        ENH_AttachMarker_LastFrame = 0;\
        ENH_AttachMarker_FrameInterval = 5;\
        addMissionEventHandler\
        [\
            'EachFrame',\
            {\
                if (ENH_AttachMarker_LastFrame + ENH_AttachMarker_FrameInterval <= diag_frameNo) then
                {
                    ENH_AttachMarker_LastFrame = diag_frameNo;\
                    ENH_AttachMarker_Markers apply
                    {
                        if (markerShape _x == '' || {!alive _y}) then\
                        {\
                            ENH_AttachMarker_Markers deleteAt _x;\
                        }\
                        else\
                        {\
                            _x setMarkerPos _y;\
                        };
                    };\
                };\
            }\
        ];\
    };\
    ENH_AttachMarker_Markers set [_entity0, _entity1]";
};
