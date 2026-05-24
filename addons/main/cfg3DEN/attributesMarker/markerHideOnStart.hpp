class ENH_MarkerHideOnStart
{
    displayName = "$STR_ENH_MAIN_MARKERHIDEONSTART_DISPLAYNAME";
    class Attributes
    {
        class ENH_MarkerHideOnStart
        {
            displayName = "$STR_ENH_MAIN_MARKERHIDEONSTART_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_MARKERHIDEONSTART_TOOLTIP";
            property = "ENH_markerHideOnStart";
            control = "Checkbox";
            expression = "\
                if (!isServer || is3DEN || !_value) exitWith {};\
                missionNamespace setVariable [format ['ENH_attributesMarker_%1_initAlpha', _this], markerAlpha _this];\
                _this setMarkerAlpha 0";
            defaultValue = "false";
        };
        class ENH_MarkerShowOnCondition
        {
            displayName = "$STR_ENH_MAIN_MARKERSHOWONCONDITION_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_MARKERSHOWONCONDITION_TOOLTIP";
            property = "ENH_markerShowOnCondition";
            control = "EditCodeMulti3";
            expression = "\
                if (!isServer || is3DEN || _value == 'false' || _value == '') exitWith {};\
                [_this, compile _value] spawn\
                {\
                    params ['_marker', '_compiledValue'];\
                    scriptName 'ENH_MarkerShowOnCondition';\
                    waitUntil {sleep 0.5; call _compiledValue};\
                    private _newAlpha = missionNamespace getVariable [format ['ENH_attributesMarker_%1_initAlpha', _marker], 1];\
                    _marker setMarkerAlpha _newAlpha;\
                }";
            validate = "expression";
            defaultValue = "''";
        };
    };
};
