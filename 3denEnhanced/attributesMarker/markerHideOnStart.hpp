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
      control = "CheckboxNumber";
      expression = "\
        if (!isServer) exitWith {};\
        if (is3DEN) exitWith {};\
        if (_value >= 0) then {_this setMarkerAlpha 0};\
      ";
      defaultValue = 0;
      typeName = "NUMBER";
    };
    class ENH_MarkerShowOnCondition
    {
      displayName = "$STR_ENH_MARKERSHOWONCONDITION_DISPLAYNAME";
      tooltip = "$STR_ENH_MARKERSHOWONCONDITION_TOOLTIP";
      property = "ENH_markerShowOnCondition";
      control = "EditCode";
      expression = "\
        if (!isServer) exitWith {};\
        if (is3DEN) exitWith {};\
        [_this, _value] spawn {\
          params ['_marker', '_value'];\
          waitUntil {\
            sleep 0.5;\
            call compile _value;\
          };\
          _marker setMarkerAlpha 1;\
        };\
      ";
      defaultValue = "''";
      validate = "expression";
    };
  };
};