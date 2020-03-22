class ENH_HoldAction
{
	collapsed = 1;
	displayName = $STR_ENH_HOLDACTION_DISPLAYNAME;
	class Attributes
	{
		class ENH_AddHoldAction
		{
			displayName = $STR_ENH_HOLDACTION_DISPLAYNAME;
			property = "ENH_HoldAction";
			control = "ENH_HoldAction";
			expression = "\
			_value params ['_name','_iconIdle','_iconProgress','_conditionShow','_conditionProgress','_codeStart','_codeProgress','_codeCompletion','_codeInterrupt','_duration','_priority','_showUnconscious','_showWindow'];\
			if (!is3DEN && {!(_name isEqualTo '')}) then\
			{\
				[\
					_this,\
					_name,\
					_iconIdle,\
					_iconProgress,\
					_conditionShow,\
					_conditionProgress,\
					compile _codeStart,\
					compile _codeProgress,\
					compile format ['%1 %2','[_this select 0,_this select 2] remoteExecCall [''removeAction'',0]; remoteExecCall ['''',_this select 0];',_codeCompletion],\
					compile _codeInterrupt,\
					nil,\
					_duration,\
					_priority,\
					true,\
					_showUnconscious,\
					_showWindow\
				] remoteExecCall ['BIS_fnc_holdActionAdd',0,_this];\
			};";
			condition = "1 - logicModule";
			defaultValue = "['','\a3\ui_f\data\igui\cfg\holdactions\holdaction_revive_ca.paa','\a3\ui_f\data\igui\cfg\holdactions\holdaction_revive_ca.paa','true','true','','','','',10,1000,false,true]";
		};
	};
};