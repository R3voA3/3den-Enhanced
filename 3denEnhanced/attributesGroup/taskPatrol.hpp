class ENH_TaskPatrol
{
	displayName = $STR_ENH_patrol_displayName;
	tooltip = $STR_ENH_patrol_tooltip;
	property = "ENH_TaskPatrol";
	control = "ENH_TaskPatrol";
	expression = "if (!is3DEN && (_value > 0)) then {[_this,getPosATL (leader _this),_value] call BIS_fnc_taskPatrol}";
	defaultValue = "0";
	typeName = "NUMBER";
};