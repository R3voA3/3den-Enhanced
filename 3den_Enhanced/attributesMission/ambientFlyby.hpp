class Enh_AmbientFlyby
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_ambientFlyby;
	class Attributes
	{
		class Enh_Type
		{
			displayName = $STR_ENH_ambientFlyby_type_displayName;
			tooltip = $STR_ENH_ambientFlyby_type_tooltip;
			property = "Enh_ambientFlyby_type";
			control = "EditArray";
			expression ="\
			if (isServer && !is3DEN && !(_value isEqualTo [])) then\
			{\
				_value spawn\
				{\
					waitUntil {time > 0.2};\
					private _startPos = missionNamespace getVariable ['Enh_ambientFlyby_startPos',[0,0,0]];\
					private _endPos = missionNamespace getVariable ['Enh_ambientFlyby_endPos',[0,0,0]];\
					private _speed = missionNamespace getVariable ['Enh_ambientFlyby_speed','normal'];\
					private _iterations = missionNamespace getVariable ['Enh_ambientFlyby_iterations',1];\
					private _delay = missionNamespace getVariable ['Enh_ambientFlyby_delay',360];\
					\
					for '_i' from 0 to _iterations do\
					{\
						sleep _delay;\
						[_startPos,_endPos,_startPos # 2,_speed,selectRandom _this] call BIS_fnc_ambientFlyby;\
					};\
				};\
			}";
			defaultValue = "[]";
		};
		class Enh_StartPos
		{
			displayName = $STR_ENH_ambientFlyby_startPosition_displayName;
			property = "Enh_ambientFlyby_startPos";
			control = "EditXYZ";
			expression = "missionNamespace setVariable ['%s',_value]";
			defaultValue = "[0,0,0]";
		};
		class Enh_EndPos
		{
			displayName = $STR_ENH_ambientFlyby_endPosition_displayName;
			property = "Enh_ambientFlyby_endPos";
			control = "EditXYZ";
			expression = "missionNamespace setVariable ['%s',_value]";
			defaultValue = "[0,0,0]";
		};
		class Enh_Speed
		{
			displayName = $STR_ENH_ambientFlyby_speed_displayName;
			tooltip = $STR_ENH_ambientFlyby_speed_tooltip;
			property = "Enh_ambientFlyby_speed";
			control = "SpeedModeGroup";
			expression = "missionNamespace setVariable ['%s',_value]";
			defaultValue = "normal";
			typeName = "STRING";
		};
		class Enh_Iterations
		{
			displayName = $STR_ENH_ambientFlyby_iterations_displayName;
			property = "Enh_ambientFlyby_iterations";
			control = "Edit";
			expression = "missionNamespace setVariable ['%s',_value]";
			defaultValue = "1";
			typeName = "NUMBER";
		};
		class Enh_Delay
		{
			displayName = $STR_ENH_ambientFlyby_delay_displayName;
			tooltip = $STR_ENH_ambientFlyby_delay_tooltip;
			property = "Enh_ambientFlyby_Delay";
			control = "SliderTime";
			expression = "missionNamespace setVariable ['%s',_value]";
			defaultValue = "360";
			typeName = "NUMBER";
		};
	};
};
