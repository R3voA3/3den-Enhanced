class ENH_MakeHostage: ENH_SetCaptive
{
	displayName = $STR_ENH_MAKEHOSTAGE_DISPLAYNAME;
	tooltip = $STR_ENH_MAKEHOSTAGE_TOOLTIP;
	property = "ENH_makeHostage";
	expression =
	"\
		if (isServer && {_value}) then\
		{\
			ENH_fnc_makeHostage =\
			{\
				if (_this getVariable ['ENH_isHostage',true]) then\
				{\
					_this switchMove 'Acts_AidlPsitMstpSsurWnonDnon04';\
					[\
					  _this,\
					  'Free Hostage',\
					  'A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_unbind_ca.paa',\
					  'A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_unbind_ca.paa',\
					  '_target getVariable [''ENH_IsHostage'',true] && {_this distance _target < 2 && {alive _target && {_target != _this}}}',\
					  'true',\
					  {},\
					  {},\
					  {\
					  	[_this # 0,'AmovPercMstpSnonWnonDnon'] remoteExec ['playMoveNow',0];\
					  	[_this # 0,_this # 2] remoteExec ['BIS_fnc_holdActionRemove',0];\
					  	_this # 0 setVariable ['ENH_IsHostage',false,true];\
					  }\
					 ] call BIS_fnc_holdActionAdd;\
				};\
			};\
			[_this,ENH_fnc_makeHostage] remoteExec ['call',0,true];\
		};\
	";
};