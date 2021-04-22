class ENH_AttachTo
{
  displayName = "Attach";
  tooltip = "Attaches this object to the closest object.";
  property = "ENH_attachTo";
  control = "Checkbox";
  expression = "if (!is3DEN && _value) then {[_this, (nearestObjects [position _this, [], 10, true] - [_this]) select 0] call BIS_fnc_attachToRelative;}";
  condition = "(1 - logicModule) * (1 - objectBrain) * (1 - objectControllable)";
  defaultValue = "false";
};