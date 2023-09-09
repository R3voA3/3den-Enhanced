class ENH_MarkerHideOnStart
{
  displayName = "$STR_ENH_MARKERHIDEONSTART_DISPLAYNAME";
  class Attributes
  {
    class ENH_MarkerHideOnStart
    {
      displayName = "$STR_ENH_MARKERHIDEONSTART_DISPLAYNAME";
      tooltip = "$STR_ENH_MARKERHIDEONSTART_TOOLTIP";
      property = "ENH_markerHideOnStart";
      control = "Checkbox";
      expression = "\
        if (!isServer || is3DEN || !_value) exitWith {};\
        _this setMarkerAlpha 0";
      defaultValue = "false";
    };
    class ENH_MarkerShowOnCondition
    {
      displayName = "$STR_ENH_MARKERSHOWONCONDITION_DISPLAYNAME";
      tooltip = "$STR_ENH_MARKERSHOWONCONDITION_TOOLTIP";
      property = "ENH_markerShowOnCondition";
      control = "EditCodeMulti3";
      expression = "\
        if (!isServer || is3DEN || _value == 'false' || _value == '') exitWith {};\
        [_this, compile _value] spawn\
        {\
          params ['_marker', '_compiledValue'];\
          scriptName 'ENH_MarkerShowOnCondition';\
          waitUntil {sleep 1; call _compiledValue};\
          _marker setMarkerAlpha 1;\
        }";
      validate = "expression";
      defaultValue = "''";
    };
  };
};