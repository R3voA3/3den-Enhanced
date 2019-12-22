class Enh_TriggerInterval
{
	displayName = "Trigger Interval";
	tooltip = "Trigger interval in seconds\nTriggers are configured to check condition approx. every 0.5 second by default. This command allows either to slow down or to speed up default check interval per trigger. Setting interval to 0 will make the trigger check its condition every frame. However, when trigger is attached to some object, the trigger will inherit the simulation frequency of the object it is attached to. This command cannot change the interval of the attached trigger.";
	property = "Enh_TriggerInterval";
	control = "Slider";
	expression = "diag_log _value; if (!is3DEN && _value != 0.5) then {diag_log _value; _this setTriggerInterval _value}";
	condition = "true";
	defaultValue = "0.5";
};