class ENH_AttachObject
{
    displayName = "$STR_ENH_MAIN_CUSTOM_CONNECTION_ATTACH_OBJECT_DISPLAYNAME";
    condition1 = "Object * Script1";
    conditionScript1 = "get3DENConnections _this findIf {_x#0 =='ENH_AttachObject'} == -1";
    condition2 = "Object";
    property = "ENH_AttachObject";
    data = "ENH_AttachObject";
    color[] =
    {
        "profilenamespace getvariable ['Map_Unknown_R',0]",
        "profilenamespace getvariable ['Map_Unknown_G',1]",
        "profilenamespace getvariable ['Map_Unknown_B',1]",
        1
    };
    cursor = "3DENConnectSync";
    // Runs on the server
    expression = "[_entity0, _entity1, true] remoteExecCall ['BIS_fnc_attachToRelative', _entity0]";
};
