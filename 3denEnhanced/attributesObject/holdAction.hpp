class Enh_HoldAction
{
	collapsed = 1;
	displayName = "Hold Action";
	class Attributes
	{
		class Enh_AddHoldAction//TO-DO: remoteExec adds the action even though it won't appear for clients because it was already used.
		{
			displayName = "Hold Action";
			property = "Enh_HoldAction";
			control = "Enh_HoldAction";
			expression = "\
			_value params ['_name','_iconIdle','_iconProgress','_conditionShow','_conditionProgress','_codeStart','_codeProgress','_codeCompletion','_codeInterrupt','_duration','_priority','_showUnconscious','_showWindow'];\
			if (!is3DEN && !(_name isEqualTo '')) then\
			{\
				[\
					_this,\
					_name,\
					_iconIdle,\
					_iconProgress,\
					format ['(%1) && (%2)',_conditionShow,'_target getVariable [''Enh_HoldActionShow'',true]'],\
					_conditionProgress,\
					compile _codeStart,\
					compile _codeProgress,\
					compile format ['%1; %2','_target setVariable [''Enh_HoldActionShow'',false,true]',_codeCompletion],\
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
			defaultValue = "['','\a3\ui_f\data\igui\cfg\holdactions\holdaction_revive_ca.paa','\a3\ui_f\data\igui\cfg\holdactions\holdaction_revive_ca.paa','true','true','','','','',10,1000,false,true,'Custom']";
		};
	};
};