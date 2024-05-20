class ENH_MakeHostage: ENH_SetCaptive
{
	displayName = "$STR_ENH_MAIN_MAKEHOSTAGE_DISPLAYNAME";
	tooltip = "$STR_ENH_MAIN_MAKEHOSTAGE_TOOLTIP";
	control = "Checkbox";
	property = "ENH_makeHostage";
	expression =
	"\
	if (isServer && _value) then\
	{\
		ENH_fnc_makeHostage =\
		{\
			if (_this getVariable ['ENH_isHostage', true]) then\
			{\
				_this switchMove 'Acts_AidlPsitMstpSsurWnonDnon04';\
				[\
				_this,\
				localize 'STR_A3_OM_SYSTEM_QUEST_HOSTAGEHOLDACTION',\
				'A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_unbind_ca.paa',\
				'A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_unbind_ca.paa',\
				'_target getVariable [''ENH_IsHostage'', true] && {_this distance _target < 2 && {alive _target && {_target != _this}}}',\
				'alive _target',\
				{},\
				{},\
				{\
					params ['_target', '_caller', '_actionId'];\
					[_target, 'AmovPercMstpSnonWnonDnon'] remoteExec ['playMoveNow', 0];\
					[_target, _actionId] remoteExec ['BIS_fnc_holdActionRemove', 0];\
					_target setVariable ['ENH_IsHostage', false, true];\
					_target setVariable ['ENH_WasFreedBy', _caller, true];\
				}\
				] call BIS_fnc_holdActionAdd;\
			};\
		};\
		[_this, ENH_fnc_makeHostage] remoteExec ['call', 0, true];\
	};\
	";
	defaultValue = "false";
};