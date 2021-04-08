class ENH_ObjectScale
{
  displayName = "EDITOR ONLY! Object Scale";
  tooltip = "EDITOR ONLY! Scales the size of the object. Object scaling is only persistent on simple Objects and/or objects where simulation is disabled.\nGenerally speaking, object scaling is not officially supported by Arma 3 and may cause unexpected behaviour.\nValue is limited from 0.0001 to 65504.";
  property = "ENH_objectScaling";
  control = "EditShort";
  expression = "if (!is3DEN) exitWith {};\
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
  _object setObjectScale _value";
  condition = "1";
  defaultValue = "1";
  typeName = "NUMBER";
  validate = "NUMBER";
};