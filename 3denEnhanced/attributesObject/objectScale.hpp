class ENH_ObjectScaling
{
  displayName = "$STR_ENH_OBJECTSCALING_DISPLAYNAME";
  tooltip = "$STR_ENH_OBJECTSCALING_TOOLTIP";
  property = "ENH_objectScaling";
  control = "ENH_ObjectScaling";
  expression = "\
  if (is3DEN) then\
  {\
    _this addEventHandler ['AttributesChanged3DEN',\
    {\
      params ['_object'];\
      _object setObjectScale ((_object get3DENAttribute 'ENH_objectScaling') # 0);\
    }];\
    _this addEventHandler ['Dragged3DEN',\
    {\
      params ['_object'];\
      _object setObjectScale ((_object get3DENAttribute 'ENH_objectScaling') # 0);\
    }];\
  };\
  [_this, _value] spawn {sleep 0.01; (_this select 0) setObjectScale (_this select 1)}";
  condition = "1 - objectSimulated";
  defaultValue = "1";
  typeName = "NUMBER";
  validate = "NUMBER";
};